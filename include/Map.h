#ifndef MAP
#define MAP

#include <iostream>
#include <SDL.h>
#include <vector>

#include "Shape.h"

class Map: public Shape{
	public:
		Map():Shape(){

		};
		void draw() const override;
		int& const move(int& const input);
};

#endif
