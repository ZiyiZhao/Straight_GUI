//
//  CardButton.cc
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//

#include "CardButton.h"

//constructors, set up the rank and suit for a button
CardButton::CardButton(const int& r, const int& s): rank_(r), suit_(s){}

//accessor to get which card was played
int CardButton::getRank(){
    return rank_;
}

//accessor to get which card was played
int CardButton::getSuit(){
    return suit_;
}

//mutator for update()
void CardButton::setSuit(int suit) {
    suit_ = suit;
}

//mutator for update()
void CardButton::setRank(int rank){
    rank_ = rank;
}
