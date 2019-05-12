#pragma once
#include"Enemy.h"
class GiantSpider : public Enemy
{
public:
	GiantSpider(string name, int attack, int health, int armor);
	~GiantSpider();
	void attackTarget(Enemy* player);

private:
	int energy;
	int netShooting;
	int poisonBite;
};

