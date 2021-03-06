#ifndef _GAME_H
#define _GAME_H

#include "Framework\timer.h"
#include "global.h"


extern StopWatch g_timer;
extern bool g_quitGame;

enum Keys
{
    K_UP,
    K_DOWN,
    K_LEFT,
    K_RIGHT,
    K_ESCAPE,
	K_SPACE,
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

struct deadzone
{
	int ID;
	COORD loc;
};



void waitUntil(long long time);													// wait until this time in milliseconds has passed
void init();																	// initialize your variables, allocate memory, etc
void getInput();																// get input from player
void update(double dt);															// update the game and the state of the game
void render();																	// renders the current state of the game to the console
void shutdown();																// do clean up, free memory
void paw(double &count, double &count2, double &count3, claw &enemy);			// spawn paws
void renderpaw (claw &enemy);													//render the paw
void damagepaw (claw &enemy);													//make paw deal damage
void damagetail (tail &enemy);													//make tail deal damage
void pickup(double &count, double &count2, double &count3, item &bonus);		//spawn items
void renderpickup (item &bonus);												//render items
void pickupeffect (double &count, double &count2, double &count3, item &bonus);	//cause item effect
void deadspace_effect (deadzone &enemy);										//make deadspace alter movement
void draw_object (string sFile, WORD wColor, int ixStart, int iyStart);			//render objects with location
void draw_object (string sFile, WORD wColor);									//render objects without location
void gameover ();																//show gameover screen



#endif // _GAME_H