#include "global.h"
#include "menu.h"		//paired file for menu.
#include "game.h"		//this is to provide the parameter to start/end game


void gameLoop()
{
	cout << "Troll Cat" << endl;
	cout << "(1)Game" << endl;
	cout << "(2)Options" << endl;
	cout << "(3)Exit" << endl;
	while(1)
	{
		int a;
		cin >> a;
		if(a == game)
		{
			break;
		}
		if(a == Exit)
		{
			g_quitGame = true;
			break;
		}

	}
}
