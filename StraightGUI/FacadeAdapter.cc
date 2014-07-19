/*
 * Player class - holds the information to display for the viewer class
 *
 */

#include "FacadeAdapter.h"
#include <iostream>
#include <sstream>

FacadeAdapter::FacadeAdapter(){
}

FacadeAdapter::~FacadeAdapter(){}

void FacadeAdapter::startGame(bool *playerType, int seed){

	// Create a new game table
	gameTable_ = new GameTable();
	// Shuffle the deck
	gameTable_->shuffle(seed);

	for(int i = 0; i < 4; i++) {
        
        // Get the player number
        std::ostringstream oss;
        oss << ( i+1 );

		if(playerType[i]) {
			players_[i] = new HumanPlayer(oss.str());
		} else {
			players_[i] = new ComputerPlayer(oss.str());
		}
	}

	
	// Assign the cards to players 
	for(int i = 0; i < 52; i++) {
		players_[i/13]->getDeltCards(gameTable_->dealCard());
	}

	// Determine who has the 7 of Spade
	for(int i = 0; i < 4; i ++) {
		if(players_[i]->hasSevenSpade()) {
			currentPlayer_ = i;
			break;
		}
	}

	//std::cout << "Done everything" << std::endl;
	//std::cout << "Player has 7S: " << currentPlayer_ << std::endl;
}
