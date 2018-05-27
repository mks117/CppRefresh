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
#include <random>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> xDist(0, 770);
	std::uniform_int_distribution<int> yDist(0, 770);
	box0.x = xDist(rng);
	box0.y = yDist(rng);
	box1.x = xDist(rng);
	box1.y = yDist(rng);
	box2.x = xDist(rng);
	box2.y = yDist(rng);

	box0.vx = 1;
	box0.vy = 1;
	box1.vx = -1;
	box1.vy = 1;
	box2.vx = 1;
	box2.vy = -1;

	player.red = 255;
	player.green = 255;
	player.blue = 255;
	
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
	player.x += player.vx;
	player.y += player.vy;

	player.ClampToScreen();

	box0.Update();
	box1.Update();
	box2.Update();

	if (box0.CollisionDetect(player))
	{
		box0.isColliding = true;
	} else box0.isColliding = false;
	if (box1.CollisionDetect(player))
	{
		box1.isColliding = true;
	}
	else box1.isColliding = false;
	if (box2.CollisionDetect(player))
	{
		box2.isColliding = true;
	}
	else box2.isColliding = false;

}

void Game::ComposeFrame()
{
	if (box0.isColliding)
	{
		box0.red = 255;
		box0.green = 0;
		box0.blue = 0;
	}
	else
	{
		box0.red = 0;
		box0.green = 255;
		box0.blue = 0;
	}

	if (box1.isColliding)
	{
		box1.red = 255;
		box1.green = 0;
		box1.blue = 0;
	}
	else
	{
		box1.red = 0;
		box1.green = 255;
		box1.blue = 0;
	}
	if (box2.isColliding)
	{
		box2.red = 255;
		box2.green = 0;
		box2.blue = 0;
	}
	else
	{
		box2.red = 0;
		box2.green = 255;
		box2.blue = 0;
	}

	DrawBox(box0.x, box0.y, box0.red, box0.green, box0.blue, box0.size);
	DrawBox(box1.x, box1.y, box1.red, box1.green, box1.blue, box1.size);
	DrawBox(box2.x, box2.y, box2.red, box2.green, box2.blue, box2.size);
	DrawBox(player.x, player.y, player.red, player.green, player.blue, player.size);
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
		if (player.inhibitRight) {}
		else
		{
			player.vx += 1;
			player.inhibitRight = true;
		}
	}
	else
	{
		player.inhibitRight = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		if (player.inhibitLeft) {}
		else
		{
			player.vx -= 1;
			player.inhibitLeft = true;
		}
	}
	else
	{
		player.inhibitLeft = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (player.inhibitUp) {}
		else
		{
			player.vy -= 1;
			player.inhibitUp = true;
		}
	}
	else
	{
		player.inhibitUp = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (player.inhibitDown) {}
		else
		{
			player.vy += 1;
			player.inhibitDown = true;
		}
	}
	else
	{
		player.inhibitDown = false;
	}
#pragma endregion

}
