#include "main.h"
EmbeddedCli *cli;
int8_t print_task_gebug;

int main(void)
{
	print_task_gebug = 0;
	init_gpio();
	led_off();
	init_uart();
	init_IRQ();
	init_cli();
	printf("\r\n-- Start --\r\n");
	init_scheduler_stack(SHED_STACK_START);
	init_task_stack();
	init_clock();
	switch_sp_to_psp();
	task1_handler();
 	while(1){}; 	
}

void idle_task(void){
	while(1){
		run_cli();
	}
}

void task1_handler(void){
	while(1){
		task_delay(500);
		if(print_task_gebug)
			printf("Task 1\n\r");
	}
}

void task2_handler(void){
	while(1){
		task_delay(600);
		if(print_task_gebug)
			printf("Task 2\n\r");
	}
}
void task3_handler(void){
	while(1){
		task_delay(700);
		if(print_task_gebug)
			printf("Task 3\n\r");
	}
}
void task4_handler(void){
	while(1){
		task_delay(800);
		if(print_task_gebug)
			printf("Task 4\n\r");
	}
}

