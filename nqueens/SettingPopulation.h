#ifndef SETTINGPOPULATION_H
#define SETTINGPOPULATION_H
#pragma once
class Human
{
	private:
		vector<int> _number;
		double _fitness;
		int _size;
	public:
		Human();
		~Human();
		Human(string _number, double _fitness);
		//Human(int Nsize, vector<Human>& population);
		//Human(int Nsize, vector<Human>& population,vector<Human>& children, vector<Human>& mutatedChildren);
		void createHuman(vector<Human> &population);
		void eraseNum();
		void eraseFit();
		void setnum(vector<int> n);
		void setfit(double f);
		int getSize();
		void setSize(int s);
		vector<int> getnum();//pushes each character of the string in
		string getNumTotal();//get the total num, from start to finish (length)
		double getFitTotal();//gets the total length of fitness, stores in a vector
		double getfit();//pushes each integer of fitness in
		void displayNum();//shows the total num on the screen all string
		void displayFit();//show the total fitness on screen all numbers

		int populationSize(int Nsize);
		void parentSelection(vector<Human> fitnessPop, vector<Human>& matingPool, int Nsize);
};

class  compareFitness
{
	public:
		bool operator() (Human f, Human g);
};
#endif