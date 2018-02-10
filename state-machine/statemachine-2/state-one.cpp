#include "state-one.h"
#include "state-two.h"
#include "state-three.h"

void StateOne::Init()
{
	std::cout << "\n++[INIT] - StateOne.";
}

void StateOne::Cleanup()
{
	std::cout << "\n++[CLEANUP] - StateOne.";
}

void StateOne::Pause()
{
	std::cout << "\n++[PAUSE] - StateOne.";
}

void StateOne::Resume()
{
	std::cout << "\n++[RESUME] - StateOne.";
}

void StateOne::HandleEvents(GameEngine * game)
{
	int input = 0;
	std::cout << "\n++[HANDLEEVENTS] - StateOne.";
	std::cout << "\n======";
	std::cout << "\n\t1 - previous state.";
	std::cout << "\n\t2 - next state.";
	std::cout << "\n\t3 - pause state.";
	std::cout << "\n======";
	std::cin >> input;
	switch (input) {
		case 1:
			std::cout << "\nInitial state";
			break;
		case 2:
			game->ChangeState(StateTwo::Instance());
			break;
		case 3:
			game->PauseState(StateThree::Instance());
			break;
	}
}

void StateOne::Update(GameEngine * game)
{
	std::cout << "\n++[UPDATE] - StateOne.";
}

void StateOne::Draw(GameEngine * game)
{
	std::cout << "\n++[DRAW] - StateOne.";
}
