#ifndef STATETHREE_H
#define STATETHREE_H
#include "igame-state.h"

class StateThree : public IGameState {
public:
	void Init();
	void Cleanup();
	void Pause();
	void Resume();
	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Draw(GameEngine* game);
	static StateThree* Instance() { return &m_StateThree; }

protected:
	StateThree() {}

private:
	static StateThree m_StateThree;

};
#endif // !STATETHREE_H
