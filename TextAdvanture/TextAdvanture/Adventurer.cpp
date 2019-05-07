#include "Adventurer.h"



Adventurer::Adventurer(string name, int attack, int health, int armor,int energy) :Enemy(name, attack, health, armor)
{
	this->energy = energy;
}


Adventurer::~Adventurer()
{
}
//show personal infomation
void Adventurer::showInformation() {
	std::cout << "Name: " << this->name << endl;
	std::cout << "Health: " << this->health << endl;
	std::cout << "Energy: " << this->energy << endl;
	std::cout << "Attack: " << this->attack << endl;
	std::cout << "Armor: " << this->armor << endl;
	if (this->fireBall != 0 || this->frozen != 0) {
		std::cout << "Magic Power: "  << endl;
		if (this->fireBall != 0) {
			std::cout << "Fire Ball" << endl;
		}
		if (this->frozen != 0) {
			std::cout << "Frozen" << endl;
		}
	}
}
//take item add to inventory
void Adventurer::addItem(Object* item) {
	if (item == NULL) {
		std::cout << "no such item!" << endl;
	}
	//if its bag need open first
	else if (item->getContainer().size() != 0) {
		std::cout << item->getName() << " cannot be taken! " << endl;
	}
	//if its euipment, add attributes into personal information directly
	else if (item->getEuipment() == true) {
		this->attack += item->getAttack();
		this->armor += item->getArmor();
		this->energy += item->getEnergy();
		std::cout << "personal info updated." << endl;
	}
	//it is item add to inventory
	else if (item->getContainer().size() == 0) {
		this->inventory.push_back(item);
		//if its key set key to true
		if (item->getName() == "portal key") {
			portalKey = true;
		}
		std::cout << "You take " << item->getName() << "." << endl;
	}
	else {
		for (Object* singleItem : item->getContainer()) {
			this->inventory.push_back(singleItem);
		}
	}
}
void Adventurer::showInventory() {
	std::cout << "Your Inventory:" << endl;
	for (Object* Item : this->inventory) {
		std::cout << Item->getName() << endl;
	}
}
bool Adventurer::getPortalKey() {
	return portalKey;
}
//attack enemy
void Adventurer::attackTarget(Enemy* target) {
	//less and equal than 0, return
	if (target->getHealth() <= 0) {
		return;
	}
	string userChoice;
	int healthyLeft=0;
	string nameEnemy = target->getName();
	//ask which combat catagory user want to use
	std::cout << "1.Body Attack\n" << "2.Magic Attack\n" << "3.Stuff Throw\n";
	std::getline(cin,userChoice);
	//body attack
	if (userChoice == "1") {
		//randomly choose kick or punch with same attack
		int decision;
		decision = rand() % 2;
		healthyLeft = (target->getHealth() - this->attack + target->getArmor());
		target->setHealth(healthyLeft);
		if (decision == 0) {
			
			std::cout << "You kick the " << nameEnemy << "." << " The damage is " << this->attack - target->getArmor() << "." << " " << nameEnemy << " has " << target->getHealth() << " health left." << endl;
		}
		if (decision == 1) {
			std::cout << "You punch the " << nameEnemy << "." << " The damage is " << this->attack - target->getArmor() << "." << " " << nameEnemy << " has " << target->getHealth() << " health left." << endl;
		}
		
	}
	//magic attack
	else if (userChoice == "2") {
		//no magic ask user about 3 actions again
		if(this->fireBall==0 && this->frozen==0) {
			std::cout << "No magic power" << endl;
			attackTarget(target);
		}
		//print powers user has ask which one they want to use
		else {
			std::cout << "Your Magic Power are:" << endl;
			string magicChoice = " ";
			if(fireBall !=0){
				std::cout << "fire ball" << endl;
			}
			if (frozen != 0) {
				std::cout << "frozen" << endl;
			}
			while (magicChoice == " ") {
				std::cout << "Which Magic power you want to use? ";
				std::getline(cin, magicChoice);
				//fire ball attack
				if (magicChoice == "fire ball" && this->fireBall != 0) {
					if (energy < 50) {
						std::cout << "Not enough energy!" << endl;
					}
					else {
						this->energy -= 50;
						healthyLeft = target->getHealth() - (this->fireBall - target->getArmor());
						target->setHealth(healthyLeft);
						std::cout << "You use fire ball to attack the " << nameEnemy << "." << " The damage is " << this->fireBall - target->getArmor() << "." << " " << nameEnemy << " has " << target->getHealth() << " health left." << endl;
					}
					
				}
				//frozen attack
				else if (magicChoice == "frozen" && frozen != 0) {
					if (energy < 30) {
						std::cout << "Not enough energy!" << endl;
					}
					else {
						this->energy -= 30;
						healthyLeft = target->getHealth() - (this->frozen - target->getArmor());
						target->setHealth(healthyLeft);
						std::cout << "You froze the " << nameEnemy << "." << " The damage is " << this->frozen - target->getArmor() << "." << " " << nameEnemy << " has " << target->getHealth() << " health left." << endl;
					}
					
				}
				else {
					std::cout<<magicChoice;

					std::cout << "Not invalid power!" << endl;
					magicChoice = " ";
				}
			}

		}
	}
	//stuff throw
	else if (userChoice == "3") {
		string inventoryAttack;
		while (healthyLeft == 0)
		{
			this->showInventory();
			//ask which one they want to use to attack
			std::cout << "Which one you want to use for attack(enter 'no' back to last menu):";
			std::getline(cin,inventoryAttack);
			//no ask 3 actions again
			if (inventoryAttack == "no") {
				attackTarget(target);
				break;
			}
			//find item from iventory
			for (Object* item : inventory) {
				if (item->getName() == inventoryAttack && item->getAttack()!=0) {

					healthyLeft = target->getHealth() - item->getAttack();
					target->setHealth(healthyLeft);
					std::cout<< "You use "<<item->getName()<< " to attack "<<nameEnemy<< "." << " The damage is " << item->getAttack() << "." << " " << nameEnemy << " has " << target->getHealth() << " health left." << endl;
					this->inventory.erase(remove(inventory.begin(), inventory.end(), item), inventory.end());
					break;
				}
			}
			//not find ask again
			if (healthyLeft == 0) {
				std::cout << "invalid item!" << endl;
			}
		}

	}
	else {
		std::cout << "invalid input!" << endl;
		attackTarget(target);
	}
}
//use item add item attributes to player
void Adventurer::useItem(string itemUse) {
	Object* itemFind = NULL;
	int count=0;
	for (Object* item : inventory) {
		count++;
		if (item->getName() == itemUse) {
			itemFind = item;
			break;
		}
	}
	if (itemFind == NULL||itemFind->getAttack()!=0) {
		std::cout << "no such item to use! " << endl;
		return;
	}
	this->attack += itemFind->getAttack();
	this->armor += itemFind->getArmor();
	this->health += itemFind->getHeal();
	this->energy += itemFind->getEnergy();
	inventory.erase(inventory.begin() + (count-1));
	std::cout << "You used " << itemUse << "." << endl;
}
//combat player and enemy
void Adventurer::combat(Room* targetRoom) {
	//no enemy, return
	if (targetRoom->getEnemies().size() == 0) {
		std::cout << "no enemy exsit in this room!" << endl;
		return;
	}
	//combat every enemy in the room
	for (Enemy* target : targetRoom->getEnemies()) {
		std::cout << "You find a " << target->getName() << endl;
		while (this->health > 0 && target->getHealth() > 0) {
			attackTarget(target);
			target->attackTarget(this);
		}
		//lose end game
		if (this->health <= 0) {
			std::cout << "You lost! You stuck in the dream forever! bye..." << endl;
			break;
		}
		//win goes next enemy
		else if (target->getHealth() <= 0) {
			std::cout << "congraduate, you win the battle!" << endl;
			std::cout << "The items you get from enemy:" << endl;
			for (Object* item : target->getEnemyDrop()) {
				std::cout << item->getName();
				if (item->getEuipment() == true) {
					this->armor += item->getArmor();
					this->attack += item->getAttack();
					this->energy += item->getEnergy();
					std::cout << "(Personal info update)" << endl;
				}
				
				else {
					std::cout << "\n";
					inventory.push_back(item);
				}
				
				
			}
			//kill small bosses get power
			if (target->getName() == "Fiery Dragon") {
				this->fireBall = this->attack * 2;
			}
			if (target->getName() == "Icy Bear") {
				this->frozen = int(this->attack*1.5);
			}
			targetRoom->removeEnemy();
		}
	}
	
}