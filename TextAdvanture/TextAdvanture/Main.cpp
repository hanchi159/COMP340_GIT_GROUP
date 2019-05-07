#include"Object.h"
#include"Room.h"
#include"Map.h"
#include"Adventurer.h"

int main() {
	string userInput;
	string userName;
	//create map
	Map* map = new Map();
	//ask user name
	std::cout << "Welcome to Night Mare game, Enter your name: ";
	std::getline(cin, userName);
	//create player
	Adventurer* player = new Adventurer(userName, 50, 300,20,10);
	//basic description of game/ background
	std::cout <<"\t"<< "You are stucking in your own dream, a monster of your dream name Nightmare stand in front of a forest with haughty posture. " ;
	std::cout << "Nightmare speaks with low voice 'I already control your dream, I will slowly dominate your mind and never let you wake.'" ;
	std::cout << "The only way you can wake yourself up is the death of Nightmare, let starting your adventure, finding Nightmare and kill it.\n" << endl;
	std::cout << "TYPE 'help' TO SEE ALL COMMANDS YOU CAN ENTER." << endl;
	map->showRoom();

	while (true) {
		string verb = "";
		string noun = "";
		std::cout << ">>";
		//get user input
		std::getline(cin, userInput);
		//get verb
		for (char x : userInput) {
			if (x == ' ' || x==NULL)
			{
				break;
			}
			verb = verb + x;

		}
		//verb go get direction go to that direction
		if (verb == "go") {
			for (int i = 3; i < userInput.size(); i++) {
				noun = noun + userInput.at(i);
			}
			if (noun == "boss room") {
				if (player->getPortalKey() == true) {
					map->move(noun);
				}
				else {
					std::cout << "You do not have the key for the portal!" << endl;
				}
			}
			else {
				map->move(noun);
			}
			
		}
		//take item
		else if (verb == "take") {
			for (int i = 5; i < userInput.size(); i++) {
				noun = noun + userInput.at(i);
			}
			player->addItem(map->take(noun));
		}
		//check direction player can go
		else if (verb == "search") {
			map->search();
		}
		//look the room
		else if (verb == "look") {
			map->showRoom();
		}
		//open object
		else if (verb == "open") {
			for (int i = 5; i < userInput.size(); i++) {
				noun = noun + userInput.at(i);
			}
			map->getCurrRoom()->open(noun);
			map->showRoom();

		}
		//check player items
		else if (userInput == "inventory") {
			player->showInventory();
			string itemUse = "";
			do{
				std::cout << "Which item you want to use?(Enter no if no item use)" << endl;
				std::getline(cin,itemUse);
				if (itemUse != "no") {
					player->useItem(itemUse);
				}
			} while (itemUse != "no");
			
		}
		//check player infomation
		else if (userInput == "info") {
			player->showInformation();
		}
		//attck enemies in the room
		else if (userInput == "attack") {
			player->combat(map->getCurrRoom());
			if (map->getCurrRoom()->getName() == "BOSS WORLD") {
				if (player->getHealth() > 0) {
					std::cout << "You escape your dream, Night Mare can not contrl you any more! You win!" << endl;
					std::cout << "THANK YOU!" << endl;
					break;
				}
			}
			if (player->getHealth() <= 0) {
				break;
			}
		}
		//check what command player can type
		else if (userInput == "help") {
			std::cout << "{go,look,search,info,inventory,open,attack}" << endl;
			std::cout << "PS:no need target for attack, it automaticaly search enemy and combat." << endl;
		}
		else {
			std::cout << "invalid input!" << endl;
		}
		std::cout << "\n";
	}
	std::cout << "\n\nGAME OVER!" << endl;
	int a;
	cin >> a;
}