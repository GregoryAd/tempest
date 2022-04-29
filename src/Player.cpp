#include "Player.h"


// obtenir la position actuelle du joueur
const int& Player::getPosition() const {
	return position;
}

// déplacer le joueur
void Player::move(int position) {
	this->position = position;
}

// affichage du joueur
void Player::draw(const Map& m) const {
	Line l = m.getLine(position);

	SDL_SetRenderDrawColor(Line::getRenderer(), color->getR(), color->getG(), color->getB(), color->getAlpha());

	Point<double> p = *l.normal();
	Point<int> pI = *doubleToInt(p * 40);
	Point<int> p2 = *l.center() + pI;

	Line l1{ std::make_unique<Point<int>>(l.getX()), std::make_unique<Point<int>>(p2) };
	Line l2{ std::make_unique<Point<int>>(l.getY()), std::make_unique<Point<int>>(p2) };
	l1.draw();
	l2.draw();
}

// tirer (générer munition)
void Player::shoot() {
	// création de la munition
	std::vector<Line> shape = {
	Line{ 50, 0, 0, 50 },
	Line{ 0, 50, 50, 100 },
	Line{ 50, 100, 100, 50 },
	Line{ 100, 50, 50, 0 },
	};
	Munition m {true, 5, std::make_shared<std::vector<Line>>(shape), position, 0, 0.30 };
	munitions.push_back(std::make_shared<Munition>(m));
}

// avance l'état des munitions en jeu du joueur
bool Player::update(const Map &m) {


	this->draw(m);
	for (int i = 0; i < munitions.size(); i++) {

		// si on arrive au centre de la map ou que la munition est détruite
		if (munitions[i]->getTunnel_position() > 100.0 || munitions[i]->getStatus() == false) {
			munitions.erase(munitions.begin()+i);
			return status;
		}
		// faire avancer les munitions

		munitions[i]->move();
		munitions[i]->draw(m);

	}

	return status;
}

// obtenir le score
const int& Player::getScore() const{
	return score;
}

// augmenter le score (si un ennemi meurt)
void Player::addScore(int add) {
	score = score + add;
}

const int& Player::getBomb() const {
	return bomb;
}

void Player::setBomb(const int& bomb) {
	this->bomb = bomb;
}

// si le joueur est touché
void Player::die() {
	// reset du score
	score = 0;
	status = false;
}

