#pragma once
#include "Player.h"
#include "Graphics.h"

class Box
{
public: 
	Box(int x_in, int y_in, int vx_in, int vy_in);
	void Update();
	bool CollisionDetect(const Player& player);
	void Draw(Graphics& gfx) const;
	bool IsColliding() const;
	void SetColliding(bool colliding);
	int r;
	int g;
	int b;
private:
	int x;
	int y;
	int vx;
	int vy;
	static constexpr int size = 40;
	bool isColliding = false;
	bool isEaten = false;
};