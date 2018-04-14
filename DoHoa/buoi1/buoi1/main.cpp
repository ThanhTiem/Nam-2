#include <iostream>
#include <SDL.h>
#include "Line.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Parapol.h"

#include "Vector2D.h"
#include "Matrix2D.h"


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

	SDL_RenderPresent(ren);
	

	//YOU CAN INSERT CODE FOR TESTING HERE

	int a, b, A, xc, yc;
	xc = 200;
	yc = 200;
	a = 100;
	b = 200;
	A = 50;

	SDL_SetRenderDrawColor(ren, 255, 255, 0, 255);
	BresenhamDrawParapolNegative(xc, yc, A, ren);
	//BresenhamDrawParapolPositive(xc, yc, A, ren);

	SDL_SetRenderDrawColor(ren, 138, 43, 226, 255);
	MidPointDrawEllipse(xc, yc, a, b, ren);



	Vector2D v1(0, 0);
	Vector2D v2(100, 100);
	Vector2D v3(v1), v4(v2);

	//m2: Matrix for transform axis
	Matrix2D m2;
	//m3: Matrix for transform line
	Matrix2D m3;

	SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
	Bresenham_Line(v1.x, v1.y, v2.x, v2.y, ren);
	//DDA_Line(v1.x, v1.y, v2.x, v2.y, ren);
	m2.set(1, 0, 0, 0, 1, 0, 0, 0, 1);

	v3.set(m2.mul(v3).x, m2.mul(v3).y);
	v4.set(m2.mul(v4).x, m2.mul(v4).y);

	SDL_SetRenderDrawColor(ren, 34, 139, 34, 255);
	Midpoint_Line(v3.x, v3.y, v4.x, v4.y, ren);

	SDL_RenderPresent(ren);
	SDL_Delay(4000);

	//Take a quick break after all that hard work
	//Quit if happen QUIT event
	bool running = true;
	double degrees = 0;
	double angle;

	while (running)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_QUIT: running = false; break;
			case SDL_KEYDOWN:
			case SDL_KEYUP:
				//INSERT YOUR CODE HERE
				
				m2.set(0, -1, 0, 1, 0, 0, 600, 300, 1);  cout << "m2: " << m2 << endl;
				m3.set(0, 1, 0, -1, 0, 0, 800, -100, 1); cout << "m3: " << m3 << endl;

				float d = sqrt(2) / 2;
				Matrix2D Quay45(d, d, 0, -d, d, 0, 0, 0, 1);
				v3.set(Quay45.mul(v3).x, Quay45.mul(v3).y); cout << v3 << endl;
				v4.set(Quay45.mul(v4).x, Quay45.mul(v4).y); cout << v4 << endl;
				Vector2D v5(v3), v6(v4);
				v5.set(Quay45.mul(v5).x, Quay45.mul(v5).y); cout << v5 << endl;
				v6.set(Quay45.mul(v6).x, Quay45.mul(v6).y); cout << v6 << endl;

				SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
				SDL_RenderClear(ren);

				SDL_SetRenderDrawColor(ren, 184, 134, 11, 255);
				Bresenham_Line(v3.x, v3.y, v4.x, v4.y, ren);

				SDL_RenderPresent(ren);

				break;
			}

		}

	}

	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();

	return 0;
}
