#pragma once
#include<string>
#include<vector>
#include<iostream>

using namespace std;
class Object
{
public:
	Object(string name);
	~Object();
	string getName();
	int getAttack();
	int getHeal();
	int getArmor();
	int getEnergy();
	bool getEuipment();
	void addContainer(Object* insertItem);
	vector<Object*> getContainer();

private:
	string name;
	int attack;
	int heal;
	int armor;
	int energy;
	bool equipment;
	vector<Object*> container;

};

