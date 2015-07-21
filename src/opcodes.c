#include <venus.h>

void (*opcodes[MAX_OPCODES])(CELL p1, CELL p2);

op(MOV_RR)
{
	CELL reg_value;
	reg_value = get_gpreg_cell(p2);
	
	set_gpreg_cell(p1, reg_value);
}

void init_opcodes() 
{
	set_opcode(OPC_MOV_RR, MOV_RR);
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

