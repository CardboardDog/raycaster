#include"clock.h"
clock createClock(){
	return SDL_GetTicks();
}
void tickClock(clock* c){
	unsigned int t = TICK-(SDL_GetTicks()-*c);
	SDL_Delay(t);
	*c = SDL_GetTicks();
}
