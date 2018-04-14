#include <iostream>
#include <SDL.h>
#include "Line.h"
#include "Clipping.h"
#include "DrawPolygon.h"

using namespace std;

int main(int, char**) {
	//First we need to start up SDL, and make sure it went ok
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	//Now create a window with title "Hello World" at 10, 10 on the screen with w:800 h:600 and show it
	SDL_Window *win = SDL_CreateWindow("Hello World!", 10, 10, 800, 600, SDL_WINDOW_SHOWN);
	//Make sure creating our window went ok
	if (win == nullptr) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	//Create a renderer that will draw to the window, -1 specifies that we want to load whichever
	//video driver supports the flags we're passing
	//Flags: SDL_RENDERER_ACCELERATED: We want to use hardware accelerated rendering
	//SDL_RENDERER_PRESENTVSYNC: We want the renderer's present function (update screen) to be
	//synchronized with the monitor's refresh rate
	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr) {
		SDL_DestroyWindow(win);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
	SDL_RenderClear(ren);


	//YOU CAN INSERT CODE FOR TESTING HERE

	int xc = 200;
	int yc = 200;
	int R = 100;

	int left = 300;
	int right = 400;
	int top = 100;
	int bottom = 600;

	RECT r = CreateWindow(left, right, top, bottom);

	Vector2D P1(400, 200);
	Vector2D P2(100, 700);
	Vector2D Q1, Q2;

	    SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
	    Bresenham_Line(P1.x, P1.y, P2.x, P2.y, ren);

	    CohenSutherland(r, P1, P2, Q1, Q2);
		
	LiangBarsky(r, P1, P2, Q1, Q2);

	SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
	Bresenham_Line(Q1.x, Q1.y, Q2.x, Q2.y, ren);


	   DrawEquilateralTriangle(xc, yc, R, ren);

	    DrawSquare(xc, yc, R, ren);

	    DrawPentagon(xc, yc, R, ren);
	   DrawHexagon(xc, yc, R, ren);

	   DrawStar(xc, yc, R, ren);
	    DrawEmptyStar(xc, yc, R, ren);

	    DrawStarEight(xc, yc, R, ren);

	DrawConvergentStar(xc, yc, R, ren);

	SDL_RenderPresent(ren);
	SDL_Delay(5000);

	//Take a quick break after all that hard work
	//Quit if happen QUIT event
	bool running = true;

	while (running)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_QUIT: running = false; break;
			}

		}

	}

	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();

	return 0;
}
