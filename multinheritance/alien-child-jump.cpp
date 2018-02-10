#include "alien-child-jump.h"

AlienChildJump::AlienChildJump() : Alien()
{
	ability = "Jump (from AlienChildJump child class)";
	abilitiesList.push_back(ability);
	abilitiesList.push_back(getAbility());
}

std::vector<std::string> AlienChildJump::getAlienAbilities()
{
	return abilitiesList;
}

void AlienChildJump::printInfo()
{
	std::cout << "\n--== Alien Child : Jump ==--";
	std::cout << "\nParent class: Alien";
	std::cout << "\n=Combined Abilities=";
	for (std::string ability : abilitiesList) {
		std::cout << std::endl << ability << std::endl;
	}
}
