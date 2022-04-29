#ifndef FONT
#define FONT

#include <SDL.h>
#include <string>


class Font {
public:
    static int simplex[95][112];
    void draw(SDL_Renderer* renderer, const std::string& str, int x, int y, const int& s) const;
};


#endif