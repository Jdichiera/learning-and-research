#include "soldier-child-knife.h"

SoldierChildKnife::SoldierChildKnife()
{
	ability = "Knife (from SoldierChildKnife child class)";
	abilitiesList.push_back(ability);
	abilitiesList.push_back(getAbility());
}

void SoldierChildKnife::printInfo()
{
	std::cout << "\n--== Soldier Child : Knife ==--";
	std::cout << "\nParent class: Soldier";
	std::cout << "\n=Combined Abilities=";
	for (std::string ability : abilitiesList) {
		std::cout << std::endl << ability << std::endl;
	}
}

std::vector<std::string> SoldierChildKnife::getSoldierAbilities()
{
	return abilitiesList;
}
