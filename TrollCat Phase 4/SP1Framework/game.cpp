// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include "Framework\timer.h"
#include "menu.h"
#include "global.h"
#include "paw.h"
#include "paw.cpp"

//counters
int counter = 0;
int counter2 = 0;
int counter3 = 0;
int counter4 = 0;
int counter5 = 0;
int counter6 = 0;
int counter7 = 0;
int counter8 = 0;
int counter9 = 0;
int counter10 = 0;
int counter11 = 0;
int counter12 = 0;

//use debugging - breakpoints, search, watch your variables
//call stack -> tells you functions used before app crash

double elapsedTime;
double deltaTime;
int life = 30;
COORD charLocation;
bool keyPressed[K_COUNT];

COORD consoleSize;
claw paw1;
claw paw2;
claw paw3;
claw paw4;
tail tail1;
tail tail2;


void paw(int &count, int &count2, int &count3, claw &enemy);
void renderpaw (claw &enemy);
void damagepaw (claw &enemy);

void init()
{
	// Set precision for floating point output
	cout << std::fixed << std::setprecision(1);

	SetConsoleTitle(L"Troll Cat");

	// Sets the console size
	setConsoleSize(65, 25);

	// Get console width and height
	CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */     

	/* get the number of character cells in the current buffer */ 
	GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi );
	consoleSize.X = csbi.srWindow.Right + 1;
	consoleSize.Y = csbi.srWindow.Bottom + 1;

	// set the character to be in the center of the screen.
	charLocation.X = consoleSize.X / 2;
	charLocation.Y = consoleSize.Y / 2 + 6;

	// set the taillocation
	tail1.loc1.X = 6;
	tail1.loc1.Y = 2;

	tail1.loc2.X = 6;
	tail1.loc2.Y = 2;

	tail2.loc1.X = 41;
	tail2.loc1.Y = 18;

	tail2.loc2.X = 41;
	tail2.loc2.Y = 18;

	//set paw locations
	paw1.loc1.X = 0;
	paw1.loc1.Y = 0;
	paw1.loc2.X = 0;
	paw1.loc2.Y = 0;
	paw1.loc3.X = 0;
	paw1.loc3.Y = 0;

	paw2.loc1.X = 0;
	paw2.loc1.Y = 0;
	paw2.loc2.X = 0;
	paw2.loc2.Y = 0;
	paw2.loc3.X = 0;
	paw2.loc3.Y = 0;

	paw3.loc1.X = 0;
	paw3.loc1.Y = 0;
	paw3.loc2.X = 0;
	paw3.loc2.Y = 0;
	paw3.loc3.X = 0;
	paw3.loc3.Y = 0;

	paw4.loc1.X = 0;
	paw4.loc1.Y = 0;
	paw4.loc2.X = 0;
	paw4.loc2.Y = 0;
	paw4.loc3.X = 0;
	paw4.loc3.Y = 0;


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
		for (int i = 0; i < 13; ++i)
		{

			if (charLocation.X != (consoleSize.X / 2 + i - 9) && charLocation.Y-1 != consoleSize.Y / 2 + 2)
			{
				b = 1;
			}	
			else if(charLocation.X != (consoleSize.X / 2 + i - 9) || charLocation.Y-1 != consoleSize.Y / 2  +2)
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
		for (int a = 0; a < 11; ++a)
		{
			if (charLocation.X-1 != (consoleSize.X / 2 + 2) && charLocation.Y != consoleSize.Y / 2 + 2 - a)
			{
				b = 1;
			}	
			else if(charLocation.X-1 != (consoleSize.X / 2 + 2) || charLocation.Y != consoleSize.Y / 2 + 2 - a)
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
		for (int i = 0; i < 13; ++i)
		{

			if (charLocation.X != (consoleSize.X / 2 + i - 9) && charLocation.Y+1 != consoleSize.Y / 2 - 8)
			{
				b = 1;
			}	
			else if(charLocation.X != (consoleSize.X / 2 + i - 9) || charLocation.Y+1 != consoleSize.Y / 2 - 8)
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
		for (int a = 0; a < 11; ++a)
		{
			if (charLocation.X+1 != (consoleSize.X / 2 - 9) && charLocation.Y != consoleSize.Y / 2 + 2 - a)
			{
				b = 1;
			}	
			else if(charLocation.X+1 != (consoleSize.X / 2 - 9) || charLocation.Y != consoleSize.Y / 2 + 2 - a)
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



	//for the dynamic movement of tail1
	if( ((tail1.loc1.Y - tail1.loc2.Y) != 18) && (tail1.loc1.X == tail1.loc2.X))
	{

		tail1.loc1.Y++;
	}
	else if ( ((tail1.loc1.X - tail1.loc2.X) != 36) && (tail1.loc1.Y != tail1.loc2.Y))
	{
		tail1.loc1.X++;
	}
	else if (tail1.loc1.Y != tail1.loc2.Y)
	{
		tail1.loc1.Y--;
	}
	else if (tail1.loc1.X != tail1.loc2.X)
	{
		tail1.loc1.X--;
	}

	//for the dynamic movement of tail2
	if( ((tail2.loc1.Y + tail2.loc2.Y) != 18) && (tail2.loc1.X == tail2.loc2.X))
	{
		tail2.loc1.Y--;
	}
	else if ( ((tail2.loc1.X + tail2.loc2.X) != 43) && (tail2.loc1.Y != tail2.loc2.Y))
	{
		tail2.loc1.X--;
	}
	else if (tail2.loc1.Y != tail2.loc2.Y)
	{
		tail2.loc1.Y++;
	}
	else if (tail2.loc1.X != tail2.loc2.X)
	{
		tail2.loc1.X++;
	}

	//set conditions of losing life (tail)
	damagetail(tail1);
	damagetail(tail2);

	//set conditions of losing life (paw)
	damagepaw (paw1);
	damagepaw (paw2);
	damagepaw (paw3);
	damagepaw (paw4);



	paw(counter, counter2, counter3, paw1);
	paw(counter4,counter5,counter6,paw2);
	paw(counter7,counter8,counter9,paw3);
	paw(counter10,counter11,counter12,paw4);

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

	//to change to txt file
	gotoXY(consoleSize.X / 2 - 8 ,consoleSize.Y / 2 - 7);
	colour(0x0B);
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
	gotoXY(56, 0);
	colour(0x1A);
	cout << "Score: " << (int)elapsedTime << endl;

	gotoXY(0, 0);
	colour(0x1B);
	cout << "Health: " << life << endl;

	// render character
	gotoXY(charLocation);
	colour(0x0C);
	std::cout << "OOO";
	gotoXY(charLocation.X, charLocation.Y + 1);
	std::cout << "OOO";

	//render cat danger zone
	rendertail (tail1);
	rendertail (tail2);

	//render paw
	renderpaw (paw1);
	renderpaw (paw2);
	renderpaw (paw3);
	renderpaw (paw4);
}
//may want to txt file

void damagetail (tail &enemy)
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 13; ++j)
		{
			for (int k = 0; k < 2; ++k)
			{
				for (int l = 0; l < 3; ++l)
				{
					if ( (charLocation.X + l == enemy.loc1.X + j) && (charLocation.Y + k == enemy.loc1.Y + i) )
					{
						life--;
					}

					if (life == -1)
					{
						string gameover;

						std::ifstream deadtext;
						deadtext.open ("dead.txt");

						while (!deadtext.eof())
						{
							getline(deadtext,gameover);
							colour(0x0C);
							cout << gameover << endl;
						}


						deadtext.close();
						colour(0x06);


						colour(0x0A);
						exit(0); 
					}
				}
			}
		}
	}
}
//change to txt file..
void rendertail (tail &enemy)
{
	gotoXY(enemy.loc1);
	colour(0x0A);
	cout << "      ,-~-, " << std::endl;
	gotoXY(enemy.loc1.X, enemy.loc1.Y + 1);
	cout << "(\\   / ,-, \\ "<< endl;
	gotoXY(enemy.loc1.X, enemy.loc1.Y + 2);
	cout << " \\'-' /   \\ \\ " << endl;
	gotoXY(enemy.loc1.X, enemy.loc1.Y + 3);
	cout << "  '--'     " << endl;

}