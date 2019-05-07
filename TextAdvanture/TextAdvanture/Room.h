#pragma once
#include"Object.h"
#include"FieryDragon.h"
#include"IcyBear.h"
#include"NightMare.h"
#include<algorithm>
class Room
{
public:
	Room(string name,string description);
	~Room();
	void addItem(Object* roomItem);
	void addEnemy(Enemy* roomEnemy);
	void printItems();
	void open(string box);
	string getName();
	string getDescription();
	Object* removeItem(string item);
	void removeEnemy();
	vector<Enemy*> getEnemies();
	std::vector<Object*> getObjects();
private:
	string name;
	string description;
	std::vector<Object*> objects;
	std::vector<Enemy*> enemies;
};

