#ifndef TEXT
#define TEXT

#include <string>
#include <SDL.h>
#include <Color.h>

// classe interm�diaire (entre Font et Scene)
class Text {
public:
	SDL_Renderer* renderer;
	std::string str;
	int x;
	int y;
	int size;
	Color color;

	// contructeur
	inline Text(SDL_Renderer* r, std::string s,const int& a,const int& b,const int& si, Color c) :
		renderer{r},
		str{s},
		x{a},
		y{b},
		size{si},
		color{c}{}

	// getters
	inline SDL_Renderer* getRenderer() const{
		return this->renderer;
	}
	inline std::string getString() const{
		return this->str;
	}
	inline int getx() const{
		return this->x;
	}
	inline int gety() const{
		return this->y;
	}
	inline int getSize() const{
		return this->size;
	}
	inline Color getColor() const{
		return this->color;
	}
};

#endif