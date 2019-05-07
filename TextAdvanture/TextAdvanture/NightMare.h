#pragma once
#include"Enemy.h"
class NightMare : public Enemy
{
public:
	NightMare(string name, int attack, int health, int armor);
	~NightMare();
	void attackTarget(Enemy* player);
private:
	int psywave;
	int psychoBoost;
	bool harden;
	bool heal;
};

