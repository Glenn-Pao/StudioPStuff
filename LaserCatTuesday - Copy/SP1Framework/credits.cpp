#include "global.h"
#include "menu.h"		//paired file for menu.
#include "game.h"		//this is to provide the parameter to start/end game
#include "Framework\console.h"
#include "credits.h"

void gameLoop();		//call from menu.cpp

//identify as credits
void Credits()
{
	string credit;


	std::ifstream credittext;
	credittext.open ("credits.txt");

	while (!credittext.eof())
	{
		getline(credittext,credit);
		colour(0x0A);
		cout << credit << endl;
	}


	credittext.close();


	while(2)
	{
		int input1;
		cin >> input1;

		//if the player presses 1...
		//bring to difficulty screen
		if(input1 == yes)
		{
			gameLoop();
			break;
		}
		//if the player presses 2...
		if(input1 == no)
		{
			cout << "Thank you for playing! ! !" << endl;
			g_quitGame = true;
			break;
		}
	}
}