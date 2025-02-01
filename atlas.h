#ifndef ATLAS_H
#define ATLAS_H
#include<etp.h>
#include<malloc.h>
#include<stdio.h>
typedef struct{
	etp_base** images;
	int length;
} atlas;
atlas* createAtlas(char*);
void freeAtlas(atlas*);
#endif
