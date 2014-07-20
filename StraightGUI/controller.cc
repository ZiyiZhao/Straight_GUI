//
//  controller.cc
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//

#include "controller.h"
#include "model.h"
#include <iostream>


Controller::Controller(Model *m) : model_(m) {}


void Controller::cardButtonClicked(const int& rank, const int& suit){
    //passed in the rank and the suit of the card
	model_->playCard(rank, suit);

}

void Controller::rageButtonClicked(){
    // PLayer rages
    model_->rage();
}