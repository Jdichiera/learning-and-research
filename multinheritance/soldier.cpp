#include "soldier.h"

Soldier::Soldier()
{
	ability = "Armor (From Soldier base class)";
}

std::string Soldier::getAbility()
{
	return ability;
}

void Soldier::printInfo()
{
}
