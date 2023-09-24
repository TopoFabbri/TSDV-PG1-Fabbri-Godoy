#pragma once

#include "../src/Headers/BaseGame.h"

using namespace ToToEng;

class Game :
	public BaseGame
{
public:
	Game(bool is3D);
	~Game() override;

	void update() override;
};