#include<SDL2/SDL.h>
#include"atlas.h"
#include"levels.h"
#include"player.h"
#include"clock.h"
#include"input.h"
int main(){
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("raycaster",0,0,320,200,SDL_WINDOW_RESIZABLE);
	SDL_Renderer* render = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
	SDL_RenderSetLogicalSize(render,320,200);
	unsigned char running = 1;

	atlas* atl = createAtlas("atlas.txt");
	printf("\n");
	levels* lvl = createLevels("levels.dat");
	player* ply = createPlayer();
	clock clk = createClock();

	while(running){
		SDL_Event event;
		if(pollInput(ply))
			running = 0;
		SDL_SetRenderDrawColor(render,0,0,0,0);
		SDL_RenderClear(render);
		SDL_SetRenderDrawColor(render,255,0,0,0);
		SDL_RenderDrawPoint(render,(int)ply->x,(int)ply->y);
		SDL_RenderPresent(render);
		tickClock(&clk);
	}
	
	freePlayer(ply);
	freeAtlas(atl);
	freeLevels(lvl);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(render);
}
