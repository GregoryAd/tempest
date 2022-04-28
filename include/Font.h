#ifndef FONT
#define FONT

#include <SDL.h>
#include <string>


class Font {
public:
    static int simplex[95][112];
    void draw(SDL_Renderer* renderer, std::string str, int x, int y, int s);
};


#endif FONT