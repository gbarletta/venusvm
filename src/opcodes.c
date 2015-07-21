#include <venus.h>

void (*opcodes[MAX_OPCODES])(CELL p1, CELL p2);

op(HLT_XX)
{
	printf("halting!!!\n");
}

op(MOV_RR)
{
	CELL reg_value;
	reg_value = get_gpreg_cell(p2);
	
	set_gpreg_cell(p1, reg_value);
}

op(MOV_RM)
{
	CELL mem_value;
	mem_value = get_memory_cell(p2);
	
	set_gpreg_cell(p1, mem_value);
}

op(MOV_MR)
{
	CELL reg_value;
	reg_value = get_gpreg_cell(p2);
	
	set_memory_cell(p1, reg_value);
}

op(MOV_MM)
{
	CELL mem_value;
	mem_value = get_memory_cell(p2);
	
	set_memory_cell(p1, mem_value);
}

op(MOV_RI)
{
	set_gpreg_cell(p1, p2);
}

void init_opcodes() 
{
	set_opcode(OPC_HLT_XX, HLT_XX);
	set_opcode(OPC_MOV_RR, MOV_RR);
	set_opcode(OPC_MOV_RM, MOV_RM);
	set_opcode(OPC_MOV_MR, MOV_MR);
	set_opcode(OPC_MOV_MM, MOV_MM);
	set_opcode(OPC_MOV_RI, MOV_RI);
}

void set_opcode(DWORD opcode, void (*instr)(CELL p1, CELL p2))
{
	if(opcode >= MAX_OPCODES) {
		printf("opcode %x does not exists\n", opcode);
		exit(1);
	}
	
	opcodes[opcode] = instr;
}

void run_opcode(DWORD opcode, CELL p1, CELL p2)
{
	if(opcode >= MAX_OPCODES) {
		printf("opcode %x does not exists\n", opcode);
		exit(1);
	}
	
	opcodes[opcode](p1, p2);
}

