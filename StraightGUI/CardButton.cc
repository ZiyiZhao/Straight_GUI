/*
 * MVC example of GTKmm program
 *
 * Controller class.  Is responsible for translating UI events (from the View)
 * into method calls to the Model.
 *
 *  Created by Jo Atlee on 06/07/09.
 *  Copyright 2009 UW. All rights reserved.
 *
 */


#include <gtkmm.h>

#include "observer.h"
#include "view.h"
#include "controller.h"
#include "model.h"
#include "subject.h"
#include "DeckGUI.h"
#include "CardButton.h"

CardButton::CardButton(Model* m):model_(m){
    card.set(deck.null());
    buttonCard.set_image(card);
    
    buttonCard.signal_clicked().connect( sigc::mem_fun( *this, &CardButton::onButtonClicked ) );
}


void CardButton::onButtonClicked() {
    controller_->nextButtonClicked();
}

void CardButton::update(){


}