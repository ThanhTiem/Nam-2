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

	if (dx == 0 || dy == 0)
		LineAxis(x1, y1, x2, y2, dx, dy, ren);
	else
	{
		//1: 0 < m < 1 & dx > 0; -1 < m < 0 & dx > 0
		if ((m > 0 && m <= 1 && dx > 0) || (m >= -1 && m < 0 && dx > 0))
		{
			DDA_Line1(dx, dy, m, x, y, x2, ren);
		}
		//2: 0 < m < 1 & dx < 0; -1 < m < 0 & dx < 0
		else if ((m > 0 && m <= 1 && dx < 0) || (m >= -1 && m < 0 && dx < 0))
		{
			DDA_Line2(dx, dy, m, x, y, x2, ren);
		}
		//3: m > 1 & dy > 0; m < -1 & dy > 0
		else if ((m >= 1 && dy > 0) || (m <= -1 && dy > 0))
		{
			DDA_Line3(dx, dy, dm, x, y, y2, ren);
		}
		//4: m > 1 & dy < 0; m < -1 & dy < 0
		else if ((m >= 1 && dy < 0) || (m <= -1 && dy < 0))
		{
			DDA_Line4(dx, dy, dm, x, y, y2, ren);
		}
	}
}



//Bresenham algorithm
//Case 1: 0 < m < 1 & dx > 0
void Bresenham_Line1(int dx, int dy, int x, int y, int x2, SDL_Renderer *ren)
{
	int p = 2 * dy - dx;
	SDL_RenderDrawPoint(ren, x, y);
	while (x < x2)
	{
		if (p <= 0) {
			p += 2 * dy;
		}
		else {
			p += 2 * dy - 2 * dx;
			y = y + 1;
		}
		x = x + 1;
		SDL_RenderDrawPoint(ren, x, y);
	}
}
//Case 2: 0 < m < 1 & dx < 0
void Bresenham_Line2(int dx, int dy, int x, int y, int x2, SDL_Renderer *ren)
{
	int p = -2 * dy + dx;
	SDL_RenderDrawPoint(ren, x, y);
	while (x > x2){
		if (p <= 0) 
			p += -2 * dy;
		
		else {
			p +=  -2 * dy + 2 * dx;
			y--;
		}
		x--;
		SDL_RenderDrawPoint(ren, x, y);
	}
}
//Case 3: m > 1 & dy > 0
void Bresenham_Line3(int dx, int dy, int x, int y, int y2, SDL_Renderer *ren)
{
	int p = 2 * dx - dy;
	SDL_RenderDrawPoint(ren, x, y);
	while (y < y2) {
		if (p <= 0) 
			p += 2 * dx;
		
		else {
			p += 2 * dx - 2 * dy;
			x++;
		}
		y++;
		SDL_RenderDrawPoint(ren, x, y);
	}
}
//Case 4: m > 1 & dy < 0
void Bresenham_Line4(int dx, int dy, int x, int y, int y2, SDL_Renderer *ren)
{
	
	int p = dy - 2 * dx;
	SDL_RenderDrawPoint(ren, x, y);
	while (y >y2)
	{
		if (p <= 0) {
			p = p - 2 * dx;
		}
		else {
			p += 2 * dy - 2 * dx;
			x--;
		}
		y--;
		SDL_RenderDrawPoint(ren, x, y);
	}
}
//Case 5: -1 < m < 0 & dx > 0
void Bresenham_Line5(int dx, int dy, int x, int y, int x2, SDL_Renderer *ren)
{
	int p = -dx - 2*dy;
	SDL_RenderDrawPoint(ren, x, y);
	while (x < x2)
	{
		if (p <= 0) {
			p = p - 2 * dy;
		}
		else {
			p = p - 2 * dx - 2 * dy;
			y--;
		}
		x++;
		SDL_RenderDrawPoint(ren, x, y);
	}
}
//Case 6: -1 < m < 0 & dx < 0
void Bresenham_Line6(int dx, int dy, int x, int y, int x2, SDL_Renderer *ren)
{
	int p = dx + 2 * dy;
	SDL_RenderDrawPoint(ren, x, y);
	while (x > x2) {
		if (p <= 0) 
			p += 2 * dy;
		else {
			p += 2 * dx + 2 * dy;
			x--;
		}
		y++;
		SDL_RenderDrawPoint(ren, x, y);
	}
}
//Case 7: m < -1 & dy > 0
void Bresenham_Line7(int dx, int dy, int x, int y, int y2, SDL_Renderer *ren)
{
	int p = -2 * dx - dy;
	SDL_RenderDrawPoint(ren, x, y);
	while (y < y2) {
		if (p <= 0)
			p = p - 2 * dy;
		else {
			p = p - 2 * dx - 2 * dy;
			x--;
		}
		y++;
		SDL_RenderDrawPoint(ren, x, y);
	}
}
//Case 8: m < -1 & dy < 0
void Bresenham_Line8(int dx, int dy, int x, int y, int y2, SDL_Renderer *ren)
{
	int p = 2 * dx + dy;
	SDL_RenderDrawPoint(ren, x, y);
	while (y > y2) {
		if (p <= 0)
			p = p + 2 * dy;
		else {
			p = p + 2 * dx + 2 * dy;
			x++;
		}
		y--;
		SDL_RenderDrawPoint(ren, x, y);
	}
}

