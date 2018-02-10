#include "alien.h"

Alien::Alien()
{
	ability = "Teeth (From Alien base class)";
}

std::string Alien::getAbility()
{
	return ability;
}

void Alien::printInfo()
{
}
