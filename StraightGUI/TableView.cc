/*
 *  Straight GUI Game
 *
 *  TableView class implementation : 
 *      Responsible for displaying the 
 *      cards currently played on table
 *  
 *  Created by Jack Wang, Errin Zhao on 17/July/2014.
 *
 */

#include "TableView.h"
#include "subject.h"
#include <iostream>

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
    tableWrapper_.add(diamondSuitCardsHBox_);
    tableWrapper_.add(spadeSuitCardsHBox_);
    tableWrapper_.add(clubSuitCardsHBox_);


    // Create empty card image
	const Glib::RefPtr<Gdk::Pixbuf> emptyCardPixbuf = deck_.null();

    // Get the arrays
    int *tableHeart_ = model_->getTableHeart();
    int *tableSpade_ = model_->getTableSpade();
    int *tableDiamond_ = model_->getTableDiamond();
    int *tableClub_ = model_->getTableClub();

    for(int i = 0 ; i < 13; i++) {

        const Glib::RefPtr<Gdk::Pixbuf> pixHeart = deck_.image((Rank)tableHeart_[i*2],(Suit)tableHeart_[i*2+1]);
        currentTableHeart_[i*2] = (int)(tableHeart_[i*2]);
        currentTableHeart_[i*2+1] = (int)(tableHeart_[i*2+1]);
        heartCardImg_[i] = new Gtk::Image( pixHeart );
        heartSuitCardsHBox_.add( *heartCardImg_[i] );

        const Glib::RefPtr<Gdk::Pixbuf> pixDiamond = deck_.image((Rank)tableDiamond_[i*2],(Suit)tableDiamond_[i*2+1]);
        currentTableDiamond_[i*2] = (int)(tableDiamond_[i*2]);
        currentTableDiamond_[i*2+1] = (int)(tableDiamond_[i*2+1]);
        diamondCardImg_[i] = new Gtk::Image( pixDiamond );
        diamondSuitCardsHBox_.add( *diamondCardImg_[i] );

        const Glib::RefPtr<Gdk::Pixbuf> pixSpade = deck_.image((Rank)tableSpade_[i*2],(Suit)tableSpade_[i*2+1]);
        currentTableSpade_[i*2] = (int)(tableSpade_[i*2]);
        currentTableSpade_[i*2+1] = (int)(tableSpade_[i*2+1]);
        spadeCardImg_[i] = new Gtk::Image( pixSpade );
        spadeSuitCardsHBox_.add( *spadeCardImg_[i] );

        const Glib::RefPtr<Gdk::Pixbuf> pixClub = deck_.image((Rank)tableClub_[i*2],(Suit)tableClub_[i*2+1]);
        currentTableClub_[i*2] = (int)(tableClub_[i*2]);
        currentTableClub_[i*2+1] = (int)(tableClub_[i*2+1]);
        clubCardImg_[i] = new Gtk::Image( pixClub );
        clubSuitCardsHBox_.add( *clubCardImg_[i] );
        
    }

    std::cout << "Subscribing TableView" << std::endl;
    model_->subscribe(this);

}

TableView::~TableView() {}

void TableView::update(){
        // Get the arrays


    std::cout << "TableView::update()" << std::endl;
    int *tableHeart_ = model_->getTableHeart();
    int *tableSpade_ = model_->getTableSpade();
    int *tableDiamond_ = model_->getTableDiamond();
    int *tableClub_ = model_->getTableClub();

    for(int i = 0 ; i < 13; i++) {

        // Only perform update if the value is different
        if(currentTableHeart_[i*2] != tableHeart_[i*2]){
            const Glib::RefPtr<Gdk::Pixbuf> pixHeart = deck_.image((Rank)tableHeart_[i*2],(Suit)tableHeart_[i*2+1]);
            heartCardImg_[i]->set(pixHeart);
            currentTableHeart_[i*2] = tableHeart_[i*2];
        }

        if(currentTableDiamond_[i*2] != tableDiamond_[i*2]){
            const Glib::RefPtr<Gdk::Pixbuf> pixDiamond = deck_.image((Rank)tableDiamond_[i*2],(Suit)tableDiamond_[i*2+1]);
            diamondCardImg_[i]->set(pixDiamond);
            currentTableDiamond_[i*2] = tableDiamond_[i*2];
        }

        if(currentTableSpade_[i*2] != tableSpade_[i*2]){
            const Glib::RefPtr<Gdk::Pixbuf> pixSpade = deck_.image((Rank)tableSpade_[i*2],(Suit)tableSpade_[i*2+1]);
            spadeCardImg_[i]->set(pixSpade);
            currentTableSpade_[i*2] = tableSpade_[i*2];
        }

        if(currentTableClub_[i*2] != tableClub_[i*2]){
            const Glib::RefPtr<Gdk::Pixbuf> pixClub = deck_.image((Rank)tableClub_[i*2],(Suit)tableClub_[i*2+1]);
            clubCardImg_[i]->set(pixClub);
            currentTableClub_[i*2] = tableClub_[i*2];
        }
        
    }
    std::cout << "TableView::update() done" << std::endl;
}