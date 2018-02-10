#ifndef BORINGMACHINE_H
#define BORINGMACHINE_H
#include "IStateMachine.h"
#include "BoringState.h"
class BoringMachine : public IStateMachine {
public:
	BoringMachine();
	IState CurrentState();
	std::vector<std::string> PossibleTransactions();
	bool Advance(std::string nextState);
	bool IsComplete();
	
	BoringState m_state;
};
#endif // !BORINGMACHINE
