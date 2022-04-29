#ifndef ENEMY
#define ENEMY

#include "Entity.h"
#include "Player.h"

class Enemy : public Entity {
private:
	int reward; // score obtenu lorsqu'il est tué
	bool border;
	int rate;
	int count;
public:
	Enemy(float speed, std::shared_ptr<std::vector<Line>> shape, int position, float tunnel_position, double pourcentage_size, int reward, int rate) :
		Entity{false, speed, shape, position, tunnel_position, pourcentage_size}, reward{ reward }, border{false}, rate{rate}, count{0}
	{}

	const int& die();
	void killPlayer(Player p, SDL_Renderer* renderer);
	int getReward();
	void move(const Map& m, Player& p);
	void trackPlayer(const Map& m, Player& p);
};


#endif 