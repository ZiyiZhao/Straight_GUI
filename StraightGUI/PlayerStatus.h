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
   	void update();
   	Gtk::Frame* getLabel();
private:
	Gtk::Frame *frame_;
  	int score_;
  	int discards_;
   	bool isAI_;

}; // Controller


#endif

