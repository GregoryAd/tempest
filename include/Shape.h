#ifndef SHAPE
#define SHAPE

#include <vector>
#include <iostream>
#include "Line.h"

class Shape : public Drawable {
private:
    std::vector<Line> shape;
public:
    void draw() const override;
};
  

#endif