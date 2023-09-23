#pragma once

#include "../src/Headers/BaseGame.h"

class Game :
	public ToToEng::BaseGame
{
public:
	Game();
	~Game() override;

	void update() override;
};