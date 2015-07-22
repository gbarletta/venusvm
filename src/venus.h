#ifndef __VENUS_H
#define __VENUS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUMBER_OF_GPREGS   	16
#define DEFAULT_MEM_SIZE 	4096
#define STACK_TOP 			DEFAULT_MEM_SIZE-1
#define MAX_OPCODES       	256
#define CODE_START			0
#define FLAGS_SIZE			32

#define STATUS_HALT			0
#define STATUS_RUNNING		1

#define op(A)				void A(CELL p1, CELL p2)

typedef unsigned int       DWORD;
typedef unsigned short int  WORD;
typedef unsigned char       BYTE;
typedef 		 int        CELL;


/* OPC_OPCODE_DESTSRC 
 * 
 * X = nothing, R = register, M = memory addr, I = immediate 
*/

enum {
	OPC_HLT_XX = 0,	
	OPC_MOV_RR,
	OPC_MOV_RM,		
	OPC_MOV_MR,		
	OPC_MOV_MM,		
	OPC_MOV_RI,		
	OPC_ADD_RR, 		
	OPC_ADD_RI, 		
	OPC_SUB_RR, 		
	OPC_SUB_RI, 		
	OPC_MUL_RR, 
	OPC_MUL_RI,
	OPC_DIV_RR,
	OPC_DIV_RI,
	OPC_AND_RR,
	OPC_AND_RI,
	OPC_JMP_RX,
	OPC_JMP_IX,
	OPC_CMP_RR,
	OPC_CMP_RI,
	OPC_JE__RX,
	OPC_JE__IX
};	

enum {
	ZERO = 0,
	EQUAL,
	GREATER,
	LESS
};

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
void set_running_status(CELL value);
CELL get_running_status();
void set_flag(DWORD flag);
void clr_flag(DWORD flag);
bool get_flag(DWORD flag);
void init_stack();
void stack_push(CELL value);
CELL stack_pop();
void init_opcodes();
void set_opcode(DWORD opcode, void (*instr)(CELL p1, CELL p2));
void run_opcode(DWORD opcode, CELL p1, CELL p2);
void init_exec();
void run_vm();

#endif
