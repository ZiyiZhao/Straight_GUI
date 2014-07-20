//
//  CardButton.h
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//


#ifndef CARDBUTTON_H
#define CARDBUTTON_H

#include <gtkmm/image.h>
#include <gtkmm/button.h>

class CardButton: public Gtk::Button{
public:
    CardButton(const int&, const int&);
    ~CardButton(){};
    int getRank();
    int getSuit();
    
    void setSuit(int);
    void setRank(int);

private:
    int rank_;
    int suit_;
};


#endif