/*
 * MVC example of GTKmm program
 *
 * Subject class.  Abstract class for Observer Pattern
 *
 *
 *  Created by Jo Atlee on 06/07/09.
 *  Copyright 2009 UW. All rights reserved.
 *
 */

#include <gtkmm/stock.h>
#include <gtkmm/label.h>
#include "DialogView.h"
#include <iostream>

// Specifies the parent window of the dialog box and the title of the dialog box.
DialogView::DialogView( Gtk::Window & parentWindow, Model* m  ) : Dialog( "Player Selection", parentWindow, true, true ){
    model_ = m;
	
	// Obtain the dialog box's vertical alignment box.
	Gtk::VBox* contentArea = this->get_vbox();
    
    Gtk::Label message("Choose which players to be human players: ", 0, 0, false);
    
    contentArea->add(message);

	// Set up a group of radio buttons, one per card in human player's hand plus the top card of the kitty.
	for ( int i = 0; i < 4; i++ ) {
        std::ostringstream oss;
		oss << "Player ";
		oss << (i+1);
		buttons.push_back( Gtk::manage( new Gtk::CheckButton( oss.str() ) ) );
		contentArea->add( *buttons[i] );
	} // for
	
	// Make the first button the initial active choice.
	//buttons[0]->set_active();
	
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
    
    model_->subscribe(this);
    
} // DialogView::DialogView

DialogView::~DialogView() {
	for ( int i = 0; i < buttons.size(); i++ ) delete buttons[i];
	buttons.clear();
} // DialogView::~DialogView

void DialogView::update(){
    
}
