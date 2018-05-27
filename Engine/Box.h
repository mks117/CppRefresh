#pragma once
#include "Player.h"

class Box
{
public: 
	void Update();
	bool CollisionDetect(Player player);
	int x;
	int y;
	int vx;
	int vy;
	int red;
	int green;
	int blue;
	static constexpr int size = 40;
	bool isColliding = false;
	bool isEaten = false;
};