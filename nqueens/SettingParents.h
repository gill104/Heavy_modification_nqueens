#ifndef SETTINGPARENTS_H
#define SETTINGPARENTS_H
class Parents : public Human
{
private:
	int _nSize;
public:
	Parents(int s);
	~Parents();
	void makingChildren(vector<Human> &matingPool, vector<Human>& children, int Nsize);
	void mixParentGene(vector<int> tempVector1, vector<int> newChild1, Human parent1, Human &child);
	void mutation(vector<Human>& child, vector<Human>& mut);

};
#endif