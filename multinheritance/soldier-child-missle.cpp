#include "soldier-child-missle.h"

SoldierChildMissle::SoldierChildMissle()
{
	ability = "Missle (from SoldierChildMissle child class)";
	abilitiesList.push_back(ability);
	abilitiesList.push_back(getAbility());
}

void SoldierChildMissle::printInfo()
{
	std::cout << "\n--== Soldier Child : Missle ==--";
	std::cout << "\nParent class: Soldier";
	std::cout << "\n=Combined Abilities=";
	for (std::string ability : abilitiesList) {
		std::cout << std::endl << ability << std::endl;
	}
}

std::vector<std::string> SoldierChildMissle::getSoldierAbilities()
{
	return abilitiesList;
}
