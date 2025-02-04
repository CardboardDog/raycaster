#ifndef RENDER_H
#define RENDER_H
#include"levels.h"
#include"player.h"
#include"atlas.h"
#include<SDL2/SDL.h>
#include<math.h>
#include"config.h"
void renderWorld(levels*, player*, atlas*, SDL_Renderer*);
#endif
