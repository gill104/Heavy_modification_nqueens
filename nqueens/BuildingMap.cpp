using namespace std;

#include <string>
#include <vector>
#include <iostream>

#include "SettingPopulation.h";
#include "BuildingMap.h";

Nqueens::Nqueens()
{
	_row = _col = 0;
}
Nqueens::~Nqueens()
{
	delete[] _map;
}
void Nqueens::deleteMap() {
	for (int x = 0; x < _row; x++) {
		delete[] _map[x];
	}
	delete[] _map;
}
void Nqueens::setSizes(int s)
{
	_row = _col = s;
}

void Nqueens::makeMap()
{
	_map = new string * [_row];
	for (int i = 0; i < _row; i++)
	{
		_map[i] = new string[_col];
	}

	for (int x = 0; x < _row; x++)
	{
		for (int y = 0; y < _col; y++)
		{
			_map[x][y] = "[ ]";
		}
	}
}

void Nqueens::display()
{
	for (int x = 0; x < _row; x++)
	{
		for (int y = 0; y < _col; y++)
		{
			cout << _map[x][y];
		}
		cout << endl;
	}
}

void Nqueens::addFitness(vector<Human>& pop, string stringFitness, double fitness, bool& gotIt)
{
	string fitString = "";

	for (int x = 0; x < pop.size(); x++)//loops through the unfitted population and saves into new vector WITH fitness
	{
		if (pop[x].getnum().size() != _row)
		{
			cout << "Faulty number" << fitString.size() << endl;
			cout << "Human num: ";
			pop[x].displayNum();
			cout << "human fit: " << pop[x].getfit() << endl;
			system("pause");
		}

		fitness = 1 / (this->checkFitness(pop[x].getnum()) + .001);		//fitness FUNCTION

		pop[x].setfit(fitness);

		if (fitness == 1000)
		{
			this->display();
			pop[x].displayNum();
			cout << pop[x].getfit() << endl;
			gotIt = true;
			return;
		}
		else
		{
			deleteMap();
		}
	}
}
double Nqueens::checkFitness(vector<int> passedValue)
{
	makeMap();
	int location = 0;
	int counter = 0;
	double fitness = 0;
	int sizeOFPassedString = 0;

	
	//cout << sizeOFPassedString << endl;
	for (int x = 0; x < passedValue.size(); x++)
	{
		location = passedValue[x];
		putInMap(location, counter);
		//system("pause");
		counter++;
		location = 0;
	}
	//this->display();
	//cout << endl;
	for (int x = 0; x < _row; x++)
	{
		for (int y = 0; y < _col; y++)
		{
			if (_map[x][y] == "[&]")//reversed X and Y to check top down, left right for queens
			{
				//cout << "we found a QUEEN!" << endl;
				//cout << "Location X: " << x << "\nLocation Y:" << y << endl;

				fitness += checkNE(x, y);
				fitness += checkSE(x, y);
				fitness += checkNW(x, y);
				fitness += checkSW(x, y);
			}
		}

	}

	//this->display();
///////cout << "thirness of this is " << 1 / (fitness + .001) << endl;
		//cout << "string: " << passedString << " with a fitness of : " << fitness << endl;
	return fitness;

	//system("pause");
}

int Nqueens::checkNE(int xPassed, int yPassed)
{
	for (int x = xPassed; x < _row;)//checking for NE diagnol
	{
		for (int y = yPassed; y < _col;)
		{
			x--;
			y++;
			if (x < 0 || y > _row - 1)
			{
				return 0;
			}
			else
			{
				if (_map[x][y] == "[&]")
				{
					//	cout << "Found a Confilct!";
					//	system("pause");
					return 1;
				}
			}
		}
	}
}
int Nqueens::checkSE(int xPassed, int yPassed)
{
	for (int x = xPassed; x < _row;)//checking for NE diagnol
	{
		for (int y = yPassed; y < _col;)
		{
			x++;
			y++;
			if (x > _row - 1 || y > _row - 1)
			{
				return 0;
			}
			else
			{
				if (_map[x][y] == "[&]")
				{
					//	cout << "Found a Confilct!";
					//system("pause");
					return 1;
				}
			}
		}
	}
}
int Nqueens::checkSW(int xPassed, int yPassed)
{
	for (int x = xPassed; x < _row;)//checking for NE diagnol
	{
		for (int y = yPassed; y < _col;)
		{
			x++;
			y--;
			if (x > _row - 1 || y < 0)
			{
				return 0;
			}
			else
			{
				if (_map[x][y] == "[&]")
				{
					//cout << "Found a Confilct!";
					//system("pause");
					return 1;
				}
			}
		}
	}
}
int Nqueens::checkNW(int xPassed, int yPassed)
{
	for (int x = xPassed; x < _row;)//checking for NE diagnol
	{
		for (int y = yPassed; y < _col;)
		{
			x--;
			y--;
			if (x < 0 || y < 0)
			{
				return 0;
			}
			else
			{
				if (_map[x][y] == "[&]")
				{
					//cout << "Found a Confilct!";
					//system("pause");
					return 1;
				}
			}
		}
	}
}
void Nqueens::putInMap(int location, int counter)
{
	//int num = stoi(Location);

	if (location < _row && counter < _row)
	{
		_map[location][counter] = "[&]";
				
	}
}