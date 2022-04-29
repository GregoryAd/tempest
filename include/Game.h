#ifndef GAME
#define GAME

#include "Map.h"
#include "Player.h"
#include "Game.h"
#include "Scene.h"

class Game
{
private:

public:
	Game()
	{

	};
	void start(SDL_Renderer* renderer, int xSize, int ySize, Scene s);

};
#endif
