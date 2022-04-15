#ifndef LINE
#define LINE

#include <iostream>
#include "../include/Point.h"
#include "../include/Drawable.h"

class Line: public Drawable{
private:
	Point<int> x;
	Point<int> y;

public:
	const Point<int>& center() const;
	const Point<int>& lineToVector() const;

	void draw() const override;
};


#endif