
#include <SDL2/SDL.h>
#include "graphics.h"

/*Graphics class
 * Holds all info dealing with graphics for the game.
 */

Graphics::Graphics(){
	SDL_CreateWindowAndRenderer(640, 480, 0, &this->_window, &this->_renderer);
	SDL_SetWindowTitle(this->_window, "CavestoryClone");
}

Graphics::~Graphics(){
	SDL_DestroyWindow(this->_window);
}

