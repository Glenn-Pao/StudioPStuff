// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include "menu.h"
#include "global.h"

int life = 5;
int counter = 0;
int *p = &counter;
double elapsedTime;
double deltaTime;
bool keyPressed[K_COUNT];
COORD charLocation;
COORD catLocation;
COORD catLocation2;
COORD pawLocation;
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
	charLocation.Y = consoleSize.Y / 2 + 6;

	// set the cat to be in center of screen
	catLocation.X = 3;
	catLocation.Y = 2;

	//set the second cat location
	catLocation2.X = 3;
	catLocation2.Y = 2;

	pawLocation.X = 0;
	pawLocation.Y = 0;

	srand( time( NULL ) );

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
	if( ((catLocation.Y - catLocation2.Y) != 15) && (catLocation.X == catLocation2.X))
	{
		catLocation.Y++;
	}
	else if ( ((catLocation.X - catLocation2.X) != 28) && (catLocation.Y != catLocation2.Y))
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
	for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 13; ++j)
			{
				if ( (charLocation.X == catLocation.X + j) && (charLocation.Y == catLocation.Y + i) )
				{
					life--;
				}

				if (life == -1)
				{
					colour(0x0C);
					cout << endl << "Game Over!!" << endl << endl;
					colour(0x06);
					cout << "\\;,._                           _,,-" << endl;
					cout << " \\`;, `-._ _..--'''```--.._ __.-',;(" << endl;
					cout << "  \\`;,  `:.  ,   ;.   .   :'  .;` /" << endl;
					cout << "   ; `;;,      .:    :.      ,;;` / " << endl;
					cout << "    \\ ';/    \\:: :  . ::/    \\;` ;  " << endl;
					cout << "     ).' __.._`        '_..__ `./   " << endl;
					cout << "     /<  \\\\ /I`,      ,'I\\ //   >   " << endl;
					cout << "     /\\   `;-7/_\\ -- /_\\7-;'   /\\   " << endl;
					cout << "     //.    `\"':\" ;; \":`\"'     /\\   " << endl;
					cout << "      |/ .  .:' __..__ `.     \\|    " << endl;
					cout << "      /\\|: ./. `=_  _=' .\\   |/     " << endl;
					cout << "         /:(/::.  \\/  .::\\) /       " << endl;
					cout << "         ////=-v-'`-v-=\\\\\\\\         " << endl;
					cout << "         ///`Nx_\\;;/_xN'\\\\\\         " << endl;
					cout << "        / /   `\"w==w\"'   \\ \\        " << endl;
					cout << "         /                \\         " << endl;


					colour(0x0A);
					exit(0); 
				}
			}
		}
	
	paw(p);

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

			gotoXY(consoleSize.X / 2 - 8 ,consoleSize.Y / 2 - 7);
			cout << "  |\\___/|  " << endl;
			gotoXY(consoleSize.X / 2 - 8 ,consoleSize.Y / 2 - 6);
			cout << " =) ^Y^ (=" << endl;
			gotoXY(consoleSize.X / 2 - 8 ,consoleSize.Y / 2 - 5);
			cout << "  \\  ^  /" << endl;
			gotoXY(consoleSize.X / 2 - 8 ,consoleSize.Y / 2 - 4);
			cout << "   )=*=(" << endl;
			gotoXY(consoleSize.X / 2 - 8 ,consoleSize.Y / 2 -3);
			cout << "  /     \\ " << endl;
			gotoXY(consoleSize.X / 2 - 8 ,consoleSize.Y / 2 -2);
			cout << "  |     |" << endl;
			gotoXY(consoleSize.X / 2 - 8 ,consoleSize.Y / 2 -1);
			cout << " /| | | |\\ " << endl;
			gotoXY(consoleSize.X / 2 - 8 ,consoleSize.Y / 2 );
			cout << " \\| | |_|/\\ " << endl;
			gotoXY(consoleSize.X / 2 - 8 ,consoleSize.Y / 2 + 1);
			cout << " //_// ___/" << endl;
			gotoXY(consoleSize.X / 2 - 8 ,consoleSize.Y / 2 + 2);
			cout << "      \\_)" << endl;



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
	std::cout << "O";

	//render cat danger zone
	gotoXY(catLocation);
	colour(0x0A);
	cout << "      ,-~-, " << std::endl;
	gotoXY(catLocation.X, catLocation.Y + 1);
	cout << "(\\   / ,-, \\ "<< endl;
	gotoXY(catLocation.X, catLocation.Y + 2);
	cout << " \\'-' /   \\ \\ " << endl;
	gotoXY(catLocation.X, catLocation.Y + 3);
	cout << "  '--'     " << endl;

	//render paw
	if (elapsedTime >= 4)
	{
		gotoXY(pawLocation.X, pawLocation.Y);
		colour(0x0E);
		cout << "   h  h" ;
		gotoXY(pawLocation.X, pawLocation.Y+1);
		cout << " h(\")(\")h";
		gotoXY(pawLocation.X, pawLocation.Y+2);
		cout << "(\"),--.(\")";
		gotoXY(pawLocation.X, pawLocation.Y+3);
		cout << " :\"    \";";
		gotoXY(pawLocation.X, pawLocation.Y+4);
		cout << " `.____,'";
	}


	//std::cout << char(221) << char(219) << char(222) << std::endl;
	//std::cout << char(219) << char(219) << char(219) << std::endl;
	//std::cout << char(219) << char(219) << char(219) <<std::endl;
	//std::cout << " " << std::endl;
	////Medium
	//
	//std::cout << char(219) << " " << char(219) << char(219) << " " << char(219) << std::endl;
	//std::cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << std::endl;
	//std::cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << std::endl;
	//std::cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << std::endl;
	//std::cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << std::endl;
	//std::cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << std::endl;
	//std::cout << " " << std::endl;
	////Large
	//
	//std::cout << char(219) << "  " << char(219)  << char(219) << char(219) << "  " << char(219) << std::endl;
	//std::cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) <<std::endl;
	//std::cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) <<std::endl;
	//std::cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << std::endl;
	//std::cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << std::endl;
	
}

void paw (int *count)
{
	*count += 1;

	
	if (elapsedTime <= 10)
	{
		if (*count >= 18)
		{
			*count -= 18;
			pawLocation.X = rand() % 50;
			pawLocation.Y = rand() % 21;
		}
	}

	else if (elapsedTime <= 25)
	{
		if (*count >= 12)
		{
			*count -= 12;
			pawLocation.X = rand() % 50;
			pawLocation.Y = rand() % 21;
		}
	}

	else if (elapsedTime <= 35)
	{
		if (*count >= 6)
		{
			*count -= 6;
			pawLocation.X = rand() % 50;
			pawLocation.Y = rand() % 21;
		}
	}


	else
	{
		pawLocation.X = rand() % 50;
		pawLocation.Y = rand() % 21;
	}
}
