#include <venus.h>

void (*opcodes[MAX_OPCODES])(CELL p1, CELL p2);

op(HLT_XX)
{
	printf("halting!!!\n");
	set_running_status(STATUS_HALT);
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

op(ADD_RR)
{
	CELL reg_value;
	reg_value = get_gpreg_cell(p1);
	
	set_gpreg_cell(p1, reg_value + get_gpreg_cell(p2));
}

op(ADD_RI)
{
	CELL reg_value;
	reg_value = get_gpreg_cell(p1);
	
	set_gpreg_cell(p1, reg_value + p2);
}

op(SUB_RR)
{
	CELL reg_value;
	reg_value = get_gpreg_cell(p1);
	
	set_gpreg_cell(p1, reg_value - get_gpreg_cell(p2));
}

op(SUB_RI)
{
	CELL reg_value;
	reg_value = get_gpreg_cell(p1);
	
	set_gpreg_cell(p1, reg_value - p2);
}

op(MUL_RR)
{
	CELL reg_value;
	reg_value = get_gpreg_cell(p1);
	
	set_gpreg_cell(p1, reg_value * get_gpreg_cell(p2));
}

op(MUL_RI)
{
	CELL reg_value;
	reg_value = get_gpreg_cell(p1);
	
	set_gpreg_cell(p1, reg_value * p2);
}

op(DIV_RR)
{
	CELL reg_value;
	reg_value = get_gpreg_cell(p1);
	
	set_gpreg_cell(p1, reg_value / get_gpreg_cell(p2));
	set_gpreg_cell(14, reg_value % get_gpreg_cell(p2));
}

op(DIV_RI)
{
	CELL reg_value;
	reg_value = get_gpreg_cell(p1);
	
	set_gpreg_cell(p1, reg_value / p2);
	set_gpreg_cell(14, reg_value % p2);
}

op(JMP_RX)
{
	CELL reg_value;
	reg_value = get_gpreg_cell(p1);
	
	set_ipreg_cell(reg_value);
}

op(JMP_IX)
{
	printf("jmp!\n");
	set_ipreg_cell(p1);
}

op(CMP_RR)
{
	CELL reg_value1;
	CELL reg_value2;
	
	reg_value1 = get_gpreg_cell(p1);
	reg_value2 = get_gpreg_cell(p2);
	
	if(reg_value1 == reg_value2) {
		set_flag(EQUAL);
	}
	
	if(reg_value1 < reg_value2) {
		set_flag(LESS);
	}
	
	if(reg_value1 > reg_value2) {
		set_flag(GREATER);
	}
	
	if(reg_value1 == 0) {
		set_flag(ZERO);
	}
}

op(CMP_RI)
{
	CELL reg_value1;
	CELL reg_value2;
	
	reg_value1 = get_gpreg_cell(p1);
	reg_value2 = p2;
	
	if(reg_value1 == reg_value2) {
		set_flag(EQUAL);
	}
	
	if(reg_value1 < reg_value2) {
		set_flag(LESS);
	}
	
	if(reg_value1 > reg_value2) {
		set_flag(GREATER);
	}
	
	if(reg_value1 == 0) {
		set_flag(ZERO);
	}
}

op(JE__RX) 
{
	CELL reg_value;	
	
	if(get_flag(EQUAL)) {
		reg_value = get_gpreg_cell(p1);
		set_ipreg_cell(reg_value);
	}
}

op(JE__IX) 
{
	if(get_flag(EQUAL)) {
		set_ipreg_cell(p1);
	}
}
	
op(JG__RX)
{
	CELL reg_value;
	
	if(get_flag(GREATER)) {
		reg_value = get_gpreg_cell(p1);
		set_ipreg_cell(reg_value);
	}
}

op(JG__IX)
{
	if(get_flag(GREATER)) {
		set_ipreg_cell(p1);
	}
}

op(JL__RX)
{
	CELL reg_value;
	
	if(get_flag(LESS)) {
		reg_value = get_gpreg_cell(p1);
		set_ipreg_cell(reg_value);
	}
}

op(JL__IX)
{
	if(get_flag(LESS)) {
		set_ipreg_cell(p1);
	}
}

op(JGE_RX)
{
	CELL reg_value;
	
	if(get_flag(GREATER) || get_flag(EQUAL)) {
		reg_value = get_gpreg_cell(p1);
		set_ipreg_cell(reg_value);
	}
}

op(JGE_IX)
{
	if(get_flag(GREATER) || get_flag(EQUAL)) {
		set_ipreg_cell(p1);
	}
}


op(JLE_RX)
{
	CELL reg_value;
	
	if(get_flag(LESS) || get_flag(EQUAL)) {
		reg_value = get_gpreg_cell(p1);
		set_ipreg_cell(reg_value);
	}
}

op(JLE_IX)
{
	if(get_flag(LESS) || get_flag(EQUAL)) {
		set_ipreg_cell(p1);
	}
}

op(JNE_RX)
{
	CELL reg_value;
	
	if(!get_flag(EQUAL)) {
		reg_value = get_gpreg_cell(p1);
		set_ipreg_cell(reg_value);
	}
}

op(JNE_IX)
{
	if(!get_flag(EQUAL)) {
		set_ipreg_cell(p1);
	}
}

op(JZ__RX)
{
	CELL reg_value;
	
	if(get_flag(ZERO)) {
		reg_value = get_gpreg_cell(p1);
		set_ipreg_cell(reg_value);
	}
}

op(JZ__IX)
{
	if(get_flag(ZERO)) {
		set_ipreg_cell(p1);
	}
}
	
op(CALL_R)
{
	CELL reg_value;
	reg_value = get_gpreg_cell(p1);
	
	set_gpreg_cell(RET_REGISTER, get_ipreg_cell());
	set_ipreg_cell(reg_value);
}

op(CALL_I)
{
	set_gpreg_cell(RET_REGISTER, get_ipreg_cell());
	set_ipreg_cell(p1);
}

op(RET_XX)
{
	set_ipreg_cell(get_gpreg_cell(RET_REGISTER));
}	

void init_opcodes() 
{
	set_opcode(OPC_HLT_XX, HLT_XX);
	set_opcode(OPC_MOV_RR, MOV_RR);
	set_opcode(OPC_MOV_RM, MOV_RM);
	set_opcode(OPC_MOV_MR, MOV_MR);
	set_opcode(OPC_MOV_MM, MOV_MM);
	set_opcode(OPC_MOV_RI, MOV_RI);
	set_opcode(OPC_ADD_RR, ADD_RR);
	set_opcode(OPC_ADD_RI, ADD_RI);
	set_opcode(OPC_SUB_RR, SUB_RR);
	set_opcode(OPC_SUB_RI, SUB_RI);
	set_opcode(OPC_MUL_RR, MUL_RR);
	set_opcode(OPC_MUL_RI, MUL_RI);
	set_opcode(OPC_DIV_RR, DIV_RR);
	set_opcode(OPC_DIV_RI, DIV_RI);
	set_opcode(OPC_JMP_RX, JMP_RX);
	set_opcode(OPC_JMP_IX, JMP_IX);
	set_opcode(OPC_CMP_RR, CMP_RR);
	set_opcode(OPC_CMP_RI, CMP_RI);
	set_opcode(OPC_JE__RX, JE__RX);
	set_opcode(OPC_JE__IX, JE__IX);
	set_opcode(OPC_JG__RX, JG__RX);
	set_opcode(OPC_JG__IX, JG__IX);
	set_opcode(OPC_JL__RX, JL__RX);
	set_opcode(OPC_JL__IX, JL__IX);
	set_opcode(OPC_JGE_RX, JGE_RX);
	set_opcode(OPC_JGE_IX, JGE_IX);
	set_opcode(OPC_JLE_RX, JLE_RX);
	set_opcode(OPC_JLE_IX, JLE_IX);
	set_opcode(OPC_JNE_RX, JNE_RX);
	set_opcode(OPC_JNE_IX, JNE_IX);
	set_opcode(OPC_JZ__RX, JZ__RX);
	set_opcode(OPC_JZ__IX, JZ__IX);
	set_opcode(OPC_CALL_R, CALL_R);
	set_opcode(OPC_CALL_I, CALL_I);
	set_opcode(OPC_RET_XX, RET_XX);
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

