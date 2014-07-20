//
//  PlayerHandView.h
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//


/*
 * 	Player class - holds the information to display for the viewer class
 */


#ifndef MVC_PLAYERHANDVIEW_H
#define MVC_PLAYERHANDVIEW_H

#include <gtkmm/frame.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include "observer.h"
#include "DeckGUI.h"
#include "controller.h"
#include "CardButton.h"

class Model;
class Controller;
class CardButton;

class PlayerHandView : public Observer{
public:
   	PlayerHandView(Model* ,Gtk::Frame*, Controller *c);	// Constructor(model, playerNum, score, discards, isAI)
   	~PlayerHandView();                                  // destructor
   	virtual void update();                              // inherited from Observer
private:
	Gtk::Frame *frame_;
	Model *model_;                                      // a pointer to model
    
	Controller *controller_;                            // Strategy Pattern member (plus signal handlers)

	DeckGUI deck_;                                      // Card Images

	Gtk::VBox playerOption_;                            // containers for widgets
	Gtk::Frame playerInfo_;
	Gtk::HBox playerHand_;

	Gtk::Button rageQuitButton_;                        // button for rage quit
	CardButton *playerCards_[13];                       // list of card buttons
	Gtk::Image *playerCardImage_[13];                   // list of card images
    void cardButtonClicked(CardButton*);                // user event call functions for card button
    void rageButtonClicked();                           // user event call functions for rage button

};
#endif

