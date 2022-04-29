#include "EnemyManager.h"
#include "Map.h"
#include <random>

// Gestion des ennemis
void EnemyManager::update(const Map& m, Player& p) {
	count++;
	init(m);
	for (int i = 0; i < enemies.size(); i++) {
		// faire avancer les ennemis
		if (enemies[i]->getStatus() == true) {
			enemies[i]->move(m, p);
			enemies[i]->draw(m);
		}

		killEnemy(p.getMunition());

		// si l'ennemi est mort, le retirer de la liste
		if (enemies[i]->getStatus() == false) {
			p.addScore(enemies[i]->getReward());
			enemies.erase(enemies.begin() + i);
		}
	}
}

// génération d'ennemis
void EnemyManager::init(const Map& m){
	std::vector<Line> shape2 = {
	Line{ 0, 0, 50, 5 },
	Line{ 50, 5, 100, 0 },
	Line{ 100, 0, 87, 5 },
	Line{ 87, 5, 95, 10 },
	Line{ 95, 10, 50, 5 },
	Line{ 50, 5, 3, 10 },
	Line{ 3, 10, 10, 5 },
	Line{ 10, 5, 0, 0 },
	};

	// proba aléatoire
	std::random_device rd; 
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0.0, 1.0);

	// position sur la map aléatoire
	std::random_device rd2;
	std::mt19937 gen2(rd2());
	std::uniform_int_distribution<> dis2(0, m.getSize()-1);

	// génération d'un ennemi
	if (count == rate) {
		count = 0;
		if ((dis(gen) < probability)) {
			Enemy e{ -2.5, std::make_shared<std::vector<Line>>(shape2), dis2(gen2), 100, 0.90, 100, 15};
			e.setStatus(true);
			enemies.push_back(std::make_unique<Enemy>(e));
		}
	}
	
}

void EnemyManager::killAll() {
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->setStatus(false);
	}
}

void EnemyManager::killEnemy(std::vector<std::shared_ptr<Munition>> munitions) {

	for (int j = 0; j < munitions.size(); j++) {

		float tpos = 0;
		int index = -1;
		for (int i = 0; i < enemies.size(); i++) {
			if (enemies[i]->getPosition() == munitions[j]->getPosition() && enemies[i]->getTunnel_position() <= munitions[j]->getTunnel_position()
				&& tpos < enemies[i]->getTunnel_position()) {
				index = i;
				tpos = enemies[i]->getTunnel_position();
			}
		}
		if (index != -1) {
			munitions[j]->setStatus(false);
			enemies[index]->setStatus(false);
		}
			
	}
}
