/*
* Observer class.  Abstract class for Observer Pattern
*
*
*  Created by Jo Atlee on 06/07/09.
*  Copyright 2009 UW. All rights reserved.
*
*/


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
    

private:
    int rank_;
    int suit_;
};


#endif