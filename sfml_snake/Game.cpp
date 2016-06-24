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

/* Constructor */

Food::Food(float sizeFactor, int width, int height) {
    
    setFillColor(sf::Color::Magenta);
    setSize(sf::Vector2f(DEFAULT_FOOD_SIZE * sizeFactor, DEFAULT_FOOD_SIZE * sizeFactor));
    
    _windowWidth = width;
    _windowHeight = height;
    
    _foodSize = int(DEFAULT_FOOD_SIZE * sizeFactor);
    
    newFood();
    
}

/* Generate new location */

void Food::newFood() {
    
    setPosition(rand() % (_windowWidth - (2 * _foodSize)) + _foodSize, rand() % (_windowHeight - (2 * _foodSize)) + _foodSize);
    
}

/* Methods of class Game */

/* Constructor */

Game::Game() {
    
    srand(unsigned(time(nullptr)));
    
    /* Temporary constant to store info about the currently selected VideoMode */
    /* Automatically chooses the best VideoMode available */
    
    const sf::VideoMode vm = sf::VideoMode::getFullscreenModes().at(0);
    
    /* Initialize window */
    
    _window.create(vm, "Snake", sf::Style::Fullscreen);
    _window.setMouseCursorVisible(false);
    _window.setVerticalSyncEnabled(true);
    _window.setFramerateLimit(10);
    
    /* Size factor is used to calculate the size of objects so that the object to screen ratio is the same on all monitors */
    
    _sizeFactor = (float)vm.width / 800.0f;
    
    _width = vm.width;
    _height = vm.height;
}

void Game::gameLoop() {
    
    /* Initialize variables */
    
    Snake snake(_sizeFactor, _width, _height);
    Food food(_sizeFactor, _width, _height);
    
    bool snakeIsAlive = true;
    int foodSize = DEFAULT_FOOD_SIZE * _sizeFactor;
    
    sf::Event event;
    
    sf::RectangleShape background;
    background.setSize(sf::Vector2f(_width, _height));
    background.setFillColor(sf::Color::Green);
    background.setPosition(0, 0);
    
    while (_window.isOpen()) {
        
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
        
        if (snakeIsAlive) {
        
            snakeIsAlive = snake.move();
        
            if ( snake.collisionWithFood(food.getPosition(), foodSize) ) food.newFood();
            
        }
        
        /* Draw on screen */
        
        _window.clear();
        
        _window.draw(background);
        _window.draw(snake);
        for (SnakePart & part : snake.getParts()) {
            _window.draw(part);
        }
        _window.draw(food);
        
        _window.display();
        
    }
    
}