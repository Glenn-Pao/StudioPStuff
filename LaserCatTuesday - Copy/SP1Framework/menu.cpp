#include "global.h"
#include "menu.h"		//paired file for menu.
#include "game.h"		//this is to provide the parameter to start/end game
#include "Framework\console.h"


void gameLoop2();
void mainLoop();


void gameLoop()
{
	string title;

	std::ifstream titletext;
	titletext.open ("title.txt");

	while (!titletext.eof())
	{
		getline(titletext,title);
		colour(0x0A);
		cout << title << endl;
	}


	titletext.close();


	while(1)
	{
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
		if(a == options)
		{
			gameLoop2();
			break;
		}

		//if the player presses 3...
		if(a == Exit)
		{
			g_quitGame = true;
			break;
		}

	}
}
