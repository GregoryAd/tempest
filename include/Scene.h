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
	Scene(const int& a, const std::vector<Button>& b, const Font& f, const std::vector<Text>& s);
	std::vector<Text> getStrings() const;
	void render(SDL_Renderer* renderer);
	void transition(SDL_Renderer* renderer) const;
	void update(SDL_Renderer* renderer, const std::string& str, const int& pos);
};


#endif