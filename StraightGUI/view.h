/*
 * MVC example of GTKmm program
 *
 * View class.  Is responsible for buttons (that user clicks) and for displaying
 * the top card of the deck.
 *
 *  Created by Jo Atlee on 06/07/09.
 *  Copyright 2009 UW. All rights reserved.
 *
 */


#ifndef MVC_VIEW_H
#define MVC_VIEW_H

#include <gtkmm.h>
#include <gtkmm/window.h>
#include <gtkmm/image.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/frame.h>
#include "DeckGUI.h"
#include "observer.h"
#include "PlayerStatus.h"

class Controller;
class Model;


class View : public Gtk::Window, public Observer {
public:
        View( Controller*, Model* );
	virtual ~View();
	virtual void update();	// Observer Pattern: concrete update() method

private:
	// Observer Pattern: to access Model accessors without having to downcast subject
	Model *model_;
	
	// Strategy Pattern member (plus signal handlers)
	Controller *controller_;

	// Card Images
	DeckGUI deck;

	// Table contents
	Gtk::VBox verticalFrame_;			// Holds the widgets for all the components
	

	// Cards on table
    Glib::RefPtr<Gtk::UIManager>   m_refUIManager;
	Glib::RefPtr<Gtk::ActionGroup> m_refActionGroup;

	Gtk::HBox heartSuitCardsBox_;		// Holds cards with suite heart
	Gtk::HBox spadeSuitCardsBox_;		// Holds cards with suite spade
	Gtk::HBox diamondSuitCardsBox_;		// Holds cards with suite diamond
	Gtk::HBox clubSuitCardsBox_;		// Holds cards with suite club 


    Gtk::Image *heartCardImg[13];          // Images to display.
	Gtk::Image *spadeCardImg[13];          // Images to display.
	Gtk::Image *diamondCardImg[13];          // Images to display.
	Gtk::Image *clubCardImg[13];          // Images to display.

	// Player Status
	Gtk::HBox playerStatusBox_;
	PlayerStatus *playerStatus_[4];

	// Action for menu items
	virtual void on_menuAction_new();
	virtual void on_menuAction_quit();
	virtual void on_menuAction_save();
    virtual void on_menuAction_restore();


}; // View

#endif
