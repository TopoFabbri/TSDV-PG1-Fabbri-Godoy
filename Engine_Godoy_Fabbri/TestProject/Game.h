#pragma once

#include "../src/Headers/BaseGame.h"
#include "Character.h"

using namespace ToToEng;

class Game :
	public BaseGame
{
public:
	Game(bool is3D, int width, int height, const char* title);
	~Game() override;

	void update() override;
};