#include <venus.h>

#define CODE_BUF 	20000

CELL *code;
int current_addr;
int start_addr;

void process_file(char *filename);
void process_line(char *line);
void alloc_code_buf(int codesz);
void free_code_buf();

int main(int argc, char **argv)
{
	if(argc <= 2) {
		printf("usage: %s [input_file] [output_file]\n", argv[0]);
		exit(0);
	}
	
	alloc_code_buf(CODE_BUF);
	process_file(argv[1]);
	return 0;
}

void alloc_code_buf(int codesz)
{
	code = (CELL *)malloc(codesz * sizeof(CELL));
	current_addr = 0;
}

void free_code_buf()
{
	free(code);
}

void process_file(char *filename)
{
	char *line;
	FILE *fp;
	
	line = (char *)malloc(64 * sizeof(char));
	
	if(line == NULL) {
		printf("cannot allocate memory\n");
		exit(1);
	}
	
	fp = fopen(filename, "r");
	
	if(fp == NULL) {
		printf("cannot open file \"%s\"\n", filename);
		exit(1);
	}
	
	while(!feof(fp)) {
		if(fgets(line, 64, fp) != NULL) {
			process_line(line);
		}
		
		strcpy(line, " ");
	}
	
	fclose(fp);
}

void process_line(char *line)
{
	char p1[32];
	char p2[32];
	char p3[32];
	
	sscanf(line, "%s %s %s", p1, p2, p3);
	printf("P1 = %s\nP2 = %s\nP3 = %s\n", p1, p2, p3);
}

	
