#include "Enemy.h"
#include "Player.h"

// supprime l'ennemi et retourne la récompense (score) obtenu
const int& Enemy::die() {
	setStatus(0);
	return reward;
}

// getters
int Enemy::getReward() {
	return reward;
}

// tuer le joueur
void Enemy::killPlayer(Player p, SDL_Renderer* renderer) {
	if ((this->getTunnel_position() == 100) &&
		(this->getPosition() == p.getPosition()))
		p.die();
}

void Enemy::move(const Map& m, Player& p) {
	count++;
	if (!getStatus())
		return;
	if (!border) {
		if (count == rate) {
			count = 0;
		}
		Entity::move();
	}
	else {
		trackPlayer(m, p);
	}
	if (getTunnel_position() <= 0)
		border = true;
}

void Enemy::trackPlayer(const Map& m, Player& p) {

	int moveLeft = m.move(this->getPosition(), -1);
	int moveRight = m.move(this->getPosition(), 1);
	int d1 = std::abs((moveLeft > 0 ? moveLeft : moveRight) - p.getPosition());
	int d2 = std::abs((moveRight > 0 ? moveRight : moveLeft) - p.getPosition());

	if (this->getPosition() == p.getPosition()) {
		p.die();
		return;
	}

	if (count != rate)
		return;
	count = 0;
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