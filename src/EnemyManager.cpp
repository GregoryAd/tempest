#include "EnemyManager.h"

// Gestion des ennemis
void Enemy::update(const Map& m) {

	this->draw(m);
	for (int i = 0; i < enemies.size(); i++) {
		// faire avancer les ennemis
		enemies[i]->move();
		enemies[i]->draw(m);

		// si l'ennemi est mort, le retirer de la liste
		if (enemies[i].getStatus == 0) {
			enemies[i].erase(enemies.begin() + i);
		}
	}
}
