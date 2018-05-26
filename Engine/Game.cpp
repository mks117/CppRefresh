/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	HandleInput();

	// apply velocity to x and y positions
	xMobile += vx;
	yMobile += vy;

	xMobile = ClampScreenX(xMobile, sMobile);
	yMobile = ClampScreenY(yMobile, sMobile);
	
	CollisionDetect(xMobile, yMobile, sMobile, xFixed0, yFixed0, sFixed0);

}

void Game::ComposeFrame()
{
	//TODO: Handle collisions on idividual boxes.
	int rMobile = 255;
	int gMobile = 255;
	int bMobile = 255;

	int rFixed;
	int gFixed;
	int bFixed;

    if (colliding)
	{
		rFixed = 255;
		gFixed = 0;
		bFixed = 0;
	}
	else
	{
		rFixed = 0;
		gFixed = 255;
		bFixed = 0;
	}

	DrawBox(xFixed0, yFixed0, rFixed, gFixed, bFixed, sFixed0);
	DrawBox(xFixed1, yFixed1, rFixed, gFixed, bFixed, sFixed1);
	DrawBox(xFixed2, yFixed2, rFixed, gFixed, bFixed, sFixed2);
	DrawBox(xFixed3, yFixed3, rFixed, gFixed, bFixed, sFixed3);
	DrawBox(xMobile, yMobile, rMobile, gMobile, bMobile, sMobile);
}

void Game::DrawBox(int x, int y, int r, int g, int b, int s)
{
	gfx.PutPixel(x, y, r, g, b);
	for (int i = 0; i < s; i++)
	{
		for (int o = 0; o < s; o++)
		{
			gfx.PutPixel(x + i, y + o, r, g, b);
		}
	}
}


int Game::ClampScreenX(int boxX, int boxS)
{
	const int left = boxX;
	const int right = boxX + boxS;

	if (left < 0)
	{
		vx = 0;
		return 0;
	}
	else if (right >= gfx.ScreenWidth)
	{
		vx = 0;
		return gfx.ScreenWidth - boxS;
	}
	else
	{
		return boxX;
	}
}

int Game::ClampScreenY(int boxY, int boxS)
{
	const int top = boxY;
	const int bottom = boxY + boxS;

	if (top < 0)
	{
		vy = 0;
		return 0;
	}
	else if (bottom >= gfx.ScreenHeight)
	{
		vy = 0;
		return gfx.ScreenHeight - boxS;
	}
	else
	{
		return boxY;
	}
}



bool Game::CollisionDetect(int box0X, int box0Y, int box0S, int box1X, int box1Y, int box1S)
{
	if (box0X <= box1X + box1S && box0X + box0S >= box1X
		&& box0Y <= box1Y + box1S && box0Y + box0S >= box1Y)
	{
		colliding = true;
	}
	else colliding = false;

	return colliding;
}

void Game::HandleInput()
{
#pragma region Input
	// Press Escape to quit app
	if (wnd.kbd.KeyIsPressed(VK_ESCAPE))
	{
		wnd.Kill();
	}

	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		if (inhibitRight) {}
		else
		{
			vx += 1;
			inhibitRight = true;
		}
	}
	else
	{
		inhibitRight = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		if (inhibitLeft) {}
		else
		{
			vx -= 1;
			inhibitLeft = true;
		}
	}
	else
	{
		inhibitLeft = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (inhibitUp) {}
		else
		{
			vy -= 1;
			inhibitUp = true;
		}
	}
	else
	{
		inhibitUp = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (inhibitDown) {}
		else
		{
			vy += 1;
			inhibitDown = true;
		}
	}
	else
	{
		inhibitDown = false;
	}
#pragma endregion

}
