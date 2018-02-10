#ifndef IGAMESTATE_H
#define IGAMESTATE_H
#include "game-engine.h"
#include <iostream>

class IGameState {
public:
	virtual void Init() = 0;
	virtual void Cleanup() = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void HandleEvents(GameEngine* game) = 0;
	virtual void Update(GameEngine* game) = 0;
	virtual void Draw(GameEngine* game) = 0;

	void ChangeState(GameEngine* game, IGameState* state) {
		game->ChangeState(state); 
	}
protected:
	IGameState() {}
};
#endif // !IGAMESTATE_H
