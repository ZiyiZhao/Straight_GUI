//
//  Deck.h
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//

#ifndef Straights_Game_h
#define Straights_Game_h

#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Deck.h"
#include <vector>

class Game{
public:
    Game();                                 //constructor
    ~Game();                                //destructor
    void startGame();                       //start the game
private:
    void invitePlayers();                   //add players
    Player* players_[4];                    //array of a set of players
    Deck* deck_;                            //contains a complete set of deck
    std::vector<Card*> cardsOnTable_;       //holds the cards that has been played
    int startingPlayer_;                    //indicate who has the 7 of spade
};


#endif
