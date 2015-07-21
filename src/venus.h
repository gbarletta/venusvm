#ifndef __VENUS_H
#define __VENUS_H

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_MEM_SIZE 4096

typedef unsigned int       DWORD;
typedef unsigned short int  WORD;
typedef unsigned char       BYTE;

void init_vm();
void free_vm();
void init_memory(DWORD memsz);
void free_memory();
void set_memory_cell(DWORD addr, BYTE value);
BYTE get_memory_cell(DWORD addr);

#endif
