#include "state-one.h"
#include "state-two.h"
#include "state-three.h"

void StateThree::Init()
{
	std::cout << "\n++[INIT] - StateThree.";
}

void StateThree::Cleanup()
{
	std::cout << "\n++[CLEANUP] - StateThree.";
}

void StateThree::Pause()
{
	std::cout << "\n++[PAUSE] - StateThree.";
}

void StateThree::Resume()
{
	std::cout << "\n++[RESUME] - StateThree.";
}

void StateThree::HandleEvents(GameEngine * game)
{
	std::cout << "\n++[HANDLEEVENTS] - StateThree.";
	int input = 0;
	std::cout << "\n======";
	std::cout << "\n\t1 - unpause.";
	std::cout << "\n======";
	std::cin >> input;
	if (input == 1) {
		game->Unpause();
	}
}

void StateThree::Update(GameEngine * game)
{
	std::cout << "\n++[UPDATE] - StateThree.";
}

void StateThree::Draw(GameEngine * game)
{
	std::cout << "\n++[DRAW] - StateThree.";
}
