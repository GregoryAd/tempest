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
	static std::shared_ptr<SDL_Renderer> renderer;
public:

	Line(std::unique_ptr<Point<int>> x, std::unique_ptr<Point<int>> y) : x{ std::move(x) }, y{ std::move(y) } {
	}

	const std::unique_ptr <Point<int>> center() const;
	const std::unique_ptr <Point<int>> lineToVector() const;
	const Point<int>* getX() const;
	const Point<int>* getY() const;

	void initRenderer(SDL_Renderer renderer);
	void draw() const override;
};


#endif