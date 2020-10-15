#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <chrono>
#include <thread>
#include "../Headers/Player.h"
#include "../Headers/Weapon.h"
#include "../Headers/Monster.h"
#include <fstream>
#include <sstream>


using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

class Utilities {
public:
	Player PlayerClass;
	static void get_input(const string &question, string &input) {
		cout << question << endl;
		getline(cin, input);
	}
	static void get_input(const string &question, int &input) {
		while (true) {
			cout << question << endl;
			string tmp;
			getline(cin, tmp);
			stringstream stream(tmp);

			if (stream >> input) {
				break;
			}

			cout << "Please enter correct value" << endl;
		}
	}

	static void draw_message(const string message) {
		cout << "\n" << endl;
		cout << setfill('=') << setw(30) << '\n';
		cout << message << "\n";
		cout << setfill('=') << setw(30) << '\n';
		cout << "\n" << endl;
	}

	static int draw_menu(const vector<string> &options) {
		int count = 1;
		cout << "\n" << endl;
		cout << setfill('=') << setw(60) << '\n';
		cout << "\n" << endl;
		for (string option : options) {
			cout << count << ") " << option << endl;
			count++;
		}
		cout << "\n" << endl;
		cout << setfill('=') << setw(30) << '\n';
		cout << "\n" << endl;

		int choice;
		get_input("Please choose an option: ", choice);
		return choice;

	}
	static int draw_abilitesmenu(const vector<string> &options) {
		system("cls");
		int count = 1;
		cout << "\n" << endl;
		cout << setfill('=') << setw(30) << '\n';
		cout << "\n" << endl;
		for (string option : options) {
			cout << count << ") " << option << endl;
			count++;
		}
		cout << "\n" << endl;
		cout << setfill('=') << setw(30) << '\n';
		cout << "\n" << endl;

		int choice;
		get_input("Please choose an option: ", choice);
		return choice;

	}
	static int draw_inventorymenu(const vector<int> inventory, Player &player) {
		int invCount = 0;
		vector<string>itemNames;
		vector<int>itemBonus;
		vector<int>itemTypes;
		while (invCount < inventory.size()) {
			ifstream lfile("LootTable.dat");
			if (lfile.fail()) {
				cerr << "File data.dat could not be opened." << endl;
				exit(1);
			}
			int lootId;
			int typeId;
			int bonus;
			int price;
			string itemName;
			while (!lfile.eof()) {
				lfile >> lootId >> typeId >> bonus >> price;
				getline(lfile, itemName);
				if (inventory[invCount] == lootId) {
					itemNames.insert(itemNames.end(), itemName);
					itemBonus.insert(itemBonus.end(), bonus);
					itemTypes.insert(itemTypes.end(), typeId);
					break;
				}

			}
			lfile.close();
			invCount++;
		}
		system("cls");
		bool InventorySearch = true;
		while (InventorySearch) {
			system("cls");
			int count = 0;
			for (string inv : itemNames) {
				cout << count << ". " << inv << '\t';
				if (count % 5 == 0  && count != 0) {
					cout << "\n" << endl;
				}
				count++;
			}
			cout << count << ". Back" << endl;
			cout << "\n" << endl;
			cout << setfill('=') << setw(30) << '\n';
			cout << "\n" << endl;
			int choice;
			get_input("Please choose an option: ", choice);
			if (choice >= inventory.size()) {
				InventorySearch = false;
				return 0;
			}
			else {
				if (itemTypes[choice] == 1) {
					Weapon *weapon = new Weapon(itemNames[choice], "Rare", itemBonus[choice], false, 0, 2000);
					player + *weapon;
					cout << "Current Damage: " << player.get_damage() << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cin.get();
					InventorySearch = false;
					return 0;
				}
				else {
					cout << "You cant wear that" << endl;
				}

			}
		}

	}
	static int draw_combatmenu(const vector<string> &options, Player &player, Monster &monster, const vector<int> inventory) {
		int monsterHit;
		int playerHit;
		system("cls");
		cout << "A " << monster.get_name() << " appears in your way" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get();
		while (monster.get_hp() != 0) {
			system("cls");
			cout << "\n" << endl;
			cout << setfill('=') << setw(60) << '\n';
			cout << "\n" << endl;
			int count = 1;
			cout << "Player Name: " << player.get_name() << " Heath: " << player.get_hp() << " Mana: " << player.get_mana() << " Damage: " << player.get_damage() <<  endl;
			cout << "Monster Name: " << monster.get_name() << " Heath: " << monster.get_hp() << endl;
			cout << endl;
			for (string option : options) {
				cout << count << ". " << option << '\t';
				if (count % 3 == 0) {
					cout << "\n" << endl;
				}
				count++;
			}
			cout << "\n" << endl;
			cout << setfill('=') << setw(60) << '\n';
			cout << "\n" << endl;

			int choice;
			get_input("Please choose an option: ", choice);
			system("cls");
			if (choice == 1) {
				playerHit = (rand() % player.get_damage()) + 1;
				cout << player.get_name() << " Hits For " << playerHit << endl;
				monsterHit = (rand() % monster.get_attack()) + 1;
				cout << monster.get_name() << " Hits For " << monsterHit << endl;
				if (monster.get_hp() <= playerHit) {
					monster.set_hp(0);
				}
				else {
					monster.set_hp(monster.get_hp() - playerHit);
				}
				player.set_hp(player.get_hp() - monsterHit);

				if (player.get_hp() <= 0) {
					cout << "Game Over" << endl;
					cout << "Hit enter to continue" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cin.get();
					return 0;
				}
				else if (monster.get_hp() <= 0) {
					cout << "Monster Defeated" << endl;
					return 1;
				}

			}
			else if (choice == 2) {
				monsterHit = round(((rand() % monster.get_attack()) + 1) / 2);
				player.set_hp(player.get_hp() - monsterHit);
			}
			else if (choice == 3) {
				vector<string>Abilities = {
					"Wolf Pack",
					"Cry",
					"Back"

				};
				choice = Utilities::draw_abilitesmenu(Abilities);
				if (choice == Abilities.size()) {

				}
				else if (choice == 1) {
					if (player.get_mana() < 10) {
						cout << "You dont have the mana" << endl;
					}
					else {
						player.set_mana(player.get_mana() - 10);
						cout << "Current Mana" << player.get_mana() << endl;
						cout << "You hear a pack of wolfs" << endl;
						cout << "They jump onto the: " << monster.get_name() << "Dealing 25 Damage" << endl;
						playerHit = 25;
						if (monster.get_hp() <= playerHit) {
							monster.set_hp(0);
							cout << "Monster Defeated" << endl;
							return 1;
						}
						else {
							monster.set_hp(monster.get_hp() - playerHit);
						}
					}
				}
				else if (choice == 2) {
					monsterHit = (rand() % monster.get_attack()) + 1;
					player.set_hp(player.get_hp() - monsterHit);
					cout << "You cry and get hit by the monster" << endl;
					cout << "Monster Hit: " << monsterHit << endl;
					cout << "Mana increase: 10 points" << endl;
					player.set_mana(player.get_mana() + 10);
				}
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.get();

			}
			else if (choice == 4) {
				Utilities::draw_inventorymenu(inventory, player);
			}
			
		}
		return 0;


	}
	static int draw_chatmenu(const string TextChat, int sizeoftext) {
		system("cls");
		cout << "\n" << endl;
		cout << setfill('=') << setw(60) << '\n';
		cout << "\n" << endl;
		int count = 0;
		const char *TextChatChar = TextChat.c_str();
		while (count < sizeoftext) {
				cout << TextChatChar[count];
				sleep_for(milliseconds(50));
			count++;
		}

		cout << "\n" << endl;
		cout << setfill('=') << setw(60) << '\n';
		cout << "\n" << endl;

		cout << "Hit enter to proceed" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get();
		return 0;

	}

