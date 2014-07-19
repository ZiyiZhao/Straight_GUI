/*
 * 	Player class - holds the information to display for the viewer class
 */


#ifndef MVC_FACADEADAPTER_H
#define MVC_FACADEADAPTER_H

#include "Game.h"

class FacadeAdapter {
public:
   	FacadeAdapter();	// Constructor(model, playerNum, score, discards, isAI)
   	~FacadeAdapter();
   	
private:
	Game *game_;
};
#endif

