#include "Entity.h"

const int& Entity::getSpeed() const {
	return speed;
}
const int& Entity::getPosition() const {
	return position;
}
const int& Entity::getTunnel_position() const {
	return tunnel_position;
}

void Entity::draw(Map& m) const {
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
	Point<double> fnorm{ fdir.getY(), fdir.getX() };

	SDL_SetRenderDrawColor(Line::getRenderer(), 255, 0, 0, 255);

	for (const Line& l : *shape) {
		Point<int> p1{ static_cast<int>((fdir.getX() + fnorm.getX()) * (l.getX().getX()/100.0)) + mid , static_cast<int>((fdir.getY() + fnorm.getY()) * (l.getX().getY()/100.0)) };
		p1 = p1 + *lineOut.center();
		Point<int> p2{ static_cast<int>((fdir.getX() + fnorm.getX()) * (l.getY().getX()/100.0)) + mid, static_cast<int>((fdir.getY() + fnorm.getY()) * (l.getY().getY()/100.0)) };
		p2 = p2 + *lineOut.center();

		Line l1{ std::make_unique<Point<int>>(p1), std::make_unique<Point<int>>(p2) };
		l1.draw();
	}

}