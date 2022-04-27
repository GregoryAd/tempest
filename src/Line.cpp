#include "Line.h"

SDL_Renderer* Line::renderer = nullptr;

const std::unique_ptr <Point<int>> Line::center() const {
	auto ptr = std::make_unique<Point<int>>(*(this->x.get()) + *(this->y.get()) / 2);
	return ptr;
}
const std::unique_ptr <Point<int>> Line::lineToVector() const {
	return std::make_unique<Point<int>>(*(this->x.get()) - *(this->y.get()));
}

const Point<int>* Line::getX() const {
	return this->x.get();
}
const Point<int>* Line::getY() const {
	return this->y.get();
}


void Line::initRenderer(SDL_Renderer *renderer) {
	Line::renderer = renderer;
}

void Line::draw() const {
	SDL_RenderDrawLine(this->renderer, this->getX()->getX(), this->getX()->getY(),
		this->getY()->getX(), this->getY()->getY());
}