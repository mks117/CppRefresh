#include "Box.h"
#include "Graphics.h"

void Box::Update()
{
	x += vx;
	y += vy;

	const int right = x + size;

	if (x < 0)
	{
		x = 0;
		vx = -vx;
	}
	else if (right >= Graphics::ScreenWidth)
	{
		x = (Graphics::ScreenWidth - size);
		vx = -vx;
	}

	const int bottom = y + size;

	if (y < 0)
	{
		y = 0;
		vy = -vy;
	}
	else if (bottom >= Graphics::ScreenHeight)
	{
		y = (Graphics::ScreenHeight - size);
		vy = -vy;
	}
}

bool Box::CollisionDetect(Player player)
{
	if (x <= player.x + player.size && x + size >= player.x
		&& y <= player.y + player.size && y + size >= player.y)
	{
		isColliding = true;
		return true;
	}
	else isColliding = false;
	return false;
}
