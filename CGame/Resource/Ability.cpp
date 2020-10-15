#include "../Headers/Ability.h"
// Constructors
Ability::Ability() {}

Ability::Ability(std::string name, std::string description, int damage, int mana_cost) {
	set_name(name);
	set_description(description);
	set_damage(damage);
	set_mana_cost(mana_cost);
}

// Getters
const std::string Ability::get_name() {
	return m_name;

}

const std::string Ability::get_description() {
	return m_description;

}

int Ability::get_damage() {
	return m_damage;

}

int Ability::get_mana_cost() {
	return m_mana_cost;

}

//Setters
void Ability::set_name(std::string name) {
	if(!name.empty()) {
		m_name = name;

	}

} 

void Ability::set_description(std::string description) {
	if(!description.empty()) {
		m_description = description;

	}

}

void Ability::set_damage(int damage) {
	if(damage > 0) {
		m_damage = damage;
	}

}

void Ability::set_mana_cost(int mana_cost) {
	if(mana_cost > 0) {
		m_mana_cost = mana_cost;
	}
}