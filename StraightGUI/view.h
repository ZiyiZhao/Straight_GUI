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
<<<<<<< HEAD
#include "PlayerStatus.h"
#include "CardButton.h"
=======
#include "PlayerStatusView.h"
#include "TableView.h"
>>>>>>> FETCH_HEAD

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
<<<<<<< HEAD
	Gtk::HBox playerStatusBox_;
	PlayerStatus *playerStatus_[4];
    
    //player's card on hand
    Gtk::HBox cardOnHand_;
    Gtk::Frame cardFrame_;
    CardButton *cardOnHandList_[13];
    
=======
	Gtk::Frame playerStatusWrapper_;
	PlayerStatusView *playerStatusView_;
>>>>>>> FETCH_HEAD

	// Action for menu items
	virtual void on_menuAction_new();
	virtual void on_menuAction_quit();
	virtual void on_menuAction_save();
    virtual void on_menuAction_restore();


}; // View

#endif
