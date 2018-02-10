#include "soldier-child-gun.h"

SoldierChildGun::SoldierChildGun()
{
	ability = "Gun (from SoldierChildGun child class)";
	abilitiesList.push_back(ability);
	abilitiesList.push_back(getAbility());
}

void SoldierChildGun::printInfo()
{
	std::cout << "\n--== Soldier Child : Gun ==--";
	std::cout << "\nParent class: Soldier";
	std::cout << "\n=Combined Abilities=";
	for (std::string ability : abilitiesList) {
		std::cout << std::endl << ability << std::endl;
	}
}

std::vector<std::string> SoldierChildGun::getSoldierAbilities()
{
	return abilitiesList;
}
