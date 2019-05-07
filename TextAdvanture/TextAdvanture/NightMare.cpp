#include "NightMare.h"



NightMare::NightMare(string name, int attack, int health, int armor) : Enemy(name, attack, health, armor)
{
	this->psywave = attack * 3;
	this->psychoBoost = attack * 2;
	this->harden = false;
	this->heal = false;
}


NightMare::~NightMare()
{
}
void NightMare::attackTarget(Enemy* player) {
	srand(time(NULL));
	int healthLeft = player->getHealth();
	int decision = rand() % 2;
	//raise armor first
	if (harden == false) {
		this->armor = this->armor * 2;
		std::cout << this->name << " use Harden skill, double the armor!" << endl;
		this->harden = true;
	}
	//less healthy heal to 1000, only happen once
	else if (health <= 30 && heal == false) {
		this->health = 1000;
		std::cout << this->name << " heal himself, healthy become 1000 !!" << endl;
		this->heal = true;
	}
	//random power attack
	else if (decision == 0) {
		healthLeft = player->getHealth() - (this->psywave - player->getArmor());
		std::cout << this->name << " use Psywave to attack you. " << " The damage is " << psywave - player->getArmor() << ". " << "you has " << player->getHealth() << " health left." << endl;
	}
	else if(decision == 1){
		healthLeft = player->getHealth() - (this->psychoBoost - player->getArmor());
		std::cout << this->name << " use Psycho Boost to attack you. " << " The damage is " << this->psychoBoost - player->getArmor() << ". " << "you has " << player->getHealth() << " health left." << endl;
	}
	player->setHealth(healthLeft);

}