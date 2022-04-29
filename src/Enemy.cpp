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

// méthode héritée de Entity
// affichage de l'ennemi
void Enemy::draw(Map& m) const {
	Line lineOut = m.getLine(position);
	Line lineIn = m.getInsideLine(position);

	Point<int> out = *lineOut.center();
	Point<int> in = *lineIn.center();


	Line directionLine{ std::make_unique<Point<int>>(in), std::make_unique<Point<int>>(out) };

	int size = lineOut.getSize() / 10;
	int mid = size / 2;

	Point<int> direction = *directionLine.lineToVector();
	Point<double> fdir = *direction.normalize() * size;
	fdir = Point<double>{ fdir.getX(), fdir.getY() };



	//Point<int> normalDirection{direction.getY(), direction.getX()};
	Point<double> fnorm{ fdir.getY(), fdir.getX() };



	//fnorm = fnorm * size;
	//fdir = fdir * size;


	Point<int> p1{ static_cast<int>((fdir.getX() + fnorm.getX()) * 0) + mid , static_cast<int>((fdir.getY() + fnorm.getY()) * 0) };
	p1 = p1 + *lineOut.center();
	Point<int> p2{ static_cast<int>((fdir.getX() + fnorm.getX()) * 50) + mid, static_cast<int>((fdir.getY() + fnorm.getY()) * 10) };
	p2 = p2 + *lineOut.center();
	Point<int> p3{ static_cast<int>((fdir.getX() + fnorm.getX()) * 100) + mid, static_cast<int>((fdir.getY() + fnorm.getY()) * 0) };
	p3 = p3 + *lineOut.center();
	Point<int> p4{ static_cast<int>((fdir.getX() + fnorm.getX()) * 80) + mid, static_cast<int>((fdir.getY() + fnorm.getY()) * 20) };
	p4 = p4 + *lineOut.center();
	Point<int> p5{ static_cast<int>((fdir.getX() + fnorm.getX()) * 100) + mid, static_cast<int>((fdir.getY() + fnorm.getY()) * 20) };
	p5 = p5 + *lineOut.center();
	Point<int> p6{ static_cast<int>((fdir.getX() + fnorm.getX()) * 50) + mid, static_cast<int>((fdir.getY() + fnorm.getY()) * 10) };
	p6 = p6 + *lineOut.center();
	Point<int> p7{ static_cast<int>((fdir.getX() + fnorm.getX()) * 0) + mid, static_cast<int>((fdir.getY() + fnorm.getY()) * 20) };
	p7 = p7 + *lineOut.center();
	Point<int> p8{ static_cast<int>((fdir.getX() + fnorm.getX()) * 20) + mid, static_cast<int>((fdir.getY() + fnorm.getY()) * 10) };
	p8 = p8 + *lineOut.center();



	Line l1{ std::make_unique<Point<int>>(p1), std::make_unique<Point<int>>(p2) };
	Line l2{ std::make_unique<Point<int>>(p2), std::make_unique<Point<int>>(p3) };
	Line l3{ std::make_unique<Point<int>>(p3), std::make_unique<Point<int>>(p4) };
	Line l4{ std::make_unique<Point<int>>(p4), std::make_unique<Point<int>>(p5) };
	Line l5{ std::make_unique<Point<int>>(p5), std::make_unique<Point<int>>(p6) };
	Line l6{ std::make_unique<Point<int>>(p6), std::make_unique<Point<int>>(p7) };
	Line l7{ std::make_unique<Point<int>>(p7), std::make_unique<Point<int>>(p8) };
	Line l8{ std::make_unique<Point<int>>(p8), std::make_unique<Point<int>>(p1) };

	SDL_SetRenderDrawColor(Line::getRenderer(), 255, 0, 0, 255);

	l1.draw();
	l2.draw();
	l3.draw();
	l4.draw();
	l5.draw();
	l6.draw();
	l7.draw();
	l8.draw();
}
