/*
 * 	Player class - holds the information to display for the viewer class
 */


#ifndef MVC_FACADEADAPTER_H
#define MVC_FACADEADAPTER_H

#include "GameTable.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Deck.h"

class FacadeAdapter {
public:
   	FacadeAdapter();	// Constructor(model, playerNum, score, discards, isAI)
   	~FacadeAdapter();

   	void startGame( bool*, int);
   	
private:
	
	// The playing table
	GameTable *gameTable_;

	// The 4 players
	Player *players_[4];

	// Current player number (0 - 3)
	int currentPlayer_;
};
#endif
