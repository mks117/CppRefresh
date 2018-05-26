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
	// Press Escape to quit app
	if (wnd.kbd.KeyIsPressed(VK_ESCAPE))
	{
		wnd.Kill();
	}

#pragma region Controls
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
	
	x += vx;
	y += vy;

	if (x + 20 > Graphics::ScreenWidth)
	{
		x = Graphics::ScreenWidth - 20;
		vx = 0;
	}

	if (x < 0)
	{
		x = 0;
		vx = 0;
	}

	if (y + 20 > Graphics::ScreenHeight)
	{
		y = Graphics::ScreenHeight - 20;
		vy = 0;
	}

	if (y < 0)
	{
		y = 0;
		vy = 0;
	}

	
}

void Game::ComposeFrame()
{
	DrawBox(x, y, 255, 255, 255);
	
}

void Game::DrawBox(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x, y, r, g, b);
	for (int i = 0; i < 20; i++)
	{
		for (int o = 0; o < 20; o++)
		{
			gfx.PutPixel(x + i, y + o, r, g, b);
		}
	}
}
