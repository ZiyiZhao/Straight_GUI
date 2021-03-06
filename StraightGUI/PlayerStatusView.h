//
//  PlayerStatusView.h
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//


/*
 * 	Player class - holds the information to display for the viewer class
 */


#ifndef MVC_PLAYERSTATUSVIEW_H
#define MVC_PLAYERSTATUSVIEW_H

#include <gtkmm/frame.h>
#include <gtkmm/box.h>
#include "observer.h"
#include "model.h"

//class Model;

class PlayerStatusView : public Observer{
public:
   	PlayerStatusView(Model* ,Gtk::Frame*);	// Constructor(model, playerNum, score, discards, isAI)
   	~PlayerStatusView();                    // desctrucor
   	void update();                          // inherited function
private:
	Gtk::Frame *frame_;                     // container box
	Model *model_;                          // pointer to model

	Gtk::HBox playerStatusHBox_;            // container boxes
	Gtk::Frame *playerStatus_[4];
};
#endif

