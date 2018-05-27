#include "Player.h"
#include "Graphics.h"

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
