using namespace std;

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "SettingPopulation.h"
Human::Human()
{

	_size = 0;
	_fitness = 0.0;
	_number.clear();
}
Human::~Human()
{

}
Human::Human(string _n, double _f)
{
	_size = stoi(_n);
	_fitness = _f;
}
Human::Human(int Nsize, vector<Human>& population)
{
	/*cout << "createPopulation" << endl;
	int tempC = 0;
	for (vector<Population * >::iterator it = population.begin(); it != population.end(); it++)
	{
		cout << tempC << ": createPopulation strings " << (*it)->getNumTotal() << endl;
		cout << tempC << ": createPopulation fitness " << (*it)->getFitTotal() << endl;
		tempC++;
	}
	system("pause");*/
	_size = Nsize;
	_number.clear();
	_fitness = 0.0;

	//random person being generated...by generating a string nSize and shuffles them to get randNum
	vector<int> randpop;
	
	for (int i = 0; i < Nsize; i++)//fills a helper vector with numbers 0 - Nsize
	{
		this->_number.push_back(i);
		//randpop.push_back(i);
	}

	//if board size is less than 10
	//create 100 humans for population with different
	//genes
	if (Nsize < 11)
	{
		for (int i = 0; i < 100; i++)//creates the population to given size
		{
			//p = new Population();
			createHuman(population);
	

		}
		//cout << "position value 2: " << population.front()->getnum().at(2) << endl;
		//system("pause");
		//for (vector<Population *>::iterator it = population.begin(); it != population.end(); it++)
		//{
		//	cout << (*it)->getnum() << endl;
		//	//system("pause");
		//}
	}
	else
	{
		//if number is greater than 10
		//we need 100 + x humans so 
		for (int i = 0; i < Nsize * 10; i++)//creates the population to given size
		{
			//p = new Population();
			//p = new Population();
			createHuman(population);

		}

		//for (vector<Population *>::iterator it = population.begin(); it != population.end(); it++)
		//{
		//	cout << (*it)->getnum() << endl;
		//	//system("pause");
		//}
	}

}
Human::Human(int Nsize, vector<Human>& population, vector<Human>& children, vector<Human>&mutatedChildren)
{
	population.clear();
	/*cout << "createPopulation" << endl;
	int tempC = 0;
	for (vector<Population * >::iterator it = population.begin(); it != population.end(); it++)
	{
		cout << tempC << ": createPopulation strings " << (*it)->getNumTotal() << endl;
		cout << tempC << ": createPopulation fitness " << (*it)->getFitTotal() << endl;
		tempC++;
	}
	system("pause");*/
	_size = Nsize;
	_number.clear();
	_fitness = 0.0;

	//random person being generated...by generating a string nSize and shuffles them to get randNum
	vector<int> randpop;
	for (int i = 0; i < Nsize; i++)//fills a helper vector with numbers 0 - Nsize
	{
		this->_number.push_back(i);
	}

	//if board size is less than 10
	//create 100 humans for population with different
	//genes
	if (Nsize < 11)
	{
		for (int i = 0; i < 100 - children.size() - mutatedChildren.size(); i++)//creates the population to given size
		{
			//p = new Population();
			createHuman(population);
		}
		std::sort(population.begin(), population.end(), compareFitness());
		//cout << "position value 2: " << population.front()->getnum().at(2) << endl;
		//system("pause");
		//for (vector<Population *>::iterator it = population.begin(); it != population.end(); it++)
		//{
		//	cout << (*it)->getnum() << endl;
		//	//system("pause");
		//}
	}
	else
	{
		//if number is greater than 10
		//we need 100 + x humans so 
		for (int i = 0; i < (Nsize * 10) - children.size() - mutatedChildren.size(); i++)//creates the population to given size
		{
			//p = new Population();
			//p = new Population();
			createHuman(population);

		}
		std::sort(population.begin(), population.end(), compareFitness());
		//for (vector<Population *>::iterator it = population.begin(); it != population.end(); it++)
		//{
		//	cout << (*it)->getnum() << endl;
		//	//system("pause");
		//}
	}
	while(!children.empty())
	{
		population.push_back(children.front());
		children.erase(children.begin());
	}
	while(!mutatedChildren.empty())
	{
		population.push_back(mutatedChildren.front());
		mutatedChildren.erase(mutatedChildren.begin());
	}
}
bool compareFitness::operator() (Human f, Human g)
{
	return f.getfit() > g.getfit();
}


