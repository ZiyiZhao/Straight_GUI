//
//  CardButton.h
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//


#ifndef CARDBUTTON_H
#define CARDBUTTON_H

#include <gtkmm/button.h>

class CardButton: public Gtk::Button{
public:
    CardButton(const int&, const int&);         //constructor
    ~CardButton(){};                            //destructor
    int getRank();                              //accessor
    int getSuit();                              //accessor
    
    void setSuit(int);                          //mutator
    void setRank(int);                          //mutator

private:
    int rank_;                                  //int representation of Rank type
    int suit_;                                  //int representation of Suit type
};


#endif