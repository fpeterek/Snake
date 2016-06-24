//
//  main.cpp
//  sfml_snake
//
//  Created by Filip Peterek on 23.06.16.
//  Copyright © 2016 Filip Peterek. All rights reserved.
//

#include <ctime>
#include <cstdlib>
#include <iostream>

#include "Game.hpp"


int main(int argc, const char* argv[]){
    
    try {
        Game game;
        game.gameLoop();
    }
    catch(...) {
        std::cout << "Fuck. " << std::endl;
    }
    
    return 0;
    
}