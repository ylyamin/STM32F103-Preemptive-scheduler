
typedef unsigned   uint32_t;
typedef unsigned char   uint8_t;

#define SRAM_START  0x20000000U
#define SRAM_SIZE   (20U * 1024U) //20KB
#define SRAM_END    ((SRAM_START) + (SRAM_SIZE))
#define STACK_START   SRAM_END

extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _la_data;
extern uint32_t _sbss;
extern uint32_t _ebss;

int main(void);

/* function prototypes of STM32F103x system exception and IRQ handlers */
void Reset_Handler                      (void); 
void NMI_Handler                        (void) __attribute__ ((weak, alias("Default_Handler"))); 
void HardFault_Handler                  (void) __attribute__ ((weak, alias("Default_Handler"))); 
void MemManage_Handler                  (void) __attribute__ ((weak, alias("Default_Handler"))); 
void BusFault_Handler                   (void) __attribute__ ((weak, alias("Default_Handler"))); 
void UsageFault_Handler                 (void) __attribute__ ((weak, alias("Default_Handler"))); 
void SVC_Handler                        (void) __attribute__ ((weak, alias("Default_Handler"))); 
void DebugMon_Handler                   (void) __attribute__ ((weak, alias("Default_Handler"))); 
void PendSV_Handler                     (void) __attribute__ ((weak, alias("Default_Handler"))); 
void SysTick_Handler                    (void) __attribute__ ((weak, alias("Default_Handler"))); 
void WWDG_IRQHandler           			(void) __attribute__ ((weak, alias("Default_Handler"))); /* Window Watchdog interrupt                        */
void PVD_IRQHandler            			(void) __attribute__ ((weak, alias("Default_Handler"))); /* PVD through EXTI line detection interrupt        */
void TAMPER_IRQHandler         			(void) __attribute__ ((weak, alias("Default_Handler"))); /* Tamper interrupt                                 */
void RTC_IRQHandler            			(void) __attribute__ ((weak, alias("Default_Handler"))); /* RTC global interrupt                             */
void FLASH_IRQHandler          			(void) __attribute__ ((weak, alias("Default_Handler"))); /* Flash global interrupt                           */
void RCC_IRQHandler            			(void) __attribute__ ((weak, alias("Default_Handler"))); /* RCC global interrupt                             */
void EXTI0_IRQHandler          			(void) __attribute__ ((weak, alias("Default_Handler"))); /* EXTI Line0 interrupt                             */
void EXTI1_IRQHandler          			(void) __attribute__ ((weak, alias("Default_Handler"))); /* EXTI Line1 interrupt                             */
void EXTI2_IRQHandler          			(void) __attribute__ ((weak, alias("Default_Handler"))); /* EXTI Line2 interrupt                             */
void EXTI3_IRQHandler          			(void) __attribute__ ((weak, alias("Default_Handler"))); /* EXTI Line3 interrupt                             */
void EXTI4_IRQHandler          			(void) __attribute__ ((weak, alias("Default_Handler"))); /* EXTI Line4 interrupt                             */
void DMA1_Channel1_IRQHandler  			(void) __attribute__ ((weak, alias("Default_Handler"))); /* DMA1 Channel1 global interrupt                   */
void DMA1_Channel2_IRQHandler  			(void) __attribute__ ((weak, alias("Default_Handler"))); /* DMA1 Channel2 global interrupt                   */
void DMA1_Channel3_IRQHandler  			(void) __attribute__ ((weak, alias("Default_Handler"))); /* DMA1 Channel3 global interrupt                   */
void DMA1_Channel4_IRQHandler  			(void) __attribute__ ((weak, alias("Default_Handler"))); /* DMA1 Channel4 global interrupt                   */
void DMA1_Channel5_IRQHandler  			(void) __attribute__ ((weak, alias("Default_Handler"))); /* DMA1 Channel5 global interrupt                   */
void DMA1_Channel6_IRQHandler  			(void) __attribute__ ((weak, alias("Default_Handler"))); /* DMA1 Channel6 global interrupt                   */
void DMA1_Channel7_IRQHandler  			(void) __attribute__ ((weak, alias("Default_Handler"))); /* DMA1 Channel7 global interrupt                   */
void ADC1_2_IRQHandler         			(void) __attribute__ ((weak, alias("Default_Handler"))); /* ADC1 and ADC2 global interrupt                   */
void USB_HP_CAN_TX_IRQHandler  			(void) __attribute__ ((weak, alias("Default_Handler"))); /* USB High Priority or CAN TX interrupts           */
void USB_LP_CAN_RX0_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler"))); /* USB Low Priority or CAN RX0 interrupts           */
void CAN_RX1_IRQHandler        			(void) __attribute__ ((weak, alias("Default_Handler"))); /* CAN RX1 interrupt                                */
void CAN_SCE_IRQHandler        			(void) __attribute__ ((weak, alias("Default_Handler"))); /* CAN SCE interrupt                                */
void EXTI9_5_IRQHandler        			(void) __attribute__ ((weak, alias("Default_Handler"))); /* EXTI Line[9:5] interrupts                        */
void TIM1_BRK_IRQHandler       			(void) __attribute__ ((weak, alias("Default_Handler"))); /* TIM1 Break interrupt                             */
void TIM1_UP_IRQHandler        			(void) __attribute__ ((weak, alias("Default_Handler"))); /* TIM1 Update interrupt                            */
void TIM1_TRG_COM_IRQHandler   			(void) __attribute__ ((weak, alias("Default_Handler"))); /* TIM1 Trigger and Commutation interrupts          */
void TIM1_CC_IRQHandler        			(void) __attribute__ ((weak, alias("Default_Handler"))); /* TIM1 Capture Compare interrupt                   */
void TIM2_IRQHandler           			(void) __attribute__ ((weak, alias("Default_Handler"))); /* TIM2 global interrupt                            */
void TIM3_IRQHandler           			(void) __attribute__ ((weak, alias("Default_Handler"))); /* TIM3 global interrupt                            */
void TIM4_IRQHandler           			(void) __attribute__ ((weak, alias("Default_Handler"))); /* TIM4 global interrupt                            */
void I2C1_EV_IRQHandler        			(void) __attribute__ ((weak, alias("Default_Handler"))); /* I2C1 event interrupt                             */
void I2C1_ER_IRQHandler        			(void) __attribute__ ((weak, alias("Default_Handler"))); /* I2C1 error interrupt                             */
void I2C2_EV_IRQHandler        			(void) __attribute__ ((weak, alias("Default_Handler"))); /* I2C2 event interrupt                             */
void I2C2_ER_IRQHandler        			(void) __attribute__ ((weak, alias("Default_Handler"))); /* I2C2 error interrupt                             */
void SPI1_IRQHandler           			(void) __attribute__ ((weak, alias("Default_Handler"))); /* SPI1 global interrupt                            */
void SPI2_IRQHandler           			(void) __attribute__ ((weak, alias("Default_Handler"))); /* SPI2 global interrupt                            */
void USART1_IRQHandler         			(void) __attribute__ ((weak, alias("Default_Handler"))); /* USART1 global interrupt                          */
void USART2_IRQHandler         			(void) __attribute__ ((weak, alias("Default_Handler"))); /* USART2 global interrupt                          */
void USART3_IRQHandler         			(void) __attribute__ ((weak, alias("Default_Handler"))); /* USART3 global interrupt                          */
void EXTI15_10_IRQHandler      			(void) __attribute__ ((weak, alias("Default_Handler"))); /* EXTI Line[15:10] interrupts                      */
void RTCAlarm_IRQHandler       			(void) __attribute__ ((weak, alias("Default_Handler"))); /* RTC Alarms through EXTI line interrupt           */                                    
void TIM8_BRK_IRQHandler       			(void) __attribute__ ((weak, alias("Default_Handler"))); /* TIM8 Break interrupt                             */
void TIM8_UP_IRQHandler        			(void) __attribute__ ((weak, alias("Default_Handler"))); /* TIM8 Update interrupt                            */
void TIM8_TRG_COM_IRQHandler   			(void) __attribute__ ((weak, alias("Default_Handler"))); /* TIM8 Trigger and Commutation interrupts          */
void TIM8_CC_IRQHandler        			(void) __attribute__ ((weak, alias("Default_Handler"))); /* TIM8 Capture Compare interrupt                   */
void ADC3_IRQHandler           			(void) __attribute__ ((weak, alias("Default_Handler"))); /* ADC3 global interrupt                            */
void FSMC_IRQHandler           			(void) __attribute__ ((weak, alias("Default_Handler"))); /* FSMC global interrupt                            */
void SDIO_IRQHandler           			(void) __attribute__ ((weak, alias("Default_Handler"))); /* SDIO global interrupt                            */
void TIM5_IRQHandler           			(void) __attribute__ ((weak, alias("Default_Handler"))); /* TIM5 global interrupt                            */
void SPI3_IRQHandler           			(void) __attribute__ ((weak, alias("Default_Handler"))); /* SPI3 global interrupt                            */
void UART4_IRQHandler          			(void) __attribute__ ((weak, alias("Default_Handler"))); /* UART4 global interrupt                           */
void UART5_IRQHandler          			(void) __attribute__ ((weak, alias("Default_Handler"))); /* UART5 global interrupt                           */
void TIM6_IRQHandler           			(void) __attribute__ ((weak, alias("Default_Handler"))); /* TIM6 global interrupt                            */
void TIM7_IRQHandler           			(void) __attribute__ ((weak, alias("Default_Handler"))); /* TIM7 global interrupt                            */
void DMA2_Channel1_IRQHandler  			(void) __attribute__ ((weak, alias("Default_Handler"))); /* DMA2 Channel1 global interrupt                   */
void DMA2_Channel2_IRQHandler  			(void) __attribute__ ((weak, alias("Default_Handler"))); /* DMA2 Channel2 global interrupt                   */
void DMA2_Channel3_IRQHandler  			(void) __attribute__ ((weak, alias("Default_Handler"))); /* DMA2 Channel3 global interrupt                   */
void DMA2_Channel4_5_IRQHandler			(void) __attribute__ ((weak, alias("Default_Handler"))); /* DMA2 Channel4 and DMA2 Channel5 global interrupt */                  


