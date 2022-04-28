#ifndef PLAYER_CONTROLLER
#define PLAYER_CONTROLLER

#include "Player.h"

class PlayerController
{
private:

public:
	PlayerController() {};

	bool checkInput(Player *p, Map& m) const;


};

#endif
