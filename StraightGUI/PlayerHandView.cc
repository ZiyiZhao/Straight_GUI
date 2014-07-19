/*
 * Player class - holds the information to display for the viewer class
 *
 */


#include "PlayerHandView.h"
#include <gtkmm/image.h>


PlayerHandView::PlayerHandView(Model *model, Gtk::Frame *frame){
	frame_ = frame;
	model_ = model;

	for(int i = 0; i < 13; i++) {
		playerCards_[i] = new Gtk::Button();
		Gtk::Image *card = new Gtk::Image(deck_.null());
		playerCards_[i]->set_image(*card);
		//playerCards_[i]->set_always_show_image();
		playerHand_.add(*playerCards_[i]);
	}
	playerOption_.add(playerHand_);

	rageQuitButton_.set_label("RAGE QUIT!!");
	playerOption_.add(rageQuitButton_);

	frame_->add(playerOption_);
	frame_->set_label("Player 1");

}

PlayerHandView::~PlayerHandView(){}

void PlayerHandView::update(){
	// Remove any widget
}
