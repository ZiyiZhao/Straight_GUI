//
//  PlayerStatusView.cc
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//

/*
 * Player class - holds the information to display for the viewer class
 *
 */


#include "PlayerStatusView.h"
#include <iostream>
#include <gtkmm/label.h>
#include <sstream>


PlayerStatusView::PlayerStatusView(Model *model, Gtk::Frame *frame){
	frame_ = frame;
	model_ = model;

		// Create one frame for each player and add it to HBox
	// Create one label for each player and add it to frame
	for(int i = 0; i < 4; i++) {

		playerStatus_[i] = new Gtk::Frame(model_->getPlayerType()[i]);
		Gtk::Label *playerLabelStatus = new Gtk::Label(model_->getPlayerStatus()[i], 0, 0, false);
		
		playerStatus_[i]->add(*playerLabelStatus);
		playerStatusHBox_.add(*playerStatus_[i]);
	}

	frame_->add(playerStatusHBox_);
	model_->subscribe(this);
	
}

PlayerStatusView::~PlayerStatusView(){
	delete frame_;
	for(int i = 0; i < 4; i++){
		delete playerStatus_[i];
	}
}

void PlayerStatusView::update(){
	// Remove any widget
	for(int i = 0; i < 4; i++) {
		playerStatus_[i]->remove();
		playerStatus_[i]->set_label(model_->getPlayerType()[i]);
		Gtk::Label *playerLabelStatus = new Gtk::Label(model_->getPlayerStatus()[i], 0, 0, false);
		playerStatus_[i]->add(*playerLabelStatus);
	}
}
