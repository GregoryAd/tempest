#include <SDL.h>

#include "PlayerController.h"
#include "Player.h"


bool PlayerController::checkInput(Player& p, Map& m, EnemyManager& em) const{

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
			if (state[SDL_SCANCODE_D])
			{
				int position = m.move(p.getPosition(), -1);
				if (position != -1)
					p.move(position);
			}
			else if (state[SDL_SCANCODE_A]) {
				int position = m.move(p.getPosition(), 1);
				if (position != -1)
					p.move(position);
			}
			else if (state[SDL_SCANCODE_SPACE]) {
				p.shoot();
			}
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