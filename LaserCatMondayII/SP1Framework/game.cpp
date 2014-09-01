// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include "Framework\timer.h"
#include "menu.h"
#include "options.h"
#include "global.h"
#include "highscore.h"
#include "difficulty.h"

//counters
vector<double> counter;

//checker
vector<int> checker;

//variables
int life;
double score;
double elapsedTime;
double deltaTime;
bool keyPressed[K_COUNT];
COORD charLocation;
COORD consoleSize;
int pawnumber;
int tailnumber;

void mainLoop();


//objects
claw paws[4];
tail tails[2];
item pickups[3];
deadzone deadspace[3];


//extra functions that will be useful for game over situations
void gameLoop();	 // menu loop
void gameLoop2();    // options loop

void init()
{
	// Set precision for floating point output
	cout << std::fixed << std::setprecision(1);

	SetConsoleTitle(L"Laser Cat");

	// Sets the console size
		setConsoleSize(63, 25);

	// Get console width and height
	CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */     

	/* get the number of character cells in the current buffer */ 
	GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi );
	consoleSize.X = csbi.srWindow.Right + 1;
	consoleSize.Y = csbi.srWindow.Bottom + 1;

	// set the character location
	if (check == 1)
	{
		charLocation.X = consoleSize.X / 2 - 4;
		charLocation.Y = consoleSize.Y / 2 ;
	}

	else
	{
		charLocation.X = consoleSize.X / 2 - 2;
		charLocation.Y = consoleSize.Y / 2 - 6 ;
	}

	//change difficulty
	if (check == 0)
	{
		pawnumber = 2;
		tailnumber = 1;
		life = 30;
		elapsedTime = 0.0;
	}

	else
	{
		pawnumber = 4;
		tailnumber = 2;
		life = 20;
		elapsedTime = 31.0;
	}


	// set the taillocation

	tails[0].loc1.X = 0;
	tails[0].loc1.Y = 2;

	tails[0].loc2.X = 0;
	tails[0].loc2.Y = 2;
	
	
	
	if (check == 1)
	{
		tails[1].loc1.X = 46;
		tails[1].loc1.Y = 18;

		tails[1].loc2.X = 46;
		tails[1].loc2.Y = 18;
	}

	//set paw locations
	for (int i = 0; i < pawnumber; ++i)
	{
		paws[i].loc1.X = 0;
		paws[i].loc1.Y = 0;
		paws[i].loc2.X = 0;
		paws[i].loc3.X = 0;
		paws[i].loc3.Y = 0;
	}

	//set item location and ID
	for (int i = 0; i < 3; ++i)
	{
		pickups[i].loc.X = 0;
		pickups[i].loc.Y = 0;
		pickups[i].ID = 1 + i;
	}

	//set deadspace location & ID
	if (check == 0)
	{
		deadspace[2].loc.X = 27;
		deadspace[2].loc.Y = 7;
		deadspace[2].ID = 3;
	}

	else
	{
		deadspace[0].loc.X = 13;
		deadspace[0].loc.Y = 7;
		deadspace[0].ID = 1;

		deadspace[1].loc.X = 35;
		deadspace[1].loc.Y = 7;
		deadspace[1].ID = 2;
	}

		

	//set seed for rand() as the time program is launched
	srand( time( NULL ) );

	//set score
	score = 0.0;

	counter.clear();
	checker.clear();

	//initialise counters
	for (int i = 0; i < 23; ++i)
	{
		counter.push_back(0);
	}

	//initialise checkers
	for (int i = 0; i < 8; ++i)
	{
		checker.push_back(0);
	}


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
	keyPressed[K_SPACE] = isKeyPressed(VK_SPACE);
}
void update(double dt)
{
	// get the delta time
	elapsedTime += dt;
	deltaTime = dt;

	//get score
	if (checker[3] == 0 && check == 0)
	{
		score += dt;
	}

	else if (checker[3] == 0 && check == 1)
	{
		score += dt + 0.2;
	}

	else if (checker[3] == 1 && check == 0)
	{
		score += dt + 1;
	}

	else 
	{
		score += dt + 1.2;
	}


	// Updating the location of the character based on the key press
	if (checker[3] == 0)
	{
		if (checker[4] == 0)
		{
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
		}

		else
		{
			if (keyPressed[K_UP] && charLocation.Y > 0)
			{
				Beep(1440, 30);
				charLocation.Y-=2; 
			}
			if (keyPressed[K_LEFT] && charLocation.X > 0)
			{
				Beep(1440, 30);
				charLocation.X-=2; 
			}
			if (keyPressed[K_DOWN] && charLocation.Y < consoleSize.Y - 1)
			{
				Beep(1440, 30);
				charLocation.Y+=2; 
			}
			if (keyPressed[K_RIGHT] && charLocation.X < consoleSize.X - 1)
			{
				Beep(1440, 30);
				charLocation.X+=2; 
			}
		}

	}
	//prevents player from moving
	else
	{
		counter[21] += 1;

		if (counter[21] >= 14)
		{
			counter[21] -= counter[21];
			checker[3] = 0;
		}
	}

	

	//for the dynamic movement of tail1

		if( ((tails[0].loc1.Y - tails[0].loc2.Y) != 18) && (tails[0].loc1.X == tails[0].loc2.X))
		{
			tails[0].loc1.Y++;
		}
		else if ( ((tails[0].loc1.X - tails[0].loc2.X) != 46) && (tails[0].loc1.Y != tails[0].loc2.Y))
		{
			tails[0].loc1.X +=2;
		}
		else if (tails[0].loc1.Y != tails[0].loc2.Y)
		{
			tails[0].loc1.Y--;
		}
		else if (tails[0].loc1.X != tails[0].loc2.X)
		{
			tails[0].loc1.X -=2;
		}

	
		//for the dynamic movement of tail2
		if (check == 1)
		{
			if( ((tails[1].loc1.Y + tails[1].loc2.Y) != 20) && (tails[1].loc1.X == tails[1].loc2.X))
			{
				tails[1].loc1.Y--;
			}
			else if ( ((tails[1].loc1.X + tails[1].loc2.X) != 46) && (tails[1].loc1.Y != tails[1].loc2.Y))
			{
				tails[1].loc1.X-=2;
			}
			else if (tails[1].loc1.Y != tails[1].loc2.Y)
			{
				tails[1].loc1.Y++;
			}
			else if (tails[1].loc1.X != tails[1].loc2.X)
			{
				tails[1].loc1.X+=2;
			}
		}



	if (checker[4] == 0)
	{
		//set conditions of losing life (tail)
		for (int i = 0; i < tailnumber; ++i)
		{
			damagetail (tails[i]); 
		}

		//set conditions of losing life (paw)
		for (int i = 0; i < pawnumber; ++i)
		{
			damagepaw (paws[i]);
		}
	}
	//prevents player from losing life
	else
	{
		counter[22] += 1;

		if (counter[22] >= 20)
		{
			counter[22] -= counter[22];
			checker[4] = 0;
		}
	}


	//set random paw spawn location
	int pawC1 = 0, pawC2 = 1, pawC3 = 2;
	for (int i = 0; i < pawnumber; ++i)
	{
		paw(counter[pawC1], counter[pawC2], counter[pawC3], paws[i]);

		pawC1 += 3;
		pawC2 += 3;
		pawC3 += 3;
	}
	
	//set random item spawn location
	int itemC1 = 12, itemC2 = 13, itemC3 = 14;
	for (int i = 0; i < 3; ++i)
	{
		pickup (counter[itemC1], counter[itemC2], counter[itemC3], pickups[i]);

		itemC1 += 3;
		itemC2 += 3;
		itemC3 += 3;
	}

	//cause item effect
	int pickC1 = 12, pickC2 = 13, pickC3 = 14;
	for (int i = 0; i < 3; ++i)
	{
		pickupeffect (counter[pickC1], counter[pickC2], counter[pickC3], pickups[i]);

		pickC1 += 3;
		pickC2 += 3;
		pickC3 += 3;
	}

	//cause deadspace to alter movement
	if (check == 0)
	{
		deadspace_effect (deadspace[2]);
	}

	else
	{
		deadspace_effect (deadspace[0]);
		deadspace_effect (deadspace[1]);
	}
	


	// quits the game if player hits the escape key
	if (keyPressed[K_ESCAPE])
	{
		Beep (1350,150);
		gotoXY (0,25);
		colour (0x02);
		cout << "Returning to main menu . . ." << endl;
		system ("pause");
		init();
		gameLoop();
	}
}

