// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include "menu.h"
#include "global.h"

int life;
double elapsedTime;
double deltaTime;
bool keyPressed[K_COUNT];
COORD charLocation;
COORD catLocation;
COORD catLocation2;
COORD consoleSize;


void init()
{
	// Set precision for floating point output
	cout << std::fixed << std::setprecision(1);

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

	//set the second cat location
	catLocation2.X = consoleSize.X / 2;
	catLocation2.Y = consoleSize.Y / 2;

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
	life = 5;

	// Updating the location of the character based on the key press
	//create the deadspace
	if (keyPressed[K_UP] && charLocation.Y > 0)
	{
		int b = 0;
		for (int i = 0; i < 5; ++i)
		{

			if (charLocation.X != (consoleSize.X / 2 + i - 2) && charLocation.Y-1 != consoleSize.Y / 2 )
			{
				b = 1;
			}	
			else if(charLocation.X != (consoleSize.X / 2 + i - 2) || charLocation.Y-1 != consoleSize.Y / 2 )
			{
				b = 1;
			}
			else
			{
				b = 0;
				break;
			}

		}
		if(b == 1)
		{
			Beep(1440, 30);
			charLocation.Y--; 
		}
	}
	if (keyPressed[K_LEFT] && charLocation.X > 0)
	{
		int b = 0;
		for (int a = 0; a < 5; ++a)
		{
			if (charLocation.X-1 != (consoleSize.X / 2 + 2) && charLocation.Y != consoleSize.Y / 2 - a)
			{
				b = 1;
			}	
			else if(charLocation.X-1 != (consoleSize.X / 2 + 2) || charLocation.Y != consoleSize.Y / 2 - a)
			{
				b = 1;
			}
			else
			{
				b = 0;
				break;
			}
		}
		if (b == 1)
		{
			Beep(1440, 30);
			charLocation.X--; 
		}
	}
	if (keyPressed[K_DOWN] && charLocation.Y < consoleSize.Y - 1)
	{
		int b = 0;
		for (int i = 0; i < 5; ++i)
		{

			if (charLocation.X != (consoleSize.X / 2 + i - 2) && charLocation.Y+1 != consoleSize.Y / 2 - 4)
			{
				b = 1;
			}	
			else if(charLocation.X != (consoleSize.X / 2 + i - 2) || charLocation.Y+1 != consoleSize.Y / 2 - 4)
			{
				b = 1;
			}
			else
			{
				b = 0;
				break;
			}

		}
		if(b == 1)
		{
			Beep(1440, 30);
			charLocation.Y++; 
		}
	}
	if (keyPressed[K_RIGHT] && charLocation.X < consoleSize.X - 1)
	{
		int b = 0;
		for (int a = 0; a < 5; ++a)
		{
			if (charLocation.X+1 != (consoleSize.X / 2 - 2) && charLocation.Y != consoleSize.Y / 2 - a)
			{
				b = 1;
			}	
			else if(charLocation.X+1 != (consoleSize.X / 2 - 2) || charLocation.Y != consoleSize.Y / 2 - a)
			{
				b = 1;
			}
			else
			{
				b = 0;
				break;
			}
		}
		if (b == 1)
		{
			Beep(1440, 30);
			charLocation.X++; 
		}
	}
	//for the dynamic movement of cat
	if( ((catLocation.Y - catLocation2.Y) != 2) && (catLocation.X == catLocation2.X))
	{
		catLocation.Y++;
	}
	else if ( ((catLocation.X - catLocation2.X) != 3) && (catLocation.Y != catLocation2.Y))
	{
		catLocation.X++;
	}
	else if (catLocation.Y != catLocation2.Y)
	{
		catLocation.Y--;
	}
	else if (catLocation.X != catLocation2.X)
	{
		catLocation.X--;
	}

	//set conditions of losing life
	if(charLocation.X == catLocation.X && charLocation.Y == catLocation.Y)
	{
		life--;
	}

	// quits the game if player hits the escape key
	if (keyPressed[K_ESCAPE])
		g_quitGame = true;    
}

void render()
{
	// clear previous screen
	colour(0x0F);
	cls();

	//render the game

	//render test screen code (not efficient at all)
	const WORD colors[] =   {
		0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
		0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
	};

	for (int i = 0; i < 5; ++i)
	{
		for (int a = 0; a < 5; ++a)
		{
			gotoXY(consoleSize.X / 2 + i - 2,consoleSize.Y / 2 - a);
			colour(colors[i]);
			cout << "*";
		}
	}

	// render time taken to calculate this frame
	gotoXY(40, 0);
	colour(0x1A);
	cout << "Score: " << (int)elapsedTime << endl;

	gotoXY(0, 0);
	colour(0x1B);
	cout << "Lives: " << life << endl;

	// render character
	gotoXY(charLocation);
	colour(0x0C);
	std::cout << (char)1;

	//render cat danger zone
	gotoXY(catLocation);
	colour(0x0A);
	cout << (char)1 << (char)1 << (char)1 << (char)1 << (char)1 << (char)1 << (char)1 << (char)1 << (char)1 << (char)1 << (char)1 << std::endl;
	gotoXY(catLocation.X, catLocation.Y + 1);
	cout << (char)1 << "         " << (char)1 << endl;
	gotoXY(catLocation.X, catLocation.Y + 2);
	cout << (char)1 << "         " << (char)1 << endl;
	gotoXY(catLocation.X, catLocation.Y + 3);
	cout << (char)1 << "         " << (char)1 << endl;
	gotoXY(catLocation.X, catLocation.Y + 4);
	cout << (char)1 << "         " << (char)1 << endl;
	gotoXY(catLocation.X, catLocation.Y + 5);
	cout << (char)1 << (char)1 << (char)1 << (char)1 << (char)1 << (char)1 << (char)1 << (char)1 << (char)1 << (char)1 << (char)1 << endl;
	
	/*
	
	//Small
	std::cout << char(221) << char(219) << char(222) << std::endl;
	std::cout << char(219) << char(219) << char(219) << std::endl;
	std::cout << char(219) << char(219) << char(219) <<std::endl;
	std::cout << " " << std::endl;
	//Medium
	
	std::cout << char(219) << " " << char(219) << char(219) << " " << char(219) << std::endl;
	std::cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << std::endl;
	std::cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << std::endl;
	std::cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << std::endl;
	std::cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << std::endl;
	std::cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << std::endl;
	std::cout << " " << std::endl;
	//Large
	
	std::cout << char(219) << "  " << char(219)  << char(219) << char(219) << "  " << char(219) << std::endl;
	std::cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) <<std::endl;
	std::cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) <<std::endl;
	std::cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << std::endl;
	std::cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << std::endl;
	*/
}
