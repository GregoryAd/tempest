#include "Entity.h"

bool Entity::getStatus() {
	return status;
}

// setter
void Entity::setStatus(bool s) {
	status = s;
}

const float& Entity::getSpeed() const {
	return speed;
}
const int& Entity::getPosition() const {
	return position;
}

void Entity::setPosition(const int& pos) {
	position = pos;
}
const float& Entity::getTunnel_position() const {
	return tunnel_position;
}

void Entity::move() {
	double distFactor = ((100.0 - tunnel_position) / 100.0);
	double choiceSpeed = std::max(std::abs(speed * distFactor), 0.5);
	if (speed < 0)
		choiceSpeed = -choiceSpeed;
	tunnel_position+= choiceSpeed;
}

void Entity::draw(const Map& m) const {
	Line lineOut = m.getLine(position);
	Line lineIn = m.getInsideLine(position);

	std::unique_ptr<Point<int>> in = lineIn.center();
	std::unique_ptr<Point<int>> out = lineOut.center();

	Line directionLine{ in->getX(), in->getY(), out->getX(), out->getY()};
	Point<int> moveDir = *directionLine.lineToVector();

	Point<double> fmoveDir{ moveDir.getX() * tunnel_position / 100.0, moveDir.getY() * tunnel_position / 100.0 };


	double distFactor = ((100.0 - tunnel_position) / 100.0);
	int size = lineOut.getSize() * size_pourcentage * distFactor;
	int mid = size / 2;

	Point<double> fdir = *lineOut.lineToVector()->normalize();

	Point<int> test = *lineOut.center() + *doubleToInt(fdir * 40);
	if (dist(test, *lineIn.center()) > dist(*lineOut.center(), *lineIn.center()))
		fdir = Point<double>{ -fdir.getX(), -fdir.getY() };

	SDL_SetRenderDrawColor(Line::getRenderer(), 255, 0, 0, 255);

	for (const Line& l : *shape) {

		double xx = (l.getX().getX() / 100.0) * size - mid;
		double xy = (l.getX().getY() / 100.0) * size;
		double yx = (l.getY().getX() / 100.0) * size - mid;
		double yy = (l.getY().getY() / 100.0) * size;

		Point<int> p1{ static_cast<int>( fdir.getX() * xx - fdir.getY() * xy ),
			static_cast<int>( fdir.getY() * xx + fdir.getX() * xy) };
		Point<int> p2{ static_cast<int>( fdir.getX() * yx - fdir.getY() * yy),
			static_cast<int>( fdir.getY() * yx + fdir.getX() * yy) };



	

		p1 = p1 + *lineOut.center() + *doubleToInt(fmoveDir);
		p2 = p2 + *lineOut.center() + *doubleToInt(fmoveDir);

		Line l1{ std::make_unique<Point<int>>(p1), std::make_unique<Point<int>>(p2) };
		l1.draw();
	}

}