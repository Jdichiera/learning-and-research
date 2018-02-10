#ifndef STATEONE_H
#define STATEONE_H
#include "igame-state.h"

class StateOne : public IGameState {
public:
	void Init();
	void Cleanup();
	void Pause();
	void Resume();
	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Draw(GameEngine* game);
	static StateOne* Instance() { return &m_StateOne; }

protected:
	StateOne() {}

private:
	static StateOne m_StateOne;

};
#endif // !STATEONE_H
