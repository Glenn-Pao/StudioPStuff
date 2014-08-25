#ifndef _GAME_H
#define _GAME_H

#include "Framework\timer.h"

extern StopWatch g_timer;
extern bool g_quitGame;

enum Keys
{
    K_UP,
    K_DOWN,
    K_LEFT,
    K_RIGHT,
    K_ESCAPE,
    K_COUNT
};

struct claw
{
	COORD loc1;
	COORD loc2;
	COORD loc3;
};

struct tail
{
	COORD loc1;
	COORD loc2;
};

void waitUntil(long long time);  // wait until this time in milliseconds has passed
void init();					// initialize your variables, allocate memory, etc
void getInput();			    // get input from player
void update(double dt);			// update the game and the state of the game
void render();					// renders the current state of the game to the console
void shutdown();				// do clean up, free memory
void paw(int &count, int &count2, int &count3, claw &enemy);
void renderpaw (claw &enemy);
void damagepaw (claw &enemy);
void damagetail (tail &enemy);
void rendertail (tail &enemy);

#endif // _GAME_H