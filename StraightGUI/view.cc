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
#include "DeckGUI.h"
#include <iostream>
#include <sstream>

// Creates buttons with labels. Sets butBox elements to have the same size, 
// with 10 pixels between widgets
View::View(Controller *c, Model *m) : model_(m), controller_(c), verticalFrame_(true,10), heartSuitCardsBox_(true,5), spadeSuitCardsBox_(true,5), diamondSuitCardsBox_(true,5), clubSuitCardsBox_(true,5), cardOnHand_(true, 5), cardFrame_("Your Cards:") {

	// Sets some properties of the window.
    set_title( "CS246 MVC example" );
	set_border_width( 10 );
	set_default_size(1000,500);
	

	/*
		The Menu Bar
	*/

	// Add panels to the window
	add(verticalFrame_);

	//Define the actions:
    m_refActionGroup = Gtk::ActionGroup::create();
    
    m_refActionGroup->add( Gtk::Action::create("MenuFile", "_Menu") );
    m_refActionGroup->add( Gtk::Action::create("NewGame", Gtk::Stock::NEW, "New Game"),
                          sigc::mem_fun(*this, &View::on_menuAction_new));
    m_refActionGroup->add( Gtk::ToggleAction::create("Save",
                                                     Gtk::Stock::SAVE, "Save" ),
                          sigc::mem_fun(*this, &View::on_menuAction_save) );
    m_refActionGroup->add( Gtk::Action::create("RestoreSavedGame", Gtk::Stock::DIRECTORY, "Restore a saved game"),
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
    verticalFrame_.pack_start(*pMenuBar, Gtk::PACK_SHRINK);


    /*
		Cards and Table
    */

	const Glib::RefPtr<Gdk::Pixbuf> emptyCardPixbuf = deck.empty();

	//	Add the cards 
	verticalFrame_.add(heartSuitCardsBox_);
	verticalFrame_.add(spadeSuitCardsBox_);
	verticalFrame_.add(diamondSuitCardsBox_);
	verticalFrame_.add(clubSuitCardsBox_);

	// Initalize the card image as empty
	// Add them to the hand
	for (int i = 0; i < 13; i++ ) {
		heartCardImg[i] = new Gtk::Image( emptyCardPixbuf );
		spadeCardImg[i] = new Gtk::Image( emptyCardPixbuf );
		diamondCardImg[i] = new Gtk::Image( emptyCardPixbuf );
		clubCardImg[i] = new Gtk::Image( emptyCardPixbuf );
		heartSuitCardsBox_.add( *heartCardImg[i] );
		spadeSuitCardsBox_.add( *spadeCardImg[i] );
		diamondSuitCardsBox_.add( *diamondCardImg[i] );
		clubSuitCardsBox_.add( *clubCardImg[i] );
	} 

	/*
	Player Status
	*/
	
	verticalFrame_.add(playerStatusBox_);
	for(int i = 0; i < 4; i++) {

		// Add the player
		std::ostringstream oss;
		oss << "Player ";
		oss << (i + 1);
		Gtk::Frame *playerFrame = new Gtk::Frame(oss.str());
		playerStatus_[i] = new PlayerStatus(playerFrame, 0, 0, false);
		playerStatusBox_.add(*playerFrame);

	}

	verticalFrame_.add(cardFrame_);
    cardFrame_.add(cardOnHand_);
    
    for (int i = 0; i < 13; i++){
        cardOnHandList_[i] = new CardButton(model_);
        cardOnHand_.pack_start(*cardOnHandList_[i]);
    }



    show_all();
    show_all_children();

    model_->subscribe(this);

} // View::View

View::~View() {}

void View::update(){

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
