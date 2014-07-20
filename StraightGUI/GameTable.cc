//
//  Deck.h
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//

#include "GameTable.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <memory>

//constructor
GameTable::GameTable(){
    deck_ = new Deck();

    // Initalize the every suit on table to be empty
    for(int i = 0; i < 13; i++) {
        tableHeart_[i*2] = -1;
        tableHeart_[i*2+1] = HEART;
        
        tableDiamond_[i*2] = -1;
        tableDiamond_[i*2+1] = DIAMOND;
        
        tableSpade_[i*2] = -1;
        tableSpade_[i*2+1] = SPADE;
        
        tableClub_[i*2] = -1;
        tableClub_[i*2+1] = CLUB;
    }
}

//destructor
GameTable::~GameTable(){
    
    // Delete deck
    delete deck_;
};

void GameTable::shuffle(int seed) {

    // Set the seed to random shuffle
    srand48( seed );
    
    // call function from logic
    deck_->shuffle();
}

// Return the next card in the deck
Card* GameTable::dealCard() {

    return deck_->getNextCard();
}

void GameTable::addCardToTable(Card *card) {
    // Add the card to table
    cardsOnTable_.push_back(card);
    
    // add the card to corresponding Suit
    if(card->getSuit() == DIAMOND) {
        tableDiamond_[(int)(card->getRank())*2] = card->getRank();
    } else if(card->getSuit() == HEART) {
        tableHeart_[(int)(card->getRank())*2] = card->getRank();
    } else if(card->getSuit() == SPADE) {
        tableSpade_[(int)(card->getRank())*2] = card->getRank();
    } else if(card->getSuit() == CLUB) {
        tableClub_[(int)(card->getRank())*2] = card->getRank();
    }
}

// accessor
int* GameTable::getTableHeart() {
    return tableHeart_;
}

// accessor
int* GameTable::getTableDiamond() {
    return tableDiamond_;
}

// accessor
int* GameTable::getTableSpade() {
    return tableSpade_;
}

// accessor
int* GameTable::getTableClub() {
    return tableClub_;
}

// accessor
std::vector<Card*> GameTable::getCurrentTable(){
    return cardsOnTable_;
}

// check if the game is over
bool GameTable::isGameOver(){
    return cardsOnTable_.size() == 52;
}