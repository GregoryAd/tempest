#ifndef ENEMY
#define ENEMY

#include "Entity.h"
#include "Player.h"

class Enemy : public Entity {
private:
	int reward; // score obtenu lorsqu'il est tué
	bool border; // si le bord est atteint

	//gestion des ticks
	int rate;
	int count;
public:
	Enemy(const float& speed, std::shared_ptr<std::vector<Line>> shape, const int& position, const float& tunnel_position,
		const double& pourcentage_size, const int& reward, const int& rate) :
		Entity{false, speed, shape, position, tunnel_position, pourcentage_size}, reward{ reward }, border{false}, rate{rate}, count{0}
	{}

	const int& die();
	const int& getReward() const;
	void move(const Map& m, Player& p);
	void trackPlayer(const Map& m, Player& p);
};


#endif 