//
//  FacadeAdapter.cc
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//


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

int* FacadeAdapter::getPlayerHand() {

	std::vector<Card*> cardsInHandVect = players_[currentPlayer_]->getPlayerHand();
	
	int cardsInHandArr[26];
	for(int i = 0; i < 26; i++) {
		cardsInHandArr[i] = -1;
	}

	for(int i = 0; i < cardsInHandVect.size(); i++) {
		cardsInHandArr[i*2] = (int)(cardsInHandVect.at(i)->getRank());
		cardsInHandArr[i*2+1] = (int)(cardsInHandVect.at(i)->getSuit());
	}

	return cardsInHandArr;
}

int* FacadeAdapter::getTableHeart() {
    return gameTable_->getTableHeart();
}

int* FacadeAdapter::getTableDiamond() {
    return gameTable_->getTableDiamond();
}

int* FacadeAdapter::getTableSpade() {
    return gameTable_->getTableSpade();
}

int* FacadeAdapter::getTableClub() {
    return gameTable_->getTableClub();
}
