#include "BoringMachine.h"

BoringMachine::BoringMachine()
{
	m_state = BoringState();
}

IState BoringMachine::CurrentState()
{
	return m_state;
}

std::vector<std::string> BoringMachine::PossibleTransactions()
{
	return std::vector<std::string>();
}

bool BoringMachine::Advance(std::string nextState)
{
	std::cout << "[Boring State Machine] - Advancing state" << std::endl;
	return m_state.Advance();
}

bool BoringMachine::IsComplete()
{
	return m_state.IsComplete();
}
