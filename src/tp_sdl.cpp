#include <SDL.h>
#include <assert.h>
#include <iostream>

#include "Line.h"
#include "Scene.h"
#include "Game.h"

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

	// --- MENU START ---
	// Boutons
	Button b1 = Button(400, 300, 200, 100, renderer);
	Button b2 = Button(400, 450, 200, 100, renderer);

	std::vector<Button> buttons;
	buttons.push_back(b1);
	buttons.push_back(b2);

	Font f;

	// Texte
	Color red = Color(255, 0, 0, 255);
	Color blue = Color(0, 0, 255, 255);
	Color yellow = Color(255, 255, 0, 255);
	Color black = Color(0, 0, 0, 255);
	Text t1 = Text(renderer, "~TEMPEST~", 220, 140, 3, blue);
	Text t2 = Text(renderer, "~TEMPEST~", 230, 150, 3, red);
	Text t3 = Text(renderer, "Start", 420, 370, 2, black);
	Text t4 = Text(renderer, "Exit", 435, 520, 2, black);

	std::vector<Text> text;
	text.push_back(t1);
	text.push_back(t2);
	text.push_back(t3);
	text.push_back(t4);

	// Scene
	Scene start(1, buttons, f, text);

	// --- MENU GAMEOVER ---
	// Texte
	t1 = Text(renderer, "~GAME OVER~", 220, 140, 3, blue);
	t2 = Text(renderer, "~GAME OVER~", 230, 150, 3, red);
	t3 = Text(renderer, "Retry", 420, 370, 2, black);
	t4 = Text(renderer, "Exit", 435, 520, 2, black);

	std::vector<Text> text2;
	text2.push_back(t1);
	text2.push_back(t2);
	text2.push_back(t3);
	text2.push_back(t4);

	// --- HUD (SCORE) ---
	// Boutons (aucun)
	std::vector<Button> emptyButtons;

	// Texte
	t1 = Text(renderer, "0", 100, 40, 1, yellow);
	int currentScore = 0; // init du score du joueur
	std::vector<Text> text3;
	text3.push_back(t1);

	// Scene
	Scene hud(3, buttons, f, text3);



	// Scene
	Scene gameover(2, buttons, f, text2);

	// nettoyer écran
	start.transition(renderer);

	// menu de base
	start.render(renderer);

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
			default:
				b1.handleEvent(&event);
				b2.handleEvent(&event);
				if (b1.CurrentSprite == 2) {
					start.transition(renderer);
					Game g{};
					g.start(renderer, xSize, ySize, hud);
				}
				if (b2.CurrentSprite == 2) {
					start.transition(renderer);
					gameover.render(renderer);
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