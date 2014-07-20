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


#include <set>
#include <iostream>
#include "subject.h"
#include "observer.h"

// standard subject class implementation
void Subject::subscribe (Observer *newView) {
    std::cout << "Got Subscriber" << std::endl;
    observers_.insert(newView);
}


void Subject::unsubscribe (Observer *formerView) {
     observers_.erase(formerView);
}


void Subject::notify() {
  Observers::iterator i;
    for (i = observers_.begin(); i != observers_.end(); ++i)
        (*i)->update();
}
