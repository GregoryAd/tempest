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
	bool status;
	std::shared_ptr<Color> color;
	std::vector<std::unique_ptr<Munition>> munitions{};

public:
	Player(int position, std::shared_ptr<Color> color) : position{ position }, color{ color }, score{ 0 }, status{true}
	{

	};

	const int& getPosition() const;
	void move(int position);
	void draw(const Map& m) const;
	void shoot();
	bool update(const Map& m);
	int getScore();
	void addScore(int add);
	void die();

};

#endif