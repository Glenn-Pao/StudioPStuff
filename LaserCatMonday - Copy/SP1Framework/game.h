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

struct item
{
	int ID;
	COORD loc;
};

void waitUntil(long long time);									// wait until this time in milliseconds has passed
void init();													// initialize your variables, allocate memory, etc
void getInput();												// get input from player
void update(double dt);											// update the game and the state of the game
void render();													// renders the current state of the game to the console
void shutdown();												// do clean up, free memory
void paw(int &count, int &count2, int &count3, claw &enemy);	// spawn paws
void renderpaw (claw &enemy);									//render the paw
void damagepaw (claw &enemy);									//make paw deal damage
void damagetail (tail &enemy);									//make tail deal damage
void rendertail (tail &enemy);									//render tail
void pickup(int &count, int &count2, int &count3, item &bonus);	//spawn items
void renderpickup (item &bonus);								//render items
void pickupeffect (item &bonus);								//cause item effect


#endif // _GAME_H