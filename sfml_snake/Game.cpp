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

Food::Food(float sizeFactor, int width, int height) {
    
    setFillColor(sf::Color::Magenta);
    setSize(sf::Vector2f(DEFAULT_FOOD_SIZE * sizeFactor, DEFAULT_FOOD_SIZE * sizeFactor));
    
    _windowWidth = width;
    _windowHeight = height;
    
    _foodSize = int(DEFAULT_FOOD_SIZE * sizeFactor);
    
    newFood();
    
}

void Food::newFood() {
    
    setPosition(rand() % (_windowWidth - (2 * _foodSize)) + _foodSize, rand() % (_windowHeight - (2 * _foodSize)) + _foodSize);
    
}

sf::Vector2f Food::position() {
    
    return getPosition();
    
}

/* Methods of class Game */

Game::Game() {
    
    srand(unsigned(time(nullptr)));
    
    const sf::VideoMode vm = sf::VideoMode::getFullscreenModes().at(0);
    
    _window.create(vm, "Snake", sf::Style::Fullscreen);
    _window.setMouseCursorVisible(false);
    _window.setVerticalSyncEnabled(true);
    _window.setFramerateLimit(10);
    
    _sizeFactor = (float)vm.width / 800.0f;
    
    _width = vm.width;
    _height = vm.height;
}

void Game::gameLoop() {
    
    Snake snake(_sizeFactor, _width, _height);
    Food food(_sizeFactor, _width, _height);
    
    bool snakeIsAlive = true;
    int foodSize = DEFAULT_FOOD_SIZE * _sizeFactor;
    
    sf::Event event;
    
    sf::RectangleShape background;
    background.setSize(sf::Vector2f(_width, _height));
    background.setFillColor(sf::Color::Green);
    background.setPosition(0, 0);
    
    while (_window.isOpen() and snakeIsAlive) {
        
        /* Handle events */
        
        while (_window.pollEvent(event)) {
            
            if (event.type == sf::Event::Closed) {
                _window.close();
            }
            
            if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape) {
                _window.close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                snake.handleEvent(event);
            }
            
        }
        
        /* Perform calculations */
        
        snakeIsAlive = snake.move();
        
        if (snake.collisionWithFood(food.position(), foodSize)) food.newFood();
        
        /* Draw on screen */
        
        _window.clear();
        
        _window.draw(background);
        _window.draw(snake);
        _window.draw(food);
        
        _window.display();
        
    }
    
}