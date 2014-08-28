#include "global.h"
#include "menu.h"
#include "options.h"
#include "game.h"
#include "highscore.h"






int load(string szFileName, Highscore* pHS) 
{
	ifstream myFile(szFileName);
	int		 i=0; 

	if (myFile.is_open())
	{
		while(!myFile.eof())
		{
			myFile >> pHS[i].name; 
			myFile >> pHS[i].score; 
			i++; 
		}
	}

	return i;
}


int write(string szFileName, Highscore* pHS) 
{
	ofstream myFile(szFileName);
	int  i = 0; 

	if (myFile.is_open())
	{
		while(i < 10)
		{
			myFile << pHS[i].name << " " << pHS[i].score << endl; 
			i++; 

		}
	}

	return i;
}



int highscore(double i)
{
	Highscore HS[10]; 
	load("highscore.txt", HS); 
	int a = (int)i;
	for (int o = 0;o < 10 ;o++)
	{
		if (a >= HS[o].score)
		{
			cout << "Enter your name" << endl;
			string name;
			cin >> name;

			int n = a;
			int counter = 0;
			Highscore arr2[10];
			for (int t = 0; t < 10;t++)
			{
				arr2[t].name = HS[t].name;
				arr2[t].score= HS[t].score;
			}
			for (int p = o + 1;p < 10;p++,o++)
			{
				HS[p] = arr2[o];
				counter++;
			}
			HS[o-counter].score = n;
			HS[o-counter].name = name;
			break;
		}
	}
	
	
	
	for(int b = 0;b < 10;b++)
	{
		cout << HS[b].name << ' ' << HS[b].score << endl;
	}
	write("highscore.txt", HS); 


	return i;
}


