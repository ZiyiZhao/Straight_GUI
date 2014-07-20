//
//  view.cc
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//
#include "observer.h"
#include "view.h"
#include "controller.h"
#include "model.h"
#include "subject.h"
#include "TableView.h"
#include "DialogView.h"

#include <iostream>
#include <sstream>
#include <gtkmm/dialog.h>
#include <gtkmm/stock.h>
#include <gtkmm/label.h>
#include <gtkmm/entry.h>

// constructor
View::View(Controller *c, Model *m): model_(m), controller_(c), seed_(0){

	// Sets properties of the window.
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
                          sigc::bind<Gtk::Window&>(sigc::mem_fun(*this, &View::on_menuAction_seed), *this ));
    m_refActionGroup->add( Gtk::Action::create("Quit", Gtk::Stock::QUIT),
                          sigc::mem_fun(*this, &View::on_menuAction_quit) );
    
    // Define how the actions are presented in the menus and toolbars:
    Glib::RefPtr<Gtk::UIManager> m_refUIManager = Gtk::UIManager::create();
    m_refUIManager->insert_action_group(m_refActionGroup);
    add_accel_group(m_refUIManager->get_accel_group());
    
    // Layout the actions in a menubar and toolbar:
    Glib::ustring ui_info =
    "<ui>"
    "  <menubar name='MenuBar'>"
    "    <menu action='MenuFile'>"
    "      <menuitem action='NewGame'/>"
    "      <menuitem action='Save'/>"
    "      <separator/>"
    "      <menuitem action='RestoreSavedGame'/>"
    "      <menuitem action='StoreSeed'/>"
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

    /*      Cards and Table 	*/
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

    // set the seed (initialized to be 0)
    model_->setSeed(seed_);

} // View::View

// destructor
View::~View() {
    std::cout << "OVER!!" << std::endl;
    delete model_;
    delete controller_;
    delete gameTableView_;
    delete playerStatusView_;
    delete playerHandView_;

}

// update the current view with new content
void View::update(){
    //show_all();
    
    if (model_->getRoundOver()){
        Gtk::Dialog dialog( "Game Status", *this );
        Gtk::VBox* contentArea = dialog.get_vbox();
        Gtk::Label message("Player Status:  ");
        
        contentArea->pack_start(message, true, false);
        dialog.show_all_children();
        //discarded cards and score for each player
        //
        //
        //
        //
        
        if (model_->getGameOver()){
            //if (true){
            
            //in case of multiple player wins
            std::string winnerPlayers = "";
            //get winner
            //
            //
            
            Gtk::Label winner ("Player " + winnerPlayers + "wins! Congratulations! ");
            contentArea->pack_start(winner, true, false);
            winner.show();
            
            Gtk::Button * okButton = dialog.add_button( Gtk::Stock::OK, Gtk::RESPONSE_OK);

        } else {
            Gtk::Label nextRound("Ready for next round? Let's start!");
            contentArea->pack_start(nextRound, true, false);
            nextRound.show();
            
            Gtk::Button * nextRoundButton = dialog.add_button( "Continue Game", Gtk::RESPONSE_ACCEPT);
        }
        
        // Wait for a response from the dialog box.
        int result = dialog.run();
        
        // determine corresponding action for different player events
        switch (result) {
            case Gtk::RESPONSE_OK:
                // what happens when the game ends?
                break;
            case Gtk::RESPONSE_ACCEPT:
                // continue to the next round
                break;
            default:
                std::cout << "unexpected button clicked" << std::endl;
                break;
        } // switch
        

    
    }
    
    
}

void View::on_menuAction_quit() {
    // Closes the main window to stop the Gtk::Main::run().
    hide();
}

// create a new game
void View::on_menuAction_new() {
    std::cout << "Creating a new game..." << std::endl;
    // diaplay a dialog for Player selection
    DialogView dialog(*this);
    // start a new game with player type defined
    model_->newGame(dialog.getPlayerType());

}

// saving the current game
void View::on_menuAction_save() {
    std::cout << "Saving the game..." << std::endl;
}

// restore a previously saved game
void View::on_menuAction_restore() {
    std::cout << "Restoring the game. Please wait..." << std::endl;
}

// setting a seed for random number generator
void View::on_menuAction_seed(Gtk::Window & parentWindow){
    
    // create a dialog for entering the seed
    Gtk::Dialog dialog( "Seed", parentWindow );
    
    // text entry for seed
    Gtk::Entry   seedField;
    Gtk::Label   dialogLabel( "Please enter a seed: " );
    
    // Add the text entry widget, and the label to the vertical box section of the dialog box.
    Gtk::VBox* contentArea = dialog.get_vbox();
    contentArea->pack_start( dialogLabel, true, false );
    contentArea->pack_start( seedField, true, false );
    
    // initialize the text entry widget to null string
    seedField.set_text( "" );
    
    // show all the widgets within the dialog
    dialogLabel.show();
    seedField.show();
    
    // Add two standard buttons, "Ok" and "Cancel" with the appropriate standard responses when clicked.
    Gtk::Button * okButton = dialog.add_button( Gtk::Stock::OK, Gtk::RESPONSE_OK);
    Gtk::Button * cancelButton = dialog.add_button( Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    
    // Wait for a response from the dialog box.
	int result = dialog.run();
    
    // stores the seed as a string
    std::string stringSeed;
    
    // determine corresponding action for different player events
    switch (result) {
        case Gtk::RESPONSE_OK:
            // store the text entry into seed (string)
            stringSeed = (std::string)seedField.get_text();
            break;
        case Gtk::RESPONSE_CANCEL:
            // in case of user event cancel, display message
            std::cout << "dialog cancelled" << std::endl;
            break;
        default:
            std::cout << "unexpected button clicked" << std::endl;
            break;
    } // switch
    
    // convert the current seed(string) into seed(int)
    std::stringstream convert(stringSeed);
    
    // handle the case when can not be converted
    if(!(convert >> seed_))  seed_ = 0;
    model_->setSeed(seed_);
    std::cout << "seed_ '" << seed_ << "'" << std::endl;
}
