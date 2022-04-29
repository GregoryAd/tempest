#include "Enemy.h"
#include "Player.h"

// désactive l'ennemi et retourne la récompense (score) obtenu
const int& Enemy::die() {
	setStatus(0);
	return reward;
}

// getters
const int& Enemy::getReward() const{
	return reward;
}

// déplace l'ennemi
void Enemy::move(const Map& m, Player& p) {
	count++;
	if (!getStatus())
		return;
	//s'il n'est pas au bord avancer
	if (!border) {
		if (count == rate) {
			count = 0;
		}
		Entity::move();
	}
	// sinon se diriger vers la position du joueur
	else {
		trackPlayer(m, p);
	}
	//si on a atteint le bord saugarde de l'état
	if (getTunnel_position() <= 0)
		border = true;
}


// aller vers le joueur par le chemin le plus proche
void Enemy::trackPlayer(const Map& m, Player& p) {

	int moveLeft = m.move(this->getPosition(), -1);
	int moveRight = m.move(this->getPosition(), 1);
	int d1 = std::abs((moveLeft > 0 ? moveLeft : moveRight) - p.getPosition());
	int d2 = std::abs((moveRight > 0 ? moveRight : moveLeft) - p.getPosition());

	//si la position est la même alors le joueur meurt
	if (this->getPosition() == p.getPosition()) {
		p.die();
		return;
	}
	//temporisation
	if (count != rate)
		return;
	count = 0;

	//déplacement du joueur en fonction du chemin le plus court
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