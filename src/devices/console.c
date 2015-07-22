#include <venus.h>

#define DEVICE_NAME "console"

CELL init()
{
	printf("loaded device: %s\n", DEVICE_NAME);
	return 0;
}

CELL quit()
{
	printf("unloaded device: %s\n", DEVICE_NAME);
	return 0;
}

CELL get(CELL addr)
{
	return 0;
}

CELL set(CELL addr, CELL value)
{
	return 0;
}

CELL exec(CELL value)
{
	return 0;
}

char *get_string(CELL *addr, CELL sz)
{
	int i;
	char *str;

	str = (char *)malloc(sz * sizeof(char));
	
	for(i = 0; i < sz; i++) {
		str[i] = (char)addr[i];
	} 
	
	return str;
}
	

CELL send(CELL *addr, CELL sz)
{
	printf("%s\n", get_string(addr, sz));
	return 0;
}
	

