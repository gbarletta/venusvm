#include <venus.h>

symbol *sym_table;
DWORD current_sym;

void init_symbols(DWORD symsz)
{
	sym_table = (symbol *)malloc(symsz * sizeof(symbol));
	
	if(sym_table == NULL) {
		printf("cannot allocate memory for sym table\n");
		exit(1);
	}
	
	current_sym = 0;
}

void add_sym(char *sym_name, CELL sym_addr, BYTE sym_type)
{
	if(current_sym >= DEFAULT_SYM_NUM) {
		printf("reached max symbols\n");
		exit(1);
	}
	
	strcpy(sym_table[current_sym].sym_name, sym_name);
	sym_table[current_sym].sym_addr = sym_addr;
	sym_table[current_sym].sym_type = sym_type;
	
	current_sym++;
}

DWORD get_sym(char *sym_name, CELL *sym_addr, BYTE *sym_type)
{
	int i;
	
	for(i = 0; i < current_sym; i++) {
		if(!strcmp(sym_table[i].sym_name, sym_name)) {
			*sym_addr = sym_table[i].sym_addr;
			*sym_type = sym_table[i].sym_type;
			return SYM_FOUND;
		}
	}
	
	return SYM_NOT_FOUND;
}
	
	
