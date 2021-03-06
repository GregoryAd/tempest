#include <SDL.h>
#include <assert.h>
#include <iostream>

#include "Line.h"
#include "Scene.h"
#include "Game.h"

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
	std::vector<Button> emptyButtons{};

	// Texte
	t1 = Text(renderer, "0", 100, 40, 1, yellow);

	t2 = Text(renderer, "Bombe: ", 600, 40, 1, yellow);
	t3 = Text(renderer, "0", 720, 40, 1, yellow);

	std::vector<Text> text3;
	text3.push_back(t1);
	text3.push_back(t2);
	text3.push_back(t3);

	// Scene
	Scene hud(3, emptyButtons, f, text3);

	// Scene
	Scene gameover(2, buttons, f, text2);

	// nettoyer ?cran
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
					b1.CurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
					start.transition(renderer);
					Game g{};
					g.start(renderer, xSize, ySize, hud, gameover);
				}
				if (b2.CurrentSprite == 2) {
					b1.CurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
					start.transition(renderer);
					SDL_Quit();
				}

			}
		}
		SDL_RenderPresent(renderer);
	}
	SDL_Quit();

	return 0;
}