#include "Box.h"

Box::Box(int x_in, int y_in, int vx_in, int vy_in)
{
	x = x_in;
	y = y_in;
	vx = vx_in;
	vy = vy_in;
}

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

bool Box::CollisionDetect(const Player& player)
{
	if (x <= player.GetX() + player.GetSize() && x + size >= player.GetX()
		&& y <= player.GetY() + player.GetSize() && y + size >= player.GetY())
	{
		isColliding = true;
		return true;
	}
	else isColliding = false;
	return false;
}

void Box::Draw(Graphics& gfx) const
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

bool Box::IsColliding() const
{
	return isColliding;
}

void Box::SetColliding(bool colliding)
{
	isColliding = colliding;
}
