#pragma once
#include "Graphics.h"

class Player
{
public:
	void ClampToScreen();
	void Draw(Graphics& gfx) const;
	int x = 400;
	int y = 300;
	int vx;
	int vy;
	int red;
	int r;
	int g;
	int b;
	static constexpr int size = 20;
	bool inhibitUp = false;
	bool inhibitDown = false;
	bool inhibitLeft = false;
	bool inhibitRight = false;
};