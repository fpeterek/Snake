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
    void newFood();
    sf::Transformable position();
    
    
};


class Game {
    
private:
    float _sizeFactor;
    sf::RenderWindow _window;
    
public:
    Game();
    void GameLoop();
    
};

#endif /* Game_hpp */
