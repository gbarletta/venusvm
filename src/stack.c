#include <venus.h>

void init_stack()
{
	set_spreg_cell(STACK_TOP);
}

void stack_push(CELL value)
{
	CELL current_stack;
	current_stack = get_spreg_cell();
	
	set_memory_cell(current_stack, value);
	set_spreg_cell(current_stack - 1);
}

CELL stack_pop() 
{
	CELL current_stack;
	CELL popped_value;
	
	current_stack = get_spreg_cell();
	popped_value  = get_memory_cell(current_stack + 1);
	
	set_spreg_cell(current_stack + 1);
	return popped_value;
}
