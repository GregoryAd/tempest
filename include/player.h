#ifndef PLAYER
#define PLAYER

#include <iostream>
#include <SDL.h>
#include <vector>
#include "Map.h"
#include "Color.h"
#include "Munition.h"

class Player
{
private:
	int position;
	int score;
	std::shared_ptr<Color> color;
	std::vector<std::unique_ptr<Munition>> munitions{};

public:
	Player(int position, std::shared_ptr<Color> color) : position{position}, color{color}, score{0}
	{

	};

	const int& getPosition() const;
	void move(int position);
	void draw(const Map& m) const;
	void shoot();
	int getScore();
	void addScore(int add);

};

#endif