#include "main.h"

void USART1_IRQHandler(void) //read
{
		uint32_t *pUSART1_SR = (uint32_t*) 0x40013800;
		uint32_t *pUSART1_DR = (uint32_t*) 0x40013804;
    	if( *pUSART1_SR & (1 << 5) ) //Bit 5 RXNE: Read data register not empty
		{
			embeddedCliReceiveChar(cli, *pUSART1_DR);
		}; 
}

 int __io_putchar(int ch){ //write
    uint32_t *pUSART1_SR = (uint32_t*) 0x40013800;
    uint32_t *pUSART1_DR = (uint32_t*) 0x40013804;
  	while( !( *pUSART1_SR & (1 << 7) ) ) {}; //TXE: Transmit data register empty
    *pUSART1_DR = ch;
 }

void init_uart(void)
{
	// USART1_TX - PA9
	// USART1_RX - PA10
	uint32_t *pRCC_APB2ENR = (uint32_t*) 0x40021018;
	uint32_t *pGPIOA_CRH   = (uint32_t*) 0x40010804;
	uint32_t *pUSART1_BRR = (uint32_t*) 0x40013808;
	uint32_t *pUSART1_CR1 = (uint32_t*) 0x4001380C;

	*pRCC_APB2ENR |= (1 << 14); // USART1 Enable
	*pRCC_APB2ENR |= (1 << 2); // IOPA Enable
 
	//PA9 output 
	*pGPIOA_CRH &= ~(3 << 4); //mode 00 
	*pGPIOA_CRH |=  (1 << 4); //mode 01: Output mode, max speed 10 MHz.
	*pGPIOA_CRH |=  (2 << 6); //conf 10: Alternate function output Push-pull

	//PA10 input
	*pGPIOA_CRH &= ~(3 << 8); //mode 00: Input mode (reset state)
	*pGPIOA_CRH |=  (1 << 10); //conf 01: Floating input (reset state)

	//bandwidth
 	uint16_t uartdiv = HSI_HZ / 9600;
    *pUSART1_BRR = ( ( ( uartdiv / 16 ) << 4 ) |
                    ( ( uartdiv % 16 ) << 0 ) );

	// Enable the USART peripheral.
	*pUSART1_CR1 |=  (1 << 13);	//UE
	*pUSART1_CR1 |=  (1 << 2); 	//RE
	*pUSART1_CR1 |=  (1 << 3);	//TE
	*pUSART1_CR1 |=  (1 << 5);	//RXNEIE

}



