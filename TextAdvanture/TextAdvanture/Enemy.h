#pragma once
#include"Object.h"
#include<string>
#include<iostream>
#include <stdio.h>
#include <stdlib.h>     
#include <time.h> 
using namespace std;
class Enemy
{
public:
	Enemy(string name, int attack,int health,int armor);
	~Enemy();
	string getName();
	int getAttack();
	int getHealth();
	int getArmor();
	vector<Object*> getEnemyDrop();
	void addDrops(Object* drop);
	void setHealth(int health);
	virtual void attackTarget(Enemy* player);
	void printEnemy();


protected:
	int attack;
	int health;
	int armor;
	string name;
	vector<Object*> enemyDrop;
};

