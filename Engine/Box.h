#pragma once
#include "Player.h"
#include "Graphics.h"

class Box
{
public: 
	void Update();
	bool CollisionDetect(Player player);
	void Draw(Graphics& gfx) const;
	int x;
	int y;
	int vx;
	int vy;
	int r;
	int g;
	int b;
	static constexpr int size = 40;
	bool isColliding = false;
	bool isEaten = false;
};