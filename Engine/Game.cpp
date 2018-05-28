/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can ristribute it and/or modify	  *
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

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	rng( rd() ),
	xDist(0, 770),
	yDist(0, 570),
	box0(xDist(rng), yDist(rng), 1, 1),
	box1(xDist(rng), yDist(rng), -1, 1),
	box2(xDist(rng), yDist(rng), 1, -1),
	box3(xDist(rng), yDist(rng), 1, 1),
	box4(xDist(rng), yDist(rng), -1, 1),
	box5(xDist(rng), yDist(rng), 1, -1),
	box6(xDist(rng), yDist(rng), 1, 1),
	box7(xDist(rng), yDist(rng), -1, 1),
	box8(xDist(rng), yDist(rng), 1, -1)
{
	player.r = 255;
	player.g = 255;
	player.b = 255;
	
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

	player.Update(wnd.kbd);
	player.ClampToScreen();

	box0.Update();
	box1.Update();
	box2.Update();
	box3.Update();
	box4.Update();
	box5.Update();
	box6.Update();
	box7.Update();
	box8.Update();

	if (box0.CollisionDetect(player))
	{
		box0.SetColliding(true);
	} else box0.SetColliding(false);

	if (box1.CollisionDetect(player))
	{
		box1.SetColliding(true);
	}
	else box1.SetColliding(false);

	if (box2.CollisionDetect(player))
	{
		box2.SetColliding(true);
	}
	else box2.SetColliding(false);

	if (box3.CollisionDetect(player))
	{
		box3.SetColliding(true);
	}
	else box3.SetColliding(false);

	if (box4.CollisionDetect(player))
	{
		box4.SetColliding(true);
	}
	else box4.SetColliding(false);
	if (box5.CollisionDetect(player))
	{
		box5.SetColliding(true);
	}
	else box5.SetColliding(false);
	if (box6.CollisionDetect(player))
	{
		box6.SetColliding(true);
	}
	else box6.SetColliding(false);
	if (box7.CollisionDetect(player))
	{
		box7.SetColliding(true);
	}
	else box7.SetColliding(false);
	if (box8.CollisionDetect(player))
	{
		box8.SetColliding(true);
	}
	else box8.SetColliding(false);

}

void Game::ComposeFrame()
{
	if (box0.IsColliding())
	{
		box0.r = 255;
		box0.g = 0;
		box0.b = 0;
	}
	else
	{
		box0.r = 0;
		box0.g = 255;
		box0.b = 0;
	}
	if (box1.IsColliding())
	{
		box1.r = 255;
		box1.g = 0;
		box1.b = 0;
	}
	else
	{
		box1.r = 0;
		box1.g = 255;
		box1.b = 0;
	}
	if (box2.IsColliding())
	{
		box2.r = 255;
		box2.g = 0;
		box2.b = 0;
	}
	else
	{
		box2.r = 0;
		box2.g = 255;
		box2.b = 0;
	}
	if (box3.IsColliding())
	{
		box3.r = 255;
		box3.g = 0;
		box3.b = 0;
	}
	else
	{
		box3.r = 0;
		box3.g = 255;
		box3.b = 0;
	}
	if (box4.IsColliding())
	{	   
		box4.r = 255;
		box4.g = 0;
		box4.b = 0;
	}	   
	else   
	{	   
		box4.r = 0;
		box4.g = 255;
		box4.b = 0;
	}
	if (box5.IsColliding())
	{
		box5.r = 255;
		box5.g = 0;
		box5.b = 0;
	}
	else
	{
		box5.r = 0;
		box5.g = 255;
		box5.b = 0;
	}
	if (box6.IsColliding())
	{
		box6.r = 255;
		box6.g = 0;
		box6.b = 0;
	}
	else
	{
		box6.r = 0;
		box6.g = 255;
		box6.b = 0;
	}
	if (box7.IsColliding())
	{
		box7.r = 255;
		box7.g = 0;
		box7.b = 0;
	}
	else
	{
		box7.r = 0;
		box7.g = 255;
		box7.b = 0;
	}
	if (box8.IsColliding())
	{
		box8.r = 255;
		box8.g = 0;
		box8.b = 0;
	}
	else
	{
		box8.r = 0;
		box8.g = 255;
		box8.b = 0;
	}

	box0.Draw(gfx);
	box1.Draw(gfx);
	box2.Draw(gfx);
	box3.Draw(gfx);
	box4.Draw(gfx);
	box5.Draw(gfx);
	box6.Draw(gfx);
	box7.Draw(gfx);
	box8.Draw(gfx);
	player.Draw(gfx);
}


void Game::HandleInput()
{
	if (wnd.kbd.KeyIsPressed(VK_ESCAPE))
	{
		wnd.Kill();
	}

}
