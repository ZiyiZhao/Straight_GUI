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
    Controller( Model* );
    void cardButtonClicked(const int&, const int&);
    void rageButtonClicked();
private:
    Model *model_;
};  // Controller


#endif

