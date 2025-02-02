#include "atlas.h"
atlas* createAtlas(char* fi){
	atlas* mAtlas = malloc(sizeof(atlas));
	mAtlas->length = 0;
	FILE* lAtlas = fopen(fi,"r");
	char path[260];
	while(fgets(path,260,lAtlas)){
		path[strcspn(path, "\n")] = 0;
		if(mAtlas->length == 0)
			mAtlas->images = malloc(sizeof(unsigned char*));
		else
			mAtlas->images = realloc(mAtlas->images, sizeof(unsigned char*)*(mAtlas->length+1));
		mAtlas->length++;
		mAtlas->images[mAtlas->length-1] = loadImage(path,64,64);
	}
	fclose(lAtlas);
	return mAtlas;
}
void freeAtlas(atlas* atl){
	for(int i=0;i<atl->length;i++)
		free(atl->images[i]);
	free(atl);
}
