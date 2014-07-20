//
//  DialogView.h
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//
#ifndef MVC_DIALOGENDVIEW_H
#define MVC_DIALOGENDVIEW_H

#include <gtkmm/dialog.h>
#include <gtkmm/box.h>
#include <gtkmm/checkbutton.h>
#include "model.h"
#include "observer.h"
#include <vector>
using std::string;
using std::vector;

class DialogEndView : public Gtk::Dialog {
public:
                                                    // Specifies the parent window of the dialog box
	DialogEndView( Gtk::Window & parentWindow);
	virtual ~DialogEndView();                          //destructor

};
#endif

