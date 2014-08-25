#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include<fstream>
#include<string>

using std :: cin;
using std :: cout;
using std :: endl;
using namespace std;

enum Sequence 
{
	game = 1,
	rules,
	options,
	Exit,
};
void gameLoop()
{
	ifstream file1("title.txt");
	string a;
	if (file1.is_open())
	{
		while(getline(file1,a))
		{
			cout << a << endl;
		}
	}
	
	while(1)
	{
		int a;
		std :: cin >> a;
		if(a == game)
		{
			break;
		}
		if(a == rules)
		{
			std :: cout << "Direction Pad: Move laser point." << std::endl;
			std :: cout << std :: endl;
			std :: cout << "Task: Avoid cat paw & cat. If you do = lose life." << std :: endl;
			std :: cout << std :: endl;
			std :: cout << "How to earn score: Stay alive as long as possible! 1 second = 1 point." << std :: endl;
			std :: cout << std :: endl;
			std :: cout << "Press another number to continue" << std :: endl;
		}
		if(a == Exit)
		{
			g_quitGame = true;
			break;
		}

	}
}
