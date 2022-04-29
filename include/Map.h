#ifndef MAP
#define MAP

#include <iostream>
#include <SDL.h>
#include <vector>

#include "Line.h"
#include "Color.h"

class Map {
	private:
		bool loop;
		std::unique_ptr<std::vector<Line>> shape;
		std::unique_ptr<std::vector<Line>> shapeInside;
		std::shared_ptr<Color> color;


	public:
		Map(bool loop, std::unique_ptr<std::vector<Line>> shape, std::unique_ptr<std::vector<Line>> shapeInside, std::shared_ptr<Color> color)
			: loop{ loop }, shape{ std::move(shape) }, shapeInside{ std::move(shapeInside) }, color{color}{
			
		};

		Map(const Map& m)
			: loop{ m.loop }, shape{ new std::vector<Line>{ *m.shape } }, shapeInside{ new std::vector<Line>{*m.shapeInside} }, color{ m.color }
		{

		}

		void draw() const;

		const Line& getLine(const int i) const;
		const Line& getInsideLine(const int i) const;
		inline const int& getSize() const { return shape->size(); }

		int move(const int& position, const int& input) const;
};

#endif
