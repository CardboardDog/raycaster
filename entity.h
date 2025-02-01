#ifndef ENTITY_H
#define ETITTY_H
#include<malloc.h>
typedef struct{
	float x;
	float y;
	unsigned char type;
} entity; 
entity* createEntity(float,float,unsigned char);
void freeEntity(entity*);
#endif
