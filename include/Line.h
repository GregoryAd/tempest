#ifndef LINE
#define LINE

#include <iostream>
#include <memory>
#include "Point.h"
#include "SDL.h"

class Line {
private:
	std::unique_ptr<Point<int>> x;
	std::unique_ptr<Point<int>> y;

	static std::unique_ptr<Point<int>> windowCenter;

	static SDL_Renderer *renderer;
public:

	Line(std::unique_ptr<Point<int>> x, std::unique_ptr<Point<int>> y) : x{ std::move(x) }, y{ std::move(y) } {
	}

	Line(const Line& l) : x{ new Point<int>{*l.x} }, y{ new Point<int>{*l.y } }  {
	}

	Line(const int& x1,const int& y1,const int& x2,const int& y2) : x{ new Point<int>(x1, y1)}, y{ new Point<int>(x2, y2)} {
	}

	std::unique_ptr <Point<int>> center() const;
	std::unique_ptr <Point<int>> lineToVector() const;
	std::unique_ptr <Point<double>> normal() const;
	const Point<int>& getX() const;
	const Point<int>& getY() const;
	const int& getSize() const;


	static void initRenderer(SDL_Renderer *renderer, std::unique_ptr<Point<int>> windowCenter);
	static SDL_Renderer *getRenderer();
	void draw() const;

};

int dist(const Point<int>& p1, const Point<int>& p2);
std::unique_ptr<Point<int>> doubleToInt(const Point<double>& p);

#endif