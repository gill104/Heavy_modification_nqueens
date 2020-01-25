
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

	Human h(Nsize, pop);

	//loop here till i find the 1000.00
	while (generations < 1000)
	{
	
		cout << "Generation:" << generations << endl;
		m.addFitness(pop, stringFitness, fitness, gotIt);

		if (gotIt == true)
		{
			cout << "FOUND SOMETHING GOOD!" << endl;
			cout << generations << endl;
			system("pause");
			return 0;
		}
		h.parentSelection(pop, matingPool, Nsize);
		
		p.makingChildren(matingPool, children, Nsize);

		p.mutation(children, mutatedChildren);

		//delete h;
		Human h(Nsize, pop, children, mutatedChildren);
		generations++;
	}

	system("pause");
	return 0;
}