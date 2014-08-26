// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include "Framework\timer.h"
#include "menu.h"
#include "options.h"
#include "global.h"

//counters for paw
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

//counters for item
int counter13 = 0;
int counter14 = 0;
int counter15 = 0;
int counter16 = 0;
int counter17 = 0;
int counter18 = 0;
int counter19 = 0;
int counter20 = 0;
int counter21 = 0;

//counters for item effect
int counter22 = 0;
int counter23 = 0;

//checkers for item pickup
int checker1 = 0;
int checker2 = 0;
int checker3 = 0;

//checkers for item effect
int checker4 = 0;
int checker5 = 0;

//variables
int life = 30;
double score;
double elapsedTime;
double deltaTime;
bool keyPressed[K_COUNT];
COORD charLocation;
COORD consoleSize;

//objects
claw paw1;
claw paw2;
claw paw3;
claw paw4;
tail tail1;
tail tail2;
item pickup1;
item pickup2;
item pickup3;

//extra functions that will be useful for game over situations
void gameLoop();	 // menu loop
void gameLoop2();    // options loop

void init()
{
	// Set precision for floating point output
	cout << std::fixed << std::setprecision(1);

	SetConsoleTitle(L"Laser Cat");

	// Sets the console size
	setConsoleSize(70, 30);

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

	//set item location and ID
	pickup1.loc.X = 0;
	pickup1.loc.Y = 0;
	pickup1.ID = 1;

	pickup2.loc.X = 0;
	pickup2.loc.Y = 0;
	pickup2.ID = 2;

	pickup3.loc.X = 0;
	pickup3.loc.Y = 0;
	pickup3.ID = 3;





	//set seed for rand() as the time program is launched
	srand( time( NULL ) );

	//set elapsed time to 0
	elapsedTime = 0.0;

	score = 0.0;
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

	//get score
	if (checker4 == 0)
	{
		score += dt;
	}

	else
	{
		score += dt + 1;
	}


	// Updating the location of the character based on the key press and creating deadspace
	// this deadspace belongs to the cat at the middle
	if (checker4 == 0)
	{
		if (keyPressed[K_UP] && charLocation.Y > 0)
		{
			int b = 0;
			for (int i = 0; i < 13; ++i)
			{

				if (charLocation.X != (consoleSize.X / 2 + i - 10) && charLocation.Y-1 != consoleSize.Y / 2 + 2)
				{
					b = 1;
				}	
				else if(charLocation.X != (consoleSize.X / 2 + i - 10) || charLocation.Y-1 != consoleSize.Y / 2  +2)
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

				if (charLocation.X != (consoleSize.X / 2 + i - 10) && charLocation.Y+1 != consoleSize.Y / 2 - 8)
				{
					b = 1;
				}	
				else if(charLocation.X != (consoleSize.X / 2 + i - 10) || charLocation.Y+1 != consoleSize.Y / 2 - 8)
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
				if (charLocation.X+1 != (consoleSize.X / 2 - 10) && charLocation.Y != consoleSize.Y / 2 + 2 - a)
				{
					b = 1;
				}	
				else if(charLocation.X+1 != (consoleSize.X / 2 - 10) || charLocation.Y != consoleSize.Y / 2 + 2 - a)
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


	}

	else
	{
		counter22 += 1;

		if (counter22 >= 14)
		{
			counter22 = 0;
			checker4 = 0;
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

	//set random paw spawn location
	paw(counter, counter2, counter3, paw1);
	paw(counter4,counter5,counter6,paw2);
	paw(counter7,counter8,counter9,paw3);
	paw(counter10,counter11,counter12,paw4);

	//set random item spawn location
	pickup (counter13, counter14, counter15, pickup1);
	pickup (counter16, counter17, counter18, pickup2);
	pickup (counter19, counter20, counter21, pickup3);

	//cause item effect
	pickupeffect (pickup1);
	pickupeffect (pickup2);
	pickupeffect (pickup3);

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


	//render deadspace
	string deadspace;

	std::ifstream deadspacetext;
	deadspacetext.open ("deadspace.txt");

	while (!deadspacetext.eof())
	{
		for (int i = 7; i >= -2; --i)
		{
			getline(deadspacetext,deadspace);
			colour(0x0B);
			gotoXY(consoleSize.X / 2 - 8 ,consoleSize.Y / 2 - i);
			cout << deadspace << endl;
		}
	}

	deadspacetext.close();




	//render score
	gotoXY(56, 0);
	colour(0x1A);
	cout << "Score: " << (int)score << endl;
	
	
	

	//render health
	gotoXY(0, 0);
	colour(0x1B);
	cout << "Health: " << life << endl;

	// render character
	string character;

	std::ifstream charactertext;
	charactertext.open ("character.txt");

	while (!charactertext.eof())
	{
		for (int i = 0; i <= 1; ++i)
		{
			getline(charactertext,character);
			colour(0x0C);
			gotoXY(charLocation.X, charLocation.Y + i);
			cout << character << endl;
		}
	}

	charactertext.close();



	//render cat danger zone

	rendertail (tail1);
	rendertail (tail2);

	//render paw
	renderpaw (paw1);
	renderpaw (paw2);
	renderpaw (paw3);
	renderpaw (paw4);

	renderpickup (pickup1);
	renderpickup (pickup2);
	renderpickup (pickup3);
}

//function to spawn paws
void paw (int &count, int &count2, int &count3, claw &enemy)
{
	count += 1;
	count2 += 1;
	count3 += 1;
	
	
	if (elapsedTime <= 10)
	{
		if (count >= 18)
		{
			count -= 1000;
			
			//small warning circle
			enemy.loc1.X = rand() % 55 + 5;
			enemy.loc1.Y = rand() % 18 + 5;
		}

		if (count2 >= 22)
		{
			count2 -= 1000;
			//medium warning circle
			enemy.loc2.X = enemy.loc1.X -2;
			enemy.loc2.Y = enemy.loc1.Y;
		}

		if (count3 >= 26)
		{
			count = 0;
			count2 = 0;
			count3 = 0;
			//cat paw does dmg
			enemy.loc3.X = enemy.loc1.X - 3;
			enemy.loc3.Y = enemy.loc1.Y - 1;
		}
	}

	else if (elapsedTime <= 20)
	{
		if (count >= 15)
		{
			count -= 1000;
			enemy.loc1.X = rand() % 55 + 5;
			enemy.loc1.Y = rand() % 18 + 5;
		}

		if (count2 >= 19)
		{
			count2 -= 1000;
			enemy.loc2.X = enemy.loc1.X -2;
			enemy.loc2.Y = enemy.loc1.Y;
		}

		if (count3 >= 23)
		{
			count = 0;
			count2 = 0;
			count3 = 0;

			enemy.loc3.X = enemy.loc1.X - 3;
			enemy.loc3.Y = enemy.loc1.Y - 1;
		}
	}

	else if (elapsedTime <= 30)
	{
		if (count >= 12)
		{
			count -= 1000;
			enemy.loc1.X = rand() % 55 + 5;
			enemy.loc1.Y = rand() % 18 + 5;
		}

		if (count2 >= 15)
		{
			count2 -= 1000;
			enemy.loc2.X = enemy.loc1.X -2;
			enemy.loc2.Y = enemy.loc1.Y;
		}

		if (count3 >= 18)
		{
			count = 0;
			count2 = 0;
			count3 = 0;
			enemy.loc3.X = enemy.loc1.X - 3;
			enemy.loc3.Y = enemy.loc1.Y - 1;
		}
	}

	else if (elapsedTime <= 40)
	{
		if (count >= 9)
		{
			count -= 1000;
			enemy.loc1.X = rand() % 55 + 5;
			enemy.loc1.Y = rand() % 18 + 5;
		}

		if (count2 >= 12)
		{
			count2 -= 1000;
			enemy.loc2.X = enemy.loc1.X -2;
			enemy.loc2.Y = enemy.loc1.Y;
		}

		if (count3 >= 15)
		{
			count = 0;
			count2 = 0;
			count3 = 0;
			enemy.loc3.X = enemy.loc1.X - 3;
			enemy.loc3.Y = enemy.loc1.Y - 1;
		}
	}

	else if (elapsedTime <= 50)
	{
		if (count >= 6)
		{
			count -= 1000;
			enemy.loc1.X = rand() % 55 + 5;
			enemy.loc1.Y = rand() % 18 + 5;
		}

		if (count2 >= 9)
		{
			count2 -= 1000;
			enemy.loc2.X = enemy.loc1.X -2;
			enemy.loc2.Y = enemy.loc1.Y;
		}

		if (count3 >= 12)
		{
			count = 0;
			count2 = 0;
			count3 = 0;
			enemy.loc3.X = enemy.loc1.X - 3;
			enemy.loc3.Y = enemy.loc1.Y - 1;
		}
	}

	else if (elapsedTime <= 80)
	{
		if (count >= 3)
		{
			count -= 1000;
			enemy.loc1.X = rand() % 55 + 5;
			enemy.loc1.Y = rand() % 18 + 5;
		}

		if (count2 >= 5)
		{
			count2 -= 1000;
			enemy.loc2.X = enemy.loc1.X -2;
			enemy.loc2.Y = enemy.loc1.Y;
		}

		if (count3 >= 7)
		{
			count = 0;
			count2 = 0;
			count3 = 0;
			enemy.loc3.X = enemy.loc1.X - 3;
			enemy.loc3.Y = enemy.loc1.Y - 1;
		}
	}

	else 
	{
		if (count >= 1)
		{
			count -= 1000;
			enemy.loc1.X = rand() % 55 + 5;
			enemy.loc1.Y = rand() % 18 + 5;
		}

		if (count2 >= 2)
		{
			count2 -= 1000;
			enemy.loc2.X = enemy.loc1.X -2;
			enemy.loc2.Y = enemy.loc1.Y;
		}

		if (count3 >= 4)
		{
			count = 0;
			count2 = 0;
			count3 = 0;
			enemy.loc3.X = enemy.loc1.X - 3;
			enemy.loc3.Y = enemy.loc1.Y - 1;
		}
	}




}

//fuction to render paw
void renderpaw (claw &enemy)
{
	if (elapsedTime >= 4.5)
	{
		string Spaw;

		std::ifstream Spawtext;
		Spawtext.open ("Spaw.txt");

		while (!Spawtext.eof())
		{
			for (int i = 0; i <= 2; ++i)
			{
				getline(Spawtext,Spaw);
				colour(0x0E);
				gotoXY(enemy.loc1.X, enemy.loc1.Y + i);
				cout << Spaw << endl;
			}
		}

		Spawtext.close();

	}

	if (elapsedTime >= 4.7)
	{
		string Mpaw;

		std::ifstream Mpawtext;
		Mpawtext.open ("Mpaw.txt");

		while (!Mpawtext.eof())
		{
			for (int i = 0; i <= 3; ++i)
			{
				getline(Mpawtext,Mpaw);
				colour(0x0E);
				gotoXY(enemy.loc2.X, enemy.loc2.Y + i);
				cout << Mpaw << endl;
			}
		}

		Mpawtext.close();

	}

	if (elapsedTime >= 4.9)
	{
		string Lpaw;

		std::ifstream Lpawtext;
		Lpawtext.open ("Lpaw.txt");

		while (!Lpawtext.eof())
		{
			for (int i = 0; i <= 4; ++i)
			{
				getline(Lpawtext,Lpaw);
				colour(0x0E);
				gotoXY(enemy.loc3.X, enemy.loc3.Y + i);
				cout << Lpaw << endl;
			}
		}

		Lpawtext.close();

	}
}

//function to make paw deal damage
void damagepaw (claw &enemy)
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			for (int k = 0; k < 2; ++k)
			{
				for (int l = 0; l < 3; ++l)
				{

					if ( (charLocation.X + l == enemy.loc3.X + j) && (charLocation.Y + k == enemy.loc3.Y + i) )
					{
						Beep(3440, 100);
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

						//reset the game
						life = 30;
						gameLoop();
						gameLoop2();
					}
				}
			}
		}
	}
}

//function to make tail deal damage
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
						Beep(3440, 100);
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

						//reset game

						life = 30;
						score = 0;
						gameLoop();
						gameLoop2();
					}
				}
			}
		}
	}
}

