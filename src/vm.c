#include <venus.h>

void init_vm()
{
	init_memory(DEFAULT_MEM_SIZE);
	init_registers();
}

void free_vm()
{
	free_memory();
}
