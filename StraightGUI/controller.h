//
//  controller.h
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//

#ifndef MVC_CONTROLLER_H
#define MVC_CONTROLLER_H


#include <gtkmm.h>

class Model;

class Controller {
public:
    Controller( Model* );                           //constructor
    ~Controller();                                  //destructor
    void cardButtonClicked(const int&, const int&); //controls when a card is played
    void rageButtonClicked();                       //controls when the rage button is clicked
private:
    Model *model_;                                  //model instance
};  // Controller


#endif

