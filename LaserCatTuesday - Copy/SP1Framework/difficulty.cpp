#include "global.h"
#include "menu.h"		//paired file for menu.
#include "game.h"		//this is to provide the parameter to start/end game
#include "Framework\console.h"
#include "difficulty.h"

void gameLoop();		//call from menu.cpp

//identify as difficulty
void hardness()
{
	string difficult;


	std::ifstream difficulttext;
	difficulttext.open ("difficulty.txt");

	while (!difficulttext.eof())
	{
		getline(difficulttext,difficult);
		colour(0x0A);
		cout << difficult << endl;
	}


	difficulttext.close();


	while(2)
	{
		int inputD;
		cin >> inputD;

		//if the player presses 1...
		if(inputD == easy)
		{
			//attach checker here
			cout << "Difficulty set!" << endl;
			break;
		}
		//if the player presses 2
		//set difficulty to medium
		if(inputD == medium)
		{
			//attach checker here
			cout << "Difficulty set!" << endl;
			break;
		}
		//if the player presses 3
		//set difficulty to hard
		if(inputD == hard)
		{
			//attach checker here
			cout << "Difficulty set!" << endl;
			break;
		}
		//if the player presses 4
		//go back to main menu
		if(inputD == menu)
		{
			gameLoop();
			break;
		}
	}

}