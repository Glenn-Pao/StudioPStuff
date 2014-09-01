#include "global.h"
#include "menu.h"		//paired file for menu.
#include "game.h"		//this is to provide the parameter to start/end game
#include "Framework\console.h"
#include "credits.h"


void gameLoop();		//call from menu.cpp

//identify as credits
void Credits()
{
	cls();
	draw_object ("credits.txt", 0x0A);

	while(true)
	{
		int input1;
		cin >> input1;

		//if the player presses 1...
		//bring to difficulty screen
		if(input1 == yes)
		{
			Beep (1350,150);
			gameLoop();
			break;
		}
		//if the player presses 2...
		if(input1 == no)
		{
			Beep (1350,150);
			cout << "Thank you for playing! ! !" << endl;
			g_quitGame = true;
			break;
		}
	}
}