void Bresenham_Line(int x1, int y1, int x2, int y2, SDL_Renderer *ren)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	float m = (float)dy / dx;
	int x = x1;
	int y = y1;

	if (dx == 0 || dy == 0)
		LineAxis(x1, y1, x2, y2, dx, dy, ren);
	else
	{
		if (m > 0 && m <= 1 && dx > 0) {
			Bresenham_Line1(dx, dy, x, y, x2, ren);
		}
		else if (m > 0 && m <= 1 && dx < 0) {
			Bresenham_Line2(dx, dy, x, y, x2, ren);
		}
		else if (m >= 1 && dy > 0) {
			Bresenham_Line3(dx, dy, x, y, y2, ren);
		}
		else if (m >= 1 && dy < 0) {
			Bresenham_Line4(dx, dy, x, y, y2, ren);
		}
		else if (m < 0 && m >= -1 && dx > 0) {
			Bresenham_Line5(dx, dy, x, y, x2, ren);
		}
		else if (m < 0 && m >= -1 && dx < 0) {
			Bresenham_Line6(dx, dy, x, y, x2, ren);
		}
		else if (m <= -1 && dy > 0) {
			Bresenham_Line7(dx, dy, x, y, y2, ren);
		}
		else if (m <= -1 && dy < 0) {
			Bresenham_Line8(dx, dy, x, y, y2, ren);
		}
	}
}