uint32_t vectors[] __attribute__((section(".isr_vector")))   = {
	STACK_START,
	(uint32_t)&Reset_Handler             ,     
	(uint32_t)&NMI_Handler               ,     
	(uint32_t)&HardFault_Handler         ,     
	(uint32_t)&MemManage_Handler         ,     
	(uint32_t)&BusFault_Handler          ,     
	(uint32_t)&UsageFault_Handler        ,     
	(uint32_t)0                          ,     
	(uint32_t)0                          ,     
	(uint32_t)0                          ,     
	(uint32_t)0                          ,     
	(uint32_t)&SVC_Handler               ,     
	(uint32_t)&DebugMon_Handler          ,     
	(uint32_t)0                          ,     
	(uint32_t)&PendSV_Handler            ,     
	(uint32_t)&SysTick_Handler           ,     
	(uint32_t)&WWDG_IRQHandler           ,
	(uint32_t)&PVD_IRQHandler            ,
	(uint32_t)&TAMPER_IRQHandler         ,
	(uint32_t)&RTC_IRQHandler            ,
	(uint32_t)&FLASH_IRQHandler          ,
	(uint32_t)&RCC_IRQHandler            ,
	(uint32_t)&EXTI0_IRQHandler          ,
	(uint32_t)&EXTI1_IRQHandler          ,
	(uint32_t)&EXTI2_IRQHandler          ,
	(uint32_t)&EXTI3_IRQHandler          ,
	(uint32_t)&EXTI4_IRQHandler          ,
	(uint32_t)&DMA1_Channel1_IRQHandler  ,
	(uint32_t)&DMA1_Channel2_IRQHandler  ,
	(uint32_t)&DMA1_Channel3_IRQHandler  ,
	(uint32_t)&DMA1_Channel4_IRQHandler  ,
	(uint32_t)&DMA1_Channel5_IRQHandler  ,
	(uint32_t)&DMA1_Channel6_IRQHandler  ,
	(uint32_t)&DMA1_Channel7_IRQHandler  ,
	(uint32_t)&ADC1_2_IRQHandler         ,
	(uint32_t)&USB_HP_CAN_TX_IRQHandler  ,
	(uint32_t)&USB_LP_CAN_RX0_IRQHandler ,
	(uint32_t)&CAN_RX1_IRQHandler        ,
	(uint32_t)&CAN_SCE_IRQHandler        ,
	(uint32_t)&EXTI9_5_IRQHandler        ,
	(uint32_t)&TIM1_BRK_IRQHandler       ,
	(uint32_t)&TIM1_UP_IRQHandler        ,
	(uint32_t)&TIM1_TRG_COM_IRQHandler   ,
	(uint32_t)&TIM1_CC_IRQHandler        ,
	(uint32_t)&TIM2_IRQHandler           ,
	(uint32_t)&TIM3_IRQHandler           ,
	(uint32_t)&TIM4_IRQHandler           ,
	(uint32_t)&I2C1_EV_IRQHandler        ,
	(uint32_t)&I2C1_ER_IRQHandler        ,
	(uint32_t)&I2C2_EV_IRQHandler        ,
	(uint32_t)&I2C2_ER_IRQHandler        ,
	(uint32_t)&SPI1_IRQHandler           ,
	(uint32_t)&SPI2_IRQHandler           ,
	(uint32_t)&USART1_IRQHandler         ,
	(uint32_t)&USART2_IRQHandler         ,
	(uint32_t)&USART3_IRQHandler         ,
	(uint32_t)&EXTI15_10_IRQHandler      ,
	(uint32_t)&RTCAlarm_IRQHandler       ,
	(uint32_t)0                          ,
	(uint32_t)&TIM8_BRK_IRQHandler       ,
	(uint32_t)&TIM8_UP_IRQHandler        ,
	(uint32_t)&TIM8_TRG_COM_IRQHandler   ,
	(uint32_t)&TIM8_CC_IRQHandler        ,
	(uint32_t)&ADC3_IRQHandler           ,
	(uint32_t)&FSMC_IRQHandler           ,
	(uint32_t)&SDIO_IRQHandler           ,
	(uint32_t)&TIM5_IRQHandler           ,
	(uint32_t)&SPI3_IRQHandler           ,
	(uint32_t)&UART4_IRQHandler          ,
	(uint32_t)&UART5_IRQHandler          ,
	(uint32_t)&TIM6_IRQHandler           ,
	(uint32_t)&TIM7_IRQHandler           ,
	(uint32_t)&DMA2_Channel1_IRQHandler  ,
	(uint32_t)&DMA2_Channel2_IRQHandler  ,
	(uint32_t)&DMA2_Channel3_IRQHandler  ,
	(uint32_t)&DMA2_Channel4_5_IRQHandler,
};


void Default_Handler(void)
{
	while(1);
}

void Reset_Handler(void)
{
	//copy .data section to SRAM
	uint32_t size = (uint32_t)&_edata - (uint32_t)&_sdata;
	
	uint8_t *pDst = (uint8_t*)&_sdata; //sram
	uint8_t *pSrc = (uint8_t*)&_la_data; //flash
	
	for(uint32_t i =0 ; i < size ; i++)
	{
		*pDst++ = *pSrc++;
	}
	
	//Init. the .bss section to zero in SRAM
	size = (uint32_t)&_ebss - (uint32_t)&_sbss;
	pDst = (uint8_t*)&_sbss;
	for(uint32_t i =0 ; i < size ; i++)
	{
		*pDst++ = 0;
	}

	main();
	
}







