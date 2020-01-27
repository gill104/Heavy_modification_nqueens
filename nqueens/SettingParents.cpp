#include <string>
#include <vector>
#include <iostream>
#include<algorithm>
using namespace std;
#include "SettingPopulation.h"
#include "SettingParents.h"

Parents::Parents(int s)
{
	this->_nSize = s;
}
Parents::~Parents()
{

}
void Parents::makingChildren(vector<Human> &matingPool, vector<Human>& children, int Nsize)
{
	vector<Human> paredParents;


	string c1String;

	string c2String;
	char  p1randCharacter = ' ';
	char p2randCharacter = ' ';
	int matingPoolSize = matingPool.size();
	Human parent1;
	Human parent2;

	vector<string> Vptemp;
	vector<string> V2ptemp;
	string p1temp;
	string p2temp;

	for (int x = 0; x < matingPoolSize / 2; x++)
	{
		parent1 = matingPool.front();
		matingPool.erase(matingPool.begin());
		parent2 = matingPool.front();
		matingPool.erase(matingPool.begin());



		int randomLocationGenotypeC1 = 0;
		int randomLocationGenotypeC2 = 0;
		//starting crossover
		//these ensure i get a number in the string, since the numbers are on even intervoles stored as "1 2 3 4 5 6"
		randomLocationGenotypeC1 = rand() % (Nsize - 2) + 2;//will cuase to have something to snip
		p1randCharacter = parent1.getnum()[randomLocationGenotypeC1];

		randomLocationGenotypeC2 = rand() % (Nsize - 2) + 2;//will have something to snip
		p2randCharacter = parent2.getnum()[randomLocationGenotypeC2];


		Human child1;
		Human child2;

		vector<int> newChild1;
		vector<int> newChild2;

		int c1Counter = 0;
		int targetChar1 = parent1.getnum()[randomLocationGenotypeC1];
		while (parent1.getnum()[c1Counter] != targetChar1)
		{
			newChild1.push_back(parent1.getnum()[c1Counter]);
			c1Counter++;
			
		}

		int c2Counter = 0;
		int targetChar2 = parent2.getnum()[randomLocationGenotypeC2];
		while (parent2.getnum()[c2Counter] != targetChar2)
		{
			newChild2.push_back(parent2.getnum()[c2Counter]);
			c2Counter++;
		}


		vector<int> tempVector1;
		vector<int> tempVector2;

		for (int i = 0; i < parent1.getSize(); i++)
		{
			tempVector1.push_back(parent1.getnum()[i]);
		}
		for (int i = 0; i < parent2.getSize(); i++)
		{
			tempVector2.push_back(parent2.getnum()[i]);
		}

		mixParentGene(tempVector1, newChild2, parent1, child1);

		mixParentGene(tempVector2, newChild1, parent2, child2);
		
		
	/*	if (child1.getnum().size() != this->_nSize)
		{
			cout << "Making child Wrong Size" << endl;
		}
		if (child2.getnum().size() != this->_nSize)
		{
			cout << "Making child2 Wrong Size" << endl;
		}*/
		children.push_back(child1);
		children.push_back(child2);

		tempVector1.clear();
		tempVector2.clear();

	}

}
void Parents::mixParentGene(vector<int> tempVector, vector<int> newChild, Human parent, Human &child)
{
	vector<int> added;
	bool found = false;
	for (int j=0; j < tempVector.size();)
	{
		for (int k = 0;  k < newChild.size(); k++)
		{
			
			if (newChild[k] == tempVector[j])
			{
				tempVector.erase(tempVector.begin() );
				//j++;
				found = true;
				break;
			}
		}
		if (!found) {
			added.push_back( tempVector[j]);
			tempVector.erase(tempVector.begin()+j);
		}
		else
		{
			found = false;
		}
		
	}
	while (!added.empty())
	{
		newChild.push_back(added.front());
		added.erase(added.begin());
	}
	child.setnum(newChild);
	
	if (child.getnum().size() != this->_nSize)
	{
		cout << "Child Size: " << child.getnum().size() << endl;
		cout << "Needed: " << this->_nSize << endl;
		cout << "Mixing Child Wrong Size!!!" << endl;
	}
	tempVector.clear();
}

void Parents::mutation(vector<Human>& child, vector<Human>& mut)
{
	int position1 = 0;
	int position2 = 0;
	int willItMutate = 0;

	char a = ' '; 
	char b = ' ';
	

	willItMutate = rand() % 100;

	int totalChildren = child.size();
	while(!child.empty())
	{
		
		willItMutate = rand() % 100;

		if (willItMutate < 10)
		{
			//cout << "Chosen Child: " << child.front().getnum() << endl;
			

			position1 = rand() % (child.front().getnum().size());
			position2 = rand() % (child.front().getnum().size());
			
			//cout << "p1: " << position1 << endl;
			//cout << "p2: " << position2 << endl;

			a = child.front().getnum()[position1];
			b = child.front().getnum()[position2];
			
			
			
	
			vector<int> mutatedA= child.front().getnum();
			mutatedA[position1] = b;
			child.front().setnum(mutatedA);

			vector<int> mutatedB = child.front().getnum();
			mutatedB[position2] = a;
			child.front().setnum(mutatedB);
			child.front().setSize(this->_nSize);

			a = ' ';
			b = ' ';

			if (child.front().getnum().size() != this->_nSize)
			{
				cout << "Mutating Gene size Wrong!!!" << endl;
			}

			mut.push_back(child.front());
			
			child.erase(child.begin());
		}
	}
}
