//
//  Deck.h
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//

#include "Game.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <memory>

//constructor
GameTable::GameTable(){
    deck_ = new Deck();
}

//destructor
GameTable::~GameTable(){
    
    // Delete deck
    delete deck_;
};

void GameTable::shuffle(int seed) {

    // Set the seed to random shuffle
    srand48( seed );

    deck_->shuffle();
}

// Return the next card in the deck
Card* GameTable::dealCard() {

    return deck_->getNextCard();
}
