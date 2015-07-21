#include <venus.h>

int main(int argc, char **argv)
{
	CELL popped_value;
	CELL popped_value2;
	
	init_vm();
	
	stack_push(0xCAFEBABE);
	stack_push(0xBABECAFE);
	popped_value = stack_pop();
	popped_value2 = stack_pop();
	
	printf("popped value: %x\n", popped_value);
	printf("popped value 2: %x\n", popped_value2);
	
	run_opcode(OPC_HLT_XX, 0, 0);
	
	free_vm();
	return 0;
} 
