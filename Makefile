# Toolchain definitions
CC=arm-none-eabi-gcc
MACH=cortex-m3
DUMP=arm-none-eabi-objdump

# C compilation directives
CFLAGS += -c
CFLAGS += -g
CFLAGS += -mcpu=$(MACH)
CFLAGS += -mthumb 
#CFLAGS += -nostdlib
#CFLAGS += -ffreestanding 

# Linker directives.
LDFLAGS += -g
LDFLAGS += -mcpu=$(MACH)
LDFLAGS += -mthumb
LDFLAGS += -nostartfiles 
LDFLAGS += --specs=nano.specs #newlib-nano
#LDFLAGS += -nodefaultlibs 
#LDFLAGS += -nostdlib
LDFLAGS += -T source/STM32F103C8TX_FLASH.ld #stm32_ls.ld 
LDFLAGS += -Wl,-Map=debug/final.map 
LDFLAGS += -Wl,--print-memory-usage 

SRC_DIR := ./source
OBJ_DIR := ./debug
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
#SRC_FILES := $(filter-out $(SRC_DIR)/syscalls.c, $(SRC_FILES))
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

all: final.elf

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ $<

final.elf: $(OBJ_FILES)
	$(CC) $(LDFLAGS) -o $(OBJ_DIR)/$@ $^
	$(DUMP) -D $(OBJ_DIR)/final.elf > $(OBJ_DIR)/final.asm

clean:
	del debug\*.o debug\*.elf debug\*.asm debug\*.map