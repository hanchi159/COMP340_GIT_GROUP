#pragma once
#include"Room.h"
#include<algorithm>
class Map
{
public:
	Map();
	~Map();
	Room* setForest();
	Room* setForestEntry();
	Room* setDesert();
	Room* setSafetyHouse();
	Room* setFarm();
	Room* setFireMountain();
	Room* setIcyWorld();
	Room* setBossRoom();
	Room* getCurrRoom();
	void move(string direction);
	Object* take(string item);
	void showRoomItem();
	void search();
	void showRoom();

private:
	Room* map[4][3];
	Room* currRoom;
	int currX;
	int currY;
};

