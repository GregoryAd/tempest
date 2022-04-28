#ifndef COLOR
#define COLOR
#include <SDL.h>

class Color
{

private:
	Uint8 r;
	Uint8 g;
	Uint8 b;
	Uint8 alpha;


public:
	Color(Uint8 r, Uint8 g, Uint8 b, Uint8 alpha) :r{r}, g{ g }, b{ b }, alpha{ alpha }
	{

	};

	Color(const Color& c) :r{ c.r }, g{ c.g }, b{ c.b }, alpha{ c.alpha }
	{

	};

	const Uint8& getR() const;
	const Uint8& getG() const;
	const Uint8& getB() const;
	const Uint8& getAlpha() const;

};
#endif