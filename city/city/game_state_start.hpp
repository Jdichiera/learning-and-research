//
//  game_state_start.hpp
//  city
//
//  Created by Dichiera, Jeramy on 3/29/17.
//  Copyright © 2017 Dichiera, Jeramy. All rights reserved.
//

#ifndef GAME_STATE_START_HPP
#define GAME_STATE_START_HPP

#include <SFML/Graphics.hpp>

#include "game_state.hpp"

class GameStateStart : public GameState{
    private:
    
        sf::View view;
    
    public:
    
        virtual void draw(const float dt);
        virtual void update(const float dt);
        virtual void handleInput();
    
        GameStateStart(Game* game);
};

#endif /* GAME_STATE_START_HPP */
