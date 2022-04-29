#ifndef ENTITY
#define ENTITY

#include <iostream>
#include <SDL.h>
#include <vector>

#include "Line"
#include "Map.h"

class Entity
{
private:
	int speed;
	std::shared_ptr<std::vector<Line>> shape;
	int position;
	int tunnel_position;

public:
	Entity(int speed, std::shared_ptr<std::vector<Line>> shape, int position, int tunnel_position) :
		speed{ speed }, shape{ shape }, position{ position }, tunnel_position{ tunnel_position }
	{

	}

	const int& getSpeed() const;
	const int& getPosition() const;
	const int& getTunnel_position() const;

	void draw(Map& m) const;

};

#endif 
