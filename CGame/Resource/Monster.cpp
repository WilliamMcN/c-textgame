#include "../Headers/Monster.h"

Monster::Monster() {

};

Monster::Monster(std::string name, std::string env, int hp, int level, int xp_value, int attack) {

};
Monster::Monster(std::string name, int hp, int attack)
{
	set_name(name);
	set_hp(hp);
	set_attack(attack);
};


/*
* Mutator
* Assigns member_hp value
* Restraints - hp must be greater than five and can not be more than 1000
*/
void Monster::set_hp(int hp) {
		m_hp = hp;
}

/*
* Mutator
* assigns name to the monster
* Restraints - String must not be empty or null
*/
void Monster::set_name(std::string name) {
	if(!name.empty()) {
		m_name = name;
	}
}

void Monster::set_env(std::string env) {
	if(!env.empty()) {
		m_env = env;
	}
}

/*
* Mutator
* Assigns level of monster
* Restraints - level can not be less than one and no greater than 100
*/
void Monster::set_level(int level) {
	if(level > 0 && level < 101) {
		m_level = level;
	}
}

/*
* Mutator
* Assigns xp value of monster
* Restraints - can not be less than 10 and no greater than 1000
*/
void Monster::set_xp_value(int xp_value) {
	if(xp_value > 9 && xp_value < 1001) {
		m_xp_value = xp_value;
	}
}

/*
* Mutator
* Assigns Weapon to monster
* Restraints of Weapon class
*/
void Monster::set_attack(int attack) {
	m_attack = attack;
}


/*
* Mutator
* Takes off health. checks for death.
*/
bool Monster::has_died(int damage) {
	if(m_hp > damage) {
		m_hp -= damage;
		return false;
	} else if(damage >= m_hp) {
		return true;
	}
	return false;
}

const int Monster::get_hp() {
	return m_hp;
}

const std::string Monster::get_name() {
	return m_name;
}

const std::string Monster::get_env() {
	return m_env;
}

const int Monster::get_level() {
	return m_level;
}

const int Monster::get_xp_value() {
	return m_xp_value;
}

const int Monster::get_attack() {
	return m_attack;
}

