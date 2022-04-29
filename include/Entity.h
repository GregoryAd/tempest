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
	bool status; // actif ou non (vivant et sur la map)
	float speed;
	std::shared_ptr<std::vector<Line>> shape;
	int position;
	float tunnel_position;
	double size_pourcentage;

public:
	Entity(const bool& status, const float& speed, std::shared_ptr<std::vector<Line>> shape, const int& position
		, const float& tunnel_position, const double& size_pourcentage) :
		status{ status }, speed{ speed }, shape{ shape }, position{ position }, tunnel_position{ tunnel_position }, size_pourcentage{size_pourcentage}
	{

	}

	virtual void move();

	bool getStatus() const;
	void setStatus(const bool& s);
	const float& getSpeed() const;
	const int& getPosition() const;
	void setPosition(const int& pos);
	const float& getTunnel_position() const;

	void draw(const Map& m) const;

};

#endif 
