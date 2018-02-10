#include <iostream>
#include "alien.h"
#include "hybrid-soldier-alien-fly-knife.h"
#include "hybrid-soldier-alien-fly-gun.h"
#include "hybrid-soldier-alien-hide-knife.h"
#include "hybrid-soldier-alien-hide-missle.h"
#include "hybrid-soldier-alien-jump-gun.h"
int main() {
	HybridSoldierAlienFlyKnife hybrid1;
	HybridSoldierAlienFlyGun hybrid2;
	HybridSoldierAlienHideKnife hybrid3;
	HybridSoldierAlienHideMissle hybrid4;
	HybridSoldierAlienJumpGun hybrid5;
	hybrid1.printInfo();
	hybrid2.printInfo();
	hybrid3.printInfo();
	hybrid4.printInfo();
	hybrid5.printInfo();

	std::cout << std::endl;
	system("pause");
	return 0;
}