#ifndef BORINGSTATE_H
#define BORINGSTATE_H
#include <iostream>
#include <vector>
#include <string>
#include "IState.h"
class BoringState : public IState {
	enum SameOldStates {
		Enter,
		DoStuff,
		Exiting,
		Done
	};

public:
	std::string GetName();
	void Run();
	bool IsComplete();
	std::vector<std::string> ListTransitions();
	bool Advance();

private:
	SameOldStates m_state = SameOldStates::Enter;


};
#endif // !BORINGSTATE_H
