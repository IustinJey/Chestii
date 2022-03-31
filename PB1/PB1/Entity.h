#pragma once
#include "patrat.hpp"

class Entity {
private:
	Patrat patrate[100];
	int length;
public:
	// CONSTRUCTOR
	Entity();

	// DESTRUCTOR
	~Entity() = default;

	// SETTERI

	// GETTERI
	int get_lenght();
	Patrat* get_patrate();

	// FUNCTIONALITATI
	void ADD_PATRAT();
	void ADD_PATRAT(Patrat);
	void SHOW_ALL();
	Patrat BIGGEST_ENTITY();
	Entity DIAL_ONE();
	Entity SEQUENCE();

};