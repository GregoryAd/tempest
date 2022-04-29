#include <cmath>

#include "Munition.h"
#include "Line.h"
#include "Map.h"

/*void Munition::draw(Map& m) const {

	Line lineOut = m.getLine(position);
	Line lineIn = m.getInsideLine(position);

	Point<int> out = *lineOut.center();
	Point<int> in = *lineIn.center();


	Line directionLine{std::make_unique<Point<int>>(in), std::make_unique<Point<int>>(out) };

	int size = lineOut.getSize() / 10;
	int mid = size / 2;

	Point<int> direction = *directionLine.lineToVector();
	Point<double> fdir = *direction.normalize() * size;
	fdir = Point<double>{ fdir.getX(), fdir.getY() };



	//Point<int> normalDirection{direction.getY(), direction.getX()};
	Point<double> fnorm{ fdir.getY(), fdir.getX() };



	//fnorm = fnorm * size;
	//fdir = fdir * size;


	Point<int> p1{ static_cast<int>((fdir.getX() + fnorm.getX()) * 0.5) + mid , static_cast<int>((fdir.getY() + fnorm.getY()) * 0)};
	p1 = p1 + *lineOut.center();
	Point<int> p2{ static_cast<int>((fdir.getX() + fnorm.getX()) * 0) + mid, static_cast<int>((fdir.getY() + fnorm.getY()) * 0.5) };
	p2 = p2 + *lineOut.center();
	Point<int> p3{ static_cast<int>((fdir.getX() + fnorm.getX()) * 0.5) + mid, static_cast<int>((fdir.getY() + fnorm.getY()) * 1) };
	p3 = p3 + *lineOut.center();
	Point<int> p4{ static_cast<int>((fdir.getX() + fnorm.getX()) * 1) + mid, static_cast<int>((fdir.getY() + fnorm.getY()) * 0.5) };
	p4 = p4 + *lineOut.center();

	Line l1{std::make_unique<Point<int>>(p1), std::make_unique<Point<int>>(p2)};
	Line l2{ std::make_unique<Point<int>>(p2), std::make_unique<Point<int>>(p3) };
	Line l3{ std::make_unique<Point<int>>(p3), std::make_unique<Point<int>>(p4) };
	Line l4{ std::make_unique<Point<int>>(p4), std::make_unique<Point<int>>(p1) };

	SDL_SetRenderDrawColor(Line::getRenderer(), 255, 0, 0, 255);
	
	l1.draw();
	l2.draw();
	l3.draw();
	l4.draw();
}*/