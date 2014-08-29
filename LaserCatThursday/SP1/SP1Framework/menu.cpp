﻿#include "global.h"
#include "menu.h"		//paired file for menu.
#include "game.h"		//this is to provide the parameter to start/end game
#include "Framework\console.h"
#include "highscore.h"

void gameLoop2();
void mainLoop();
void Instructions();


void gameLoop()
{
	while(1)
	{
		cls();
		draw_object ("title.txt", 0x0A);
		int a;
		cin >> a;

		//if the player presses 1...
		if(a == game)
		{
			//call the main loop function to play game
			mainLoop();
			break;
		}
		//if the player presses 2...
		if(a == instructions)
		{
			Instructions();
			break;
		}

		if(a == options)
		{
			cls();
			gameLoop2();
			break;
		}

		//if the player presses 3...
		if(a == HS)
		{
			cls();
			draw_object ("HS.txt", 0x0A);
			cout << endl;
			Highscore HS[10]; 
			load("highscore.txt", HS);
			for(int b = 0;b < 10;b++)
			{
				cout << HS[b].name << "				" << HS[b].score << endl;
			}
			write("highscore.txt", HS); 
			cout << endl << "Enter 1 to return to Main Menu" << endl;
			int a;
			cin >> a;
			if (a == 1)
			{
				continue;
			}
		}

		//if the player presses 4...
		if(a == Exit)
		{
			g_quitGame = true;
			break;
		}

	}
}
