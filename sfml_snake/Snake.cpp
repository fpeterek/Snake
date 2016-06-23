//
//  Snake.cpp
//  sfml_snake
//
//  Created by Filip Peterek on 23.06.16.
//  Copyright © 2016 Filip Peterek. All rights reserved.
//

#include "Snake.hpp"


Snake::Snake(float sizeFactor) {
    setPosition(400 * sizeFactor, 250 * sizeFactor);
    setSize(sf::Vector2f(30 * sizeFactor, 30 * sizeFactor));
    setFillColor(sf::Color::Red);
    _sizeFactor = sizeFactor;
}