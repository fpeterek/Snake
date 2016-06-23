//
//  Snake.hpp
//  sfml_snake
//
//  Created by Filip Peterek on 23.06.16.
//  Copyright © 2016 Filip Peterek. All rights reserved.
//

#ifndef Snake_hpp
#define Snake_hpp

#include <stdio.h>

#include <SFML/Graphics.hpp>

#include "Game.hpp"

#define DEFAULT_SNAKE_SIZE 25


enum Direction {
    
    none,
    up,
    down,
    left,
    right
    
};


class Snake : public sf::RectangleShape {
    
private:
    
    float _sizeFactor;
    int _windowHeight, _windowWidth, _snakeSize;
    Direction _dir;
    
public:
    
    Snake(float, int, int);
    
    void handleEvent(sf::Event&);
    bool move();
    bool collisionWithFood(sf::Vector2f, int);
    
};

#endif /* Snake_hpp */
