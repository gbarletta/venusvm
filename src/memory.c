#include <venus.h>

CELL *memory;
DWORD current_size;

void init_memory(DWORD memsz)
{
	int i;
	memory = (CELL *)malloc(memsz * sizeof(CELL));
	
	for(i = 0; i < memsz; i++) {
		*(memory + i) = 0;
	}
	
	current_size = memsz;
}

void free_memory()
{
	free(memory);
}
	
void set_memory_cell(DWORD addr, CELL value) 
{
	if(addr >= current_size) {
		printf("addr %x does not exists\n", addr);
		exit(1);
	}
	
	*(memory + addr) = value;
}

CELL get_memory_cell(DWORD addr)
{
	if(addr >= current_size) {
		printf("addr %x does not exists\n", addr);
		exit(1);
	}
	
	return *(memory + addr);
}
