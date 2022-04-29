#ifndef ENEMYMANAGER
#define ENEMYMANAGER

#include <Enemy.h>

class EnemyManager {
private :
	std::vector<std::unique_ptr<Enemy>> enemies{};
	int count; // compteur pour spawn d'ennemi
	int rate; // fr�quence de spawn
	double probability; // probabilit� de spawn
public :
	EnemyManager(int rate, double probability) (enemies{}, count{ 0 }, rate{ rate }, probability{ probability })
	 {};
	void init();
	void update(const Map& m);
};

#endif