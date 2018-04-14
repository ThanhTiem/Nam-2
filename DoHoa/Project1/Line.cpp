#include "Line.h"
//DDA algorithm
void DDA_Line1(int dx, int dy, float m, float x, float y, int x2, SDL_Renderer *ren)
{
	SDL_RenderDrawPoint(ren, x, int(y + 0.5));
	while (x < x2)
	{
		x = x + 1;
		y = y + m;
		SDL_RenderDrawPoint(ren, x, int(y + 0.5));
	}
}

void DDA_Line2(int dx, int dy, float m, float x, float y, int x2, SDL_Renderer *ren)
{
	SDL_RenderDrawPoint(ren, x, int(y + 0.5));
	while (x > x2)
	{
		x--;
		y -= m;
		SDL_RenderDrawPoint(ren, x, int(y + 0.5));
	}
}
void DDA_Line3(int dx, int dy, float dm, float x, float y, int y2, SDL_Renderer *ren)
{
	
	SDL_RenderDrawPoint(ren, x, int(y + 0.5));
	while (y < y2)
	{
		x+= dm;
		y++;
		SDL_RenderDrawPoint(ren, x, int(y + 0.5));
	}
}

void DDA_Line4(int dx, int dy, float dm, float x, float y, int y2, SDL_Renderer *ren)
{
	SDL_RenderDrawPoint(ren, x, int(y + 0.5));
	while (y > y2)
	{
		x -= dm;
		y--;
		SDL_RenderDrawPoint(ren, x, int(y + 0.5));
	}
}
void DDA_Line(int x1, int y1, int x2, int y2, SDL_Renderer *ren)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	float m = (float)dy / dx;
	float dm = (float)dx / dy;
	float x = x1;
	float y = y1;

	//1: 0 < m < 1 & dx > 0; -1 < m < 0 & dx > 0
	if ((m > 0 && m < 1 && dx > 0) || (m > -1 && m < 0 && dx > 0))
	{
		DDA_Line1(dx, dy, m, x, y, x2, ren);
	}
	//2: 0 < m < 1 & dx < 0; -1 < m < 0 & dx < 0
	else if ((m > 0 && m < 1 && dx < 0) || (m > -1 && m < 0 && dx < 0))
	{
		DDA_Line2(dx, dy, m, x, y, x2, ren);
	}
	//3: m > 1 & dy > 0; m < -1 & dy > 0
	else if ((m > 1 && dy > 0) || (m < -1 && dy > 0))
	{
		DDA_Line3(dx, dy, dm, x, y, y2, ren);
	}
	//4: m > 1 & dy < 0; m < -1 & dy < 0
	else if ((m > 1 && dy < 0) || (m < -1 && dy < 0))
	{
		DDA_Line4(dx, dy, dm, x, y, y2, ren);
	}
}

