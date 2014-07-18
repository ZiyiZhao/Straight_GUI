/*
 *  Straight GUI Game
 *
 *  TableView class implementation : 
 *      Responsible for displaying the 
 *      cards currently played on table
 *  
 *  Created by Jack Wang on 17/July/2014.
 *
 */

#include "TableView.h"
#include "subject.h"

// TableView class implementation : 
//      Responsible for displaying the cards currently played on table
TableView::TableView(Model *m, Gtk::Frame *f) : heartSuitCardsHBox_(true,5), spadeSuitCardsHBox_(true,5), diamondSuitCardsHBox_(true,5), clubSuitCardsHBox_(true,5) {    
    
    // Assigning and initalizing variables
    model_ = m;
    frameWrapper_ = f;

    /*                          */
    /*      Cards and Table     */
    /*                          */

    // Add game table to frame
    frameWrapper_->add(tableWrapper_);

    //  Add cards to table 
    tableWrapper_.add(heartSuitCardsHBox_);
    tableWrapper_.add(spadeSuitCardsHBox_);
    tableWrapper_.add(diamondSuitCardsHBox_);
    tableWrapper_.add(clubSuitCardsHBox_);


    // Create empty card image
	const Glib::RefPtr<Gdk::Pixbuf> emptyCardPixbuf = deck_.null();

	// Initalize each index of the card image as empty cards
    // Add the image to the cardHbox
	for (int i = 0; i < 13; i++ ) {

		heartCardImg_[i] = new Gtk::Image( emptyCardPixbuf );
		spadeCardImg_[i] = new Gtk::Image( emptyCardPixbuf );
		diamondCardImg_[i] = new Gtk::Image( emptyCardPixbuf );
		clubCardImg_[i] = new Gtk::Image( emptyCardPixbuf );
		
        heartSuitCardsHBox_.add( *heartCardImg_[i] );
		spadeSuitCardsHBox_.add( *spadeCardImg_[i] );
		diamondSuitCardsHBox_.add( *diamondCardImg_[i] );
		clubSuitCardsHBox_.add( *clubCardImg_[i] );
	} 

}

TableView::~TableView() {}

void TableView::update(){

}