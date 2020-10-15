#include "../Headers/Armer.h"

Armer::Armer() {};
Armer::Armer(std::string name, int armer_value, int worth, bool is_magic, int magic_armer) {
	set_name(name);
	set_armer_value(armer_value);
	set_worth(worth);
	set_is_magic(is_magic);
	set_magic_armer(magic_armer);
}

void Armer::set_name(std::string name) {
	if(!name.empty()) {
		m_name = name;
	}
}

void Armer::set_armer_value(int armer_value) {
	if(armer_value > 0) {
		m_armer_value = armer_value;
	}
}

void Armer::set_worth(int worth) {
	if(worth > 0) {
		m_worth = worth;
	}
}

void Armer::set_is_magic(bool is_magic) {
	m_is_magic = is_magic;
}

void Armer::set_magic_armer(int magic_armer) {
	if(magic_armer > 0) {
		m_magic_armer = magic_armer;
	}
}

const std::string Armer::get_name() {
	return m_name;
}

const int Armer::get_armer_value() {
	return m_armer_value;
}

const int Armer::get_worth() {
	return m_worth;
}

const bool Armer::is_magic() {
	return m_is_magic;
}

const int Armer::get_magic_armer() {
	return m_magic_armer;
}