//
//  Deck.h
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//

#ifndef Straights_GameTable_h
#define Straights_GameTable_h

#include "Deck.h"
#include <vector>

class GameTable{
public:
    GameTable();                                 //constructor
    ~GameTable();                                //destructor

    void shuffle(int);
    Card* dealCard();
    void addCardToTable(Card *card);

    int* getTableHeart();
    int* getTableDiamond();
    int* getTableSpade();
    int* getTableClub();
    					                         //start the game
private:
    //void invitePlayers();                   //add players
    //Player* players_[4];                    //array of s set of players
    Deck* deck_;                            //contains a complete set of deck
    std::vector<Card*> cardsOnTable_;       //holds the cards that has been played

    int tableHeart_[26];
    int tableDiamond_[26];
    int tableSpade_[26];
    int tableClub_[26];
};


#endif
