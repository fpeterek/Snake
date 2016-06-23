//
//  Game.hpp
//  sfml_snake
//
//  Created by Filip Peterek on 23.06.16.
//  Copyright © 2016 Filip Peterek. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>

#include "Snake.hpp"


class Food : sf::RectangleShape {
    
private:
    float _sizeFactor;
    
public:
    Food(float);
    void newFood();
    sf::Transformable position();
    
    
};


class Game {
    
private:
    float _sizeFactor;
    sf::RenderWindow _window;
    
public:
    Game();
    void gameLoop();
    
};

#endif /* Game_hpp */
