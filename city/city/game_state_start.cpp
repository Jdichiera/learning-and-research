//
//  game_state_start.cpp
//  city
//
//  Created by Dichiera, Jeramy on 3/29/17.
//  Copyright © 2017 Dichiera, Jeramy. All rights reserved.
//

#include <SFML/Graphics.hpp>

#include "game_state_start.hpp"
#include "game_state_editor.hpp"
#include "game_state.hpp"

void GameStateStart::draw(const float dt){
    this->game->window.setView(this->view);
    
    this->game->window.clear(sf::Color::Black);
    this->game->window.draw(this->game->background);
    
    return;
}

void GameStateStart::update(const float dt){
    
}

void GameStateStart::handleInput(){
    sf::Event event;
    
    while(this->game->window.pollEvent(event)){
        switch(event.type){
                
                //Close the window
            case sf::Event::Closed:{
                game->window.close();
                break;
            }
                //Resize the window
            case sf::Event::Resized:{
                this->view.setSize(event.size.width, event.size.height);
                this->game->background.setPosition(this->game->window
                                                   .mapPixelToCoords(sf::Vector2i(0, 0)));
                this->game->background.setScale(float(event.size.width) / float(this->game->background.getTexture()->getSize().x),float(event.size.height / float(this->game->background.getTexture()-getSize().y));
                break;
            }
            case sf::Event::KeyPressed:{
                if(event.key.code == sf::Keyboard::Escape) this->game->window.close();
                break;
            }
            default: break;
        }
                                                
    }
    return;
}