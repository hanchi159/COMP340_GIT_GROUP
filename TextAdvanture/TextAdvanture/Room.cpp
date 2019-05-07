#include "Room.h"



Room::Room(string name,string description)
{
	this->name = name;
	this->description = description;
	this->objects = vector<Object*>();
	this->enemies = vector<Enemy*>();

}


Room::~Room()
{
}

void Room::addItem(Object* roomItem) {
	this->objects.push_back(roomItem);
}
void Room::addEnemy(Enemy* roomEnemy) {
	this->enemies.push_back(roomEnemy);

}
//show items in the room
void Room::printItems() {
	for (int i = 0; i < objects.size(); i++) {
		std::cout << objects.at(i)->getName() << "\t" << endl;
	}
	
}
string Room::getName() {
	return this->name;

}
string Room::getDescription() {
	return this->description;
}
vector<Object*> Room::getObjects() {
	return this->objects;
}
vector<Enemy*> Room::getEnemies() {
	return this->enemies;
}
//remove match item from list of items
Object* Room::removeItem(string item) {
	for (Object* temp : objects) {
		if (temp->getName() == item) {
			if (temp->getContainer().size() != 0) {
				return temp;

				break;
			}
			objects.erase(remove(objects.begin(), objects.end(), temp), objects.end());
			return temp;
		}
	}
	return NULL;
}
void Room::removeEnemy() {
	this->enemies.erase(enemies.begin());
}
//open item with many items in it
void Room::open(string box) {
	Object* boxfind = NULL;
	for (int i = 0; i < this->objects.size();i++) {
		if (this->objects.at(i)->getName() == box) {
			boxfind = objects.at(i);
		}
	}
	if (boxfind == NULL) {
		std::cout << "no such thing!" << endl;
	}
	else if (boxfind->getContainer().size() != 0) {
		for (Object* x : boxfind->getContainer()) {
			this->objects.push_back(x);
		}
		this->objects.erase(objects.begin());
	}
	else {
		std::cout << box << " cannot be opened!" << endl;
	}
	
}