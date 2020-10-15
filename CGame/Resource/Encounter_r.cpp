#pragma once
#include "../Headers/Encounter.h"
#include "Utilities.cpp"
#include "../Headers/Monster.h"

Monster MonsterClass;
Encounter::Encounter() {};

Encounter::Encounter(Monster *monster, int *amount) {
	if(*amount > 1 && *amount < 6) {
		for(int i = 0 ; i < *amount ; i++) {
			m_monsters.push_back(*monster);
		}
	} else if(*amount == 1) {
		m_monsters.push_back(*monster);
	}
};

const std::vector<Monster> Encounter::get_monsters() {
	return m_monsters;

}

void Encounter::spawnMonster(Monster &monster) {
	ifstream mfile("EncounterMonster.dat");
	if (mfile.fail()) {
		cerr << "File data.dat could not be opened." << endl;
		exit(1);
	}
	int monsterHeath;
	int monsterAttack;
	int monsterId;
	string monsterName;
	int rngMonster = (rand() % 12) + 1;
	while(!mfile.eof()) {
			mfile >> monsterId >> monsterAttack >> monsterHeath;
			getline(mfile, monsterName);
			if (monsterId == rngMonster) {
				monster.set_hp(monsterHeath);
				monster.set_attack(monsterAttack);
				monster.set_name(monsterName);
				break;
			}

	}
	mfile.close();
};

