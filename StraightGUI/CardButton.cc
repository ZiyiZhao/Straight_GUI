//
//  CardButton.cc
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//

#include <gtkmm.h>
#include <iostream>
#include "CardButton.h"

CardButton::CardButton(const int& r, const int& s): rank_(r), suit_(s){}

int CardButton::getRank(){
    return rank_;
}

int CardButton::getSuit(){
    return suit_;
}

void CardButton::setSuit(int suit) {
    suit_ = suit;
}

void CardButton::setRank(int rank){
    rank_ = rank;
}
