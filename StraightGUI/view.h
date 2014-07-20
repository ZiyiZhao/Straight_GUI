//
//  view.h
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//
#ifndef MVC_VIEW_H
#define MVC_VIEW_H

#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/frame.h>
#include "observer.h"
#include "PlayerStatusView.h"
#include "PlayerHandView.h"
#include "TableView.h"

class Controller;
class Model;


class View : public Gtk::Window, public Observer {
public:
    View( Controller*, Model* );                        // cosntructor
	virtual ~View();                                    // destructor
	
	virtual void update();                              // Observer Pattern: concrete update() method

private:
	Model *model_;                                      // Observer Pattern: to access Model accessors without having to downcast subject
	
	Controller *controller_;                            // Strategy Pattern member (plus signal handlers)

	Gtk::VBox gameWindowWrapper_;                       // the most outer vbox

	Glib::RefPtr<Gtk::UIManager>   m_refUIManager;      // reference pointer of set of UI widgets
	Glib::RefPtr<Gtk::ActionGroup> m_refActionGroup;    // reference pointer of a set of action group widgets
    
                                                        // Game table and cards
	Gtk::Frame gameTableWrapper_;                       // wrapper that contains table of cards as images
	TableView *gameTableView_;                          // view that contains a set of cards that is currently on table

                                                        // Player Status
	Gtk::Frame playerStatusWrapper_;                    // frame for player status
	PlayerStatusView *playerStatusView_;                // individual views that contains player information
    
                                                        // player's card on hand
    Gtk::Frame playerHandWrapper_;                      // frame for cards on current player's hand
    PlayerHandView *playerHandView_;                    // buttons to display the cards that currently on player's hand
    
    int seed_;                                          // stores the seed from user input

                                                        // on click action event functions for menu items
	virtual void on_menuAction_new();                   // when "New game" in menu is clicked
	virtual void on_menuAction_quit();                  // when "Quit" in menu is clicked
	virtual void on_menuAction_save();                  // when "save" in menu is clicked
    virtual void on_menuAction_restore();               // when "restore" in menu is clicked
    virtual void on_menuAction_seed(Gtk::Window & parentWindow);
                                                        // when "Seed" in menu is clicked


}; // View

#endif
