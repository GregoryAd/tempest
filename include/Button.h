#ifndef BUTTON
#define BUTTON

#include <SDL.h>

enum ButtonSprite{
    BUTTON_SPRITE_MOUSE_OUT = 0,
    BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
    BUTTON_SPRITE_MOUSE_DOWN = 2,
    BUTTON_SPRITE_MOUSE_UP = 3,
    BUTTON_SPRITE_TOTAL = 4
};

class Button {
private:
    SDL_Rect box;
    SDL_Texture* texture;
    static SDL_Renderer* renderer;
public:
    Button(const int& x, const int& y, const int& w, const int& h, SDL_Renderer* renderer);
    void setPosition(const int& x, const int& y);
    void handleEvent(SDL_Event* e);
    void render() const;
    ButtonSprite CurrentSprite;
    ~Button();
};

#endif