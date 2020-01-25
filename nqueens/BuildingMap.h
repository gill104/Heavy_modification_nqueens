#ifndef BUILDINGMAP_H
#define BUILDINGMAP_H
#pragma once
class Nqueens
{
private:
	int _row;
	int _col;
	string** _map;
	
public:
	Nqueens();

	~Nqueens();

	void setSizes(int s);
	void makeMap();
	void deleteMap();
	void display();
	void addFitness(vector<Human> &pop, string stringFitness, double fitness, bool& gotIt);
	double checkFitness(vector<int> passedValue);

	int checkNE(int xPassed, int yPassed);
	int checkSE(int xPassed, int yPassed);
	int checkSW(int xPassed, int yPassed);
	int checkNW(int xPassed, int yPassed);
	void putInMap(int location, int counter);
};


#endif