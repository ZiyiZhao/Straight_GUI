/*
 * MVC example of GTKmm program
 *
 * Controller class.  Is responsible for translating UI events (from the View)
 * into method calls to the Model.
 *
 *  Created by Jo Atlee on 06/07/09.
 *  Copyright 2009 UW. All rights reserved.
 *
 */


#include <gtkmm.h>
#include "CardButton.h"

CardButton::CardButton(const int& r, const int& s): rank_(r), suit_(s){}

int CardButton::getRank(){
    return rank_;
}

int CardButton::getSuit(){
    return suit_;
}
