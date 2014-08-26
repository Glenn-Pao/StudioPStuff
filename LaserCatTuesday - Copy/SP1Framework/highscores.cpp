#include "highscores.h"

int load(string szFileName, highscore* pHS) 
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


int write(string szFileName, highscore* pHS) 
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



int Highscore(int x) //x is the final calculated score
{
	highscore HS[10]; 
	load("highscore.txt", HS); 
	for(int b = 0;b < 10;b++)
	{
		cout << HS[b].name << ' ' << HS[b].score << endl;
	}
	int a = x;
	for (int i = 0;i < 10 ;i++)
	{
		if (a >= HS[i].score)
		{
			int n = a;
			int counter = 0;
			highscore arr2[10];
			for (int t = 0; t < 10;t++)
			{
				arr2[t].name = HS[t].name;
				arr2[t].score= HS[t].score;
			}
			for (int p = i + 1;p < 10;p++,i++)
			{
				HS[p] = arr2[i];
				counter++;
			}
			HS[i-counter].score = n;
			HS[i-counter].name = "newb";
			break;
		}
	}
	for(int b = 0;b < 10;b++)
	{
		cout << HS[b].name << ' ' << HS[b].score << endl;
	}
	write("highscore.txt", HS); 



}