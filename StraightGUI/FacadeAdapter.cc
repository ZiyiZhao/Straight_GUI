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

bool FacadeAdapter::playCard(int rank, int suit) {
	std::cout << "In adapter" << std::endl;
	int playType = players_[currentPlayer_]->playCardType(rank, suit, gameTable_->getCurrentTable());
	std::cout << "type of play: " << playType << std::endl;
	if(1 == playType) {
		gameTable_->addCardToTable(players_[currentPlayer_]->playCard(rank, suit));	
		currentPlayer_ = ((currentPlayer_ + 1) % 4);
		return true;
	} else if(playType == 0) {
		players_[currentPlayer_]->discardCard(rank, suit);
		currentPlayer_ = ((currentPlayer_ + 1) % 4);
		return true;
	}

	return false;
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
