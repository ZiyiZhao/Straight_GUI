/*
 *	Straight GUI Game
 *
 *	TableView class header : 
 *		Responsible for displaying the 
 *		cards currently played on table
 *  
 *  Created by Jack Wang, Errin on 17/July/2014.
 *
 */


#ifndef MVC_TABLEVIEW_H
#define MVC_TABLEVIEW_H

#include <gtkmm/image.h>
#include <gtkmm/box.h>
#include <gtkmm/frame.h>
#include "DeckGUI.h"
#include "observer.h"

class Model;


class TableView : public Observer {

public:

	// Construct a Table view and initalize the cards as null
	TableView( Model*, Gtk::Frame* );

	// Destructor
	virtual ~TableView();

	// Update Method
	virtual void update();

private:

	// Hold the model and frame pointers
	Model *model_;
	Gtk::Frame *frameWrapper_;

	// Card Images
	DeckGUI deck_;

	// VBox used as table to hold Hbox of cards
	Gtk::VBox tableWrapper_;

	// Hbox to hold cards of the same suite
	Gtk::HBox heartSuitCardsHBox_;				
	Gtk::HBox spadeSuitCardsHBox_;				
	Gtk::HBox diamondSuitCardsHBox_;			
	Gtk::HBox clubSuitCardsHBox_;				

	// Card image array
    Gtk::Image *heartCardImg_[13];         		
	Gtk::Image *spadeCardImg_[13];      	
	Gtk::Image *diamondCardImg_[13];    	  	
	Gtk::Image *clubCardImg_[13];

	int currentTableHeart_[26];
	int currentTableDiamond_[26];
	int currentTableSpade_[26];
	int currentTableClub_[26];           		


};

#endif
