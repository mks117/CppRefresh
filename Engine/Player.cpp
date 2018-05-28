#include "Player.h"


void Player::ClampToScreen()
{
	const int right = x + size;

	if (x < 0)
	{
		vx = 0;
		x = 0;
	}
	else if (right >= Graphics::ScreenWidth)
	{
		vx = 0;
		x = Graphics::ScreenWidth - size;
	}

	const int bottom = y + size;

	if (y < 0)
	{
		vy = 0;
		y = 0;
	}
	else if (bottom >= Graphics::ScreenHeight)
	{
		vy = 0;
		y = Graphics::ScreenHeight - size;
	}
}

void Player::Draw(Graphics& gfx) const
{
	gfx.PutPixel(x, y, r, g, b);
	for (int i = 0; i < size; i++)
	{
		for (int o = 0; o < size; o++)
		{
			gfx.PutPixel(x + i, y + o, r, g, b);
		}
	}
}

void Player::Update(const Keyboard & kbd)
{
#pragma region Input
	// Press Escape to quit app


	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		vx += speed;
	}

	if (kbd.KeyIsPressed(VK_LEFT))
	{
		vx -= speed;
	}

	if (kbd.KeyIsPressed(VK_UP))
	{
		vy -= speed;
	}

	if (kbd.KeyIsPressed(VK_DOWN))
	{
		vy += speed;
	}
#pragma endregion

	// apply velocity to x and y positions
	x += vx;
	y += vy;
}

int Player::GetX() const
{
	return x;
}

int Player::GetY() const
{
	return y;
}

int Player::GetSize() const
{
	return size;
}