	static void create_player(Player &player) {
		string char_name;
		system("cls");
		Utilities::get_input("What is your name hero?", char_name);

		int mana = (rand()% 20) + 10;
		int health = (rand() % 20) + 10 + 10000;
		int s_attack = (rand() % 30) + 15 + 100;
		
		
		player.set_name(char_name);
		player.set_mana(mana);
		player.set_exp(0);
		player.set_level(1);
		player.set_money(0);
		player.set_base_damage(s_attack);
		player.set_hp(health);
		system("cls");
		cout << "Name:" << player.get_name() << " Heath:" << player.get_hp() << " Mana:" << player.get_mana() << " Attack:" << s_attack + 1 << endl;
		
		cout << "Hit enter to continue" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get();
	}

	static void get_story(int storyselect) {
		ifstream sfile("pStory.dat");
		if (sfile.fail()) {
			cerr << "File data.dat could not be opened." << endl;
			exit(1);
		}
		int storynum;
		string story;
		while (!sfile.eof()) {
			sfile >> storynum;
			getline(sfile, story);
			if (storynum == storyselect) {
				Utilities::draw_chatmenu(story, story.length());
				break;
			}

		}
		sfile.close();


		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get();
	
	};

	static void get_story_respones(int storyselect, string file_Name) {
		ifstream sfile(file_Name);
		if (sfile.fail()) {
			cerr << "File data.dat could not be opened." << endl;
			exit(1);
		}
		int storyId;
		int ResponId;
		int rstoryId;
		int rResponId;
		int choice = 0;
		int sectionId;
		int rsectionId;
		string story;
		string rstory;
		vector<string> responses;
		bool HasChanged = false;
		while (!sfile.eof()) {
			sfile >> storyId >> sectionId >> ResponId;
			getline(sfile, story);
			system("cls");
				if (ResponId == 1) {
					if (HasChanged == true) {
						while (choice != responses.size()){
							ifstream rfile("respone.dat");
							if (rfile.fail()) {
								cerr << "File data.dat could not be opened." << endl;
								exit(1);
							}
							choice = Utilities::draw_menu(responses);
							while (!rfile.eof()) {
								rfile >> rstoryId >> rsectionId >> rResponId;
								getline(rfile, rstory);
								if (storyId == rstoryId) {
									if (sectionId == rsectionId) {
										if (choice == rResponId)
										{
											Utilities::draw_chatmenu(rstory, rstory.length());
											break;
										}
									}
								}
							}
							rfile.close();
						}
						cout << storyId << sectionId << ResponId << endl;
						cout << rstoryId << rsectionId << rResponId << endl;
						responses.clear();
						HasChanged = false;
						choice = 0;
					}
					Utilities::draw_chatmenu(story, story.length());
				}
				else 
				{
					HasChanged = true;
					responses.insert(responses.end(), story);
				}

		}
		sfile.close();


		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get();

	};
	static void npcChat(int NpcChatStory, int NpcChatAnwsers) {
		ifstream sfile("NpcChat.dat");
		if (sfile.fail()) {
			cerr << "File data.dat could not be opened." << endl;
			exit(1);
		}
		int NpcNum;
		string story;
		while (!sfile.eof()) {
			sfile >> NpcNum;
			getline(sfile, story);
			if (NpcNum == NpcChatStory) {
				Utilities::draw_chatmenu(story, story.length());
				break;
			}
			cout << "Test" << endl;

		}
		sfile.close();
		Utilities::npcAnwsers(NpcChatAnwsers);


		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get();
	};
	static void npcAnwsers(int NpcChatAnswers) {
		ifstream sfile("NpcChatAnswers.dat");
		if (sfile.fail()) {
				cerr << "File data.dat could not be opened." << endl;
				exit(1);
			}
		int NpcAnswerId, NpcAnswer1, NpcAnswer2, NpcAnswer3, NpcAnswer4;
		string story;
		vector<string> answers;
		while (!sfile.eof()) {
			sfile >> NpcAnswerId >> NpcAnswer1 >> NpcAnswer2 >> NpcAnswer3 >> NpcAnswer4;
			if (NpcAnswerId == NpcChatAnswers) {
				if (NpcAnswer1 == 1) {
					answers.insert(answers.end(), "Enter");
				}
				else if (NpcAnswer1 == 2) {
					answers.insert(answers.end(), "Save");
				}
				else if (NpcAnswer1 == 3) {
					answers.insert(answers.end(), "Yes");
				}


				// Answers 2
				if (NpcAnswer2 == 1) {
					answers.insert(answers.end(), "Leave");
				}
				else if (NpcAnswer2 == 2) {
					answers.insert(answers.end(), "Attack");
				}
				else if (NpcAnswer2 == 3) {
					answers.insert(answers.end(), "No");
				}


				//Answers 3 
				if (NpcAnswer3 == 0) {
					break;
				}
				else if (NpcAnswer3 == 1) {
					answers.insert(answers.end(), "Attack");
				}
				else if (NpcAnswer3 == 2) {
					answers.insert(answers.end(), "Pay");
				}
				else if (NpcAnswer3 == 3) {
					answers.insert(answers.end(), "Ignore");

				}
				else if (NpcAnswer3 == 4) {
					answers.insert(answers.end(), "Leave");
				}


				//Answers 4
				if (NpcAnswer4 == 0) {
					break;
				}
				else if (NpcAnswer4 == 1) {
					answers.insert(answers.end(), "Betray");
				}
				else if (NpcAnswer4 == 2) {
					answers.insert(answers.end(), "Kill");
				}
				else if (NpcAnswer4 == 3) {
					answers.insert(answers.end(), "Ignore");

				}
				else if (NpcAnswer4 == 4) {
					answers.insert(answers.end(), "Leave");
				}

				
				break;
			}

		}
		sfile.close();
		Utilities::draw_menu(answers);
		answers.clear();
	};
};
