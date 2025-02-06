#ifndef ENTITY_H
#define ENTITY_H
#include<malloc.h>
typedef struct{
	float x;
	float y;
	unsigned char type;
	unsigned char ai;
	unsigned char draw;
	int pxs; // projected x start
	int pxe; // projected x end
	int ps;
	float pd;
} entity; 
entity* createEntity(float,float,unsigned char);
void freeEntity(entity*);
#endif
