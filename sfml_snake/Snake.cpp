//
//  Snake.cpp
//  sfml_snake
//
//  Created by Filip Peterek on 23.06.16.
//  Copyright © 2016 Filip Peterek. All rights reserved.
//

#include "Snake.hpp"

#define DEBUG


Snake::Snake(float sizeFactor, int width, int height) {
    
    setPosition(width / 2, height / 2);
    setSize(sf::Vector2f(DEFAULT_SNAKE_SIZE * sizeFactor, DEFAULT_SNAKE_SIZE * sizeFactor));
    setFillColor(sf::Color::Red);
    
    _sizeFactor = sizeFactor;
    
    _windowWidth = width;
    _windowHeight = height;
    
    _snakeSize = int(DEFAULT_SNAKE_SIZE * sizeFactor);
    
}

void Snake::handleEvent(sf::Event & event) {
    
#ifndef DEBUG
    
    switch (event.key.code) {
        
        case sf::Keyboard::W:
            if (_dir != down) _dir = up;
            break;
        
        case sf::Keyboard::A:
            if (_dir != right) _dir = left;
            break;
            
        case sf::Keyboard::D:
            if (_dir != left) _dir = right;
            break;
            
        case sf::Keyboard::S:
            if (_dir != up) _dir = down;
            break;
            
        default:
            break;
            
    }
    
#else
    
    static Direction oldDir;
    
    switch (event.key.code) {
            
        case sf::Keyboard::W:
            _dir = up;
            break;
            
        case sf::Keyboard::A:
            _dir = left;
            break;
            
        case sf::Keyboard::D:
            _dir = right;
            break;
            
        case sf::Keyboard::S:
            _dir = down;
            break;
            
        case sf::Keyboard::Space:
            if (_dir != none) { oldDir = _dir; _dir = none; }
            else _dir = oldDir;
            break;
            
        default:
            break;
            
    }
    
#endif
    
}


bool Snake::move() {
    
    if (_dir == none) return true;
    
    float posX = getPosition().x;
    float posY = getPosition().y;
    
    switch (_dir) {
            
        case up:
            posY -= _snakeSize;
            break;
            
        case down:
            posY += _snakeSize;
            break;
            
        case left:
            posX -= _snakeSize;
            break;
            
        case right:
            posX += _snakeSize;
            break;
            
        default:
            break;
    }
    
    if (posX < 0) posX = _windowWidth - _snakeSize;
    else if (posX > _windowWidth) posX = 0;
    
    if (posY < 0) posY = _windowHeight - _snakeSize;
    else if (posY >=_windowHeight) posY = 0;
    
    setPosition(posX, posY);
    
    return true;
    
}


















