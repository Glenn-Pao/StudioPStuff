#include "global.h"
#include "menu.h"		//paired file for menu.
#include "game.h"		//this is to provide the parameter to start/end game
#include "Framework\console.h"

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
