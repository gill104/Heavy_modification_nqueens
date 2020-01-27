
//WORK ON PARENT SELECTION AND CHILDREN NEXT
#include<iostream>
#include<time.h>
#include<algorithm>
#include<vector>
#include<string>
#include<stdlib.h>
#include<sstream>

using namespace std;
#include "SettingPopulation.h"
#include "SettingParents.h"
#include "BuildingMap.h"
void makePopulation(vector<int>, vector<Human>&, vector<Human>&, vector<Human>&, int);
void parentSelection(vector<Human>, vector<Human>&, int);

int main()
{
	srand(time(NULL));

	int generations = 0;
	int Nsize = 0;
	bool gotIt = false;
	string stringFitness = "";
	double fitness = 0.0;

	vector<Human> pop;
	vector<Human> matingPool;//clean
	vector<Human> children;//clean
	vector<Human> mutatedChildren;//clean
	


	Nqueens m;
	cout << "what is your board size?";
	cin >> Nsize;

	Parents p(Nsize);
	m.setSizes(Nsize);

	vector<int> person;
	for (int x = 0; x < Nsize; x++)
	{
		person.push_back(x);
	}

	//Human* h = new Human(Nsize, pop, children, mutatedChildren);

	//loop here till i find the 1000.00
	while (generations < 1000)
	{
		
		makePopulation(person, pop, children, mutatedChildren, Nsize);
		cout << "Generation:" << generations << endl;
		m.addFitness(pop, stringFitness, fitness, gotIt);

		if (gotIt == true)
		{
			cout << "FOUND SOMETHING GOOD!" << endl;
			cout << generations << endl;
			system("pause");
			return 0;
		}
		parentSelection(pop, matingPool, Nsize);
		
		p.makingChildren(matingPool, children, Nsize);

		p.mutation(children, mutatedChildren);
	
		generations++;
	}
	system("pause");
	return 0;
}
void makePopulation(vector<int> person, vector<Human> &pop, vector<Human>& children, vector<Human>& mutatedChildren, int Nsize)
{
	if (!children.empty() || !mutatedChildren.empty())
	{
		//cout << "new generation " << endl;
		//system("pause");
		pop.clear();
		pop.shrink_to_fit();
		//population.shrink_to_fit();
	}
	Human h;
	h.setSize(Nsize);

	if (Nsize < 11)
	{
		for (int x = 0; x < 100; x++)
		{
			random_shuffle(person.begin(), person.end());//shuffles the numbers within the randpop (helper variables)
			h.setnum(person);

			pop.push_back(h);
		}
		/*delete h;*/
	}
	else
	{
		for (int x = 0; x < Nsize * 10; x++)
		{
			random_shuffle(person.begin(), person.end());//shuffles the numbers within the randpop (helper variables)
			h.setnum(person);

			pop.push_back(h);
		}
		/*delete h;*/
	}
	if (children.empty() || !mutatedChildren.empty())
	{
		//cout << "adding childrend and mutated" << endl;
		while (!children.empty())
		{
			pop.push_back(children.front());
			children.erase(children.begin());
		}
		while (!mutatedChildren.empty())
		{
			pop.push_back(mutatedChildren.front());
			mutatedChildren.erase(mutatedChildren.begin());
		}
	}
	
}

void parentSelection(vector<Human> population, vector<Human>& matingPool, int Nsize)
{
	int popSize = 0;
	if (Nsize < 11)
	{
		popSize = 100;
	}
	else
		popSize = Nsize * 10;

	double tenPercent = popSize * .10;
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
		string humanNum;//rename if needed

		for (int x = 0; x < 3; x++)
		{

			if (maxValue < threeChosen.front().getfit())
			{
				maxValue = threeChosen.front().getfit();
				best.clear();
				best.push_back(threeChosen.front());
				threeChosen.erase(threeChosen.begin());
			}
			else
			{
				threeChosen.erase(threeChosen.begin());
			}
		}
		maxValue = 0.0;

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
