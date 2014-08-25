#include "global.h"
#include "game.h"
#include "Framework\timer.h"
#include "game.cpp"


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
//to change to txt file..would be best..
void renderpaw (claw &enemy)
{
	if (elapsedTime >= 4.5)
	{
		gotoXY(enemy.loc1.X, enemy.loc1.Y);
		colour(0x0E);
		cout << "  * ";
		gotoXY(enemy.loc1.X, enemy.loc1.Y + 1);
		cout << "*   *";
		gotoXY(enemy.loc1.X, enemy.loc1.Y + 2);
		cout << "  * ";
	}
	if (elapsedTime >= 4.7)
	{

		gotoXY(enemy.loc2.X, enemy.loc2.Y);
		colour(0x0E);
		cout << "  *  *";
		gotoXY(enemy.loc2.X, enemy.loc2.Y + 1);
		cout << "*      *";
		gotoXY(enemy.loc2.X, enemy.loc2.Y+2);
		cout << "*      *";
		gotoXY(enemy.loc2.X, enemy.loc2.Y+3);
		cout << "  *  *";
	}

	if (elapsedTime >= 4.9)
	{
		gotoXY(enemy.loc3.X, enemy.loc3.Y);
		colour(0x0E);
		cout << "   h  h" ;
		gotoXY(enemy.loc3.X, enemy.loc3.Y+1);
		cout << " h(\")(\")h";
		gotoXY(enemy.loc3.X, enemy.loc3.Y+2);
		cout << "(\"),--.(\")";
		gotoXY(enemy.loc3.X, enemy.loc3.Y+3);
		cout << " :\"    \";";
		gotoXY(enemy.loc3.X, enemy.loc3.Y+4);
		cout << " `.____,'";

	}
}

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
