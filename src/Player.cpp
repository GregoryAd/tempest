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