// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>

double elapsedTime;
double deltaTime;
bool keyPressed[K_COUNT];
COORD charLocation;
COORD catLocation;
COORD consoleSize;

void init()
{
    // Set precision for floating point output
    std::cout << std::fixed << std::setprecision(1);

    SetConsoleTitle(L"Troll Cat");

    // Sets the console size
    setConsoleSize(50, 25);

    // Get console width and height
    CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */     

    /* get the number of character cells in the current buffer */ 
    GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi );
    consoleSize.X = csbi.srWindow.Right + 1;
    consoleSize.Y = csbi.srWindow.Bottom + 1;

    // set the character to be in the center of the screen.
    charLocation.X = consoleSize.X / 2;
    charLocation.Y = consoleSize.Y / 2;

	// set the cat to be in center of screen
	catLocation.X = consoleSize.X / 2;
	catLocation.Y = consoleSize.Y / 2;
	//set in a range?
    elapsedTime = 0.0;
}

void shutdown()
{
    // Reset to white text on black background
	colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}

void getInput()
{    
    keyPressed[K_UP] = isKeyPressed(VK_UP);
    keyPressed[K_DOWN] = isKeyPressed(VK_DOWN);
    keyPressed[K_LEFT] = isKeyPressed(VK_LEFT);
    keyPressed[K_RIGHT] = isKeyPressed(VK_RIGHT);
    keyPressed[K_ESCAPE] = isKeyPressed(VK_ESCAPE);
}
void update(double dt)
{
    // get the delta time
    elapsedTime += dt;
    deltaTime = dt;

	
	//attach conditions for location of cat and cat paw
	//make use of arrays to do this
	if(charLocation.X == catLocation.X && charLocation.Y == catLocation.Y)
	{
		std::cout << ":(";
		
	}
    // Updating the location of the character based on the key press
    if (keyPressed[K_UP] && charLocation.Y > 0)
    {
        Beep(1440, 30);
        charLocation.Y--; 
    }
    if (keyPressed[K_LEFT] && charLocation.X > 0)
    {
        Beep(1440, 30);
        charLocation.X--; 
    }
    if (keyPressed[K_DOWN] && charLocation.Y < consoleSize.Y - 1)
    {
        Beep(1440, 30);
        charLocation.Y++; 
    }
    if (keyPressed[K_RIGHT] && charLocation.X < consoleSize.X - 1)
    {
        Beep(1440, 30);
        charLocation.X++; 
    }
	if(catLocation.Y > 0)
	{
		catLocation.Y++;
	}

    // quits the game if player hits the escape key
    if (keyPressed[K_ESCAPE])
	{
        g_quitGame = true;
	}
	
}

void render()
{
    // clear previous screen
    colour(0x0F);
    cls();

	for (int i = 0; i < 12; ++i)
	{
		gotoXY(3*i,i+1);
		
	}

    // render time taken to calculate this frame
    gotoXY(40, 0);
    colour(0x1A);
     std::cout << "Score: " << (int)elapsedTime << std::endl;
  
    gotoXY(0, 0);
    colour(0x1B);
    std::cout << "Lives: 5" << std::endl;

    // render character
    gotoXY(charLocation);
    colour(0x0C);
    std::cout << (char)1;

	//render cat
	gotoXY(catLocation);
	colour(0x0A);
	//this is the deadzone
	//most inefficient code xD
	std::cout << (char)1 << (char)1 << (char)1 << (char)1 << (char)1 << (char)1 << (char)1 << (char)1 << (char)1 << (char)1 << (char)1 << std::endl;
	std::cout << (char)1 << "         " << (char)1 << std::endl;
	std::cout << (char)1 << "         " << (char)1 << std::endl;
	std::cout << (char)1 << "         " << (char)1 << std::endl;
	std::cout << (char)1 << "         " << (char)1 << std::endl;
	std::cout << (char)1 << (char)1 << (char)1 << (char)1 << (char)1 << (char)1 << (char)1 << (char)1 << (char)1 << (char)1 << (char)1 << std::endl;

}
