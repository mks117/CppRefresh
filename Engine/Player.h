#pragma once

class Player
{
public:
	void ClampToScreen();
	int x = 400;
	int y = 300;
	int vx;
	int vy;
	int red;
	int green;
	int blue;
	static constexpr int size = 20;
	bool inhibitUp = false;
	bool inhibitDown = false;
	bool inhibitLeft = false;
	bool inhibitRight = false;
};