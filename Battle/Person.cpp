#include "person.h"

int Person::id = 0;

Person::Person() {
	weapons = new Weapons();

	// random fill the stats
	this->FillStats();

	weapon = weapons->GetWeapon("Fist");

	// set the persons id
	personID = id;
	id++;
}

void Person::FillStats() {
	this->strength = rand() % 100 + 1;
	this->defense = rand() % 100 + 1;
	this->intelligence = rand() % 100 + 1;
	this->luck = rand() % 100 + 1;
	this->health = 100;
	cout << strength << " | " << defense << " | " << intelligence << " | " << luck << "\n";
}

void Person::AttackPerson(Person* p) {
	// TODO : based on nature does this person sneak, rush etc.

	// check what to do based on weapon range
	switch (this->weapon.range)
	{
	case this->weapon.melee:
		MeleeAttack(p);
		break;	
	case this->weapon.ranged:
		RangeAttack(p);
		break;
	default:
		break;
	}
}

void Person::MeleeAttack(Person* p) {
	// the damage
	/// D = 1 + p->defense / 100 
	/// T = this->weapon.meleeDamage * D
	/// T * this->strength / 100
	float _damage = (this->weapon.meleeDamage / (1 + p->defense / 100)) * this->strength / 100;

	// if the luck is higher then the random number
	/// luck/100 + 1 (ex: 1.23 luck = 23) else just the normal damage
	float mult = this->luck > (rand() % 100 + 1) ? ((this->luck/100) + 1) : 1;

	// if it needs to multiply
	if (mult > 1) {
		_damage = _damage * mult;
	}

	// give the person damage
	p->ReceiveDamage(_damage);
}

void Person::RangeAttack(Person* p) {
	// the damage
	/// D = 1 + p->defense / 100
	/// T = this->weapon.rangedDamage * D
	/// T * this->intelligence / 100
	float _damage = (this->weapon.rangedDamage / (1 + p->defense / 100)) * this->intelligence / 100;

	// if the luck is higher then the random number
	/// luck/100 + 1 (ex: 1.23 luck = 23) else just the normal damage
	float mult = this->luck > (rand() % 100 + 1) ? ((this->luck / 100) + 1) : 1;

	// if it needs to multiply
	if (mult > 1) {
		_damage = _damage * mult;
	}

	// give the person damage
	p->ReceiveDamage(_damage);
	cout << this->personID << "|| dealt: " << _damage << " to " << p->personID << " | the stats are | " << this->weapon.name << " | " << this->intelligence  << " | " << p->defense <<  "\n";
}

void Person::ReceiveDamage(int dam) {
	this->health -= dam;
}

// search things
void Person::SearchErea() {
	// like finding thins, hurting himself to something, finding a other person ect

	// Currently add one
	int randomEvent = rand() % 2 + 1;

	// if the person finds a random weapon
	Weapon randomFoundWeapon = weapons->RandomWeapon();

	switch (randomEvent)
	{
	case 1:
		// check if it isnt the same weapon
		if (randomFoundWeapon.name != this->weapon.name)
		{
			// check the found weapon range type
			if (randomFoundWeapon.range == Weapon::melee)
			{
				// check the current weapon range type
				if (this->weapon.range == Weapon::melee)
				{
					// if the found weapon is stonger for the user  use that weapon - for current melee & found melee
					if ((this->weapon.meleeDamage * this->strength / 100) < randomFoundWeapon.meleeDamage * this->strength / 100)
					{
						this->weapon = randomFoundWeapon;
					}
				}
				else {
					// if the found weapon is stonger for the user  use that weapon - for current ranged & found melee
					if ((this->weapon.rangedDamage * this->intelligence / 100) < randomFoundWeapon.meleeDamage * this->strength / 100)
					{
						this->weapon = randomFoundWeapon;
						cout << personID << "|| New Weapon: " << this->weapon.name << "\n";
					}
				}
			}
			else {
				// check the current weapon range type
				if (this->weapon.range == Weapon::ranged)
				{
					// if the found weapon is stonger for the user  use that weapon - for current ranged & found ranged
					if ((this->weapon.rangedDamage * this->intelligence / 100) < randomFoundWeapon.rangedDamage * this->intelligence / 100)
					{
						this->weapon = randomFoundWeapon;
						cout << personID << "|| New Weapon: " << this->weapon.name << "\n";
					}
				}
				else {
					// if the found weapon is stonger for the user  use that weapon - for current melee & found ranged
					if ((this->weapon.meleeDamage * this->strength / 100) < randomFoundWeapon.rangedDamage * this->intelligence / 100)
					{
						this->weapon = randomFoundWeapon;
					}
				}
			}
		}
		break;
	case 2:
		// TODO: the person can find something to recieve health back (medic kit, badages etc)
		Heal(10 / this->intelligence/100);
		break;
	default: // dunno yet 
		break;
	}
}

void Person::Heal(int heal) {

}

Person::~Person()
{

}