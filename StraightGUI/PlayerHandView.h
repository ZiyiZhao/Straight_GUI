/*
 * 	Player class - holds the information to display for the viewer class
 */


#ifndef MVC_PLAYERHANDVIEW_H
#define MVC_PLAYERHANDVIEW_H

#include <gtkmm/frame.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include "observer.h"
#include "DeckGUI.h"

class Model;

class PlayerHandView : public Observer{
public:
   	PlayerHandView(Model* ,Gtk::Frame*);	// Constructor(model, playerNum, score, discards, isAI)
   	~PlayerHandView();
   	void update();
private:
	Gtk::Frame *frame_;
	Model *model_;

	DeckGUI deck_;

	Gtk::VBox playerOption_;
	Gtk::HBox playerHand_;

	Gtk::Button rageQuitButton_;
	Gtk::Button *playerCards_[13];
};
#endif

