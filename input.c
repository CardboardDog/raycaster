#include "input.h"
#define keyCheck(evnt, chck) if(evnt.key.keysym.sym == chck)
#define autoKeys(evnt, mode) keyCheck(evnt,SDLK_w) keys[0] = mode; \
		       keyCheck(evnt,SDLK_s) keys[1] = mode; \
		       keyCheck(evnt,SDLK_a) keys[2] = mode; \
		       keyCheck(evnt,SDLK_d) keys[3] = mode; \
		       keyCheck(evnt,SDLK_SPACE) keys[4] = 1; \
		       keyCheck(evnt,SDLK_1) keys[5] = mode; \
		       keyCheck(evnt,SDLK_2) keys[6] = mode; \
		       keyCheck(evnt,SDLK_3) keys[7] = mode; \
		       keyCheck(evnt,SDLK_4) keys[8] = mode; \
		       keyCheck(evnt,SDLK_5) keys[9] = mode; \
		       keyCheck(evnt,SDLK_ESCAPE) keys[10] = 1;
unsigned char keys[11] = {0,0,0,0,0,0,0,0,0,0,0};
unsigned char pollInput(player* p, levels* l){
	unsigned char running = 0;
	SDL_Event evnt;
	while(SDL_PollEvent(&evnt)){
		if(evnt.type == SDL_QUIT)
			running = 1;
		if(evnt.type == SDL_KEYDOWN){
			autoKeys(evnt,1)
		}else if(evnt.type == SDL_KEYUP){
			autoKeys(evnt,0)
		}
	}
	float d = 0.1f*(float)(keys[0]-keys[1]);
	float nx = p->x+d*sin(p->rotation);
	float ny = p->y+d*cos(p->rotation);
	if(!l->maps[l->level]->data[(int)p->y][(int)nx])
		p->x=nx;
	if(!l->maps[l->level]->data[(int)ny][(int)p->x])
		p->y=ny;
	p->rotation-=radian*(float)(keys[2]-keys[3]);
	return running;
}