//Midpoint algorithm
//Case 1: 0 < m < 1 & dx > 0
void Midpoint_Line1(int dx, int dy, int x, int y, int x2, SDL_Renderer *ren)
{
	int p = 2 * dy - dx;
	int const1 = 2 * dy - 2 * dx;
	int const2 = 2 * dy;
	SDL_RenderDrawPoint(ren, x, y);
	while (x < x2) {
		if (p <= 0) {
			p += const2;
		}
		else {
			p += const1;
			y++;
		}
		x++;
		SDL_RenderDrawPoint(ren, x, y);
	}
}
//Case 2: 0 < m < 1 & dx < 0
void Midpoint_Line2(int dx, int dy, int x, int y, int x2, SDL_Renderer *ren)
{
	int p = -2 * dy + dx;
	int const1 = -2 * dy + 2 * dx;
	int const2 = -2 * dy;
	SDL_RenderDrawPoint(ren, x, y);
	while (x > x2) {
		if (p <= 0) {
			p += const2;
		}
		else {
			p += const1;
			y--;
		}
		x--;
		SDL_RenderDrawPoint(ren, x, y);
	}
}
//Case 3: m > 1 & dy > 0
void Midpoint_Line3(int dx, int dy, int x, int y, int y2, SDL_Renderer *ren)
{
	int p = 2 * x - dy;
	int const1 = 2 * dx - 2 * dy;
	int const2 = 2 * dx;
	SDL_RenderDrawPoint(ren, x, y);
	while (y < y2) {
		if (p <= 0) {
			p += const2;
		}
		else {
			p += const1;
			x++;
		}
		y++;
		SDL_RenderDrawPoint(ren, x, y);
	}
}
//Case 4: m > 1 & dy < 0
void Midpoint_Line4(int dx, int dy, int x, int y, int y2, SDL_Renderer *ren)
{
	int p = dy - 2 * dx;
	int const1 = 2 * dy - 2 * dx;
	int const2 = 2 * dx;
	SDL_RenderDrawPoint(ren, x, y);
	while (y > y2) {
		if (p <= 0) {
			p += const2;
		}
		else {
			p += const1;
			x--;
		}
		y--;
		SDL_RenderDrawPoint(ren, x, y);
	}
}
//Case 5: -1 < m < 0 & dx > 0
void Midpoint_Line5(int dx, int dy, int x, int y, int x2, SDL_Renderer *ren)
{
	int p = -2 * dy - dx;
	int const1 = -2 * dy - 2 * dx;
	int const2 = -2 * dy;
	SDL_RenderDrawPoint(ren, x, y);
	while (x < x2) {
		if (p <= 0) {
			p += const2;
		}
		else {
			p += const1;
			y--;
		}
		x++;
		SDL_RenderDrawPoint(ren, x, y);
	}
}
//Case 6: -1 < m < 0 & dx < 0
void Midpoint_Line6(int dx, int dy, int x, int y, int x2, SDL_Renderer *ren)
{
	int p = 2 * dy + dx;
	int const1 = 2 * dy + 2 * dx;
	int const2 = 2 * dy;
	SDL_RenderDrawPoint(ren, x, y);
	while (x > x2) {
		if (p <= 0) {
			p += const2;
		}
		else {
			p += const1;
			x--;
		}
		y++;
		SDL_RenderDrawPoint(ren, x, y);
	}
}
//Case 7: m < -1 & dy > 0
void Midpoint_Line7(int dx, int dy, int x, int y, int y2, SDL_Renderer *ren)
{
	int p = -2 * dx - dy;
	int const1 = -2 * dy - 2 * dx;
	int const2 = -2 * dy;
	SDL_RenderDrawPoint(ren, x, y);
	while (y < y2) {
		if (p <= 0) {
			p += const2;
		}
		else {
			p += const1;
			x--;
		}
		y++;
	SDL_RenderDrawPoint(ren, x, y);
	}
}
//Case 8: m < -1 & dy < 0
void Midpoint_Line8(int dx, int dy, int x, int y, int y2, SDL_Renderer *ren)
{
	int p = dy + 2 * dx;
	int const1 = 2 * dy + 2 * dx;
	int const2 = 2 * dy;
	SDL_RenderDrawPoint(ren, x, y);
	while (y > y2) {
		if (p <= 0) {
			p += const2;
		}
		else {
			p += const1;
			x++;
		}
		y--;
		SDL_RenderDrawPoint(ren, x, y);
	}
}
void Midpoint_Line(int x1, int y1, int x2, int y2, SDL_Renderer *ren)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int x = x1;
	int y = y1;
	float m = (float)dy / dx;

	if (dx == 0 || dy == 0)
		LineAxis(x1, y1, x2, y2, dx, dy, ren);
	else
	{
		if (m > 0 && m <= 1 && dx > 0)
			Midpoint_Line1(dx, dy, x, y, x2, ren);
		else if (m > 0 && m <= 1 && dx < 0)
			Midpoint_Line2(dx, dy, x, y, x2, ren);
		else if (m >= 1 && dy > 0)
			Midpoint_Line3(dx, dy, x, y, y2, ren);
		else if (m >= 1 && dy < 0)
			Midpoint_Line4(dx, dy, x, y, y2, ren);
		else if (m < 0 && m >= -1 && dx > 0)
			Midpoint_Line5(dx, dy, x, y, x2, ren);
		else if (m < 0 && m >= -1 && dx < 0)
			Midpoint_Line6(dx, dy, x, y, x2, ren);
		else if (m <= -1 && dy > 0)
			Midpoint_Line7(dx, dy, x, y, y2, ren);
		else if (m <= -1 && dy < 0)
			Midpoint_Line8(dx, dy, x, y, y2, ren);
	}

}

void LineAxis(int x1, int y1, int x2, int y2, int dx, int dy, SDL_Renderer *ren)
{
	//Line has dx = 0 OR dy = 0
	if (x1 == x2)   // duong thang dung
	{
		while (y1 != y2 + 1)
		{
			y1 += 1;
			SDL_RenderDrawPoint(ren, y1, y2);
		}
	}

	else if (y1 == y2)  // duong ngang
	{
		while (x1 != x2 + 1)
		{
			
			x1 += 1;
			SDL_RenderDrawPoint(ren, x1, x2);
		}
	}
}


