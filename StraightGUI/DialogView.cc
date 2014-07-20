//
//  DialogView.cc
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//
#include <gtkmm/stock.h>
#include <gtkmm/label.h>
#include "DialogView.h"
#include <iostream>

// Specifies the parent window of the dialog box and the title of the dialog box.
DialogView::DialogView( Gtk::Window & parentWindow) : Dialog( "Player Selection", parentWindow, true, true ){
	
	// Obtain the dialog box's vertical alignment box.
	Gtk::VBox* contentArea = this->get_vbox();
    
    // set up the message to display at the top of the dialog box
    Gtk::Label message("Choose which players to be human players: ", 0, 0, false);
    
    contentArea->add(message);

	// Set up a list of check box for choosing player type for 4 players
	for ( int i = 0; i < 4; i++ ) {
        // adding int to a string
        std::ostringstream oss;
		oss << "Player ";
		oss << (i+1);
        // set up the check box into a button array
		buttons.push_back( Gtk::manage( new Gtk::CheckButton( oss.str() ) ) );
		contentArea->add( *buttons[i] );
	} // for
	
	// Add a standard "ok" buttons with the appropriate responses when clicked.
    Gtk::Button * okButton = add_button( Gtk::Stock::OK, Gtk::RESPONSE_OK);
	show_all_children();
	
    // Wait for a response from the dialog box.
	int result = run();
    switch (result) {
        case Gtk::RESPONSE_OK:
            for ( int i = 0; i < 4; i++ ) {
				if ( buttons[i]->get_active() ) {
                    //if active, then the player is choosen to be human player
					playerList_[i] = true;
                    
                    std::cout << playerList_[i]<<std::endl;
				} else {
                    //computer player otherwise
                    playerList_[i] = false;
                    std::cout << playerList_[i]<<std::endl;
                }  //if
			} // for
            //call on click event to give to controller
            break;
    } // switch
}   // DialogView::DialogView

DialogView::~DialogView() {
    //delete every button in button array
	for ( int i = 0; i < buttons.size(); i++ ) delete buttons[i];
	buttons.clear();
} // DialogView::~DialogView

//accessor
bool* DialogView::getPlayerType() {
	return playerList_;
}
