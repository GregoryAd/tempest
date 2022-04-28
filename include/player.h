#ifndef PLAYER
#define PLAYER

#include <iostream>
#include <SDL.h>
#include <vector>
#include "Map.h"
#include "Color.h"

class Player
{
private:
	int position;
	std::shared_ptr<Color> color;

public:
	Player(int position, std::shared_ptr<Color> color) : position{position}, color{color}
	{

	};

	const int& getPosition() const;
	void move(int position);
	void draw(const Map& m) const;

};

#endif