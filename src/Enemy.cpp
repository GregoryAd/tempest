#include "Enemy.h"

// supprime l'ennemi et retourne la récompense (score) obtenu
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

// tuer le joueur
void Enemy::killPlayer(Player p, SDL_Renderer* renderer, Scene gameover) {
	if ((this->getTunnel_position() == 100) &&
		(this->getPosition() == p.getPosition()))
		p.die(gameover, renderer);
}