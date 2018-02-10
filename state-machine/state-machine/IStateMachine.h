#ifndef ISTATEMACHINE_H
#define ISTATEMACHINE_H
#include "IState.h"
#include <vector>

class IStateMachine {
public:
	virtual IState CurrentState() { return IState(); }
	virtual std::vector<std::string> PossibleTransitions() { return std::vector<std::string>(); }
	virtual bool Advance(std::string nextState) { return true; }
	virtual bool IsComplete() { return true; }
private:

};
#endif // !ISTATEMACHINE
