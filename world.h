#ifndef WORLD_H
#define WORLD_H
#include"levels.h"
#include"player.h"
#include"atlas.h"
#include<SDL2/SDL.h>
#include<math.h>
#include"config.h"
void simulateWorld(levels*, player*, atlas*, SDL_Renderer*);
#endif
