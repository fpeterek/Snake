//
//  Game.cpp
//  sfml_snake
//
//  Created by Filip Peterek on 23.06.16.
//  Copyright © 2016 Filip Peterek. All rights reserved.
//

#include <cstdlib>
#include <ctime>

#include "Game.hpp"


/* Methods of class Food */

Food::Food(float sizeFactor) {
    setFillColor(sf::Color::Magenta);
    setSize(sf::Vector2f(20 * sizeFactor, 20 * sizeFactor));
    setPosition(rand() % 800 * _sizeFactor, rand() % 450 * _sizeFactor);
}

void Food::newFood() {
    setPosition(rand() % 800 * _sizeFactor, rand() % 450 * _sizeFactor);
}

/* Methods of class Game */

Game::Game() {
    
    sf::VideoMode vm = sf::VideoMode::getFullscreenModes().at(0);
    
    _window.create(vm, "Snake", sf::Style::Fullscreen);
    _window.setMouseCursorVisible(false);
    _window.setVerticalSyncEnabled(true);
    _window.setFramerateLimit(60);
    
    _sizeFactor = (float)vm.width / 800.0f;
}

void Game::gameLoop() {
    
}