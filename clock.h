#ifndef CLOCK_H
#define CLOCK_H
#include<SDL2/SDL.h>
#define FPS 60
#define TICK 17
typedef unsigned int clock;
clock createClock();
void tickClock(clock*);
#endif
