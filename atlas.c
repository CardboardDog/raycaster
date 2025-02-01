#include "atlas.h"
atlas* createAtlas(char* fi){
	atlas* mAtlas = malloc(sizeof(atlas));
	mAtlas->length = 0;
	FILE* lAtlas = fopen(fi,"r");
	char path[260];
	while(fgets(path,260,lAtlas)){
		if(mAtlas->length == 0)
			mAtlas->images = malloc(sizeof(etp_base*));
		else
			mAtlas->images = realloc(mAtlas->images, sizeof(etp_base*)*(mAtlas->length+1));
		mAtlas->length++;
		mAtlas->images[mAtlas->length-1] = etp_create_base();
		if(!etp_loads(mAtlas->images[mAtlas->length-1],path))
			printf("loaded texture: %s",path);	
		else
			printf("failed to load texture: %s",path);
	}
	fclose(lAtlas);
	return mAtlas;
}
void freeAtlas(atlas* atl){
	for(int i=0;i<atl->length;i++)
		etp_free(atl->images[i]);
	free(atl);
}
