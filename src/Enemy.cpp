#include "Enemy.h"

// supprime l'ennemi et retourne la r�compense (score) obtenu
const int& Enemy::die() {
	status = 0;
	return reward;
}

// getters
int Enemy::getReward() {
	return reward;
}

bool Enemy::getStatus() {
	return status;
}

// setter
void Enemy::setStatus(bool s) {
	status = s;
}
