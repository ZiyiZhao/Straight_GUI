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

#include <gtkmm.h>
#include <gtkmm/window.h>
#include <gtkmm/image.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/frame.h>
#include "observer.h"
#include "view.h"
#include "controller.h"
#include "model.h"
#include "subject.h"
#include "DeckGUI.h"


class Controller;
class DeckGUI;
class Observer;

class CardButton: public Gtk::Button, public Observer {
public:
    CardButton(Model*);
    ~CardButton(){};
    virtual void update();	         //modify the button image given address of the cardImage
    

private:
    Gtk::Button buttonCard;
    Gtk::Image card;
    Model *model_;
    // Card Images
	DeckGUI deck;
    
    // Strategy Pattern member (plus signal handlers)
	Controller *controller_;
    
    void onButtonClicked();
};


#endif