#ifndef __VENUS_H
#define __VENUS_H

#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_GPREGS   16
#define DEFAULT_MEM_SIZE 4096
#define STACK_TOP DEFAULT_MEM_SIZE-1

typedef unsigned int       DWORD;
typedef unsigned short int  WORD;
typedef unsigned char       BYTE;
typedef 		 int        CELL;

void init_vm();
void free_vm();
void init_memory(DWORD memsz);
void free_memory();
void set_memory_cell(DWORD addr, CELL value);
CELL get_memory_cell(DWORD addr);
void init_registers();
void set_gpreg_cell(DWORD reg, CELL value);
CELL get_gpreg_cell(DWORD reg);
void set_ipreg_cell(CELL value);
CELL get_ipreg_cell();
void set_spreg_cell(CELL value);
CELL get_spreg_cell();
void init_stack();
void stack_push(CELL value);
CELL stack_pop();

#endif
