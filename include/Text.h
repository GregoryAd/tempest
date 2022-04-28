#ifndef TEXT
#define TEXT

#include <string>
#include <SDL.h>
#include <Color.h>

// classe intermédiaire (entre Font et Scene)
class Text {
public:
	SDL_Renderer* renderer;
	std::string str;
	int x;
	int y;
	int size;
	Color color;

	// contructeur
	inline Text(SDL_Renderer* r, std::string s, int a, int b, int si, Color c) :
		renderer{r},
		str{s},
		x{a},
		y{b},
		size{si},
		color{c}{}

	// getters
	inline SDL_Renderer* getRenderer() {
		return this->renderer;
	}
	inline std::string getString() {
		return this->str;
	}
	inline int getx() {
		return this->x;
	}
	inline int gety() {
		return this->y;
	}
	inline int getSize() {
		return this->size;
	}
	inline Color getColor() {
		return this->color;
	}
};

#endif