#ifndef LEVELS_H
#define LEVELS_H
#include<stdio.h>
#include<malloc.h>
#include"entity.h"
typedef struct{
	int width;
	int height;
	unsigned char** data;
	entity** objects;
	int length;
} map;
typedef struct{
	unsigned char level;
	int length;
	map** maps;
} levels;
map* createMap(int, int);
void freeMap(map*);
levels* createLevels(char*);
void freeLevels(levels*);
#endif
