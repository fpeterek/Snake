//
//  Snake.cpp
//  sfml_snake
//
//  Created by Filip Peterek on 23.06.16.
//  Copyright © 2016 Filip Peterek. All rights reserved.
//

#include <cmath>

#include "Snake.hpp"


/* SnakePart */

/* Constructor */

SnakePart::SnakePart(sf::Vector2f pos, float sizeFactor) {
    setPosition(pos);
    setFillColor(sf::Color::Red);
    setSize(sf::Vector2f(DEFAULT_SNAKE_SIZE * sizeFactor, DEFAULT_SNAKE_SIZE * sizeFactor));
    
    _sizeFactor = sizeFactor;
}


/* Snake */

/* Constructor */

Snake::Snake(float sizeFactor, int width, int height) {
    
    setPosition(width / 2, height / 2);
    setSize(sf::Vector2f(DEFAULT_SNAKE_SIZE * sizeFactor, DEFAULT_SNAKE_SIZE * sizeFactor));
    setFillColor(sf::Color::Red);
    
    _sizeFactor = sizeFactor;
    
    _windowWidth = width;
    _windowHeight = height;
    
    _snakeSize = int(DEFAULT_SNAKE_SIZE * sizeFactor);
    
}

/* Handles user input */

void Snake::handleEvent(sf::Event & event) {
    
    switch (event.key.code) {
        
        case sf::Keyboard::W:
            if (_dir != down or not _parts.size()) _dir = up;
            break;
        
        case sf::Keyboard::A:
            if (_dir != right or not _parts.size()) _dir = left;
            break;
            
        case sf::Keyboard::D:
            if (_dir != left or not _parts.size()) _dir = right;
            break;
            
        case sf::Keyboard::S:
            if (_dir != up or not _parts.size()) _dir = down;
            break;
            
        default:
            break;
            
    }
    
}


bool Snake::move() {
    
    /* Doesn't move if _dir is none */
    
    if (_dir == none) return true;
    
    /* Each SnakePart moves to the position of the SnakePart in front of it */
    
    if (_parts.size()) {
        
        for (int i = _parts.size() - 1; i > 0; --i) {
            
            _parts.at(i).setPosition( _parts.at(i - 1).getPosition() );
            
        }
        
        _parts.at(0).setPosition(getPosition());
        
    }
    
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
    
    /* If snake moves out of screen bounds it will appear on the other side of the screen */
    
    if (posX < 0) posX = _windowWidth - _snakeSize;
    else if (posX > _windowWidth) posX = 0;
    
    if (posY < 0) posY = _windowHeight - _snakeSize;
    else if (posY >=_windowHeight) posY = 0;
    
    setPosition(posX, posY);
    
    /* Checks for collision */
    
    for (SnakePart part : _parts) {
        
        if (getPosition() == part.getPosition()) return false;
        
    }
    
    /* Return true if snake doesn't collide with anything */
    
    return true;
    
}

/* Checks for collision with food */

bool Snake::collisionWithFood(sf::Vector2f foodPosition, int foodSize) {
    
    if (fabs(getPosition().x - foodPosition.x) <= foodSize and fabs(getPosition().y - foodPosition.y) <= foodSize) {
        
        grow();
        return true;
        
    }
    
    return false;
    
}

/* Adds one SnakePart after snake consumes food */

void Snake::grow() {
    
    if (not _parts.size()) {
        _parts.emplace_back(getPosition(), _sizeFactor);
    }
    else {
        _parts.emplace_back(_parts.back().getPosition(), _sizeFactor);
    }
    
}

/* Returns an std::vector of SnakeParts so they can be drawn to the screen */

std::vector<SnakePart> & Snake::getParts() {
    
    return _parts;
    
}











