#pragma once
#include"Enemy.h"
#include"Map.h"
class Adventurer:public Enemy
{
public:
	Adventurer(string name, int attack, int health, int armor,int energy);
	~Adventurer();
	void showInformation();
	void addItem(Object* item);
	void showInventory();
	void attackTarget(Enemy* target);
	void useItem(string itemUse);
	void combat(Room* targetRoom);
	bool getPortalKey();

private:
	int energy;
	int lighteningBall;
	int frozen;
	int fireBall;
	bool portalKey;
	vector<Object*> inventory;
};

