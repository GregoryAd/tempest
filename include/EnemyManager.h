#ifndef ENEMYMANAGER
#define ENEMYMANAGER

#include <Enemy.h>

class EnemyManager {
private :
	std::vector<std::unique_ptr<Enemy>> enemies{};
	int count; // compteur pour spawn d'ennemi
	int rate; // fréquence de spawn
	double probability; // probabilité de spawn
public :
	EnemyManager(int rate, double probability):enemies{}, count{ 0 }, rate{ rate }, probability{ probability }
	 {};
	void init(const Map& m);
	void update(const Map& m, Player& p);
	void killEnemy(std::vector<std::shared_ptr<Munition>> munitions);
};

#endif