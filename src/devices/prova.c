#include <venus.h>
#include "SDL/SDL.h"

SDL_Surface *screen;
pthread_t renderer;
bool running;

char *current_string;

void *render()
{
	while(running) {
	
	}
	
	return NULL;
}

CELL init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
    SDL_WM_SetCaption("VenusVM - Monitor device", 0);

	running = true;
	
    if(pthread_create(&renderer, NULL, render, NULL)) {
		fprintf(stderr, "Error creating thread\n");
		return 1;
	}

	return 0;
}

CELL quit()
{
	running = false;
	pthread_join(renderer, NULL);
	SDL_Quit();
	return 0;
}

CELL get(CELL addr)
{
	printf("GET %d\n", addr);
	return 0;
}

CELL set(CELL addr, CELL value)
{
	printf("SET %d %d\n", addr, value);
	return 0;
}

CELL exec(CELL value)
{
	return 0;
}

void get_string(CELL *addr, CELL sz)
{
	int i;
	char *str;

	str = (char *)malloc(sz * sizeof(char));
	
	for(i = 0; i < sz; i++) {
		str[i] = (char)addr[i];
	} 
	
	current_string = str;
}
	

CELL send(CELL *addr, CELL sz)
{
	get_string(addr, sz);
	
	printf("%s\n", current_string);
	return 0;
}
	
