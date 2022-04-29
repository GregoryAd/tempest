#ifndef MUNITION
#define MUNITION

#include <iostream>
#include <SDL.h>
#include <vector>
#include "Map.h"
#include "Entity.h"

class Munition: public Entity
{
private:

public:
	Munition(bool status, float speed, std::shared_ptr<std::vector<Line>> shape, int position, float tunnel_position, double size_pourcentage):
		Entity{ status, speed, shape, position, tunnel_position, size_pourcentage }
	{};
};
#endif
