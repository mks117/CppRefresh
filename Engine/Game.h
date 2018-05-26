/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
	void DrawBox(int x, int y, int r, int g, int b, int s);
	int ClampScreenX(int xMobile, int sMobile);
	int ClampScreenY(int yMobile, int sMobile);
	bool CollisionDetect(int box0X, int box0Y, int box0S, int box1X, int box1Y, int box1S);
	void HandleInput();
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	/********************************/
	int xMobile = 400;
	int yMobile = 300;
	int sMobile = 20;
	int xFixed0 = 200;
	int yFixed0 = 200;
	int sFixed0 = 40;

	int xFixed1 = 50;
	int yFixed1 = 200;
	int sFixed1 = 40;

	int xFixed2 = 200;
	int yFixed2 = 50;
	int sFixed2 = 40;

	int xFixed3 = 400;
	int yFixed3 = 400;
	int sFixed3 = 40;

	bool colliding = false;
	int vx = 0;
	int vy = 0;
	int gb = 255;
	bool inhibitUp = false;
	bool inhibitDown = false;
	bool inhibitLeft = false;
	bool inhibitRight = false;
};