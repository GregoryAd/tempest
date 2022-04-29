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
	float speed;
	std::shared_ptr<std::vector<Line>> shape;
	int position;
	float tunnel_position;
	double size_pourcentage;

public:
	Entity(float speed, std::shared_ptr<std::vector<Line>> shape, int position, float tunnel_position, double size_pourcentage) :
		speed{ speed }, shape{ shape }, position{ position }, tunnel_position{ tunnel_position }, size_pourcentage{size_pourcentage}
	{

	}

	virtual void move();
	const float& getSpeed() const;
	const int& getPosition() const;
	const float& getTunnel_position() const;

	void draw(const Map& m) const;

};

#endif 
