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
	Munition m { 1, std::make_shared<std::vector<Line>>(shape), position, 0, 0.10 };
	munitions.push_back(std::make_unique<Munition>(m));
}

// avance l'état des munitions en jeu du joueur
void Player::update(const Map &m) {


	this->draw(m);
	for (int i = 0; i < munitions.size(); i++) {
		// faire avancer les munitions
		munitions[i]->move();
		munitions[i]->draw(m);

		// si on arrive au centre de la map
		if (munitions[i]->getTunnel_position() == 100) {
			munitions.erase(munitions.begin()+i);
		}
	}
}

//getters
// obtenir la scene "gameover"
Scene Player::getGameOver() {
	return gameover;
}

// obtenir le score
int Player::getScore() {
	return score;
}

// augmenter le score (si un ennemi meurt)
void Player::addScore(int add) {
	score = score + add;
}

// si le joueur est touché
void Player::die(Scene gameover, SDL_Renderer* renderer) {
	// reset du score
	score = 0;
	// écran de game over
	gameover.transition(renderer);
	gameover.render(renderer);
}

