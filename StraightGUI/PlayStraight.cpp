//
//  Deck.h
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//

#include "Game.h"

int main(int argc,char *argv[]){
    
    // Get the argument
    std::string num = "";
    for(int i = 1; i < argc; i++)
       num += argv[i];
    
    int number = atoi(num.c_str());
    
    srand48(number);
    
    //srand48(0);
    
    Game* game = new Game();
    game->startGame();
    delete game;
    return 0;
}
