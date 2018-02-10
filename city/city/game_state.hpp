//
//  game_state.hpp
//  city
//
//  Created by Dichiera, Jeramy on 3/29/17.
//  Copyright © 2017 Dichiera, Jeramy. All rights reserved.
//

#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "game.hpp"

class GameState{
    public:
    
        Game* game;
    
        virtual void draw(const float dt) = 0;
        virtual void update(const float dt) = 0;
        virtual void handleInput() = 0;
};

#endif /* GAME_STATE_HPP */
