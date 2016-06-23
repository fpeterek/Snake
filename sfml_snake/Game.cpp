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

#include "Snake.hpp"

/* Methods of class Food */

Food::Food(float sizeFactor) {
    setFillColor(sf::Color::Magenta);
    setSize(sf::Vector2f(20 * sizeFactor, 20 * sizeFactor));
    setPosition(rand() % 800 * _sizeFactor, rand() % 450 * _sizeFactor);
}

void Food::newFood() {
    setPosition(rand() % 800 * _sizeFactor, rand() % 450 * _sizeFactor);
}

sf::Vector2f Food::position() {
    return getPosition();
}

/* Methods of class Game */

Game::Game() {
    
    sf::VideoMode vm = sf::VideoMode::getFullscreenModes().at(0);
    
    _window.create(vm, "Snake", sf::Style::Fullscreen);
    _window.setMouseCursorVisible(false);
    _window.setVerticalSyncEnabled(true);
    _window.setFramerateLimit(60);
    
    _sizeFactor = (float)vm.width / 800.0f;
    
    _height = vm.height;
    _width = vm.width;
}

void Game::gameLoop() {
    
    Snake snake(_sizeFactor);
    
    sf::Event event;
    
    sf::RectangleShape background;
    background.setSize(sf::Vector2f(800 * _sizeFactor, 450 * _sizeFactor));
    background.setFillColor(sf::Color::Green);
    background.setPosition(0, 0);
    
    while (_window.isOpen()) {
        
        /* Handle events */
        
        while (_window.pollEvent(event)) {
            
            if (event.type == sf::Event::Closed) {
                _window.close();
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                _window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                snake.handleEvent(event);
            }
            
        }
        
        /* Perform calculations */
        
        
        /* Draw on screen */
        
        _window.clear();
        
        _window.draw(background);
        _window.draw(snake);
        
        _window.display();
        
    }
}