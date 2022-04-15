#ifndef DRAWABLE
#define DRAWABLE

#include <SDL.h>
#include <iostream>
#include <vector>

#include "Line.h"

class Drawable{
public:
	virtual void draw() const = 0;
};

#endif