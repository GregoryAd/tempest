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
	Munition(int speed, std::shared_ptr<std::vector<Line>> shape, int position, int tunnel_position):
		Entity{ speed, shape, position, tunnel_position }
	{};
};
#endif
