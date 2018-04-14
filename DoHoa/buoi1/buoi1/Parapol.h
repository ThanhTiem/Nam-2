#ifndef PARAPOL_H
#define PARAPOL_H
#include <SDL.h>
void BresenhamDrawParapolPositive(int xc, int yc, int A, SDL_Renderer *ren);
void BresenhamDrawParapolNegative(int xc, int yc, int A, SDL_Renderer *ren);
void MidPointDrawParapol(int xc, int yc, int A, SDL_Renderer *ren);
#endif
