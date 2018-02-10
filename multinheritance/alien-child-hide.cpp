#include "alien-child-hide.h"

AlienChildHide::AlienChildHide() : Alien()
{
	ability = "Hide (from AlienChildHide child class)";
	abilitiesList.push_back(ability);
	abilitiesList.push_back(getAbility());
}

std::vector<std::string> AlienChildHide::getAlienAbilities()
{
	return abilitiesList;
}

void AlienChildHide::printInfo()
{
	std::cout << "\n--== Alien Child : Hide ==--";
	std::cout << "\nParent class: Alien";
	std::cout << "\n=Combined Abilities=";
	for (std::string ability : abilitiesList) {
		std::cout << std::endl << ability << std::endl;
	}
}
