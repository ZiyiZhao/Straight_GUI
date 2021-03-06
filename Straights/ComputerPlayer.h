//
//  Deck.h
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//

#ifndef __Straights__ComputerPlayer__
#define __Straights__ComputerPlayer__

#include <iostream>
#include "Player.h"
#include "HumanPlayer.h"

class ComputerPlayer: public Player{
public:
    ComputerPlayer(const std::string& playerName):Player(playerName){};         //constructor
    ComputerPlayer(const Player& humanPlayer):Player(humanPlayer){};            //copy constructor
    Command* turn(const std::vector<Card*>) const;                              //create a legal command for the computer player
    void displayHand(std::vector<Card*>) const{};
    
};

#endif /* defined(__Straights__ComputerPlayer__) */
