//
//  Game.cpp
//  sfml_snake
//
//  Created by Filip Peterek on 23.06.16.
//  Copyright © 2016 Filip Peterek. All rights reserved.
//

#include "Game.hpp"


/* Methods of class Game */

Game::Game() {
    sf::VideoMode vm = sf::VideoMode::getFullscreenModes().at(0);
    
    _window.create(vm, "Snake", sf::Style::Fullscreen);
    _window.setMouseCursorVisible(false);
    _window.setVerticalSyncEnabled(true);
    _window.setFramerateLimit(60);
    
    _sizeFactor = (float)vm.width / 800.0f;
}

void Game::GameLoop() {
    
}