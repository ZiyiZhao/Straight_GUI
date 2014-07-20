
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
#include "PlayerHandView.h"

PlayerHandView::PlayerHandView(Model *model, Gtk::Frame *frame, Controller *c): model_(model), frame_(frame), controller_(c){

	int *playerHand = model_->getPlayerHand();
	for(int i = 0; i < 13; i++) {
		playerCards_[i] = Gtk::manage(new CardButton(playerHand[i*2],playerHand[i*2+1]));
		playerCardImage_[i] = new Gtk::Image(deck_.image((Rank)playerHand[i*2],(Suit)playerHand[i*2+1]));
		playerCards_[i]->set_image(*playerCardImage_[i]);
        
        playerCards_[i]->signal_clicked().connect( sigc::bind<int, int>(sigc::mem_fun( *this, &PlayerHandView::cardButtonClicked), playerCards_[i]-> getRank(), playerCards_[i]-> getSuit()) );

        
		playerHand_.add(*playerCards_[i]);
	}
	playerOption_.add(playerHand_);

	Gtk::Label *playerInfo = new Gtk::Label(model_->getInfoForPlayer());
	playerInfo->set_size_request(-1, 30);
	playerOption_.add(*playerInfo);

	rageQuitButton_.set_label("RAGE QUIT!!");
    rageQuitButton_.signal_clicked().connect(sigc::mem_fun( *this, &PlayerHandView::rageButtonClicked) );

	playerOption_.add(rageQuitButton_);

	frame_->add(playerOption_);
	frame_->set_label("Player 1");
    
    model_->subscribe(this);

}

PlayerHandView::~PlayerHandView(){}

void PlayerHandView::update(){
	int* cardsInHand = model_->getPlayerHand();
	for(int i = 0; i < 13; i++) {
		playerCardImage_[i]->set(deck_.image((Rank)cardsInHand[i*2],(Suit)cardsInHand[i*2+1]));
	}
}

void PlayerHandView::cardButtonClicked(const int& rank,const int& suit ){
    controller_ -> cardButtonClicked(rank, suit);
}

void PlayerHandView::rageButtonClicked(){
    controller_-> rageButtonClicked();
}