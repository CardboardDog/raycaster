#include"image.h"
unsigned char* loadImage(char* p, int w, int h){
	unsigned char* img = malloc(w*h*3*sizeof(char));
	FILE* raw = fopen(p,"r");
	if(raw == NULL){
		printf("failed to load texture: %s\n",p);
		return img;
	}
	for(int c=0;c<(w*h*3);c++){
		unsigned char cr;
		if(EOF==(cr=fgetc(raw)))
			break;
		else 
			img[c]=cr;
	}
	fclose(raw);
	printf("loaded texture: %s\n",p);
	return img;
}
