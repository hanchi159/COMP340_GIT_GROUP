#include "Map.h"


//set map
Map::Map()
{
	map[0][0] = this->setBossRoom();
	map[0][1] = NULL;
	map[0][2] = this->setIcyWorld();
	map[1][0] = NULL;
	map[1][1] = this->setFireMountain();
	map[1][2] = this->setFarm();
	map[2][0] = this->setSafetyHouse();
	map[2][1] = this->setForest();
	map[2][2] = this->setDesert();
	map[3][0] = NULL;
	map[3][1] = this->setForestEntry();
	map[3][2] = NULL;
	this->currX = 3;
	this->currY = 1;
	currRoom = map[3][1];

}


Map::~Map()
{
}

Room* Map::setForest() {
	Room* forest = new Room("DEEP FOREST", "You go into deep forest! There is a tiger sleep near a tree. One bag in front of you, seem many good stuff in that bag. Around that bag, some medicines on the ground.");
	forest->addEnemy(new Enemy("Tiger", 100, 60, 5));
	forest->addItem(new Object("blueberry"));
	Object* bag = new Object("bag");
	bag->addContainer(new Object("energy drink"));
	bag->addContainer(new Object("healthy fruit"));
	forest->addItem(bag);
	return forest;
}
Room* Map::setForestEntry() {
	Room* forestEntry = new Room("FROREST ENTRY", "A voice form sky 'Start your adventure, boy! here is you equipment, take it and go!' ");
	forestEntry->addItem(new Object("wooden sword"));
	forestEntry->addItem(new Object("fabric suit"));
	return forestEntry;
}
Room* Map::setDesert() {
	Room* Desert = new Room("DESERT", "This is desert world, one Dream Patrol roam around. He holds a bottle of water seem special.");
	Enemy* dreamPatrol = new Enemy("Dream Patrol", 120, 60, 20);
	Desert->addEnemy(new GiantSpider("Giant Spider",50, 200, 20));
	dreamPatrol->addDrops(new Object("holy water"));
	dreamPatrol->addDrops(new Object("iron suit"));
	dreamPatrol->addDrops(new Object("iron sword"));
	Desert->addEnemy(dreamPatrol);
	return Desert;
}
Room* Map::setSafetyHouse() {
	Room* safetyHouse = new Room("SAFETY HOUSE", "welcome to safety house! take a break here, it is really same. There are some fruit on the desk. Some attackable thing and one key on the wall.");
	safetyHouse->addItem(new Object("rock"));
	safetyHouse->addItem(new Object("rock"));
	safetyHouse->addItem(new Object("lighten darts"));
	safetyHouse->addItem(new Object("healthy fruit"));
	safetyHouse->addItem(new Object("holy water"));
	safetyHouse->addItem(new Object("portal key"));
	return safetyHouse;
}
Room* Map::setFarm() {
	Room* farm = new Room("FARM", "The middle of the farm has a small cabin. A Dream Hunter walk around the cabin. In the jungle, some sneaks are hiding and attemp to attack.");
	farm->addItem(new Object("lighten darts"));
	farm->addEnemy(new Enemy("sneak", 20,50, 5));
	farm->addEnemy(new Enemy("sneak", 20, 50, 5));
	farm->addEnemy(new Enemy("sneak", 20, 50, 5));
	Enemy* dreamHuter = new Enemy("Dream Hunter", 120, 200, 15);
	dreamHuter->addDrops(new Object("healthy fruit"));
	dreamHuter->addDrops(new Object("holy water"));
	farm->addEnemy(dreamHuter);
	return farm;

}
Room* Map::setFireMountain() {
	Room* fireMountain = new Room("FIRE MOUNTAIN", "The mountain explode with flame, one dragon fly on the top of the flame. Under the mountain, A wizard dragon and dragon knight guard the mountain and protect the fiery dragon. ");
	fireMountain->addEnemy(new Enemy("Wizard Dragon", 150, 240, 20));
	fireMountain->addEnemy(new Enemy("Dragon Knight", 130, 260, 30));
	FieryDragon* fieryDragon = new FieryDragon("Fiery Dragon", 80, 300, 50);
	fieryDragon->addDrops(new Object("dragon fruit"));
	fieryDragon->addDrops(new Object("fire stone"));
	fieryDragon->addDrops(new Object("evil juice"));
	fieryDragon->addDrops(new Object("healthy fruit"));
	fieryDragon->addDrops(new Object("energy drink"));
	fireMountain->addEnemy(fieryDragon);
	return fireMountain;
}
Room* Map::setIcyWorld() {
	Room* icyWorld = new Room("ICY WORLD", "This world is iced, two bears stand front of one large bear.");
	icyWorld->addEnemy(new Enemy("Archer Bear", 150, 230, 20));
	icyWorld->addEnemy(new Enemy("Kungfu Bear", 130, 260, 40));
	IcyBear* icyBear = new IcyBear("Icy Bear", 80, 300, 50);
	icyBear->addDrops(new Object("bear heart"));
	icyBear->addDrops(new Object("icy stone"));
	icyBear->addDrops(new Object("energy drink"));
	icyBear->addDrops(new Object("holy water"));
	icyWorld->addEnemy(icyBear);
	return icyWorld;
}
Room*Map::setBossRoom() {
	Room* bossRoom = new Room("BOSS WORLD", "This is your final step, Night Mare stand there ready to fight.");
	bossRoom->addEnemy(new NightMare("Night Mare", 170, 1000, 100));
	return bossRoom;
}
//show room information
void Map::showRoom() {
	std::cout << currRoom->getName() << endl;
	std::cout << currRoom->getDescription() << endl;
	currRoom->printItems();
}

