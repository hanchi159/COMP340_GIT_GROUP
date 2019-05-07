#include "Enemy.h"



Enemy::Enemy(string name, int attack, int health,int armor)
{
	this->name = name;
	this->attack = attack;
	this->health = health;
	this->armor = armor;
	enemyDrop = vector<Object*>();
}


Enemy::~Enemy()
{
}
string Enemy::getName() {
	return name;
}
int Enemy::getAttack() {
	return attack;
}
int Enemy::getHealth() {
	return health;
}
int Enemy::getArmor() {
	return armor;
}
//when enemy dead items will drop 
vector<Object*> Enemy::getEnemyDrop() {
	return this->enemyDrop;
}
void Enemy::printEnemy() {
	std::cout << "The enemy is " << this->getName() << " Attack: " << this->getAttack() << " health: " << this->getHealth() << " Armor: " << this->getArmor() << endl;


}
void Enemy::setHealth(int health) {
	this->health = health;

}
//attack player
void Enemy::attackTarget(Enemy* player) {
	if (this->health <= 0) {
		return;
	}
	int healthLeft = player->getHealth() - (attack - player->getArmor());
	player->setHealth(healthLeft);
	std::cout << this->name << " attack you. " << " The damage is " << attack - player->getArmor() << ". " << "you has " << player->getHealth() << " health left." << endl;
}
void Enemy::addDrops(Object* drop) {
	this->enemyDrop.push_back(drop);
}