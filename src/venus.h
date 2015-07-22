#ifndef __VENUS_H
#define __VENUS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <dlfcn.h>
#include <pthread.h>

#define NUMBER_OF_GPREGS   	16
#define DEFAULT_MEM_SIZE 	4096
#define STACK_TOP 			DEFAULT_MEM_SIZE-1
#define MAX_OPCODES       	256
#define CODE_START			0
#define FLAGS_SIZE			32
#define DEFAULT_SYM_NUM		256
#define DEFAULT_DEV_NUM		256
#define RET_REGISTER		15
#define DEV_REGISTER    	13

#define STATUS_HALT			0
#define STATUS_RUNNING		1

#define SYM_TYPE_FUNC		0
#define SYM_TYPE_VAR		1

#define SYM_NOT_FOUND		0
#define SYM_FOUND			1

#define op(A)				void A(CELL p1, CELL p2)


typedef unsigned int       DWORD;
typedef unsigned short int  WORD;
typedef unsigned char       BYTE;
typedef 		 int        CELL;


/* OPC_OPCODE_DESTSRC 
 * 
 * X = nothing, R = register, M = memory addr, I = immediate, S = symbol 
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
	OPC_JE__IX,
	OPC_JG__RX,
	OPC_JG__IX,
	OPC_JL__RX,
	OPC_JL__IX,
	OPC_JGE_RX,
	OPC_JGE_IX,
	OPC_JLE_RX,
	OPC_JLE_IX,
	OPC_JNE_RX,
	OPC_JNE_IX,
	OPC_JZ__RX,
	OPC_JZ__IX,
	OPC_CALL_R,
	OPC_CALL_I,
	OPC_CALL_S,
	OPC_RET_XX,
	OPC_GET_II,
	OPC_SET_II,
	OPC_RUN_II
};	

enum {
	ZERO = 0,
	EQUAL,
	GREATER,
	LESS
};

struct SYM {
	char  sym_name[32];
	DWORD sym_addr;
	BYTE  sym_type;
};

typedef struct SYM symbol;

typedef DWORD  (*dev_init)();
typedef CELL  (*dev_get)(CELL addr);
typedef CELL  (*dev_set)(CELL addr, CELL value);
typedef CELL  (*dev_send)(CELL *addr, CELL size);
typedef CELL  (*dev_exec)(CELL value);
typedef DWORD  (*dev_exit)();

struct DEVICE {
	char  dev_name[32];
	void *dev_handler;
	dev_init init_func;
	dev_exit quit_func;
	dev_get  get_func;
	dev_set  set_func;
	dev_send send_func;
	dev_exec exec_func;
};

typedef struct DEVICE device;

void init_vm();
void free_vm();
void init_memory(DWORD memsz);
void free_memory();
void set_memory_cell(DWORD addr, CELL value);
CELL get_memory_cell(DWORD addr);
CELL *get_cell_physaddr(DWORD cell_addr);
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
void init_symbols(DWORD symsz);
void add_sym(char *sym_name, CELL sym_addr, BYTE sym_type);
DWORD get_sym(char *sym_name, CELL *sym_addr, BYTE *sym_type);
void init_devices(DWORD devnum);
void free_devices();
void install_device(char *dev_name);
CELL device_get(CELL dev_id, CELL addr);
CELL device_set(CELL dev_id, CELL addr, CELL value);
CELL device_send(CELL dev_id, CELL addr, CELL sz);
CELL device_exec(CELL dev_id, CELL value);

#endif
