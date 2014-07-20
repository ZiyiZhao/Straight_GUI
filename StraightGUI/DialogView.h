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

class DialogView : public Gtk::Dialog {
public:
                                                    // Specifies the parent window of the dialog box
	DialogView( Gtk::Window & parentWindow);
	virtual ~DialogView();                          //destructor
	bool* getPlayerType();                          //returns the pointer of the playerList array

private:
	vector<Gtk::CheckButton *>   buttons;           // Buttons for the messages.
    bool playerList_[4];                            //false represents computer player, and true represent human player
};
#endif

