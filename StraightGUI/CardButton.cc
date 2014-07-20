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
    std::cout << "get Rank: " <<rank_ << std::endl;
    return rank_;
}

int CardButton::getSuit(){
    return suit_;
}

void CardButton::setSuit(int suit) {
    std::cout << "set Rank: " <<rank_ << std::endl;
    suit_ = suit;
}

void CardButton::setRank(int rank){
    rank_ = rank;
}
