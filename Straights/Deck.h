//
//  Deck.h
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//

#ifndef __Straights__Deck__
#define __Straights__Deck__

#include <iostream>
#include <cstdlib>
#include "Card.h"

class Deck{
public:
    Deck();                     // Constuctor
    ~Deck();                    // Destructor
    void shuffle();             // Apply a shuffle algorithm to the deck
    Card* getNextCard();        // Retrive the next card in deck
    void displayDeck() const;   // Prints the deck
    
private:
    int currentCardIndex_;      // The current index of the card, used by getNextCard();
    const int CARD_COUNT;       // The number of cards in the deck
    Card* cards_[52];           // An Array that holds all the cards in the deck
};

#endif