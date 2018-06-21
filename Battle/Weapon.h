#pragma once
#include <string>

using namespace std;

class Weapon
{
public:
	Weapon();
	~Weapon();

	// the weapon variables basic
	float meleeDamage;
	float rangedDamage;
	float critMultiplier;

	string name;
	int range;

	static const enum Range
	{
		melee,
		ranged
	};
};

