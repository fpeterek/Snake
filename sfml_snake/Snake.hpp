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


class Snake : sf::RectangleShape {
    
private:
    float _sizeFactor;
    
public:
    Snake(float);
    
};

#endif /* Snake_hpp */
