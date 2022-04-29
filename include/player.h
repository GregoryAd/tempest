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
	std::shared_ptr<Color> color;
	std::vector<std::unique_ptr<Munition>> munitions{};

public:
	Player(int position, std::shared_ptr<Color> color) : position{position}, color{color}
	{

	};

	const int& getPosition() const;
	void move(int position);
	void draw(const Map& m) const;
	void shoot();

};

#endif