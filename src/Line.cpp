#include "Line.h"

SDL_Renderer* Line::renderer = nullptr;
std::unique_ptr<Point<int>> Line::windowCenter;


std::unique_ptr<Point<int>> Line::center() const {
	Point<int> ptr{ (*(this->x.get()) + *(this->y.get())) / 2};
	return std::make_unique<Point<int>>(ptr);
}
std::unique_ptr<Point<int>> Line::lineToVector() const {
	Point<int> ptr{ *(this->x) - *(this->y) };


	return std::make_unique<Point<int>>(ptr);
}

std::unique_ptr <Point<double>> Line::normal() const {

	Line l1{ getX().getY(), getX().getX(), getY().getY(), getY().getX() };
	Point<int> normal = *l1.lineToVector();
	Point<double> fnorm = *normal.normalize();
	Point<int> test = *center() + *doubleToInt(fnorm * 10);

	if (dist(*Line::windowCenter, test) > dist(*Line::windowCenter, *center())) {
		return std::make_unique<Point<double>>(fnorm);
	}

	Line l2{ getY().getY(), getY().getX(), getX().getY(), getX().getX() };
	normal = *l2.lineToVector();
	fnorm = *normal.normalize();

	return std::make_unique<Point<double>>(fnorm);
}

const Point<int>& Line::getX() const {
	return *this->x.get();
}
const Point<int>& Line::getY() const {
	return *this->y.get();
}

const int& Line::getSize() const {
	return dist(*x, *y);
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
	return static_cast<int>(sqrt(pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2)));
}

std::unique_ptr<Point<int>> doubleToInt(Point<double> p) {
	return std::make_unique<Point<int>>(static_cast<int>(p.getX()), static_cast<int>(p.getY()));
}