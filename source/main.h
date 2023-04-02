#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdint.h>

//typedef unsigned        uint32_t;
//typedef unsigned short  uint16_t;
//typedef unsigned char   uint8_t;

#define EMBEDDED_CLI_IMPL
#include "embedded_cli.h"
#define HSI_HZ 	8000000U
#define TICK_HZ 1000U

#define SIZE_TASK_STACK 1024U
#define SIZE_SCHED_STACK 1024U
#define SRAM_START 0x20000000U
#define SRAM_SIZE (20U * 1024U)
#define SRAM_END  ((SRAM_START) + (SRAM_SIZE))
#define T1_STACK_START ((SRAM_END) - (1 * SIZE_TASK_STACK))
#define T2_STACK_START ((SRAM_END) - (2 * SIZE_TASK_STACK))
#define T3_STACK_START ((SRAM_END) - (3 * SIZE_TASK_STACK))
#define T4_STACK_START ((SRAM_END) - (4 * SIZE_TASK_STACK))
#define IDLE_STACK_START ((SRAM_END) - (5 * SIZE_TASK_STACK))
#define SHED_STACK_START ((SRAM_END) - (6 * SIZE_TASK_STACK))
#define MAX_TASKS 5
#define TASK_READY_STATE  0x00
#define TASK_BLOCKED_STATE  0xFF

#define INTERRUPT_DISABLE()  do{__asm volatile ("MOV R0,#0x1"); asm volatile("MSR PRIMASK,R0"); } while(0)
#define INTERRUPT_ENABLE()  do{__asm volatile ("MOV R0,#0x0"); asm volatile("MSR PRIMASK,R0"); } while(0)

typedef struct
{
	uint32_t psp_value;
	uint32_t block_count;
	uint8_t  current_state;
	void (*task_handler)(void);
}TCB_t;

extern TCB_t user_tasks[];
extern uint32_t g_tick_count;
extern EmbeddedCli *cli;
extern int8_t print_task_gebug;

extern int __io_putchar(int ch);
void init_clock(void);
void init_gpio(void);
void init_uart(void);
void init_IRQ(void);
void toggl_led(void);
void led_on(void);
void led_off(void);
void init_cli(void);
void run_cli(void);
void get_time_ms(void);

void idle_task(void);
void task1_handler(void);
void task2_handler(void);
void task3_handler(void);
void task4_handler(void);
void task_delay(uint32_t tick_count);
void init_scheduler_stack(uint32_t shed_top_of_stack);
void init_task_stack(void);
__attribute__((naked)) void switch_sp_to_psp(void);

#endif //MAIN_H
