//
//  Snake.cpp
//  sfml_snake
//
//  Created by Filip Peterek on 23.06.16.
//  Copyright © 2016 Filip Peterek. All rights reserved.
//

#include "Snake.hpp"


Snake::Snake(float sizeFactor) {
    setPosition(400 * sizeFactor, 225 * sizeFactor);
    setSize(sf::Vector2f(30 * sizeFactor, 30 * sizeFactor));
    setFillColor(sf::Color::Red);
    _sizeFactor = sizeFactor;
}

void Snake::handleEvent(sf::Event & event) {
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
            
        case sf::Keyboard::Space:
            _dir = none;
            break;
            
        default:
            break;
    }
}