#include"entity.h"
entity* createEntity(float x, float y, unsigned char t){
	entity* e = malloc(sizeof(entity));
	e->x=x;
	e->y=y;
	e->type=t;
	return e;
}
void freeEntity(entity* e){
	free(e);
}
