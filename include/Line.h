#ifndef LINE
#define LINE

#include <iostream>
#include <memory>
#include "Point.h"
#include "Drawable.h"
#include "SDL.h"


class Line : public Drawable {
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

	Line(int x1, int y1, int x2, int y2) : x{ new Point<int>(x1, y1)}, y{ new Point<int>(x2, y2)} {
	}

	Point<int> *center() const;
	Point<int> *lineToVector() const;
	Point<int> *normal() const;
	const Point<int>& getX() const;
	const Point<int>& getY() const;

	static void initRenderer(SDL_Renderer *renderer, std::unique_ptr<Point<int>> windowCenter);
	static SDL_Renderer *getRenderer();
	void draw() const override;
};

int dist(const Point<int>& p1, const Point<int>& p2);


#endif