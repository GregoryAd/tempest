#include "Button.h"
SDL_Renderer* Button::renderer;

// constructeur
Button::Button(int x, int y, int w, int h, SDL_Renderer* renderer){
    box.x = x;
    box.y = y;
    box.w = w;
    box.h = h;
    this->renderer = renderer;

    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, w, h);
}

void Button::setPosition(int x, int y){
    box.x = x;
    box.y = y;
}

void Button::handleEvent(SDL_Event* e){
    
    if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP){
        
        int x, y;
        SDL_GetMouseState(&x, &y);

        // La souris est elle sur le bouton ?
        bool inside = true;

        // Souris à gauche du bouton
        if (x < this->box.x){
            inside = false;
        }
        // A droite du bouton
        else if (x > this->box.x + this->box.w){
            inside = false;
        }
        // Au dessus
        else if (y < this->box.y){
            inside = false;
        }
        // En dessous
        else if (y > this->box.y + this->box.h){
            inside = false;
        }

        // Si on est en dehors du bouton
        if (!inside){
            CurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
        }
        // Si on est dans le bouton
        else{
            switch (e->type){
            case SDL_MOUSEMOTION:
                CurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
                break;

            case SDL_MOUSEBUTTONDOWN:
                CurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
                break;

            case SDL_MOUSEBUTTONUP:
                CurrentSprite = BUTTON_SPRITE_MOUSE_UP;
                break;
            }
        }
    }
}


// affichage du bouton
void Button::render(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(renderer, &box);
}

// destruction du bouton
Button::~Button() {
    SDL_DestroyTexture(this->texture);
}