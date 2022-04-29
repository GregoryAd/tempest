#ifndef SCENE
#define SCENE

#include <iostream>
#include "Point.h"
#include "Button.h"
#include "Font.h"
#include "Text.h"
#include <vector>

class Scene {
private:
	int sceneNumber;
	std::vector<Button> buttons;
	Font font;
	std::vector<Text> strings;
public:
	Scene(int a, std::vector<Button> b, Font f, std::vector<Text> s);
	std::vector<Text> getStrings();
	void render(SDL_Renderer* renderer);
	void transition(SDL_Renderer* renderer);
	void update(SDL_Renderer* renderer, std::string str, int pos);
};


#endif