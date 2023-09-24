#pragma once

#include "../src/Headers/BaseGame.h"
#include "conio.h"

class Game :
	public ToToEng::BaseGame
{
public:
	Game(bool is3D);
	~Game() override;

	void update() override;
};