#ifndef STATETWO_H
#define STATETWO_H
#include "igame-state.h"

class StateTwo : public IGameState {
public:
	void Init();
	void Cleanup();
	void Pause();
	void Resume();
	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Draw(GameEngine* game);
	static StateTwo* Instance() { return &m_StateTwo; }

protected:
	StateTwo() {}

private:
	static StateTwo m_StateTwo;

};
#endif // !STATETWO_H
