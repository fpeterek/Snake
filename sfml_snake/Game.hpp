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

#define DEFAULT_FOOD_SIZE 20


class Food : public sf::RectangleShape {
    
private:
    
    float _sizeFactor;
    int _windowWidth, _windowHeight, _foodSize;
    
public:
    
    Food(float, int, int);
    void newFood();
    sf::Vector2f position();
    
    
};


class Game {
    
private:
    
    float _sizeFactor;
    int _height, _width;
    sf::RenderWindow _window;
    
public:
    
    Game();
    void gameLoop();
    
};

#endif /* Game_hpp */
