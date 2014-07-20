
//
//  PlayerHandView.cc
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//


/*
 * Player class - holds the information to display for the viewer class
 *
 */


#include <gtkmm/image.h>
#include <gtkmm/label.h>
#include <iostream>
#include <sstream>
#include "PlayerHandView.h"

//constructor
PlayerHandView::PlayerHandView(Model *model, Gtk::Frame *frame, Controller *c): model_(model), frame_(frame), controller_(c){

    // get cards of player's hand
	int *playerHand = model_->getPlayerHand();
    
    //create buttons and assign properties
	for(int i = 0; i < 13; i++) {
        //add button
		playerCards_[i] = Gtk::manage(new CardButton(playerHand[i*2],playerHand[i*2+1]));
        // create image
		playerCardImage_[i] = new Gtk::Image(deck_.image((Rank)playerHand[i*2],(Suit)playerHand[i*2+1]));
        //set image
		playerCards_[i]->set_image(*playerCardImage_[i]);
        playerCards_[i]->set_sensitive(false);
        //set onclick events using bindings
        playerCards_[i]->signal_clicked().connect( sigc::bind<CardButton*>(sigc::mem_fun( *this, &PlayerHandView::cardButtonClicked), playerCards_[i]));
        //add the cardbutton onto player's hand
		playerHand_.add(*playerCards_[i]);
	}
    
	playerOption_.add(playerHand_);
    
    //create a button containing message to player
	Gtk::Label *playerInfoLabel = new Gtk::Label(model_->getInfoForPlayer());
    //set properties for playerInfo_
	playerInfo_.set_label("Player Message Box: ");
	playerInfo_.add(*playerInfoLabel);
	playerInfo_.set_size_request(-1, 30);
	playerOption_.add(playerInfo_);
    
    //set properties of rage quit button
	rageQuitButton_.set_label("RAGE QUIT!!");
	rageQuitButton_.set_sensitive(false);
    rageQuitButton_.signal_clicked().connect(sigc::mem_fun( *this, &PlayerHandView::rageButtonClicked) );

	playerOption_.add(rageQuitButton_);
    
    // add the contents into window
	frame_->add(playerOption_);
	frame_->set_label("Player 1");
    
    model_->subscribe(this);

}

//destructor
PlayerHandView::~PlayerHandView(){
	delete frame_;
	for(int i = 0; i < 13; i++){
		delete playerCards_[i];
		delete playerCardImage_[i];
	}
}

// updates the player hand view
void PlayerHandView::update(){
    
    //get player type
	std::ostringstream oss;
	if(model_->getCurrentPlayerType() == 1) {
		oss << "Player ";
	} else {
		oss << "Computer ";
	}
	oss << model_->getCurrentPlayerNumber();
    
    //set the player type and number
	frame_->set_label(oss.str());
    
    // constructs new card array that holds the current player's cards
	int* cardsInHand = model_->getPlayerHand();
	for(int i = 0; i < 13; i++) {
		playerCardImage_[i]->set(deck_.image((Rank)cardsInHand[i*2],(Suit)cardsInHand[i*2+1]));
		if(cardsInHand[i*2] != -1){
			playerCards_[i]->setRank(cardsInHand[i*2]);
			playerCards_[i]->setSuit(cardsInHand[i*2+1]);
			playerCards_[i]->set_sensitive(true);
		} else {
			playerCards_[i]->set_sensitive(false);
		}
	}
    // properties of buttons and boxs
	rageQuitButton_.set_sensitive(true);
	playerInfo_.remove();
	playerInfo_.add(*(new Gtk::Label(model_->getInfoForPlayer())));
}

// on click event
void PlayerHandView::cardButtonClicked(CardButton *button ){
    controller_ -> cardButtonClicked(button->getRank(), button->getSuit());
}

//on click event
void PlayerHandView::rageButtonClicked(){
    controller_-> rageButtonClicked();
}
