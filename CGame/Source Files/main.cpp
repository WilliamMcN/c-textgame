#pragma once
#include "../Resource/Utilities.cpp"
#include "../Headers/Player.h"
#include <cstdlib>
#include <ctime>
#include "../Headers/Monster.h"
#include "../Headers/Encounter.h"
#include "../Headers/LootTable.h"

int monsterDrop(int monsterFight)
{
	LootTable LootClass;

	if (monsterFight == 1) {
		int item = LootClass.get_drop();
		return item;
	}
	return 0;
}

int OpenInv(vector<int>inventory)
{
		ifstream lfile("loottable.dat");
		if (lfile.fail()) {
			cerr << "File data.dat could not be opened." << endl;
			exit(1);
		}
		int itemId;
		int itemType;
		int itemBonus;
		int itemPrice;
		string itemName;
		int rngitem = (rand() % 28) + 1;
		while (!lfile.eof()) {
			lfile >> itemId >> itemType >> itemBonus >> itemPrice;
			getline(lfile, itemName);
			if (itemId == rngitem) {
				return itemId;
			}
	
		}
		lfile.close();
		return 0;
}

int main() {
	int dungeonCount = 0;
	int Playerchoice;
	srand(time(0));
	bool is_playing = true;
	Monster MonsterClass;
	Player PlayerClass;
	Encounter EncounterClass;
	LootTable LootClass;
	int monsterFight = 1;
	int item;
	while (is_playing) {
		// options for the player
		vector<string> options = {
			"Start Game",
			"Quit"

		};
		vector<int> inventory = {
			1,2,13,4,15,16,4,18,19
		};
		vector<string> combatoptions = {
			"Attack",
			"Defend",
			"Abilities",
			"Inventory",
			"Run"

		};
		int choice = Utilities::draw_menu(options);
		// if they want to quit
		if (choice == 2) {
			is_playing = false;
			continue;
		}

		item = LootClass.get_drop();
		inventory.insert(inventory.end(), item);
		item = LootClass.get_drop();
		inventory.insert(inventory.end(), item);
		Player *player = new Player();
		Weapon *weapon = new Weapon("Hands", "Rare", 1, false, 0, 2000);
		//Player *player = new Player;
		Monster *monster = new Monster;
		system("cls");
		string banner = "Hello, and Welcome Brave Knight! Help bring down the corrupt, be the champion we all need!";
		int bobc = Utilities::draw_chatmenu(banner, banner.length());
		// creates the player so the game can begin.
		Utilities::create_player(*player);
		*player + *weapon;
		system("cls");
		Utilities::get_story_respones(1, "The_Begining.dat");
		Encounter::spawnMonster(*monster);
		monsterFight = Utilities::draw_combatmenu(combatoptions,*player, *monster,inventory);
		if (monsterFight == 1) {
			item = LootClass.get_drop();
			inventory.insert(inventory.end(), item);
			cout << inventory[0] << endl;
		}
		cout << "A dungeon appears" << endl;
		Utilities::get_input("Enter Dungeon? (1. Enter or 2. Leave)", Playerchoice);
		dungeonCount = 0;
		if (Playerchoice == 1) {
			while (dungeonCount < 10) {
				Encounter::spawnMonster(*monster);
				monsterFight = Utilities::draw_combatmenu(combatoptions, *player, *monster, inventory);
				if (monsterFight == 1) {
					item = LootClass.get_drop();
					inventory.insert(inventory.end(), item);
				}
				dungeonCount++;
			}
			monster->set_attack(30);
			monster->set_hp(400);
			monster->set_name("Gurdian Of The Forest");
			monsterFight = Utilities::draw_combatmenu(combatoptions, *player, *monster, inventory);
			if (monsterFight == 1) {
				item = LootClass.get_drop();
				inventory.insert(inventory.end(), item);
			}
		}
		Utilities::get_story_respones(2, "Part 2 Marshal House.txt");
		Utilities::get_input("Help Marshal? (1. yes or 2. no)", Playerchoice);
		if(Playerchoice == 1){
			monster->set_attack(10);
			monster->set_hp(100);
			monster->set_name("Village Guard");
			monsterFight = Utilities::draw_combatmenu(combatoptions, *player, *monster, inventory);
			if (monsterFight == 1) {
				item = LootClass.get_drop();
				inventory.insert(inventory.end(), item);
			}
			Utilities::get_story_respones(3, "Part 3a Town Good.txt");
		}
		else {
			cout << "Guards take the money and leave" << endl;
			Utilities::get_story_respones(3, "Part 3a Town Bad.txt");
		}
		Utilities::get_input("Join or Fight Bugsworth? (1. Join or 2. Fight)", Playerchoice);
		if (Playerchoice == 2) {
			monster->set_attack(25);
			monster->set_hp(200);
			monster->set_name("Jeffords");
			monsterFight = Utilities::draw_combatmenu(combatoptions, *player, *monster, inventory);
			if (monsterFight == 1) {
				item = LootClass.get_drop();
				inventory.insert(inventory.end(), item);
			}
			Utilities::get_story_respones(4, "Part 4b Fight Town.txt");
		}
		else {
			Utilities::get_story_respones(4, "Part 4a Join Town.txt");
		}
		//More stories to come 
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get();
	}
}