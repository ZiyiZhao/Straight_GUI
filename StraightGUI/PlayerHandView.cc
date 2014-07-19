/*
 * Player class - holds the information to display for the viewer class
 *
 */


#include <gtkmm/image.h>
#include <gtkmm/label.h>
#include "PlayerHandView.h"

PlayerHandView::PlayerHandView(Model *model, Gtk::Frame *frame){
	frame_ = frame;
	model_ = model;

	int *playerHand = model_->getPlayerHand();
	for(int i = 0; i < 13; i++) {
		playerCards_[i] = new Gtk::Button();
		Gtk::Image *card = new Gtk::Image(deck_.image((Rank)playerHand[i*2],(Suit)playerHand[i*2+1]));
		playerCards_[i]->set_image(*card);
		playerHand_.add(*playerCards_[i]);
	}
	playerOption_.add(playerHand_);

	Gtk::Label *playerInfo = new Gtk::Label(model_->getInfoForPlayer());
	playerInfo->set_size_request(-1, 30);
	playerOption_.add(*playerInfo);

	rageQuitButton_.set_label("RAGE QUIT!!");
	playerOption_.add(rageQuitButton_);

	frame_->add(playerOption_);
	frame_->set_label("Player 1");

}

PlayerHandView::~PlayerHandView(){}

void PlayerHandView::update(){
	// Remove any widget
}
