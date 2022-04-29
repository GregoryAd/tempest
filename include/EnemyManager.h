#ifndef ENEMYMANAGER
#define ENEMYMANAGER

#include <Enemy.h>

class EnemyManager {
private :
	std::vector<std::unique_ptr<Enemy>> enemies{};
public :
	void update(const Map& m);
};

#endif