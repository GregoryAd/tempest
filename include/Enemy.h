#ifndef ENEMY
#define ENEMY

#include "Entity.h"

class Enemy : public Entity {
private :
	bool status; // actif ou non (vivant et sur la map)
	int reward; // score obtenu lorsqu'il est tué
public :
	Enemy(int speed, std::shared_ptr<std::vector<Line>> shape, int position, int tunnel_position, int reward) :
		speed{ speed }, shape{ shape }, position{ position }, tunnel_position{ tunnel_position }, status{ 0 }, reward{ reward }
	const int& die();
	int getReward();
	bool getStatus();
	void setStatus(bool s);
};


#endif 