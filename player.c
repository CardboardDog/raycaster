#include"player.h"
player* createPlayer(){
	player* plyr = malloc(sizeof(player));
	plyr->health = 100;
	plyr->power = 15;
	plyr->x = 2.0f;
	plyr->y = 2.0f;
	plyr->rotation = 90.0f;
	plyr->active = 0;
	plyr->damage = 0;
	plyr->tool = -1;
	for(int i=0;i<5;i++)
		plyr->unlocked[i] = 0;
	return plyr;
}
void freePlayer(player* plyr){
	free(plyr);
}
