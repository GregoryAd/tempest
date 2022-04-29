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

	//Line directionLine{ std::make_unique<Point<int>>(in), std::make_unique<Point<int>>(out) };

	int size = lineOut.getSize() * size_pourcentage;
	int mid = size / 2;

	Point<double> fdir = *lineOut.lineToVector()->normalize();
	Point<int> test = *lineOut.center() + *doubleToInt(fdir * 40);
	if (dist(test, *lineIn.center()) > dist(*lineOut.center(), *lineIn.center()))
		fdir = Point<double>{ -fdir.getX(), -fdir.getY() };



	/*if (fdir.getX() < 0)
		fdir = Point<double>{ -fdir.getX(), fdir.getY() };

	if (fdir.getY() < 0)
		fdir = Point<double>{ fdir.getX(), -fdir.getY() };*/
	//Point<double> fdir = *direction.normalize();

	Point<double> fnorm{ fdir.getY(), fdir.getX() };

	SDL_SetRenderDrawColor(Line::getRenderer(), 255, 0, 0, 255);

	std::cout << " direction x: " << fdir.getX() << "y: " << fdir.getY() << std::endl;
	std::cout << " normal x: " << -fdir.getY() << "y: " << fdir.getX() << std::endl;
	for (const Line& l : *shape) {
		//Point<int> p1{ static_cast<int>((fdir.getX() + fnorm.getX()) * (l.getX().getX()/100.0)) + mid , static_cast<int>((fdir.getY() + fnorm.getY()) * (l.getX().getY()/100.0)) };
		//p1 = p1 + *lineOut.center();
		//Point<int> p2{ static_cast<int>((fdir.getX() + fnorm.getX()) * (l.getY().getX()/100.0)) + mid, static_cast<int>((fdir.getY() + fnorm.getY()) * (l.getY().getY()/100.0)) };
		//p2 = p2 + *lineOut.center();

		double xx = (l.getX().getX() / 100.0) * size - mid;
		double xy = (l.getX().getY() / 100.0) * size;
		double yx = (l.getY().getX() / 100.0) * size - mid;
		double yy = (l.getY().getY() / 100.0) * size;

		Point<int> p1{ static_cast<int>( fdir.getX() * xx - fdir.getY() * xy ),
			static_cast<int>( fdir.getY() * xx + fdir.getX() * xy) };
		Point<int> p2{ static_cast<int>( fdir.getX() * yx - fdir.getY() * yy),
			static_cast<int>( fdir.getY() * yx + fdir.getX() * yy) };

		p1 = p1 + *lineOut.center();
		p2 = p2 + *lineOut.center();

		Line l1{ std::make_unique<Point<int>>(p1), std::make_unique<Point<int>>(p2) };
		l1.draw();
	}

}