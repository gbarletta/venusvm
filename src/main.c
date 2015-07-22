#include <venus.h>

int main(int argc, char **argv)
{
	init_vm();
	
	install_device("console");

	device_send(1, 0, 5);
	
	free_vm();
	return 0;
} 
