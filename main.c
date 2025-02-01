#include<SDL2/SDL.h>
#include"atlas.h"
#include"levels.h"
int main(){
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("hello word",0,0,320,200,SDL_WINDOW_RESIZABLE);
	SDL_Renderer* render = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
	SDL_RenderSetLogicalSize(render,320,200);
	unsigned char running = 1;

	atlas* atl = createAtlas("atlas.txt");
	printf("\n");
	levels* lvl = createLevels("levels.dat");

	while(running){
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT)
				running = 0;
		}
		SDL_RenderClear(render);
		SDL_RenderPresent(render);
	}
	
	freeAtlas(atl);
	freeLevels(lvl);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(render);
}
