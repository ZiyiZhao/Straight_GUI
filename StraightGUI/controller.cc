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

//constructor
Controller::Controller(Model *m) : model_(m) {}

//destructor
Controller::~Controller(){
    delete model_;
}

void Controller::cardButtonClicked(const int& rank, const int& suit){
    //passed in the rank and the suit of the card
	model_->playCard(rank, suit);

} // Controller::cardButtonClicked

void Controller::rageButtonClicked(){
    // PLayer(human) rages, and quits the game
    model_->rage();
} // Controller::rageButtonClicked