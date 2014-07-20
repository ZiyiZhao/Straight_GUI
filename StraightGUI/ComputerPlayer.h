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
#include "Card.h"

class ComputerPlayer: public Player{
public:
    ComputerPlayer(const std::string& playerName):Player("Computer " + playerName){};           //constructor
    ComputerPlayer(const Player& humanPlayer):Player(humanPlayer){};                            //copy constructor
    Command* turn(const std::vector<Card*>) const;                                              //create a legal command for the computer player
    void displayHand(std::vector<Card*>) const{};                                               //inherited virtual function
    
    Card* comPlayCard(const std::vector<Card*>) const;                                          //returns a card pointer after creating a command
    
};

#endif /* defined(__Straights__ComputerPlayer__) */
