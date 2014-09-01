#include "global.h"
#include "menu.h"		//paired file for menu.
#include "game.h"		//this is to provide the parameter to start/end game
#include "Framework\console.h"
#include "options.h"

void gameLoop();		//call from menu.cpp
void Credits();			//call from credits.cpp
void Difficulty();		//call from difficulty.cpp

void gameLoop2()
{
	draw_object ("options.txt", 0x0A);

	while(4)
	{
		int input;
		cin >> input;

		//if the player presses 1...
		//bring to difficulty screen
		if(input == difficulty)
		{
			Beep (2000,200);
			cls();
			Difficulty();
			break;
		}
		//if the player presses 2...
		if(input == 2)
		{
			Beep (2000,200);
			cls();
			Credits();
			break;
		}

		if(input == menu)
		{
			Beep (1350,150);
			cls();
			gameLoop();
			break;
		}

	}
}