void render()
{
	// clear previous screen
	colour(0x0F);
	cls();

	//render deadspace
	if (check == 0)
	{
		draw_object ("deadspace.txt", 0x0B, deadspace[2].loc.X, deadspace[2].loc.Y);
	}

	else
	{
		draw_object ("deadspace.txt", 0x0B, deadspace[0].loc.X, deadspace[0].loc.Y);
		draw_object ("deadspace.txt", 0x0B, deadspace[1].loc.X, deadspace[1].loc.Y);
	}

	//render score
	if (charLocation.Y == 24)
	{
		gotoXY(54, 1);
		colour(0x1A);
		cout << "Score: " << (int)score << endl;
	}
	else if (charLocation.Y == 25)
	{
		gotoXY(54, 2);
		colour(0x1A);
		cout << "Score: " << (int)score << endl;
	}
	else
	{
		gotoXY(54, 0);
		colour(0x1A);
		cout << "Score: " << (int)score << endl;
	}



	//render health
	if (charLocation.Y == 24)
	{
		gotoXY(0, 1);
		colour(0x1B);
		cout << "Health: " << life << endl;
	}

	else if (charLocation.Y == 25)
	{
		gotoXY(0, 2);
		colour(0x1B);
		cout << "Health: " << life << endl;
	}
	else
	{
		gotoXY(0, 0);
		colour(0x1B);
		cout << "Health: " << life << endl;
	}


	// render character
	if (checker[4] == 0)
	{
		draw_object ("character.txt", 0x0C, charLocation.X, charLocation.Y);
	}
	//create a blinking effect
	else
	{
		if (static_cast<int>(counter[22]) % 2 != 0)
		{
			draw_object ("character.txt", 0x0C, charLocation.X, charLocation.Y);
		}
	}

	//render tail
	for (int i = 0; i < tailnumber; ++i)
	{
		draw_object ("tail.txt", 0x0A, tails[i].loc1.X,  tails[i].loc1.Y);
	}

	//render paw
	for (int i = 0; i < pawnumber; ++i)
	{
		renderpaw (paws[i]);
	}

	//render items
	for (int i = 0; i < 3; ++i)
	{
		renderpickup (pickups[i]);
	}

}

