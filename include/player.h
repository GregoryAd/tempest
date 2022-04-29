#ifndef PLAYER
#define PLAYER

#include <iostream>
#include <SDL.h>
#include <vector>
#include "Map.h"
#include "Color.h"
#include "Munition.h"
#include "Scene.h"

class Player
{
private:
	int position;
	int score;
	int bomb;
	bool status;
	std::shared_ptr<Color> color;
	std::vector<std::shared_ptr<Munition>> munitions{};

public:
	Player(int position, int bomb, std::shared_ptr<Color> color) : position{ position }, bomb{bomb}, color{color}, score{0}, status{true}
	{

	};
	inline std::vector<std::shared_ptr<Munition>> getMunition() const { return munitions; }
	const int& getPosition() const;

	void move(int position);
	void draw(const Map& m) const;
	void shoot();
	bool update(const Map& m);
	const int& getScore() const;
	void addScore(int add);
	const int& getBomb() const;
	void setBomb(const int& bomb);
	void die();

};

#endif