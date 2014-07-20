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
#include "observer.h"
#include "PlayerStatusView.h"
#include "PlayerHandView.h"
#include "TableView.h"
//#include "CardButton.h"

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

	Gtk::VBox gameWindowWrapper_;

	// Menu variables
	Glib::RefPtr<Gtk::UIManager>   m_refUIManager;
	Glib::RefPtr<Gtk::ActionGroup> m_refActionGroup;

	// Game table and cards
	Gtk::Frame gameTableWrapper_;
	TableView *gameTableView_;

	// Player Status
	Gtk::Frame playerStatusWrapper_;
	PlayerStatusView *playerStatusView_;
    
    //player's card on hand
    Gtk::Frame playerHandWrapper_;
    PlayerHandView *playerHandView_;
    
    //store seed
    int seed_;

	// Action for menu items
	virtual void on_menuAction_new();
	virtual void on_menuAction_quit();
	virtual void on_menuAction_save();
    virtual void on_menuAction_restore();
    virtual void on_menuAction_seed(Gtk::Window & parentWindow);


}; // View

#endif
