#include "IcyBear.h"



IcyBear::IcyBear(string name, int attack, int health, int armor) :Enemy(name,attack,health,armor)
{
	this->energy = 50;
	this->frozen = 1.5*attack;
	this->kungfuPunch = 2*attack;
}


IcyBear::~IcyBear()
{
}
//attack player
void IcyBear::attackTarget(Enemy* player) {
	//no health return
	if (this->health <= 0) {
		return;
	}
	srand(time(NULL));
	int healthLeft = player->getHealth();
	//random choose power to attack
	if (this->energy >= 10) {
		int decision = rand() % 2;
		if (decision == 0) {
			healthLeft = player->getHealth() - (frozen - player->getArmor());
			std::cout << this->name << " use Frozen to attack you. " << " The damage is " << frozen - player->getArmor() << ". " << "you has " << healthLeft << " health left."<<endl;
		}
		else {
			healthLeft = player->getHealth() - (this->kungfuPunch - player->getArmor());
			std::cout << this->name << " use Kungfu Punch to attack you. " << " The damage is " << this->kungfuPunch - player->getArmor() << ". " << "you has " << healthLeft << " health left." << endl;
		}
	}
	//no energy regular attack
	else {
		healthLeft = player->getHealth() - (this->attack - player->getArmor());
		std::cout << this->name << " attack you. " << " The damage is " << attack - player->getArmor() << ". " << "you has " << healthLeft << " health left." << endl;
	}
	player->setHealth(healthLeft);
	
}
