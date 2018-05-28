#pragma once
#include "Graphics.h"
#include "Keyboard.h"

class Player
{
public:
	void ClampToScreen();
	void Draw(Graphics& gfx) const;
	void Update(const Keyboard& kbd);
	int GetX() const;
	int GetY() const;
	int GetSize() const;
	int r;
	int g;
	int b;
private:
	int x = 400;
	int y = 300;
	float vx;
	float vy;
	static constexpr float speed = 0.5f;
	static constexpr int size = 20;
};