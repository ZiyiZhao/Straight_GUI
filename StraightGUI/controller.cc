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


#include "controller.h"
#include "model.h"


Controller::Controller(Model *m) : model_(m) {}


void Controller::cardButtonClicked(const int& rank, const int& suit){
    //passed in the rank and the suit of the card

}

void Controller::rageButtonClicked(){
    //this is rage

}