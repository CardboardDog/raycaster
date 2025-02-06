#include"render.h"
#define atlTex(atl,tex) atl->images[tex]
float depthBuffer[screenW];
void drawLine(unsigned short int x, int y, unsigned char row, unsigned char texture, atlas* atlas, SDL_Renderer* rend){
	float co = (float)y/64.0f;
	int s = (screenH/2)-(y/2);
	if(x<0 || x>=screenW)
		return;
	for(int p=0;p<64;p++){
		int pos = ((p*64)+row)*3;
		pos = (pos>64*64*3)?64*64*3:pos;
		SDL_Color color = {atlTex(atlas,texture)[pos],atlTex(atlas,texture)[pos+1],atlTex(atlas,texture)[pos+2],255};
		if(color.g >= 255)
			continue;
		SDL_SetRenderDrawColor(rend,color.r,color.g,color.b,color.a);
		SDL_RenderDrawLine(rend,x,(int)(s+((float)p*co)),x,(int)(s+((float)(p+1)*co)));
	}
}
int sortEntity(const void* a,const void* b){
	entity* c = *((entity**)a);
	entity* d = *((entity**)b);
	if((!c->draw && !d->draw) || (c->pd==d->pd)) return 0;
	if(!c->draw || c->pd>d->pd) return -1;
	if(!d->draw || c->pd<d->pd) return 1;
	return 0;
}
void renderEntities(levels* lvl, player* ply, atlas* atl, SDL_Renderer* rnd){
	qsort(lvl->maps[lvl->level]->objects,lvl->maps[lvl->level]->length,sizeof(entity*),sortEntity);
	for(int e=0;e<lvl->maps[lvl->level]->length;e++){
		entity* ent = lvl->maps[lvl->level]->objects[e];
		if(!ent->draw)
			continue;
		int p = ent->pxs+((ent->pxe-ent->pxs)/2);
		p += (ent->ps-(ent->pxe-ent->pxs))*(1.0f/(float)screenW)*p;
		p -= (ent->ps-(ent->pxe-ent->pxs))*(1.0f/(float)screenW)*(screenW-p);
		p -= ent->ps/2;
		float mov = 64.0f/(float)ent->ps;
		float pos = 0.0f;
		for(int x=p;x<p+ent->ps;x++){
			pos+=mov;
			if(x>0 && x<screenW && depthBuffer[x]>ent->pd){
				drawLine(x,ent->ps,(int)pos,6,atl,rnd);
			}
		}
	}
}
void renderWorld(levels* lvl, player* ply, atlas* atl, SDL_Renderer* rnd){
	for(int e=0;e<lvl->maps[lvl->level]->length;e++)
		lvl->maps[lvl->level]->objects[e]->draw = 0;
	float d=ply->rotation-((fov/2.0f)*radian);
	for(int c=0;c<screenW;c++){
		d+=radian*(fov/(float)screenW);
		float v[2] = {sin(d)*step,cos(d)*step};
		float pos[2] = {ply->x,ply->y};
		int dist=0;
		for(;dist<maxRender;dist++){
			pos[0]+=v[0];
			pos[1]+=v[1];
			for(int e=0;e<lvl->maps[lvl->level]->length;e++){
				entity* ent=lvl->maps[lvl->level]->objects[e];
				if(pos[0]>=ent->x-0.5 && pos[0]<=ent->x+0.5 && pos[1]>=ent->y-0.5 && pos[1]<=ent->y+0.5){
					if(!ent->draw){
						ent->pxs = c;
						float sx = fabs(ply->x-ent->x);
						float sy = fabs(ply->y-ent->y);
						ent->pd = sqrtf((sx*sx)+(sy*sy));
						ent->draw = 1;
						ent->ps = screenW/ent->pd;
						ent->ps = (ent->ps>screenH*3)?screenH*3:ent->ps;
					}
					ent->pxe = c;
				}
			}
			int gx = floor(pos[0]);
			int gy = floor(pos[1]);
			unsigned char tex = lvl->maps[lvl->level]->data[gy][gx]; 
			if(tex){
				float dx = fabs(ply->x-pos[0]);
				float dy = fabs(ply->y-pos[1]);
				float wall = sqrtf((dx*dx)+(dy*dy));
				float depth = wall;
				wall*=cos(d-ply->rotation);
				wall=((float)screenH)/wall;
				depthBuffer[c]=depth;
				drawLine(c,(int)wall,(int)(64*(pos[0]+pos[1]))%64,tex-1,atl,rnd);
				break;
			}
		}
	}
	renderEntities(lvl,ply,atl,rnd);
}
