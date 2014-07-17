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
#include "cardbutton.h"

class Controller;
class Model;
class CardButton;


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

	// Member widgets:
    Gtk::Frame cardsOnTable;      //frame to display cards on table
	Gtk::HBox heartsOnTable;     // displays cards on table that are suit Heart
    //Gtk::HBox diamondOnTable;     // displays cards on table that are suit Diamond
    //Gtk::HBox clubOnTable;     // displays cards on table that are suit Club
    //Gtk::HBox spadeOnTable;     // displays cards on table that are suit Spade
    
	//Gtk::HBox playerInfo;       //displays player's info
    Gtk::HBox cardsOnHand;    //displays the current player's cards on hand
    
    Gtk::VBox outsideVertical;     //the most outer vertical frame of the window
    
	//Gtk::Button next_button;
	//Gtk::Button reset_button;
	Gtk::Image *card[13];
    
    Glib::RefPtr<Gtk::UIManager>   m_refUIManager;
	Glib::RefPtr<Gtk::ActionGroup> m_refActionGroup;


	// Signal handlers:
	void nextButtonClicked();
	void resetButtonClicked();
    
    virtual void on_menuAction_new();
	virtual void on_menuAction_quit();
	virtual void on_menuAction_save();
    virtual void on_menuAction_restore();

}; // View

#endif
