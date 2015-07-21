#ifndef __VENUS_H
#define __VENUS_H

#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_GPREGS   	16
#define DEFAULT_MEM_SIZE 	4096
#define STACK_TOP 			DEFAULT_MEM_SIZE-1
#define MAX_OPCODES       	256

#define op(A)	void A(CELL p1, CELL p2)

#define OPC_HLT_XX		0
#define OPC_MOV_RR		1
#define OPC_MOV_RM		2
#define OPC_MOV_MR		3
#define OPC_MOV_MM		4
#define OPC_MOV_RI		5

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
void init_opcodes();
void set_opcode(DWORD opcode, void (*instr)(CELL p1, CELL p2));
void run_opcode(DWORD opcode, CELL p1, CELL p2);

#endif
