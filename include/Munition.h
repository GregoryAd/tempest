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
	Munition(const bool& status,const float& speed, std::shared_ptr<std::vector<Line>> shape, const int& position,
		const float& tunnel_position, const double& size_pourcentage):
		Entity{ status, speed, shape, position, tunnel_position, size_pourcentage }
	{};
};
#endif
