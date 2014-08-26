#ifndef _HIGHSCORES_H
#define _HIGHSCORES_H


#include "global.h"

using std :: ifstream;
using std :: ofstream;

struct highscore
{
	string name; 
	int score; 
};

#endif