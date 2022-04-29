#include "Game.h"
#include "PlayerController.h"
#include "Munition.h"
#include "Enemy.h"
#include "EnemyManager.h"

void Game::start(SDL_Renderer* renderer,const int& xSize,const int& ySize, Scene& hud, Scene& gameover) const{

	int centerX = xSize / 2;
	int centerY = ySize / 2;

	//initialisation pour l'affichage des lignes
	Line::initRenderer(renderer, std::make_unique<Point<int>>(centerX, centerY));

	//forme exterieur de la carte
	int lineSize = 200;

	int xStart = centerX - (lineSize * 3) / 2;
	int yStart = centerY - (lineSize * 3) / 2;

	int xEnd = centerX + (lineSize * 3) / 2;
	int yEnd = centerY + (lineSize * 3) / 2;

	std::vector<Line> v = {
		Line{ xStart, yStart, xStart + lineSize, yStart },
		Line{ xStart + lineSize, yStart, xStart + lineSize * 2, yStart },
		Line{ xStart + lineSize * 2, yStart, xStart + lineSize * 3, yStart },

		Line{ xEnd, yStart, xEnd, yStart + lineSize },
		Line{ xEnd, yStart + lineSize, xEnd, yStart + lineSize * 2 },
		Line{ xEnd, yStart + +lineSize * 2, xEnd, yStart + lineSize * 3 },

		Line{ xStart + lineSize * 3, yEnd, xStart + lineSize * 2, yEnd },
		Line{ xStart + lineSize * 2, yEnd, xStart + lineSize, yEnd },
		Line{ xStart + lineSize, yEnd, xStart, yEnd },

		Line{ xStart, yStart + lineSize * 3, xStart, yStart + lineSize * 2 },
		Line{ xStart, yStart + lineSize * 2, xStart, yStart + lineSize },
		Line{ xStart, yStart + lineSize, xStart, yStart }

	};

	//forme intérieur de la carte
	lineSize = 25;

	xStart = centerX - (lineSize * 3) / 2;
	yStart = centerY - (lineSize * 3) / 2;

	xEnd = centerX + (lineSize * 3) / 2;
	yEnd = centerY + (lineSize * 3) / 2;

	std::vector<Line> v1 = {
		Line{ xStart, yStart, xStart + lineSize, yStart },
		Line{ xStart + lineSize, yStart, xStart + lineSize * 2, yStart },
		Line{ xStart + lineSize * 2, yStart, xStart + lineSize * 3, yStart },

		Line{ xEnd, yStart, xEnd, yStart + lineSize },
		Line{ xEnd, yStart + lineSize, xEnd, yStart + lineSize * 2 },
		Line{ xEnd, yStart + +lineSize * 2, xEnd, yStart + lineSize * 3 },

		Line{ xStart + lineSize * 3, yEnd, xStart + lineSize * 2, yEnd },
		Line{ xStart + lineSize * 2, yEnd, xStart + lineSize, yEnd },
		Line{ xStart + lineSize, yEnd, xStart, yEnd },

		Line{ xStart, yStart + lineSize * 3, xStart, yStart + lineSize * 2 },
		Line{ xStart, yStart + lineSize * 2, xStart, yStart + lineSize },
		Line{ xStart, yStart + lineSize, xStart, yStart }

	};

	Map m{ true, std::make_unique<std::vector<Line>>(v),  std::make_unique<std::vector<Line>>(v1), std::make_shared<Color>(0, 36, 128, 255) };
	Player p{ 7, 3,  std::make_shared<Color>(255, 255, 0, 255) };
	PlayerController pc{};


	EnemyManager em(30, 0.6f);

	bool quit = false;
	bool status = true;

	//boucle du jeu tant que le joueur n'est pas mort ou qu'il ne quitte pas
	while (!quit && status)
	{
		quit = pc.checkInput(p, m, em);

		gameover.transition(renderer);

		m.draw();
		em.update(m, p);

		hud.update(renderer, std::to_string(p.getScore()), 0);
		hud.update(renderer, std::to_string(p.getBomb()), 2);
		hud.render(renderer);
		status = p.update(m);

		SDL_RenderPresent(renderer);
		SDL_Delay(1000 / 30);
	}
	if (quit)
		SDL_Quit();;
	gameover.transition(renderer);
	gameover.render(renderer);
}