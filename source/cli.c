#include "main.h"

void writeChar(EmbeddedCli *embeddedCli, char c){
	__io_putchar(c);
}

void run_cli(void){
    embeddedCliProcess(cli);
}

void cmd_led_on(EmbeddedCli *cli, char *args, void *context){
    led_on();
}

void cmd_led_off(EmbeddedCli *cli, char *args, void *context){
    led_off();
}

void cmd_led_toggl(EmbeddedCli *cli, char *args, void *context){
    toggl_led();
}
void cmd_get_time(EmbeddedCli *cli, char *args, void *context){
    get_time_ms();
}

void cmd_print_task_gebug(EmbeddedCli *cli, char *args, void *context){
    if (print_task_gebug)
	{
		print_task_gebug = 0;
	} 
	else
	{
		print_task_gebug = 1;
	}     
}



void init_cli(void){
    EmbeddedCliConfig *config = embeddedCliDefaultConfig();
    cli = embeddedCliNew(config);
	cli->writeChar = writeChar;

	CliCommandBinding comm[] = {
        {
            "led-on",
            "Turn led on",
            false,
            NULL,
            cmd_led_on
        },
        {
            "led-off",
            "Turn led off",
            false,
            NULL,
            cmd_led_off
        }
        ,
        {
            "led-toggl",
            "Toggle led",
            false,
            NULL,
            cmd_led_toggl
        }
        ,
        {
            "get-time",
            "Show time",
            false,
            NULL,
            cmd_get_time
        }
        ,
        {
            "print-task-gebug",
            "Print task gebug",
            false,
            NULL,
            cmd_print_task_gebug
        }
    };

    for(int i = 0;i<(sizeof comm / sizeof comm[0]);i++){
        embeddedCliAddBinding(cli,comm[i]);
    }

    printf("\r\n-- Cli initilized --\r\n");

}

