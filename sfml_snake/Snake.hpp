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

#define DEFAULT_SNAKE_SIZE 30


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
    int _windowHeigth, _windowWidth;
    Direction _dir;
    
public:
    Snake(float, int, int);
    
    void handleEvent(sf::Event&);
    bool move();
    
};

#endif /* Snake_hpp */
