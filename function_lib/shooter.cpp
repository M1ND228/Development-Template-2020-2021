#include "shooter.h"

std::string Gun::attack(int &enemyHealth)
{
	std::string output = "";
	if (patrons > 0)
	{
		patrons--;													// test
		if (patrons == 0) output = "Patrony konchelys";				// test
		enemyHealth -= damage;
		if (enemyHealth <= 0) output = "Your Win";					// test
	}
	else
	{
		output = "Your miss attack!";								// test
	}
	return output;
}
