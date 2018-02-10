#include "alien-child-fly.h"

AlienChildFly::AlienChildFly() : Alien()
{
	ability = "Fly (from AlienChildFly child class)";
	abilitiesList.push_back(ability);
	abilitiesList.push_back(getAbility());
}

std::vector<std::string> AlienChildFly::getAlienAbilities()
{
	return abilitiesList;
}

void AlienChildFly::printInfo()
{
	std::cout << "\n--== Alien Child : Fly ==--";
	std::cout << "\nParent class: Alien";
	std::cout << "\n=Combined Abilities=";
	for (std::string ability : abilitiesList) {
		std::cout << std::endl << ability << std::endl;
	}
}

