#include "Game.h"
#include "PlayerController.h"

void Game::start(SDL_Renderer* renderer, int xSize, int ySize, Scene s) {

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

		Line{ xStart + lineSize * 2, yEnd, xStart + lineSize * 3, yEnd },
		Line{ xStart + lineSize, yEnd, xStart + lineSize * 2, yEnd },
		Line{ xStart, yEnd, xStart + lineSize, yEnd },

		Line{ xStart, yStart + lineSize * 2, xStart, yStart + lineSize * 3 },
		Line{ xStart, yStart + lineSize, xStart, yStart + lineSize * 2 },
		Line{ xStart, yStart, xStart, yStart + lineSize },

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

		Line{ xStart + lineSize * 2, yEnd, xStart + lineSize * 3, yEnd },
		Line{ xStart + lineSize, yEnd, xStart + lineSize * 2, yEnd },
		Line{ xStart, yEnd, xStart + lineSize, yEnd },

		Line{ xStart, yStart + lineSize * 2, xStart, yStart + lineSize * 3 },
		Line{ xStart, yStart + lineSize, xStart, yStart + lineSize * 2 },
		Line{ xStart, yStart, xStart, yStart + lineSize },

	};

	Map m{ true, std::make_unique<std::vector<Line>>(v),  std::make_unique<std::vector<Line>>(v1), std::make_shared<Color>(0, 36, 128, 255) };
	Player p{ 7,  std::make_shared<Color>(255, 255, 0, 255) };
	PlayerController pc{};

	// placeholder for score
	int score = 0;

	bool quit = false;
	while (!quit)
	{
		quit = pc.checkInput(&p, m);

		// test score
		score++;

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		m.draw();
		p.draw(m);

		s.update(renderer, std::to_string(score), s.getStrings()[0]);

		SDL_RenderPresent(renderer);
		SDL_Delay(1000 / 30);
	}
	SDL_Quit();

}