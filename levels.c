#include"levels.h"
void mapEntities(map* m){
	for(int y=0;y<m->height;y++){
		for(int x=0;x<m->width;x++){
			int id = (signed int)m->data[y][x];
			if(id>9){
				m->data[y][x] = (unsigned char)0;
				if(m->length==0)
					m->objects = malloc(sizeof(entity*));
				else
					m->objects = realloc(m->objects,sizeof(entity*)*(m->length+1));
				m->objects[m->length] = createEntity((float)y,(float)x,id);
				m->length++;
			}
		}
	}
}
map* createMap(int w, int h){
	map* mMap = malloc(sizeof(map));
	mMap->width = w;
	mMap->height = h;
	mMap->data = malloc(h*sizeof(unsigned char*));
	mMap->length = 0;
	for(int line=0;line<mMap->height;line++)
		mMap->data[line] = malloc(w*sizeof(unsigned char));
	return mMap;
}
void freeMap(map* mMap){
	for(int line=0;line<mMap->height;line++)
		free(mMap->data[line]);
	for(int obj=0;obj<mMap->length;obj++)
		freeEntity(mMap->objects[obj]);
	free(mMap->objects);
	free(mMap->data);
}
levels* createLevels(char* src){
	FILE* lLevels = fopen(src,"r");
	levels* mLevels = malloc(sizeof(levels));
	mLevels->length = 0;
	mLevels->level = 0;
	unsigned char block;
	while(1){
		block = fgetc(lLevels);
		if(block == (unsigned char)0xFF)
			break;
		int width = (signed int)block;
		int height = (int)fgetc(lLevels);
		if(mLevels->length == 0)
			mLevels->maps = malloc(sizeof(map*));
		else
			mLevels->maps = realloc(mLevels->maps,sizeof(map*)*(mLevels->length+1));
		mLevels->maps[mLevels->length] = createMap(width,height);
		for(int y=0;y<height;y++)
			for(int x=0;x<width;x++)
				mLevels->maps[mLevels->length]->data[y][x] = fgetc(lLevels);
		mapEntities(mLevels->maps[mLevels->length]);
		printf("loaded level: %i %ix%i\n",mLevels->length,width,height);
		mLevels->length++;
	}
	fclose(lLevels);
	return mLevels;
}
void freeLevels(levels* lvl){
	for(int m=0;m<lvl->length;m++)
		freeMap(lvl->maps[m]);
	free(lvl->maps);
	free(lvl);
}
