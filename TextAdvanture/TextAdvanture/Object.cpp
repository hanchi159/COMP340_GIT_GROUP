#include "Object.h"


//each item has different construtor
Object::Object(string name)
{
	this->name = name;
	this->armor = 0;
	this->attack = 0;
	this->energy = 0;
	this->heal = 0;
	this->equipment = false;
	if (name == "bag") {
		this->container = vector<Object*>();
	}
	if (name == "energy drink") {
		this->energy = 20;
	}
	else if (name == "healthy fruit") {
		this->heal = 150;
	}
	else if (name == "lighten darts") {
		this->attack = 150;
	}
	else if (name == "rock") {
		this->attack = 150;
	}
	else if (name == "holy water") {
		this->heal = 150;
	}
	else if (name == "evil juice") {
		this->armor = 20;
	}
	else if (name == "blueberry") {
		this->energy = 20;
	}
	else if (name == "dragon fruit") {
		this->energy = 50;
		this->heal = 1000;
	}
	else if (name == "bear heart") {
		this->energy = 50;
		this->heal = 1000;
	}
	else if (name == "icy stone") {
		this->attack = 50;
		this->armor = 50;
		this->equipment = true;
	}
	else if (name == "fire stone") {
		this->attack = 70;
		this->armor = 70;
		this->equipment = true;
	}
	else if (name == "wooden sword") {
		this->attack = 20;
		this->equipment = true;
	}
	else if (name == "fabric suit") {
		this->armor = 20;
		this->energy = 20;
		this->equipment = true;
	}
	else if (name == "iron sword") {
		this->attack = 40;
		this->equipment = true;
	}
	else if (name == "iron suit") {
		this->armor = 20;
		this->energy = 40;
		this->equipment = true;
	}
}


Object::~Object()
{
}

string Object::getName() {
	return this->name;

}
int Object::getAttack() {
	return this->attack;
}
int Object::getHeal() {
	return this->heal;
}
int Object::getArmor() {
	return this->armor;
}
int Object::getEnergy() {
	return this->energy;
}
//bag has many other objects in it.
void Object::addContainer(Object* insertItem) {
	this->container.push_back(insertItem);
}
vector<Object*> Object::getContainer() {
	return this->container;
}
bool Object::getEuipment() {
	return this->equipment;
}