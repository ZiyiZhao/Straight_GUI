//
//  DialogView.h
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//
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

class DialogView : public Gtk::Dialog {
public:
	// Specifies the parent window of the dialog box
	DialogView( Gtk::Window & parentWindow, Model*);
	virtual ~DialogView();
	bool* getPlayerType();

private:
	vector<Gtk::CheckButton *>   buttons;       // Buttons for the messages.
    bool playerList_[4];                          //0 represents computer player, and 1 represent human player
    Model* model_;
};
#endif

