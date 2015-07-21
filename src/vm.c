#include <venus.h>

void init_vm()
{
	init_memory(DEFAULT_MEM_SIZE);
}

void free_vm()
{
	free_memory();
}
