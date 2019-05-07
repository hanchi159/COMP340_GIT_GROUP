#pragma once
#include"Enemy.h"
class FieryDragon : public Enemy
{
public:
	FieryDragon(string name, int attack, int health, int armor);
	~FieryDragon();
	void attackTarget(Enemy* player);

private:
	int energy;
	int fireBall;
	int dragonRoar;
};

