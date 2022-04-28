#include <SDL.h>
#include <assert.h>
#include <iostream>

#include "Line.h"
#include "Button.h"


Uint8 color[4] = {255,255,0,255};
int last_x;
int last_y;

void draw(SDL_Renderer* renderer)
{
	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_SPACE])
	{
		SDL_SetRenderDrawColor(renderer, 0,0,0,255);
		SDL_RenderClear(renderer);
	}
	int x,y;
	if (SDL_GetMouseState(&x,&y) & SDL_BUTTON(SDL_BUTTON_LEFT)) 
	{
		const Uint8* state = SDL_GetKeyboardState(NULL);
		SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], color[3]);
		if (state[SDL_SCANCODE_RSHIFT])
		{
			SDL_RenderDrawLine(renderer, last_x,last_y,x,y);
		}
		else
		{
			SDL_RenderDrawPoint(renderer, x, y);
		}
		last_x = x;
		last_y = y;
	}
}

int main(int argc, char** argv)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cerr << "Pb init SDL" << std::endl;
		return 0;
	}

	int xSize = 1000;
	int ySize = 750;

	SDL_Window* window = SDL_CreateWindow("Test_SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, xSize, ySize,
		SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	assert(renderer != NULL);


	// Boutons
	Button b1 = Button(100, 100, 200, 100, renderer);
	Button b2 = Button(100, 300, 200, 100, renderer);


	bool quit = false;
	while (!quit)
	{
		SDL_Event event;
		while (!quit && SDL_PollEvent(&event))
		{

			// nettoyer écran
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			SDL_RenderClear(renderer);

			// Affichage boutons
			b1.render();
			b2.render();

			switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			default:
				b1.handleEvent(&event);
				b2.handleEvent(&event);
				if (b1.CurrentSprite == 2) {
					std::cout << "Clic sur bouton 1" << std::endl;
				}
				if (b2.CurrentSprite == 2) {
					std::cout << "Clic sur bouton 2" << std::endl;
				}

			}
		}
		SDL_RenderPresent(renderer);
	}
	SDL_Quit();

	return 0;
}

/*int main(int argc, char** argv)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cerr<<"Pb init SDL"<< std::endl;
		return 0;
	}

	SDL_Window* window = SDL_CreateWindow("Test_SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600,
						  SDL_WINDOW_SHOWN|SDL_WINDOW_ALLOW_HIGHDPI);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	assert (renderer != NULL);

	bool quit = false;
	while (!quit)
	{
		SDL_Event event;
		while (!quit && SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			}
		}

		draw(renderer);
		SDL_RenderPresent(renderer);
	}
	SDL_Quit();

	return 0;
}
*/