#include "global.h"
#include "menu.h"		//paired file for menu.
#include "game.h"		//this is to provide the parameter to start/end game
#include "Framework\console.h"
#include "difficulty.h"

void gameLoop();		//call from menu.cpp

//identify as difficulty
void Difficulty()
{
	draw_object ("difficulty.txt", 0x0A);

	while(true)
	{
		int input1;
		cin >> input1;

		//if the player presses 1...
		if(input1 == easy)
		{
			int check = 1;
			gameLoop();
			break;
		}
		//if the player presses 2...
		if(input1 == medium)
		{
			int check = 2;
			gameLoop();
			break;
		}
		//if the player presses 3...
		if(input1 == hard)
		{
			int check = 3;
			gameLoop();
			break;
		}
	}
}