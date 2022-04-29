#include <SDL.h>

#include "PlayerController.h"
#include "Player.h"

//vérifie si une action à lieu ou non, retourne si on quitte ou non
bool PlayerController::checkInput(Player& p, const Map& m, EnemyManager& em) const{

	SDL_Event event;
	int returned = SDL_PollEvent(&event);
	if (returned) {
		
		switch (event.type)
		{
		case SDL_QUIT:
			return true;
			break;

		case SDL_KEYDOWN:
			const Uint8* state = SDL_GetKeyboardState(NULL);
			//touche gauche
			if (state[SDL_SCANCODE_D])
			{
				int position = m.move(p.getPosition(), -1);
				if (position != -1)
					p.move(position);
			}
			//touche droite
			else if (state[SDL_SCANCODE_A]) {
				int position = m.move(p.getPosition(), 1);
				if (position != -1)
					p.move(position);
			}
			//tirer (espace)
			else if (state[SDL_SCANCODE_SPACE]) {
				p.shoot();
			}
			//bombe f
			else if (state[SDL_SCANCODE_F]) {
				if (p.getBomb() != 0) {
					em.killAll();
					p.setBomb(p.getBomb() - 1);
				}
			}

			return false;
			
		}
	}

	return false;
}