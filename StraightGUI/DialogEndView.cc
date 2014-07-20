//
//  DialogView.cc
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//
#include <gtkmm/stock.h>
#include <gtkmm/label.h>
#include "DialogEndView.h"
#include <iostream>
#include <sstream>

// Specifies the parent window of the dialog box and the title of the dialog box.
DialogEndView::DialogEndView( Gtk::Window & parentWindow, Model* model) : Dialog( "Round End", parentWindow, true, true ){
	
	// Obtain the dialog box's vertical alignment box.
	Gtk::VBox* contentArea = this->get_vbox();
    
	std::ostringstream oss;
	for(int i = 0; i < 4; i++) {

	}

    // set up the message to display at the top of the dialog box
    Gtk::Label message("Choose which players to be human players: ", 0, 0, false);
    
    contentArea->add(message);
}   // DialogView::DialogView

DialogEndView::~DialogEndView() {
  
} // DialogView::~DialogView

//accessor
bool* DialogEndView::getPlayerType() {
	return playerList_;
}
