#include "global.h"
#include "menu.h"		//paired file for menu.
#include "game.h"		//this is to provide the parameter to start/end game
#include "Framework\console.h"
#include "difficulty.h"

void gameLoop();		//call from menu.cpp
void mainLoop();

int check;

//identify as difficulty
void Difficulty()
{
	draw_object ("difficulty.txt", 0x0A);

	while(true)
	{
		int input1;
		cin >> input1;

		//if the player presses 1...
		if(input1 == normal)
		{
			Beep (2000,200);
			check = 0;
			init();
			mainLoop();
			break;
		}
		//if the player presses 2...
		if(input1 == hard)
		{
			Beep (2000,200);
			check = 1;
			init();
			mainLoop();
			break;
		}

		if(input1 == back)
		{
			Beep (1350,150);
			cls();
			gameLoop();
			break;
		}
	}
}