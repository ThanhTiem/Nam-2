#include <iostream>
#include <SDL.h>
#include "Line.h"

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

	float x1 = 400, y1 = 300, x2 = 300, y2 = 100;
	
	//A sleepy rendering loop, wait for 3 seconds and render and present the screen each time
	SDL_RenderClear(ren);
	//Set color for render
	SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);

	DDA_Line(x1, y1, x2, y2, ren);

	SDL_RenderPresent(ren);
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
