//
//  PlayerStatus.cc
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//


/*
 * Player class - holds the information to display for the viewer class
 *
 */


#include "PlayerStatus.h"
#include <sstream>
#include <iostream>



PlayerStatus::PlayerStatus(Gtk::Frame *f, int score, int discards, bool isAI){
	frame_ = f;
	score_ = score;
	discards_ = discards;
	isAI_ = isAI;

	// Update the Status
	PlayerStatus::update();
}

void PlayerStatus::update(){
	// Remove any widget
	frame_->remove();

	// Add new label
	std::ostringstream oss;
	oss << "Player Point:     ";
	oss << score_;
	oss << "\n";
	oss << "Player Discards:  ";
	oss << discards_;
	oss << "\n";

	Gtk::Label *playerLabelStatus = new Gtk::Label(oss.str(), 0, 0, false);
	frame_->add(*playerLabelStatus);
}

Gtk::Frame* PlayerStatus::getLabel(){
	return frame_;
}
