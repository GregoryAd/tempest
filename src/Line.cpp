#include "Line.h"

SDL_Renderer* Line::renderer = nullptr;
std::unique_ptr<Point<int>> Line::windowCenter;


Point<int> *Line::center() const {
	Point<int>* ptr = new Point<int>{ (*(this->x.get()) + *(this->y.get())) / 2};
	return ptr;
}
Point<int> *Line::lineToVector() const {
	return new Point<int>{ *(this->x.get()) - *(this->y.get()) };
}

Point<int> *Line::normal() const {

	Line l1{ getX().getY(), getX().getX(), getY().getY(), getY().getX() };
	Point<int> normal = *l1.lineToVector();
	normal.normalize();
	Point<int> test = *center()+normal*10;

	if (dist(*Line::windowCenter, test) > dist(*Line::windowCenter, *center())) {
		return new Point<int>{ normal };
	}

	Line l2{ getY().getY(), getY().getX(), getX().getY(), getX().getX() };
	normal = *l2.lineToVector();
	normal.normalize();

	return new Point<int>{ normal };
}

const Point<int>& Line::getX() const {
	return *this->x.get();
}
const Point<int>& Line::getY() const {
	return *this->y.get();
}


void Line::initRenderer(SDL_Renderer *renderer, std::unique_ptr<Point<int>> windowCenter) {
	Line::renderer = renderer;
	Line::windowCenter = std::move(windowCenter);
}

SDL_Renderer* Line::getRenderer() {
	return renderer;
}

void Line::draw() const {
	SDL_RenderDrawLine(this->renderer, this->getX().getX(), this->getX().getY(),
		this->getY().getX(), this->getY().getY());
}

int dist(const Point<int>& p1, const Point<int>& p2) {
	return (int)sqrt(pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2));
}