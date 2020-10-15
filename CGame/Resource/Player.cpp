#pragma once
#include"../Headers/Player.h"
#include "../Headers/Weapon.h"
Player::Player() {};
Player::Player(std::string name, int hp, int mana) {
	set_name(name);
	set_hp(hp);
	set_mana(mana);
	set_level(1);
	set_exp(0);
	set_money(0);
}

//accessors 
const std::string Player::get_name() {
	return m_name;
}
const int Player::get_hp() {
	return m_heath;
}
const int Player::get_mana() {
	return m_mana;
}
const int Player::get_current_mana() {
	return m_current_mana;
}
const int Player::get_level() {
	return m_level;
}
const int Player::get_exp() {
	return m_exp;
}
const int Player::get_money() {
	return m_money;
}
const int Player::get_damage() {
	return m_damage;
}
const int Player::get_armour() {
	return m_armour;
}
const void Player::set_abilities(std::vector<Ability> abilities) {
	 m_ablities = abilities;
}
const int Player::get_base_attack() {
	return m_base_attack;
}

//setters
void Player::set_base_damage(int base_attack) {
	m_base_attack = base_attack;
}

void Player::set_name(std::string name) {
	if(!name.empty())
	m_name = name;
}
void Player::set_hp(int hp) {
	m_heath = hp;
}
void Player::set_mana(int mana) {
	m_mana = mana;
}
void Player::set_current_mana(int current_mana) {
	 m_current_mana = current_mana;
}
void Player::set_level(int level) {
	m_level = level;
}
void Player::set_exp(int exp) {
	m_exp = exp;
}
void Player::set_money(int money) {
	m_money = money; 
}
void Player::set_damage(Weapon weapon) {
	if (&weapon == NULL) {
		m_damage = m_base_attack;
	}
	else if (&m_base_attack != NULL) {
		m_damage = m_base_attack + weapon.get_damage();
	}
	else if (&m_base_attack == NULL) {
		m_damage = weapon.get_damage();
	}

}
void Player::set_armour(Armer armer) {
	m_armour = armer.get_armer_value();
}

void Player::change_heath(int heath) {
	m_heath = m_heath + heath;
}
void Player::change_money(int price) {
	m_money = m_money + price;
}
void Player::change_mana(int mana_cost) {
	m_current_mana = m_current_mana - mana_cost;
}
// overloaded operator
void Player::operator+(const Weapon other) {
	set_damage(other);
}