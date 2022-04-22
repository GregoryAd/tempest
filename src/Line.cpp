#include "Line.h"

const std::unique_ptr <Point<int>> Line::center() const {
	auto ptr = std::unique_ptr<Point<int>>{ (this->x + this->y) / 2 };
	return ptr;
}
const std::unique_ptr <Point<int>> Line::lineToVector() const {
	auto ptr = std::unique_ptr<Point<int>>{ this->x - this->y};
	return ptr;
}

const Point<int>* Line::getX() const {
	return this->x.get();
}
const Point<int>* Line::getY() const {
	this->y.get();
}


void Line::initRenderer(SDL_Renderer renderer) {
	this->renderer = renderer;
}

void Line::draw() const override{
	SDL_RenderDrawLine(this->renderer, this->getX()->getX, this->getX()->getY, 
		this->getY()->getX, this->getY()->getY);
}
