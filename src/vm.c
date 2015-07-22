#include <venus.h>

/*
 * mov r0, #25
 * cmp r0, #25
 * je  $0
 * hlt
 */

void simple_program() 
{
	/* mov r0, #25 */
	set_memory_cell(0, OPC_MOV_RI);
	set_memory_cell(1, 0);
	set_memory_cell(2, 25);
	
	/* cmp r0, #25 */
	set_memory_cell(3, OPC_CMP_RI);
	set_memory_cell(4, 0);
	set_memory_cell(5, 24);
	
	/* je $0 */
	set_memory_cell(6, OPC_JE__IX);
	set_memory_cell(7, 0);
	set_memory_cell(8, 0);
	
	/* hlt */
	set_memory_cell(9,  OPC_HLT_XX);
	set_memory_cell(10, 0);
	set_memory_cell(11, 0);
}

void init_vm()
{
	init_memory(DEFAULT_MEM_SIZE);
	init_symbols(DEFAULT_SYM_NUM);
	init_registers();
	init_stack();
	init_opcodes();
	init_exec();	
	simple_program();
}

void init_exec()
{
	set_ipreg_cell(CODE_START);
	set_running_status(STATUS_RUNNING);
}

void run_vm()
{
	CELL current_addr;
	CELL current_instr;
	CELL current_p1;
	CELL current_p2;
	
	while(get_running_status()) {
		current_addr = get_ipreg_cell();
		
		current_instr = get_memory_cell(current_addr);
		current_p1    = get_memory_cell(current_addr + 1);
		current_p2    = get_memory_cell(current_addr + 2);
		
		current_addr += 3;
		set_ipreg_cell(current_addr);
		
		run_opcode(current_instr, current_p1, current_p2);
	}
}

void free_vm()
{
	free_memory();
}
