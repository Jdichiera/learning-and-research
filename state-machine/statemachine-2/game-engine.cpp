#include "game-engine.h"

void GameEngine::Init()
{
	// Do all of your SDL stuff
	m_running = true;
}

void GameEngine::Cleanup()
{
	while (!states.empty()) {
		states.back()->Cleanup();
		states.pop_back();
	}

	// Do other SDL cleanup activities and quit SDL
}

void GameEngine::ChangeState(IGameState * state)
{
	// Clean the current state which is at the back of the vector
	if (!states.empty()) {
		states.back()->Cleanup();
		states.pop_back();
	}

	// Store and init the new state
	states.push_back(state);
	states.back()->Init();
}

void GameEngine::PauseState(IGameState * state)
{
	// Pause the current state and add another one onto the stack
	if (!states.empty()) {
		states.back()->Pause();
	}
	states.push_back(state);
	states.back()->Init();
}

void GameEngine::Unpause()
{
	// Clean up the current state
	if (!states.empty()) {
		states.back()->Cleanup();
		states.pop_back();
	}

	// Resume the state
	if (!states.empty()) {
		states.back()->Resume();
	}
}

void GameEngine::HandleEvents()
{
	states.back()->HandleEvents(this);
}

void GameEngine::Update()
{
	states.back()->Update(this);
}

void GameEngine::Draw()
{
	states.back()->Draw(this);
}
