#ifndef MUNITION
#define MUNITION

#include <iostream>
#include <SDL.h>
#include <vector>
#include "Map.h"

class Munition
{
private:
	std::unique_ptr<Point<int>> velocity;
	std::shared_ptr<std::vector<Line>> shape;
	int position;
	int tunnel_position;


public:
	Munition(std::unique_ptr<Point<int>> velocity, std::shared_ptr<std::vector<Line>> shape, int position): 
		velocity{ std::move(velocity) }, shape{ shape }, position{ position }
	{};
	Munition(int position) :
		position{ position }
	{};
	void draw(Map& m) const;
};
#endif
