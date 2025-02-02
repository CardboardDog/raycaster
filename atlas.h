#ifndef ATLAS_H
#define ATLAS_H
#include"image.h"
#include<malloc.h>
#include<stdio.h>
#include<string.h>
typedef struct{
	unsigned char** images;
	int length;
} atlas;
atlas* createAtlas(char*);
void freeAtlas(atlas*);
#endif