//function to render tail
void rendertail (tail &enemy)
{
	string tail;

		std::ifstream tailtext;
		tailtext.open ("tail.txt");

		while (!tailtext.eof())
		{
			for (int i = 0; i <= 3; ++i)
			{
				getline(tailtext,tail);
				colour(0x0A);
				gotoXY(enemy.loc1.X, enemy.loc1.Y + i);
				cout << tail << endl;
			}
		}

	tailtext.close();
}

//function to spawn items
void pickup(int &count, int &count2, int &count3, item &bonus)
{
	count += 1;
	count2 += 1;
	count3 += 1;

	if (bonus.ID == 1 && count >= 75 && elapsedTime >= 15)
	{
		checker1 = 0;
		count = 0;
		bonus.loc.X = rand() % 63 + 3;
		bonus.loc.Y = rand() % 23 + 3;
	}

	if (bonus.ID == 2 && count2 >= 100 && elapsedTime >= 23)
	{
		checker2 = 0;
		count2 = 0;
		bonus.loc.X = rand() % 63 + 3;
		bonus.loc.Y = rand() % 23 + 3;
	}

	if (bonus.ID == 3 && count3 >= 140 && elapsedTime >= 31)
	{
		checker3 = 0;
		count3 = 0;
		bonus.loc.X = rand() % 63 + 3;
		bonus.loc.Y = rand() % 23 + 3;
	}

	if (checker1 == 1 && bonus.ID == 1)
	{
		bonus.loc.X = 0;
		bonus.loc.Y = 0;
	}

	if (checker2 == 1 && bonus.ID == 2)
	{
		bonus.loc.X = 0;
		bonus.loc.Y = 0;
	}

	if (checker3 == 1 && bonus.ID == 3)
	{
		bonus.loc.X = 0;
		bonus.loc.Y = 0;
	}
}


