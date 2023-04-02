#include "main.h"

void init_IRQ(void)
{
	uint32_t *pNVIC_ISER1 = (uint32_t*) 0xE000E104;
	*pNVIC_ISER1 |= (1 << (37 % 32)); // Enable IRQ 37 USART1

	uint32_t *pSHCRS = (uint32_t*) 0xE000ED24; // Enable Usage Bus Mem Handlers
	*pSHCRS |= (1 << 18);
	*pSHCRS |= (1 << 17);
	*pSHCRS |= (1 << 16);
}

void NMI_Handler(void)  		{while(1);}
void HardFault_Handler(void)  	{while(1);}
void MemManage_Handler(void)  	{while(1);}
void BusFault_Handler(void)  	{while(1);}
//void UsageFault_Handler(void) 	{while(1);} 

__attribute__ ((naked)) void UsageFault_Handler(void)
{
	//here we extracted the value of MSP which happens to be the
	//base address of the stack frame(thread mode) which got saved during the exception entry
	//from thread mode to handler mode
	__asm ("MRS r0,MSP");
	while(1);
	__asm ("BX LR");
	//__asm ("B UsageFault_Handler_c");
}
/*
void UsageFault_Handler_c(uint32_t *pBaseStackFrame)
{
	uint32_t *pUFSR = (uint32_t*)0xE000ED2A;
	printf("Exception : UsageFault\n\r");
	printf("UFSR = %lx\n\r",(*pUFSR) & 0xFFFF);
	printf("pBaseStackFrame = %p\n\r",pBaseStackFrame);   
	printf("Value of R0 = %lx\n\r", pBaseStackFrame[0]);
	printf("Value of R1 = %lx\n\r", pBaseStackFrame[1]);
	printf("Value of R2 = %lx\n\r", pBaseStackFrame[2]);
	printf("Value of R3 = %lx\n\r", pBaseStackFrame[3]);
	printf("Value of R12 = %lx\n\r", pBaseStackFrame[4]);
	printf("Value of LR = %lx\n\r", pBaseStackFrame[5]);
	printf("Value of PC = %lx\n\r", pBaseStackFrame[6]);
	printf("Value of XPSR = %lx\n\r", pBaseStackFrame[7]);
	while(1);
}
*/

/*
Value of R0 = fc70f7fe
Value of R1 = 28009009
Value of R2 = 84abf000
Value of R3 = 1b039a03
Value of R12 = ea239304
Value of LR = 46a873e3
Value of PC = 93039208
Value of XPSR = e6949509


*/