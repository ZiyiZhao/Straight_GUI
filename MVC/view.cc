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
#include "cardbutton.h"
#include <iostream>

// Creates buttons with labels. Sets butBox elements to have the same size, 
// with 10 pixels between widgets
View::View(Controller *c, Model *m) : model_(m), controller_(c), heartsOnTable(true,5), cardsOnHand(true, 5){

	// Sets some properties of the window.
    set_title( "CS246 MVC example" );
	set_border_width( 10 );
    //set_default_size(200,200);

    ////////////////////////////try///////////////////////////////
    add(outsideVertical);
    
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
    
    //register_stock_items(); //Makes the "example_stock_rain" stock item available.
    
    
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
        std::cerr << "building menus and toolbars failed: " <<  ex.what();
    } // catch
    
    Gtk::Widget* pMenuBar = m_refUIManager->get_widget("/MenuBar") ;
    
    outsideVertical.pack_start(*pMenuBar, Gtk::PACK_SHRINK);     // Add the MenuBar to the window

	// Add panels to the window
	//add(panels);
    
    cardsOnTable.set_label("Cards On Table:");
    cardsOnTable.set_label_align(Gtk::ALIGN_LEFT, Gtk::ALIGN_TOP);
    cardsOnTable.set_shadow_type( Gtk::SHADOW_ETCHED_OUT );
    
    
    const Glib::RefPtr<Gdk::Pixbuf> nullCardPixbuf = deck.null();
    
    for (int i = 0; i < 13; i++){
        card[i] = new Gtk::Image( nullCardPixbuf );
        heartsOnTable.add(*card[i]);
    }
    
    cardsOnTable.add(heartsOnTable);
    
    outsideVertical.pack_start(cardsOnTable);
    
    //outsideVertical.add(diamondOnTable);
    //outsideVertical.add(clubOnTable);
    //outsideVertical.add(spadeOnTable);
    
    //outsideVertical.add(playerInfo);
    //outsideVertical.add(cardsOnHand);

	// Add button box and card image to the panels
	//panels.add( butBox );
	//panels.add( card );
	//card.set( deck.null() );
    
   // for (int i = 0; i < 13; i++){

        Gtk::Button buttonCard("hi");
        //Gtk::Image card;

        //card.set(deck.null());
        //buttonCard.set_image(card);
    
        //buttonCard.signal_clicked().connect( sigc::mem_fun( *this, &Button::onButtonClicked ) );

        //add(buttonCard);
        buttonCard.show();



        //CardButton buttonOfCard;
        //add button into cardsOnhand;
    
        cardsOnHand.pack_start(buttonCard);
   // }

    outsideVertical.pack_start(cardsOnHand);
	// Add buttons to the box (a container). Buttons initially invisible
	//butBox.add( next_button );
	//butBox.add( reset_button );


	// Associate button "clicked" events with local onButtonClicked() method defined below.
	//next_button.signal_clicked().connect( sigc::mem_fun( *this, &View::nextButtonClicked ) );
	//reset_button.signal_clicked().connect( sigc::mem_fun( *this, &View::resetButtonClicked ) );
	
	
	// The final step is to display the buttons (they display themselves)
	show_all();

	// Register view as observer of model
	model_->subscribe(this);

} // View::View

View::~View() {}


void View::update() {
    /*
  Suits suit = model_->suit();
  Faces face = model_->face();
  if ( suit == NOSUIT ) 
    card.set( deck.null() );
  else
    card.set( deck.image(face, suit) );
     */

}

void View::nextButtonClicked() {
  controller_->nextButtonClicked();
} // View::nextButtonClicked

void View::resetButtonClicked() {
  controller_->resetButtonClicked();
} // View::resetButtonClicked


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