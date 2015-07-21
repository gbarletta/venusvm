#include <venus.h>

BYTE *memory;
DWORD current_size;

void init_memory(DWORD memsz)
{
	int i;
	memory = (BYTE *)malloc(memsz * sizeof(BYTE));
	
	for(i = 0; i < memsz; i++) {
		*(memory + i) = 0;
	}
	
	current_size = memsz;
}

void free_memory()
{
	free(memory);
}
	
void set_memory_cell(DWORD addr, BYTE value) 
{
	if(addr >= current_size) {
		printf("addr %x does not exists\n", addr);
		exit(1);
	}
	
	*(memory + addr) = value;
}

BYTE get_memory_cell(DWORD addr)
{
	if(addr >= current_size) {
		printf("addr %x does not exists\n", addr);
		exit(1);
	}
	
	return *(memory + addr);
}
