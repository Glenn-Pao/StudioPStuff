#ifndef _HIGHSCORE_H
#define _HIGHSCORE_H

#include "global.h"
struct Highscore
{
	string name; 
	int score; 
};
int load(string szFileName, Highscore* pHS);
int write(string szFileName, Highscore* pHS);
int highscore(double i);









#endif