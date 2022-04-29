#ifndef ENEMY
#define ENEMY

#include "Entity.h"
#include "Player.h"

class Enemy : public Entity {
private:
	bool status; // actif ou non (vivant et sur la map)
	int reward; // score obtenu lorsqu'il est tué
	bool border;
public:
	Enemy(float speed, std::shared_ptr<std::vector<Line>> shape, int position, float tunnel_position, double pourcentage_size, int reward) :
		Entity{ speed, shape, position, tunnel_position, pourcentage_size }, status{ 0 }, reward{ reward }, border{false}
	{}

	const int& die();
	void killPlayer(Player p, SDL_Renderer* renderer);
	int getReward();
	bool getStatus();
	void setStatus(bool s);
	void move(const Map& m, Player& p);
	void trackPlayer(const Map& m, Player& p);
};


#endif 