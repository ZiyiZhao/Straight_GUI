//
//  PlayerStatus.h
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//


/*
 * 	Player class - holds the information to display for the viewer class
 */


#ifndef MVC_PLAYERSTATUS_H
#define MVC_PLAYERSTATUS_H


#include <gtkmm.h>

class View;

class PlayerStatus : public Gtk::Frame{
public:
   	PlayerStatus(Gtk::Frame*, int, int, bool);	// Constructor(model, playerNum, score, discards, isAI)
   	void update();                              // inherited update()
   	Gtk::Frame* getLabel();                     //accessor
private:
	Gtk::Frame *frame_;                         // frame for contents
  	int score_;                                 // player score
  	int discards_;                              // player discards
   	bool isAI_;                                 // determines if it is a computer

}; // Controller


#endif

