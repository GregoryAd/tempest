#include "Map.h"

void Map::draw() const {

	std::vector<Line> v1 = *shape;
	std::vector<Line> v2 = *shapeInside;

	SDL_SetRenderDrawColor(Line::getRenderer(), color->getR(), color->getG(), color->getB(), color->getAlpha());

	for (int i = 0; i < v1.size(); i++) {
		v1[i].draw();
		v2[i].draw();

		Line l1{ std::make_unique<Point<int>>(v1[i].getX()), std::make_unique<Point<int>>(v2[i].getX()) };
		l1.draw();
		
		//Line l2{ std::make_unique<Point<int>>(v1[i].getY()), std::make_unique<Point<int>>(v2[i].getY()) };
		//l2.draw();
	}
}

const Line& Map::getLine(const int i) const {
	return  (*shape.get())[i];
}

const Line& Map::getInsideLine(const int i) const {
	return  (*shapeInside.get())[i];
}

int Map::move(const int& position, const int& input) const {
	if (position + input < 0) 
		return (loop) ? shape->size() - 1 : -1;

	if (position + input >= shape->size())
		return (loop) ? 0 : -1;

		

	return position + input;
}