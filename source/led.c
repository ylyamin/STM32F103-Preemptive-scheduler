#include "main.h"

void init_gpio(void)
{
	//LED D2 = PC13 pin 2
	uint32_t *pRCC_APB2ENR = (uint32_t*) 0x40021018;
	uint32_t *pGPIOC_CRH   = (uint32_t*) 0x40011004;

	*pRCC_APB2ENR |= (1 << 4); // IOPC Enable
	*pGPIOC_CRH &= ~(3 << 20); //mode 00 
	*pGPIOC_CRH |= (2 << 20);  //mode 10 - Output mode, max speed 2 MHz.
	*pGPIOC_CRH &= ~(3 << 22); //conf 00 - General purpose output push-pull
}

void led_off(void){
	uint32_t *pGPIOx_ODR   = (uint32_t*) 0x4001100C;
	*pGPIOx_ODR &= ~(1 << 13); // led off

}

void led_on(void){
	uint32_t *pGPIOx_ODR   = (uint32_t*) 0x4001100C;
	*pGPIOx_ODR |= (1 << 13); // led on
}


void toggl_led(void)
{
	uint32_t *pGPIOx_ODR   = (uint32_t*) 0x4001100C;
	uint32_t led_state = *pGPIOx_ODR & (1 << 13);
	if (led_state)
	{
		led_off();
	} 
	else
	{
		led_on();
	} 
}


