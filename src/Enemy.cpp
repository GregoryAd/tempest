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

// tuer le joueur
void Enemy::killPlayer(Player p, SDL_Renderer* renderer) {
	if ((this->getTunnel_position() == 100) &&
		(this->getPosition() == p.getPosition()))
		p.die(p.getGameOver(), renderer);
}

void Enemy::move(const Map& m, const Player& p) {
	if (!status)
		return;
	if (!border)
		Entity::move();
	else
		trackPlayer(m, p);
	if (getTunnel_position() <= 0)
		border = true;
}

void Enemy::trackPlayer(const Map& m, const Player& p) {
	int d1 = std::abs(m.move(this->getPosition(), -1) - p.getPosition());
	int d2 = std::abs(m.move(this->getPosition(), 1) - p.getPosition());

	if (d1 - 1 == 0 || d2 + 1 == 0)
		return;


	if (d1 <= d2) {
		int pos = m.move(this->getPosition(), -1);
		pos = (pos < 0) ? m.move(this->getPosition(), 1) : pos;
		this->setPosition(pos);
		return;
	}
	else{
		int pos = m.move(this->getPosition(), 1);
		pos = (pos < 0) ? m.move(this->getPosition(), -1) : pos;
		this->setPosition(pos);
		return;
	}
}