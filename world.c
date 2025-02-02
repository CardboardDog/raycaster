#include"world.h"
#define atlTex(atl,tex) atl->images[tex]
void drawLine(unsigned short int x, int y, unsigned char row, unsigned char texture, atlas* atlas, SDL_Renderer* rend){
	float co = (float)y/64.0f;
	int s = (screenH/2)-(y/2);
	for(int p=0;p<64;p++){
		int pos = ((p*64)+row)*3;
		SDL_SetRenderDrawColor(rend,atlTex(atlas,texture)[pos],atlTex(atlas,texture)[pos+1],atlTex(atlas,texture)[pos+2],255);
		SDL_RenderDrawLine(rend,x,(int)(s+((float)p*co)),x,(int)(s+((float)(p+1)*co)));
	}
}
void simulateWorld(levels* lvl, player* ply, atlas* atl, SDL_Renderer* rnd){
	float d=ply->rotation-((fov/2.0f)*radian);
	for(int c=0;c<screenW;c++){
		d+=radian*(fov/(float)screenW);
		float v[2] = {sin(d)*step,cos(d)*step};
		float pos[2] = {ply->x,ply->y};
		int dist=0;
		for(;dist<maxRender;dist++){
			pos[0]+=v[0];
			pos[1]+=v[1];
			int gx = floor(pos[0]);
			int gy = floor(pos[1]);
			unsigned char tex = lvl->maps[lvl->level]->data[gy][gx]; 
			if(tex){
				float dx = fabs(ply->x-pos[0]);
				float dy = fabs(ply->y-pos[1]);
				float wall = sqrtf((dx*dx)+(dy*dy));
				wall*=cos(d-ply->rotation);
				wall=((float)screenH)/wall;
				drawLine(c,(int)wall,(int)(64*(pos[0]+pos[1]))%64,tex-1,atl,rnd);
				break;
			}
		}
	}
}
