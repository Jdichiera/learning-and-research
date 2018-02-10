//
//  game.hpp
//  city
//
//  Created by Dichiera, Jeramy on 3/29/17.
//  Copyright © 2017 Dichiera, Jeramy. All rights reserved.
//

#ifndef GAME_HPP
#define GAME_HPP

#include <stack>
#include <SFML/Graphics.hpp>

class GameState;

class Game{
    public:
    
    std::stack<GameState*> states;
    
    sf::RenderWindow window;
    
    void pushState(GameState* state);
    void popState();
    void changeState(GameState* state);
    GameState* peekState();
    
    void gameLoop();
    
    Game();
    ~Game();
};


#endif /* GAME_HPP */
