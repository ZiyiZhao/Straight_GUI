//
//  HumanPlayer.h
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//

#ifndef __Straights__HumanPlayer__
#define __Straights__HumanPlayer__

#include <iostream>
#include "Player.h"

class HumanPlayer: public Player{
public:
    HumanPlayer(std::string);                                           //constructor
    Command* turn(std::vector<Card*>) const;                            //check for legal commands
    void displayHand(std::vector<Card*>) const;                         //display the cards currently on hand
    
    Card* comPlayCard(const std::vector<Card*>) const;                  //inherited from player's pure virtual function
private:
    void displayGameTable(const std::vector<Card*>, const std::vector<Card*>) const;
                                                                        // display the cards that have already been played
    std::string sort(const std::vector<Card*>&) const;                  //sorts the array of Suit
};

#endif