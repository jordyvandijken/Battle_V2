#pragma once

#include <map>
#include <time.h>
#include <string>
#include <functional>

#include "Weapon.h"
#include "fist.h"
#include "ak_47.h"
#include "recurve_bow.h"

class WeaponContainer
{
private:
	std::string m_strWeaponName;
	Weapon* m_weapon;

public:
	std::function<Weapon*()> m_fAllocator;

	WeaponContainer(std::string a_strWeaponName) {
		this->m_strWeaponName = a_strWeaponName;
		m_weapon = NULL;
	};

	~WeaponContainer() {
		if (Available())
		{
			delete m_weapon;
		}
	}

	template<class T>
	void SetWeaponType() {
		m_fAllocator = [this]() {
			this->m_weapon = ((Weapon*) new T());
			return m_weapon;
		};
	}

	Weapon* Allocate() {
		return m_fAllocator();
	}

	void Free() {
		delete m_weapon;
		m_weapon = NULL;
	}

	bool Available() {
		return m_weapon != NULL;
	}

	Weapon* GetWeapon() {
		return m_weapon;
	}

};


class Weapons
{
private:

	std::map<std::string, WeaponContainer*> m_mWeapons;
public:

	Weapons();

	~Weapons();

	template<class T>
	void RegisterWeapon(std::string a_strWeaponname);

	Weapon GetWeapon(std::string a_strWeaponName);

	Weapon RandomWeapon();
};

template <class T>
void Weapons::RegisterWeapon(std::string a_strWeaponName) {
	static_assert(std::is_base_of<Weapon, T>::value);

	WeaponContainer* container = new WeaponContainer(a_strWeaponName);
	container->SetWeaponType<T>();

	m_mWeapons.emplace(a_strWeaponName, container);
}

