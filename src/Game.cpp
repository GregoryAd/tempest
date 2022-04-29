#include "Game.h"
#include "PlayerController.h"
#include "Munition.h"
#include "Enemy.h"
#include "EnemyManager.h"

void Game::start(SDL_Renderer* renderer, int xSize, int ySize, Scene hud, Scene gameover) {

	int centerX = xSize / 2;
	int centerY = ySize / 2;

	Line::initRenderer(renderer, std::make_unique<Point<int>>(centerX, centerY));

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
	Player p{ 7, 1,  std::make_shared<Color>(255, 255, 0, 255) };
	PlayerController pc{};


	std::vector<Line> shape = {
		Line{ 50, 0, 0, 50 },
		Line{ 0, 50, 50, 100 },
		Line{ 50, 100, 100, 50 },
		Line{ 100, 50, 50, 0 },
	};

	std::vector<Line> shape2 = {
	Line{ 0, 0, 50, 5 },
	Line{ 50, 5, 100, 0 },
	Line{ 100, 0, 87, 5 },
	Line{ 87, 5, 95, 10 },
	Line{ 95, 10, 50, 5 },
	Line{ 50, 5, 3, 10 },
	Line{ 3, 10, 10, 5 },
	Line{ 10, 5, 0, 0 },
	};

	EnemyManager em(35, 0.5f);
	//Munition mun{ 1, std::make_shared<std::vector<Line>>(shape), 7, 100, 0.10 };
	//Enemy e{-5, std::make_shared<std::vector<Line>>(shape2), 0, 100, 0.90, 100};
	//e.setStatus(true);
	bool quit = false;
	bool status = true;
	while (!quit && status)
	{
		quit = pc.checkInput(p, m, em);



		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		m.draw();

		em.update(m, p);

		hud.update(renderer, std::to_string(p.getScore()), hud.getStrings()[0]);
		status = p.update(m);

		SDL_RenderPresent(renderer);
		SDL_Delay(1000 / 30);
	}
	if (quit)
		SDL_Quit();;
	gameover.transition(renderer);
	gameover.render(renderer);
}