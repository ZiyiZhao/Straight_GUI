/*
 * MVC example of GTKmm program
 *
 * Subject class.  Abstract class for Observer Pattern
 *
 *
 *  Created by Jo Atlee on 06/07/09.
 *  Copyright 2009 UW. All rights reserved.
 *
 */


#ifndef MVC_DIALOGVIEW_H
#define MVC_DIALOGVIEW_H

#include <gtkmm/dialog.h>
#include <gtkmm/box.h>
#include <gtkmm/checkbutton.h>
#include "model.h"
#include "observer.h"
#include <vector>
using std::string;
using std::vector;

class Observer;
class Model;

class DialogView : public Gtk::Dialog, public Observer {
public:
	// Specifies the parent window of the dialog box
	DialogView( Gtk::Window & parentWindow, Model*);
	virtual ~DialogView();
    virtual void update();                      // Observer Pattern: concrete update() method
	
private:
	vector<Gtk::CheckButton *>   buttons;       // Buttons for the messages.
    int playerList[4];                          //0 represents computer player, and 1 represent human player
    Model* model_;
};
#endif