//function to render items
void renderpickup (item &bonus)
{
		string pickup;

		std::ifstream pickuptext;
		pickuptext.open ("item.txt");

		while (!pickuptext.eof())
		{
				getline(pickuptext,pickup);
				
				if (bonus.ID == 1 && elapsedTime >= 15  && checker1 == 0)
				{
					colour(0x0A);
					gotoXY(bonus.loc);
					cout << pickup << endl;
				}
				else if (bonus.ID == 2 && elapsedTime >= 23 && checker2 == 0)  
				{
					colour(0x0D);
					gotoXY(bonus.loc);
					cout << pickup << endl;
				}
				else if (bonus.ID == 3 && elapsedTime >= 31 && checker3 == 0)
				{
					colour(0x0C);
					gotoXY(bonus.loc);
					cout << pickup << endl;
				}

		pickuptext.close();
	}
}

void pickupeffect (item &bonus)
{
	for (int k = 0; k < 2; ++k)
	{
		for (int l = 0; l < 3; ++l)
		{
			if ( (charLocation.X + l == bonus.loc.X) && (charLocation.Y + k == bonus.loc.Y) )
			{
				Beep(4440, 100);

				if (bonus.ID == 1)
				{
					life += 10;
					checker1 = 1;
					counter13 = 0;
				}

				if (bonus.ID == 2)
				{
					checker5 = 1;
					checker2 = 1;
					counter16 = 0;
				}

				if (bonus.ID == 3)
				{
					checker4 = 1;
					checker3 = 1;
					counter19 = 0;
				}
			}
		}
	}
}