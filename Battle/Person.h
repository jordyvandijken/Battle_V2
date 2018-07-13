#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "Weapon.h"
#include "Weapons.h"


class Person {
public:
	Person();
	~Person();
	static int id;
	int personID;

	// person stats
	float strength;
	float defense;
	float intelligence;
	float luck;
	float health;

	// persons items
	Weapon weapon;

	/// public functions
	// attack the person
	void AttackPerson(Person* p);
	// Receive damage
	void ReceiveDamage(int dam);
	// Heal the person
	void Heal(int heal);

	// search the erea
	void SearchErea();

	// TEMP::
	Weapons* weapons;

private:

	// random fill the stats
	void FillStats();
	// the action if the current weapon is melee
	void MeleeAttack(Person* p);
	// the action if the current weapon is ranged
	void RangeAttack(Person* p);
};

#endif