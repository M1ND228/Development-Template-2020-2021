#ifndef INCLUDE_SHOOTER_H_
#define INCLUDE_SHOOTER_H_

#include <iostream>
#include <string>

// class Weapon -> 
// damage
// attack(&enemyHealth)
// consrt

// -> class Gun; class knife
// patrons
// attack();

// Gameplay;
// Gun knife
// attack(key, &enemyHealth)

class Weapon {
protected:
	int damage;
public:
	int getDamage() { return this->damage; };
	Weapon(int _damage = 10) : damage(_damage)
	{
		if (_damage <= 0) throw std::logic_error("Input error");
	};
	virtual std::string attack(int &enemyHealth) { return "";  };
};


class Gun : public Weapon {
	int patrons;

public:
	Gun(int _patrons = 8) : Weapon(), patrons(_patrons) {};
	Gun(int _damage, int _patrons = 8) : Weapon(_damage), patrons(_patrons) {};
	std::string attack(int &enemyHealth);
};

class Knife : public Weapon {
private:
	bool inStock;
public:
	Knife() : Weapon(), inStock(true) {};
	Knife(int _damage) : Weapon(_damage), inStock(true) {};
	std::string attack(int &enemyHealth);
};


class Gameplay {
	Gun ownGun;
	Knife ownKnife;
public:
	std::string attack(std::string key, int &enemyHealth);
};
#endif  // INCLUDE_ADD_H_