#include "FieryDragon.h"



FieryDragon::FieryDragon(string name, int attack, int health, int armor) :Enemy(name, attack, health, armor)
{
	this->energy = 50;
	this->fireBall = 2.5*attack;
	this->dragonRoar = 2*attack;
}


FieryDragon::~FieryDragon()
{
}
//attack player
void FieryDragon::attackTarget(Enemy* player) {
	//no health return
	if (this->health <= 0) {
		return;
	}
	srand(time(NULL));
	int healthLeft = player->getHealth();
	//random choose power to attack
	if (this->energy >= 10) {
		int decision = rand() % 2;
		if (decision == 1) {
			healthLeft = player->getHealth() - (fireBall - player->getArmor());
			std::cout << this->name<<" use Fire Ball to attack you. "<< " The damage is " << fireBall - player->getArmor() << ". " << "you has " << player->getHealth()<< " health left." << endl;
		}
		else {
			healthLeft = player->getHealth() - (this->dragonRoar - player->getArmor());
			std::cout << this->name << " use Dragon Roar to attack you. " << " The damage is " << dragonRoar - player->getArmor() << ". " << "you has " << player->getHealth() << " health left." << endl;
		}
		this->energy -= 10;
	}
	//no energy regular attack
	else {
		healthLeft = player->getHealth() - (this->attack - player->getArmor());
		std::cout << this->name << " attack you. " << " The damage is " << attack - player->getArmor() << ". " << "you has " << player->getHealth() << " health left." << endl;
	}
	player->setHealth(healthLeft);
	
}
