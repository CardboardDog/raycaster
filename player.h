#ifndef PLAYER_H
#define PLAYER_H
#include<malloc.h>
#include"config.h"
typedef struct{
	unsigned char health;
	unsigned short int power;
	float x;
	float y;
	float rotation;
	unsigned char active;
	unsigned char damage;
	char tool;
	unsigned char unlocked[5];
} player;
player* createPlayer();
void freePlayer(player*);
#endif
