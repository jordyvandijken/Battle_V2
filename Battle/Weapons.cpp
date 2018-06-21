#include "Weapons.h"

// Initialise weapons
//// melee
/// basic
// Fist
Weapon Weapons::fist = Fist();
/// mechanical

/// crafted

//// ranged
/// mechanical
// AK-47
Weapon Weapons::ak_47 = Ak_47();
/// crafted
Weapon Weapons::recurveBow = Recurve_bow();


Weapon Weapons::RandomWeapon() {
	int randomWeapon = rand() % 3;

	switch (randomWeapon)
	{
	case 1:
		return ak_47;
		break;
	case 2:
		return recurveBow;
		break;
	default:
		return fist;
		break;
	}
}


