#include "global.h"
#include "menu.h"		//paired file for menu.
#include "game.h"		//this is to provide the parameter to start/end game
#include "Framework\console.h"
#include "options.h"

void gameLoop();		//call from menu.cpp
void Credits();			//call from credits.cpp

void gameLoop2()
{
	string option;

	std::ifstream optiontext;
	optiontext.open ("options.txt");

	while (!optiontext.eof())
	{
		getline(optiontext,option);
		colour(0x0A);
		cout << option << endl;
	}


	optiontext.close();


	while(4)
	{
		int input;
		cin >> input;

		//if the player presses 1...
		//bring to difficulty screen
		if(input == difficulty)
		{
			//place difficulty codes here
			break;
		}
		//if the player presses 2...
		if(input == 2)
		{
			//place highscores codes here
			break;
		}

		//if the player presses 3...
		if(input == 3)
		{
			Credits();
			break;
		}
		if(input == menu)
		{
			gameLoop();
			break;
		}

	}
}
