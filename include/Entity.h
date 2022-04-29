#ifndef ENTITY
#define ENTITY

#include <iostream>
#include <SDL.h>
#include <vector>

#include "Line.h"
#include "Map.h"

class Entity
{
private:
	int speed;
	std::shared_ptr<std::vector<Line>> shape;
	int position;
	int tunnel_position;
	double size_pourcentage;

public:
	Entity(int speed, std::shared_ptr<std::vector<Line>> shape, int position, int tunnel_position, double size_pourcentage) :
		speed{ speed }, shape{ shape }, position{ position }, tunnel_position{ tunnel_position }, size_pourcentage{size_pourcentage}
	{

	}

	const int& getSpeed() const;
	const int& getPosition() const;
	const int& getTunnel_position() const;

	void draw(Map& m) const;

};

#endif 
