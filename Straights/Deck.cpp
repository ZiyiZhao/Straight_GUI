//
//  Deck.h
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//

#include "Deck.h"

//constructor
Deck::Deck():CARD_COUNT(52){
    
    currentCardIndex_ = 0;
    
    //index of the cards_ array;
    int index = 0;
    //iterate through Suit enum
    for (int i = CLUB; i < SUIT_COUNT; i++){
        //iterate through Rank enum
        for (int j = ACE; j < RANK_COUNT; j++){
            cards_[index++] = new Card((Suit)i, (Rank)j);
        }
    }
}

//destructor
Deck::~Deck(){
    
    for (int i = 0; i < CARD_COUNT; i++){
        //delete every pointer of card in cards_
        delete cards_[i];
        cards_[i] = NULL;
    }
}

void Deck::shuffle(){
    /* To ensure that the your cards are ordered the same way as
     the given program, use this shuffling algorithm.
     
     CARD_COUNT is the constant 52
     cards_ is an array of pointers to cards
     */

    int n = CARD_COUNT;

    while ( n > 1 ) {
        int k = (int) (lrand48() % n);
        --n;
        Card *c = cards_[n];
        cards_[n] = cards_[k];
        cards_[k] = c;
    }
    
    // Reset the card positon back to 0
    currentCardIndex_ = 0;
}

//accessor
Card* Deck::getNextCard(){
    return cards_[currentCardIndex_++];
}

//display the deck in rows of 13
void Deck::displayDeck() const {
    for(int row = 0; row < 4; row++){
        for(int col = 0; col < 13; col++)
            std::cout << *cards_[row*13+col] << " ";
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}