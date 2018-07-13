#include "Weapons.h"

Weapons::Weapons() {
	RegisterWeapon<Fist>("Fist");
	RegisterWeapon<Ak_47>("Ak_47");
	RegisterWeapon<Recurve_bow>("Recurve_bow");
}

Weapons::~Weapons() {
	std::map<std::string, WeaponContainer*>::iterator it = m_mWeapons.begin();
	
	while (it != m_mWeapons.end())
	{
		delete it->second;
		it++;
	}

	m_mWeapons.clear();
}

Weapon Weapons::GetWeapon(std::string a_strWeaponName) {
	std::map<std::string, WeaponContainer*>::iterator weapon = m_mWeapons.find(a_strWeaponName);

	if (weapon != m_mWeapons.end())
	{
		WeaponContainer* container = weapon->second;

		if (container->Available()) {
			container->Free();
		}

		if (!container->Available()) {
			container->Allocate();
			return *container->GetWeapon();
		}
		else {
			return *container->GetWeapon();
		}
	}
}

Weapon Weapons::RandomWeapon() {
	std::map<std::string, WeaponContainer*>::iterator weapons;
	auto it = m_mWeapons.begin();
	std::advance(it, rand() % m_mWeapons.size());
	WeaponContainer* container = it->second;

	if (!container->Available()) {
		container->Allocate();
		return *container->GetWeapon();
	}
	else {
		return *container->GetWeapon();
	}
}