Room* Map::getCurrRoom() {
	return this->currRoom;
}
//player move
void Map::move(string direction) {
	if (direction == "boss room") {
		//0,2 and 1,1 are two rooms can go to boss room
		if ((currX == 0 && currY == 2) || (currX == 1 && currY == 1)) {
			string doubleCheck="yes";
			//double check with user if they want to go boss room or not
			while (doubleCheck == "yes" || doubleCheck == "no") {
				std::cout << "If you go into boss room, there is no way out there.\n you either die or kill the boss.\nARE YOU SURE YOU WANT TO GO IN?" << endl;
				std::getline(cin, doubleCheck);
				if (doubleCheck == "yes") {
					currRoom = map[0][0];
					currX = 0;
					currY = 0;
					doubleCheck = " ";
				}
				else if (doubleCheck == "no") {
					std::cout << "You are not ready for boss fight. You are at same room." << endl;
					doubleCheck = " ";
				}
				else {
					std::cout << "invalid answer" << endl;
					doubleCheck = "yes";
				}
			}
		}
		//not in that two room can not go to boss room
		else {
			std::cout << "You are not able to get into the boss room" << endl;
		}
	}
	else if (direction == "north") {
		if ((map[currX-1][currY] == NULL) || currX-1 <0 || currY > 2) {
			std::cout << "no such room" << endl;
		}
		else {
			currRoom = map[currX - 1][currY];
			currX -= 1;
		}
	}
	else if (direction == "south") {
		if ((map[currX + 1][currY] == NULL) || currX + 1 > 3 || currY > 2) {
			std::cout << "no such room" << endl;
		}
		else {
			currRoom = map[currX + 1][currY];
			currX += 1;
		}
	}
	else if (direction == "west") {
		if ((map[currX][currY-1] == NULL) || currX > 3 || currY-1 < 0) {
			std::cout << "no such room" << endl;
		}
		else {
			currRoom = map[currX][currY-1];
			currY -= 1;
		}
	}
	else if (direction == "east") {
		if ((map[currX][currY+1] == NULL) || currX > 3 || currY+1 > 2) {
			std::cout << "no such room" << endl;
		}
		else {
			currRoom = map[currX][currY+1];
			currY += 1;
		}
	}
	else {
		std::cout << "invalid direction!\n" << endl;

	}
	//std::cout << "your location: " << currX << "\t" << currY << endl;
	showRoom();
}
//once take item remove item.
Object* Map::take(string item) {
	return currRoom->removeItem(item);
}
void Map::showRoomItem() {
	currRoom->printItems();
}
//check which direction user can go
void Map::search() {
	std::cout << "Directions you can go: " << endl;
	if (map[currX + 1][currY] != NULL && currX+1<=3) {
		std::cout << "south" << endl;
	}
	if (map[currX - 1][currY] != NULL && currX-1>=0) {
		std::cout << "north" << endl;
	}
	if (map[currX][currY + 1] != NULL && currY+1<=2) {
		std::cout << "east" << endl;
	}
	if (map[currX][currY - 1] != NULL && currY-1 >= 0) {
		std::cout << "west" << endl;
	}
}