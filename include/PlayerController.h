#ifndef PLAYER_CONTROLLER
#define PLAYER_CONTROLLER

#include "Player.h"
#include "EnemyManager.h"

class PlayerController
{
private:

public:
	PlayerController() {};

	bool checkInput(Player& p, const Map& m, EnemyManager& em) const;


};

#endif
