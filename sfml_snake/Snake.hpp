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


enum Direction {
    none,
    down    = 0,
    left    = 1,
    up      = 2,
    right   = 3
};


class Snake : public sf::RectangleShape {
    
private:
    float _sizeFactor;
    Direction _dir;
    
public:
    Snake(float);
    
    void handleEvent(sf::Event&);
    
};

#endif /* Snake_hpp */
