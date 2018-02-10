#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <vector>
#include "igame-state.h"
class IGameState;

class GameEngine {
public:
	// This is where you would init all of your SDL stuff
	void Init();
	void Cleanup();

	void ChangeState(IGameState* state);
	void PauseState(IGameState* state);

	void Unpause();

	void HandleEvents();
	void Update();
	void Draw();

	bool Running() { return m_running; }
	void Quit() { m_running = false; }

	//SDL_surface* screen;

private:
	std::vector<IGameState*> states;

	bool m_running;
	bool m_fullscreen;
};
#endif // !GAMEENGINE_H
