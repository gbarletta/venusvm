#include <venus.h>

int main(int argc, char **argv)
{
	init_vm();
	
	run_vm();
	
	printf("%d\n", get_ipreg_cell());
	
	free_vm();
	return 0;
} 
