#include "GiantSpider.h"



GiantSpider::GiantSpider(string name, int attack, int health, int armor) : Enemy(name, attack, health, armor)
{
	this->energy = 20;
	this->netShooting = 1.5*attack;
	this->poisonBite = 2 * attack;
}


GiantSpider::~GiantSpider()
{
}
void GiantSpider::attackTarget(Enemy* player) {
	//no health return
	if (this->health <= 0) {
		return;
	}
	srand(time(NULL));
	int healthLeft = player->getHealth();
	//random choose power to attack
	if (this->energy >= 5) {
		int decision = rand() % 2;
		if (decision == 1) {
			healthLeft = player->getHealth() - (netShooting - player->getArmor());
			std::cout << this->name << " use Net Shooting to attack you. " << " The damage is " << netShooting - player->getArmor() << ". " << "you has " << player->getHealth() << " health left." << endl;
		}
		else {
			healthLeft = player->getHealth() - (this->poisonBite - player->getArmor());
			std::cout << this->name << " use Poison Bite to attack you. " << " The damage is " << poisonBite - player->getArmor() << ". " << "you has " << player->getHealth() << " health left." << endl;
		}
		this->energy -= 5;
	}
	//no energy regular attack
	else {
		healthLeft = player->getHealth() - (this->attack - player->getArmor());
		std::cout << this->name << " attack you. " << " The damage is " << attack - player->getArmor() << ". " << "you has " << player->getHealth() << " health left." << endl;
	}
	player->setHealth(healthLeft);

}