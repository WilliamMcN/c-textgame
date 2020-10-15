#include "../Headers/Weapon.h"

Weapon::Weapon() {};

//constructors
Weapon::Weapon(std::string name, std::string raraty, int damage_stat, bool is_magic, int magic_damage, int worth) {
	set_name(name);
	set_raraty(raraty);
	set_damage_stat(damage_stat);
	set_is_magic(is_magic);
	set_magic_damage(magic_damage);
	set_worth(worth);
}

//setters

void Weapon::set_name(std::string name) {
	if(!name.empty()) {
		m_name = name;
	}
}

void Weapon::set_raraty(std::string raraty) {
	if(!m_name.empty()) {
		m_raraty = raraty;
	}
}

void Weapon::set_damage_stat(int damage_stat) {
	if(damage_stat > 0) {
		m_damage_stat = damage_stat;
	}
}

void Weapon::set_is_magic(bool is_magic) {
	m_is_magic = is_magic;
}

void Weapon::set_magic_damage(int magic_damage) {
	if(magic_damage > 0) {
		m_magic_damage = magic_damage;
	}
}

void Weapon::set_worth(int worth) {
	if(worth > 0) {
		m_worth = worth;
	}
}

//Getters

std::string Weapon::get_name() {
	return m_name;
}

std::string Weapon::get_raraty() {
	return m_raraty;
}

int Weapon::get_damage() {
	return m_damage_stat;
}

bool Weapon::check_is_magic() {
	return m_is_magic;
}

int Weapon::get_magic_damage() {
	return m_magic_damage;
}

int Weapon::get_worth() {
	return m_worth;
}