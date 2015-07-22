#include <venus.h>

CELL gp_registers[NUMBER_OF_GPREGS];
CELL ip_register;
CELL sp_register;
CELL running_status;

void init_registers()
{
	int i;
	
	for(i = 0; i < NUMBER_OF_GPREGS; i++) {
		gp_registers[i] = 0;
	}
}

void set_gpreg_cell(DWORD reg, CELL value) 
{
	if(reg >= NUMBER_OF_GPREGS) {
		printf("register %d does not exists\n", reg);
		exit(1);
	}
	
	gp_registers[reg] = value;
}

void set_ipreg_cell(CELL value) 
{
	ip_register = value;
}

void set_spreg_cell(CELL value)
{
	sp_register = value;
}

CELL get_gpreg_cell(DWORD reg)
{
	if(reg >= NUMBER_OF_GPREGS) {
		printf("register %d does not exists\n", reg);
		exit(1);
	}
	
	return gp_registers[reg];
}

CELL get_ipreg_cell()
{
	return ip_register;
}

CELL get_spreg_cell()
{
	return sp_register;
}

void set_running_status(CELL value)
{
	running_status = value;
}

CELL get_running_status()
{
	return running_status;
}
