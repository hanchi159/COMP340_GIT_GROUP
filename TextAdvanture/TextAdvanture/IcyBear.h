#pragma once
#include"Enemy.h"
class IcyBear : public Enemy
{
public:
	IcyBear(string name, int attack, int health, int armor);
	~IcyBear();
	void attackTarget(Enemy* player);

private:
	int energy;
	int frozen;
	int kungfuPunch;
};

