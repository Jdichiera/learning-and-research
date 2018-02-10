#include "BoringState.h"

std::string BoringState::GetName()
{
	return std::to_string(m_state);
}

void BoringState::Run()
{
}

bool BoringState::IsComplete()
{
	return m_state = SameOldStates::Done;
}

std::vector<std::string> BoringState::ListTransitions()
{
	std::vector<std::string> transitions;

	switch (m_state) {
	case SameOldStates::Enter:
		transitions.push_back("DoStuff");
		break;
	case SameOldStates::DoStuff:
		transitions.push_back("Exiting");
		break;
	case SameOldStates::Exiting:
		transitions.push_back("Done");
		break;
	case SameOldStates::Done:
		transitions.push_back("Done");
		break;
	}
	return transitions;
}

bool BoringState::Advance()
{
	switch (m_state) {
	case SameOldStates::Enter:
		m_state = SameOldStates::DoStuff;
		break;
	case SameOldStates::DoStuff:
		m_state = SameOldStates::Exiting;
		break;
	case SameOldStates::Exiting:
		m_state = SameOldStates::Done;
		break;
	case SameOldStates::Done:
		
		break;
	
	}
	return true;
}
