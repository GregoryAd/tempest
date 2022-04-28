#include "Scene.h"
#include <iostream>
#include <vector>

// constructeur
Scene::Scene(int a, std::vector<Button> b, Font f, std::vector<Text> s) {
	sceneNumber = a;
	buttons = b;
	font = f;
	strings = s;
}

// affichage
void Scene::render(SDL_Renderer* renderer) {

	// affichage des boutons (toujours bleus)
	for (Button& button : buttons) {
		button.render();
	}

	// affichage du texte (couleur variable)
	for (Text& string : strings) {
		SDL_SetRenderDrawColor(renderer,
			(string.getColor()).getR(),
			(string.getColor()).getG(),
			(string.getColor()).getB(),
			(string.getColor()).getAlpha());
		font.draw(string.getRenderer(),
			string.getString(),
			string.getx(),
			string.gety(),
			string.getSize());
	}

}

// passer d'une sc�ne � la suivante
void Scene::transition(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}
