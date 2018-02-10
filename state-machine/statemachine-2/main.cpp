// https://gamedevelopment.tutsplus.com/tutorials/finite-state-machines-theory-and-implementation--gamedev-11867
// http://gamedevgeek.com/tutorials/managing-game-states-in-c/

#include "game-engine.h"
#include "state-one.h"
#include "state-two.h"
#include "state-three.h"

int main() {
	GameEngine game;
	game.Init();
	game.ChangeState(StateOne::Instance());

	while (game.Running()) {
		game.HandleEvents();
		game.Update();
		game.Draw();
	}

	game.Cleanup();

	system("PAUESE");

	return 0;
}