#pragma once
#include "../Headers/LootTable.h"
#include "Utilities.cpp"

LootTable::LootTable(){

};

	/*void LootTable::add_weapon(const Weapon &weapon) {
		m_weapons.push_back(weapon);

	}

 	void LootTable::add_armer(const Armer &armer) {
 		m_arms.push_back(armer);

 	}

	const std::vector<Weapon> LootTable::get_weapons() {
		return m_weapons;

	}
	const std::vector<Armer>  LootTable::get_armer() {
		return m_arms;*/
	//}

	const void LootTable::print_weapon_loot() {
		int index = 1;
		//for(Weapon weapon : m_weapons) {
			//std::cout << index << ") " << weapon.get_name() << " Worth: " << weapon.get_worth() << std::endl;
			//index++;

		//}
	}

	const void LootTable::print_armer_loot() {
		int index = 1;
		/*for(Armer armer : m_arms) {
			std::cout << index << ") " << armer.get_name() << " Worth: " << armer.get_worth() << std::endl;
			index++;

		}*/
	}

	int LootTable::get_drop()
	{

		int rngitem = (rand() % 28) + 1;
		cout << "Item Found" << endl;
		return rngitem;
	}
