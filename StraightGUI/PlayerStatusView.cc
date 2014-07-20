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

PlayerStatusView::~PlayerStatusView(){}

void PlayerStatusView::update(){

	std::cout << "PlayerStatusView::update()" << std::endl;
	// Remove any widget
	frame_->remove();

	// Add new label
	std::ostringstream oss;
	oss << "Player Point:     ";
	oss << 100;	// Need to change
	oss << "\n";
	oss << "Player Discards:  ";
	oss << 100;	// Need to change
	oss << "\n";

	Gtk::Label playerLabelStatus(oss.str(), 0, 0, false);
	frame_->add(playerLabelStatus);

	std::cout << "PlayerStatusView::update() done" << std::endl;
}
