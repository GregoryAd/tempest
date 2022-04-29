#ifndef PLAYER
#define PLAYER

#include <iostream>
#include <SDL.h>
#include <vector>
#include "Map.h"
#include "Color.h"
#include "Munition.h"
#include "Scene.h"

class Player
{
private:
	int position;
	int score;
	std::shared_ptr<Color> color;
	std::vector<std::unique_ptr<Munition>> munitions{};
	Scene gameover;

public:
	Player(int position, std::shared_ptr<Color> color, Scene gameover) : position{ position }, color{ color }, gameover{ gameover }, score{ 0 }
	{

	};

	const int& getPosition() const;
	void move(int position);
	void draw(const Map& m) const;
	void shoot();
	int getScore();
	Scene getGameOver();
	void addScore(int add);
	void die(Scene gameover, SDL_Renderer* renderer);

};

#endif