void Human::createHuman(vector<Human> &population)
{
	random_shuffle(this->_number.begin(), this->_number.end());//shuffles the numbers within the randpop (helper variables)
	
	this->setnum(this->_number);

	if (this->getnum().size() != this->getSize())
	{
		cout << "WHAT!" << endl;
	}

	population.push_back(*this);//pushes this RANDOM (shuffled)	;
	
	if (this->getnum().size() != this->getSize())
	{
		cout << "bad human created" << endl;
	}
}
void Human::eraseNum()
{
	_number.clear();
}
void Human::eraseFit()
{
	_fitness = 0.0;
}
void Human::setnum(vector<int> n)
{
	this->_number = n;

}
void Human::setfit(double f)
{
	_fitness = f;
}
int Human::getSize()
{
	return _size;
}
void Human::setSize(int s)
{
	this->_size = s;
}
vector<int> Human::getnum()//pushes each character of the string in
{	
	return this->_number;
}
string Human::getNumTotal()//get the total num, from start to finish (length)
{
	/*string total = "";
	for (vector<string >::iterator iter = _number.begin(); iter != _number.end(); iter++)
	{
		total += (*iter);
		total += " ";
	}
	return total;*/
	return "";
}
double Human::getFitTotal()//gets the total length of fitness, stores in a vector
{
	/*double fitnessT = 0.0;
	for (vector<double>::iterator it = _fitness.begin(); it != _fitness.end(); it++)
	{
		fitnessT += ((*it));
	}
	return fitnessT;*/
	return 0.0;
}
double Human::getfit()//pushes each integer of fitness in
{
	/*vector<double> fitnessT;
	for (vector<double>::iterator it = _fitness.begin(); it != _fitness.end(); it++)
	{
		fitnessT.push_back((*it));
	}
	return fitnessT;*/
	return this->_fitness;
}
void Human::displayNum()//shows the total num on the screen all string
{
	string num = "";
	
	for(int x = 0; x < this->_number.size(); x++)
	{
		num += to_string(_number[x]);
		num += " ";
	}
	cout << num << endl;
	//system("pause");
}
void Human::displayFit()//show the total fitness on screen all numbers
{
	/*for (vector<double >::iterator it = _fitness.begin(); it != _fitness.end(); it++)
	{
		cout << (*it);
	}*/
	//system("pause");
}

int Human::populationSize(int Nsize)
{
	if (Nsize < 11)
	{
		return 100;
	}
	else
		return Nsize * 10;
}
void Human::parentSelection(vector<Human> population, vector<Human>& matingPool, int Nsize)
{
	double tenPercent = populationSize(Nsize) * .10;
	/////cout << "we need to get: " << tenPercent << endl;
	double maxValue = 0;

	vector<Human> threeChosen;
	vector<Human> best;

	int current = 0;
	int randomHuman = 0;


	while (current < tenPercent)
	{
		//p = new Population();

		for (int x = 0; x < 3; x++)//doing this with replacement not removing anything from parent pop;
		{
			randomHuman = rand() % population.size();
			threeChosen.push_back(population[randomHuman]);
		}

		//vector<string> t;
		//string e;
		//t = threeChosen.front()->getnum();
		//for (vector<string>::iterator it = t.begin(); it != t.end(); it++)//gets the total amount of items in unfitted population
		//{
		//	e += (*it);
		//	e += " ";
		//	cout << "e: " << e << endl;
		//	/*cout << "\nMating pool string: " << (*it)->getNumTotal() << endl;
		//	cout << "Mating pool fitness: " << (*it)->getFitTotal() << endl;*/
		//	system("pause");
		//}
		//cout << "at 1: " << t.at(1) << endl;
		//cout << "at 2: " << t.at(2) << endl;
		//cout << "at 3: " << t.at(3) << endl;
		//cout << "at 4: " << t.at(4) << endl;
		//system("pause");

		string humanNum;//rename if needed
	
		for (int x = 0; x < 3; x++)
		{

			if (maxValue < threeChosen.front().getfit() )
			{
				maxValue = threeChosen.front().getfit();
				best.clear();
				best.push_back(threeChosen.front());
				threeChosen.erase(threeChosen.begin());
				//p->eraseNum();
				//p->eraseFit();
				//for (vector<string >::iterator it = fitString.begin(); it != fitString.end(); it++)
				//{
				//	s = (*it);
				//	p->setnum(s);//makes sure each number is stored seprately
				//}
				//p->setfit(maxValue);
				//threeChosen.erase(threeChosen.begin());
			}
			else
			{
				threeChosen.erase(threeChosen.begin());
			}
		}


		maxValue = 0.0;

		//cout << "best out of the three: " << p->getNumTotal() << endl;
		//cout << "best out of the 3: " << p->getFitTotal() << endl;

		matingPool.push_back(best.front());
		threeChosen.clear();
		best.clear();
		current++;
	}

	if (matingPool.size() % 2 != 0)//ensures even parents
	{
		threeChosen.clear();
		randomHuman = rand() % population.size();
		threeChosen.push_back(population[randomHuman]);

		matingPool.push_back(threeChosen.front());
	}
	threeChosen.clear();
	best.clear();
}

