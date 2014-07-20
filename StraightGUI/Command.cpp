//
//  Deck.h
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//

#include "Command.h"
#include <cassert>
#include <sstream>
using namespace std;

istream &operator>>(istream &in, Command &c){
	c.type = BAD_COMMAND;
	
    //take in a command
	string cmd;
	in >> cmd;
	
    //check for command types, and perform corresponding action
	if (cmd == "play") {
		c.type = PLAY;
		in >> c.card;
	} else if (cmd == "discard") {
		c.type = DISCARD;
		in >> c.card;
	} else if (cmd == "deck") {
		c.type = DECK;
	} else if (cmd == "quit") {
		c.type = QUIT;
	} else if (cmd == "ragequit") {
		c.type = RAGEQUIT;
	}
	
    //assert if input fails or command type = bad command
	assert(!in.fail() && c.type != BAD_COMMAND);
	
	return in;
}