//function to spawn paws
void paw (double &count, double &count2, double &count3, claw &enemy)
{
	count += 1;
	count2 += 1;
	count3 += 1;
	
	
	if (elapsedTime <= 10)
	{
		if (count >= 18 && elapsedTime >= 4.5)
		{
			count -= 1000;
			
			//small warning circle
			enemy.loc1.X = rand() % 53 + 5;
			enemy.loc1.Y = rand() % 16 + 1;
		}

		if (count2 >= 22 && elapsedTime >= 4.7)
		{
			count2 -= 1000;
			//medium warning circle
			enemy.loc2.X = enemy.loc1.X -2;
			enemy.loc2.Y = enemy.loc1.Y;
		}

		if (count3 >= 26 && elapsedTime >= 4.9)
		{
			count = 0;
			count2 = 0;
			count3 = 0;
			//catpaw
			enemy.loc3.X = enemy.loc1.X - 3;
			enemy.loc3.Y = enemy.loc1.Y - 1;
		}
	}

	else if (elapsedTime <= 20)
	{
		if (count >= 15)
		{
			count -= 1000;
			enemy.loc1.X = rand() % 53 + 5;
			enemy.loc1.Y = rand() % 16 +1;
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
			enemy.loc1.X = rand() % 53 + 5;
			enemy.loc1.Y = rand() % 16 + 1;
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
		if (check == 1)
		{
			if (count >= 9 && elapsedTime >= 35.5)
			{
				count -= 1000;
				enemy.loc1.X = rand() % 53 + 5;
				enemy.loc1.Y = rand() % 16 + 1;
			}

			if (count2 >= 12 && elapsedTime >= 35.7)
			{
				count2 -= 1000;
				enemy.loc2.X = enemy.loc1.X -2;
				enemy.loc2.Y = enemy.loc1.Y;
			}

			if (count3 >= 15 && elapsedTime >= 35.9)
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
			if (count >= 9)
			{
				count -= 1000;
				enemy.loc1.X = rand() % 53 + 5;
				enemy.loc1.Y = rand() % 16 + 1;
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

	}

	else if (elapsedTime <= 50)
	{
		if (count >= 6)
		{
			count -= 1000;
			enemy.loc1.X = rand() % 53 + 5;
			enemy.loc1.Y = rand() % 16 + 1;
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
			enemy.loc1.X = rand() % 53 + 5;
			enemy.loc1.Y = rand() % 16 + 1;
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
			enemy.loc1.X = rand() % 53 + 5;
			enemy.loc1.Y = rand() % 16 + 5;
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
	if (check == 0)
	{
		if (elapsedTime >= 4.7)
		{
			draw_object ("Spaw.txt", 0x0E, enemy.loc1.X,  enemy.loc1.Y);
		}

		if (elapsedTime >= 4.9)
		{
			draw_object ("Mpaw.txt", 0x0E, enemy.loc2.X,  enemy.loc2.Y);
		}

		if (elapsedTime >= 5.1)
		{
			draw_object ("Lpaw.txt", 0x0E, enemy.loc3.X,  enemy.loc3.Y);
		}
	}

	else
	{
		if (elapsedTime >= 35.5)
		{
			draw_object ("Spaw.txt", 0x0E, enemy.loc1.X,  enemy.loc1.Y);
		}

		if (elapsedTime >= 35.7)
		{
			draw_object ("Mpaw.txt", 0x0E, enemy.loc2.X,  enemy.loc2.Y);
		}

		if (elapsedTime >= 35.9)
		{
			draw_object ("Lpaw.txt", 0x0E, enemy.loc3.X,  enemy.loc3.Y);
		}
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

					if (life <= 0)
					{
						gameover();
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

					if (life <= 0)
					{
						gameover();
					}
				}
			}
		}
	}
}

//function to spawn items
void pickup(double &count, double &count2, double &count3, item &bonus)
{
	count += 1;
	count2 += 1;
	count3 += 1;

	if (check == 0)
	{
		if (bonus.ID == 1 && count >= 75 && elapsedTime >= 15)
		{
			checker[0] = 0;
			count -= count;
			bonus.loc.X = rand() % 62 + 3;
			bonus.loc.Y = rand() % 22 + 3;			
		}

		if (bonus.ID == 2 && count2 >= 100 && elapsedTime >= 23)
		{
			checker[1] = 0;
			count2 -= count2;
			bonus.loc.X = rand() % 62 + 3;
			bonus.loc.Y = rand() % 22 + 3;
		}

		if (bonus.ID == 3 && count3 >= 140 && elapsedTime >= 31)
		{
			checker[2] = 0;
			count3 -= count3;
			bonus.loc.X = rand() % 62 + 3;
			bonus.loc.Y = rand() % 22 + 3;
		}
	}

	else
	{
		if (bonus.ID == 1 && count >= 75 && elapsedTime >= 46)
		{
			checker[0] = 0;
			count -= count;
			bonus.loc.X = rand() % 62 + 3;
			bonus.loc.Y = rand() % 22 + 3;			
		}

		if (bonus.ID == 2 && count2 >= 100 && elapsedTime >= 54)
		{
			checker[1] = 0;
			count2 -= count2;
			bonus.loc.X = rand() % 62 + 3;
			bonus.loc.Y = rand() % 22 + 3;
		}

		if (bonus.ID == 3 && count3 >= 140 && elapsedTime >= 62)
		{
			checker[2] = 0;
			count3 -= count3;
			bonus.loc.X = rand() % 62 + 3;
			bonus.loc.Y = rand() % 22 + 3;
		}
	}

	if (checker[0] == 1 && bonus.ID == 1)
	{
		bonus.loc.X = 0;
		bonus.loc.Y = 0;
	}

	if (checker[1] == 1 && bonus.ID == 2)
	{
		bonus.loc.X = 0;
		bonus.loc.Y = 0;
	}

	if (checker[2] == 1 && bonus.ID == 3)
	{
		bonus.loc.X = 0;
		bonus.loc.Y = 0;
	}


}



//function to render items
void renderpickup (item &bonus)
{
	if (check == 0)
	{
		if (bonus.ID == 1 && elapsedTime >= 16  && checker[0] == 0)
		{
			draw_object ("item1.txt", 0x0A, bonus.loc.X,  bonus.loc.Y);
		}
		else if (bonus.ID == 2 && elapsedTime >= 24 && checker[1] == 0)  
		{
			draw_object ("item2.txt", 0x0D, bonus.loc.X,  bonus.loc.Y);
		}
		else if (bonus.ID == 3 && elapsedTime >= 33 && checker[2] == 0)
		{
			draw_object ("item3.txt", 0x0C, bonus.loc.X,  bonus.loc.Y);
		}
	}

	else
	{
		if (bonus.ID == 1 && elapsedTime >= 47  && checker[0] == 0)
		{
			draw_object ("item1.txt", 0x0A, bonus.loc.X,  bonus.loc.Y);
		}
		else if (bonus.ID == 2 && elapsedTime >= 55 && checker[1] == 0)  
		{
			draw_object ("item2.txt", 0x0D, bonus.loc.X,  bonus.loc.Y);
		}
		else if (bonus.ID == 3 && elapsedTime >= 64 && checker[2] == 0)
		{
			draw_object ("item3.txt", 0x0C, bonus.loc.X,  bonus.loc.Y);
		}
	}

}
//function to carry out item effects
void pickupeffect (double &count, double &count2, double &count3, item &bonus)
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
					score += 5;
					life += 10;

					if (life > 50)
					{
						life = 50;
					}

					checker[0] = 1;
					count -= count;
				}

				if (bonus.ID == 2)
				{
					score += 5;
					checker[1] = 1;
					checker[4] = 1;
					count2 -= count2;
				}

				if (bonus.ID == 3)
				{
					score += 5;
					checker[2] = 1;
					checker[3] = 1;
					count3 -= count3;
				}
			}
		}
	}
}
//function to read from text file
void draw_object(string sFile, WORD wColor, int ixStart, int iyStart)
{
	string buffer;

	int i = 0;

	ifstream ifile;

	ifile.open (sFile);

	colour(wColor);

	while (!ifile.eof())
	{
		getline(ifile, buffer);    

		gotoXY(ixStart, iyStart+i);

		cout << buffer << endl;

		i++; 

	}

	ifile.close(); 
}
//overloaded draw_object function that doesn't take in location
void draw_object(string sFile, WORD wColor)
{
	string buffer;

	ifstream ifile;

	ifile.open (sFile);

	colour(wColor);

	while (!ifile.eof())
	{
		getline(ifile, buffer);    

		cout << buffer << endl;
	}

	ifile.close(); 
}

//function to cause deadspace effects
void deadspace_effect (deadzone &enemy)
{
	if (checker[4] == 0)
	{
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				for (int k = 0; k < 2; ++k)
				{
					for (int l = 0; l < 3; ++l)
					{
						if ( (charLocation.X + l == enemy.loc.X + j) && (charLocation.Y + k == enemy.loc.Y + i) )
						{
							if (enemy.ID == 1)
							{
								charLocation.X++;
							}
							else if (enemy.ID == 2)
							{
								charLocation.X--;
							}
							else
							{
								charLocation.Y--;
							}
						}
					}
				}
			}
		}
	}
}
//function to display gameover screen
void gameover()
{
	cls();
	//show gameover screen
	draw_object ("dead.txt", 0x0C);
	colour(0x0A);
	highscore(score);

	cout << endl << "Enter 1 to replay" << endl;
	cout << "Enter 2 to return to Main Menu" << endl;

	int inputGO = 0;
	cin.clear();
	cin >> inputGO;
	//reset the game
	if (inputGO == 1)
	{
		Beep (2000,200);
		init();
		mainLoop();

	}
	if (inputGO == 2)
	{
		Beep (1350,150);
		init();
		gameLoop();
	}
}