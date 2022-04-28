#ifndef SCENE
#define SCENE

#include <iostream>
#include <memory>
#include "Point.h"
#include "Drawable.h"
#include "SDL.h"

class Scene {
private:
	int sceneNumber;
public:
	Scene(int a);
	void render(SDL_Renderer* renderer);
	void transition();
	void update();
};


#endif