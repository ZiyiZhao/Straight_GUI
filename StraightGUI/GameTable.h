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
    GameTable();                                //constructor
    ~GameTable();                               //destructor

    void shuffle(int);                          // shuffle method for cards
    Card* dealCard();                           // deal the card to each player
    void addCardToTable(Card *card);            // when played a card
    
                                                // accessors
    int* getTableHeart();
    int* getTableDiamond();
    int* getTableSpade();
    int* getTableClub();
    
    bool isGameOver();                          // check if game is over

    std::vector<Card*> getCurrentTable();
    
private:

    Deck* deck_;                                //contains a complete set of deck
    std::vector<Card*> cardsOnTable_;           //holds the cards that has been played

    int tableHeart_[26];                        // contains cards sorted by Suit
    int tableDiamond_[26];
    int tableSpade_[26];
    int tableClub_[26];
};


#endif
