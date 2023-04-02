#include "main.h"

uint8_t current_task = 1; //task1 is running
uint32_t g_tick_count = 0;

void init_clock(void)
{
	uint32_t *pSYST_CSR = (uint32_t*) 0xE000E010;
	uint32_t *pSYST_RVR = (uint32_t*) 0xE000E014;
	uint32_t count = (HSI_HZ/TICK_HZ)-1;
	*pSYST_CSR &=  (0x00000000);
	*pSYST_RVR &=  (0x00000000);
	*pSYST_RVR |= count;
	*pSYST_CSR |= (1 << 2);
	*pSYST_CSR |= (1 << 1);
	*pSYST_CSR |= (1 << 0);
}

__attribute__((naked)) void PendSV_Handler(void){
	/*Save the context of current task */
	//1. Get current running task's PSP value
	__asm volatile("MRS R0,PSP");
	//2. Using that PSP value store SF2( R4 to R11)
	__asm volatile("STMDB R0!,{R4-R11}");
	__asm volatile("PUSH {LR}");
	//3. Save the current value of PSP
    __asm volatile("BL save_psp_value");

	/*Retrieve the context of next task */
	//1. Decide next task to run
    __asm volatile("BL update_next_task");
	//2. get its past PSP value
	__asm volatile ("BL get_psp_value");
	//3. Using that PSP value retrieve SF2(R4 to R11)
	__asm volatile ("LDMIA R0!,{R4-R11}");
	//4. update PSP and exit
	__asm volatile("MSR PSP,R0");
	__asm volatile("POP {LR}");
	__asm volatile("BX LR");
}

void update_global_tick_count(void){
	g_tick_count++;
	if(g_tick_count == UINT32_MAX){g_tick_count = 0;}
}


void unblock_task(){
	for(int i = 1 ; i < MAX_TASKS ; i++)
	{
		if(user_tasks[i].current_state != TASK_READY_STATE)
		{
			if(user_tasks[i].block_count == g_tick_count)
			{
				user_tasks[i].current_state = TASK_READY_STATE;
			}
		}

	}
}

void schedule(void){
	//pend the pendsv exception
	uint32_t *pICSR = (uint32_t*)0xE000ED04;
	*pICSR |= ( 1 << 28);
}

void SysTick_Handler(void){
	update_global_tick_count();
	unblock_task();
	schedule();
}


void get_time_ms(void){
    printf("[time:%lu]\r\n",g_tick_count);
}

__attribute__((naked)) void init_scheduler_stack(uint32_t shed_top_of_stack){
	__asm volatile("MSR MSP ,%0"::"r"(shed_top_of_stack):);
	__asm volatile("BX LR");

}


#define DUMMY_XPSR 0x01000000U 
TCB_t user_tasks[MAX_TASKS];

void init_task_stack(void){

	user_tasks[0].current_state = TASK_READY_STATE;
	user_tasks[1].current_state = TASK_READY_STATE;
	user_tasks[2].current_state = TASK_READY_STATE;
	user_tasks[3].current_state = TASK_READY_STATE;
	user_tasks[4].current_state = TASK_READY_STATE;

	user_tasks[0].psp_value = IDLE_STACK_START;
	user_tasks[1].psp_value = T1_STACK_START;
	user_tasks[2].psp_value = T2_STACK_START;
	user_tasks[3].psp_value = T3_STACK_START;
	user_tasks[4].psp_value = T4_STACK_START;


	user_tasks[0].task_handler = idle_task;
	user_tasks[1].task_handler = task1_handler;
	user_tasks[2].task_handler = task2_handler;
	user_tasks[3].task_handler = task3_handler;
	user_tasks[4].task_handler = task4_handler;


	uint32_t *pPSP;
	for(int i =0; i < MAX_TASKS; i++ ){
		pPSP = (uint32_t*) user_tasks[i].psp_value; //PSP
		pPSP--;
		*pPSP = DUMMY_XPSR;			//XPSR 
		pPSP--;
		*pPSP = (uint32_t) user_tasks[i].task_handler; 	//PC
		pPSP--;
		*pPSP = 0xFFFFFFFD;			//LR
		
		for(int j = 0; j < 13; j++)
		{
			pPSP--;
			*pPSP = 0; //R1-12
		}
		user_tasks[i].psp_value = (uint32_t)pPSP;
	}

}

uint32_t get_psp_value(void){
	return user_tasks[current_task].psp_value;
}

void save_psp_value(uint32_t current_psp_value)
{
	user_tasks[current_task].psp_value = current_psp_value;
}


void update_next_task(void){
	int state = TASK_BLOCKED_STATE;

	for(int i= 0 ; i < (MAX_TASKS) ; i++)
	{
		current_task++;
	    current_task %= MAX_TASKS;
		state = user_tasks[current_task].current_state;
		if( (state == TASK_READY_STATE) && (current_task != 0) )
			break;
	}

	if(state != TASK_READY_STATE)
		current_task = 0;
}

__attribute__((naked)) void switch_sp_to_psp(void){

	//1. init PSP with Task 1 stack start adress
	__asm volatile ("PUSH {LR}");
	__asm volatile ("BL get_psp_value");
	__asm volatile ("MSR PSP,R0");
	__asm volatile ("POP {LR}");
	//2. change SP to PSP using Control register
	__asm volatile ("MOV R0,#0X02");
	__asm volatile ("MSR CONTROL,R0");
	__asm volatile ("BX LR");


}

void task_delay(uint32_t tick_count){
	INTERRUPT_DISABLE();
	if(current_task){
		user_tasks[current_task].block_count = g_tick_count + tick_count;
		user_tasks[current_task].current_state = TASK_BLOCKED_STATE;
		schedule();
	}
	INTERRUPT_ENABLE();
}

