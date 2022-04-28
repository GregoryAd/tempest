#include "Player.h"


const int& Player::getPosition() const {
	return position;
}
void Player::move(int position) {
	this->position = position;
}

void Player::draw(const Map& m) const {
	Line l = m.getLine(position);

	SDL_SetRenderDrawColor(Line::getRenderer(), color->getR(), color->getG(), color->getB(), color->getAlpha());

	Point<int> p = *l.normal();
	p = p * 40;
	Point<int> p2 = *l.center() + p;

	Line l1{ std::make_unique<Point<int>>(l.getX()), std::make_unique<Point<int>>(p2) };
	Line l2{ std::make_unique<Point<int>>(l.getY()), std::make_unique<Point<int>>(p2) };
	l1.draw();
	l2.draw();
}