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


#include "observer.h"
#include "view.h"
#include "controller.h"
#include "model.h"
#include "subject.h"
#include <iostream>
#include <sstream>
#include "TableView.h"
#include "DialogView.h"

// Creates buttons with labels. Sets butBox elements to have the same size, 
// with 10 pixels between widgets
View::View(Controller *c, Model *m): model_(m), controller_(c){

	// Sets some properties of the window.
    set_title( "Stright GUI Game" );
	set_border_width( 10 );
	set_default_size(1000,500);

	add(gameWindowWrapper_);
	

	/*		The Menubar 	*/

	// Create the actions:
    m_refActionGroup = Gtk::ActionGroup::create();
    // Define the actions:
    m_refActionGroup->add( Gtk::Action::create("MenuFile", "_Menu") );
    m_refActionGroup->add( Gtk::Action::create("NewGame", Gtk::Stock::NEW, "New Game"),
                          sigc::mem_fun(*this, &View::on_menuAction_new));
    m_refActionGroup->add( Gtk::ToggleAction::create("Save",
                                                     Gtk::Stock::SAVE, "Save" ),
                          sigc::mem_fun(*this, &View::on_menuAction_save) );
    m_refActionGroup->add( Gtk::Action::create("RestoreSavedGame", Gtk::Stock::DIRECTORY, "Restore saved game"),
                          sigc::mem_fun(*this, &View::on_menuAction_restore) );
    m_refActionGroup->add( Gtk::Action::create("StoreSeed", Gtk::Stock::DIRECTORY, "Store Seed"),
                          sigc::mem_fun(*this, &View::on_menuAction_restore) );
    m_refActionGroup->add( Gtk::Action::create("Quit", Gtk::Stock::QUIT),
                          sigc::mem_fun(*this, &View::on_menuAction_quit) );
    
    //Define how the actions are presented in the menus and toolbars:
    Glib::RefPtr<Gtk::UIManager> m_refUIManager = Gtk::UIManager::create();
    m_refUIManager->insert_action_group(m_refActionGroup);
    add_accel_group(m_refUIManager->get_accel_group());
    
    //Layout the actions in a menubar and toolbar:
    Glib::ustring ui_info =
    "<ui>"
    "  <menubar name='MenuBar'>"
    "    <menu action='MenuFile'>"
    "      <menuitem action='NewGame'/>"
    "      <menuitem action='Save'/>"
    "      <separator/>"
    "      <menuitem action='RestoreSavedGame'/>"
    "      <separator/>"
    "      <menuitem action='Quit'/>"
    "    </menu>"
    "  </menubar>"
    "</ui>";
    
    try {
        m_refUIManager->add_ui_from_string(ui_info);
    } catch(const Glib::Error& ex) {
        std::cerr << "building menus failed: " <<  ex.what();
    } // catch
    
    Gtk::Widget* pMenuBar = m_refUIManager->get_widget("/MenuBar") ;

    // Add the menu bar to the frame
    gameWindowWrapper_.pack_start(*pMenuBar, Gtk::PACK_SHRINK);

    /*	Cards and Table 	*/
	gameTableView_ = new TableView(model_, &gameTableWrapper_);
	gameWindowWrapper_.add(gameTableWrapper_);

	/*		Player Status 		*/
	playerStatusView_ = new PlayerStatusView(model_, &playerStatusWrapper_);
	gameWindowWrapper_.add(playerStatusWrapper_);

    /*      Player Options      */
    playerHandView_ = new PlayerHandView(model_, &playerHandWrapper_, controller_);
    gameWindowWrapper_.add(playerHandWrapper_);

    show_all();
    model_->subscribe(this);

    // Player selection
    DialogView dialog(*this, model_);
    model_->setSeed(0);
    model_->newGame(dialog.getPlayerType());

} // View::View

View::~View() {}

void View::update(){
    show_all();
}

void View::on_menuAction_quit() {
    hide(); //Closes the main window to stop the Gtk::Main::run().
}

void View::on_menuAction_new() {
    std::cout << "Creating a new game..." << std::endl;
}

void View::on_menuAction_save() {
    std::cout << "Saving the game..." << std::endl;
}

void View::on_menuAction_restore() {
    std::cout << "Restoring the game. Please wait..." << std::endl;
}
