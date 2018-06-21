#pragma once
#include "Weapon.h"
#include "Fist.h"
#include "Ak_47.h"
#include "Recurve_bow.h"

class Weapons
{
public:
	// a list of existing weapons
	static Weapon fist;
	static Weapon ak_47;
	static Weapon recurveBow;

	// gives a random weapon
	static Weapon RandomWeapon();
};

