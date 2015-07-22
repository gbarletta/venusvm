#include <venus.h>

void simple_program() 
{
	set_memory_cell(0, OPC_MOV_RI);
	set_memory_cell(1, 10);
	set_memory_cell(2, 123);
	
	set_memory_cell(3, OPC_JMP_IX);
	set_memory_cell(4, 0);
	set_memory_cell(5, 0);
}

void init_vm()
{
	init_memory(DEFAULT_MEM_SIZE);
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
