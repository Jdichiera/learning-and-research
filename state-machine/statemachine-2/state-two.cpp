#include "state-one.h"
#include "state-two.h"
#include "state-three.h"

void StateTwo::Init()
{
	std::cout << "\n++[INIT] - StateTwo.";
}

void StateTwo::Cleanup()
{
	std::cout << "\n++[CLEANUP] - StateTwo.";
}

void StateTwo::Pause()
{
	std::cout << "\n++[PAUSE] - StateTwo.";
}

void StateTwo::Resume()
{
	std::cout << "\n++[RESUME] - StateTwo.";
}

void StateTwo::HandleEvents(GameEngine * game)
{
	std::cout << "\n++[HANDLEEVENTS] - StateTwo.";
	int input = 0;
	std::cout << "\n======";
	std::cout << "\n\t1 - previous state.";
	std::cout << "\n\t2 - next state.";
	std::cout << "\n\t3 - pause state.";
	std::cout << "\n======";
	std::cin >> input;
	switch (input) {
	case 1:
		game->ChangeState(StateOne::Instance());
		break;
	case 2:
		std::cout << "\nNo next state";
		break;
	case 3:
		game->PauseState(StateThree::Instance());
		break;
	}
}

void StateTwo::Update(GameEngine * game)
{
	std::cout << "\n++[UPDATE] - StateTwo.";
}

void StateTwo::Draw(GameEngine * game)
{
	std::cout << "\n++[DRAW] - StateTwo.";
}
