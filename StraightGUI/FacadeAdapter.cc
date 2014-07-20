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

FacadeAdapter::~FacadeAdapter(){
	for(int i = 0; i < 4; i++) {
		delete players_[i];
	}
	delete gameTable_;
}

void FacadeAdapter::startGame(bool *playerType, int seed){

	// Create a new game table
	gameTable_ = new GameTable();
	// Shuffle the deck
	gameTable_->shuffle(seed);
	roundOver_ = false;
	gameOver_ = false;

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
	checkNextPlayer();
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
	int playType = players_[currentPlayer_]->playCardType(rank, suit, gameTable_->getCurrentTable());
	if(1 == playType) {
		gameTable_->addCardToTable(players_[currentPlayer_]->playCard(rank, suit));	
		currentPlayer_ = ((currentPlayer_ + 1) % 4);
		checkNextPlayer();
		return true;
	} else if(playType == 0) {
		players_[currentPlayer_]->discardCard(rank, suit);
		currentPlayer_ = ((currentPlayer_ + 1) % 4);
		checkNextPlayer();
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

int* FacadeAdapter::getPlayerName() {
	int playerName[4];
	for(int i = 0; i < 4; i++) {
		if(players_[i]->getPlayerName()[0] == 'P'){
			playerName[i] = 1; // human = true
		} else {
			playerName[i] = 0;
		}
	}
	return playerName;
}

int* FacadeAdapter::getPlayerScore(){
	int playerScore[4];
	for(int i = 0; i < 4; i++) {
		playerScore[i] = players_[i]->calculateScore();
	}
	return playerScore;
}

int* FacadeAdapter::getDiscardCards(){
	int discardCards[4];
	for(int i = 0; i < 4; i++) {
		discardCards[i] = players_[i]->getNumOfDiscardCards();
	}
	return discardCards;
}

int FacadeAdapter::getCurrentPlayerNumber(){
	return currentPlayer_;
}

int FacadeAdapter::getCurrentPlayerType(){
	if(players_[currentPlayer_]->getPlayerName()[0] == 'P') {
		return 1;
	}
	return 0;
}

void FacadeAdapter::rage(){
	Player *ragedPlayer = new ComputerPlayer(*players_[currentPlayer_]);
	delete players_[currentPlayer_];
	players_[currentPlayer_] = ragedPlayer;
	checkNextPlayer();
}

void FacadeAdapter::checkNextPlayer(){
	while(players_[currentPlayer_]->getPlayerName()[0]=='C' && 
		players_[currentPlayer_]->getPlayerHand().size() > 0){
		Card *card = players_[currentPlayer_]->comPlayCard(gameTable_->getCurrentTable());
		playCard((int)(card->getRank()), (int)(card->getSuit()));
	}
	checkGameOver();
}

bool FacadeAdapter::ifGameOver() {
	return gameOver_;
}

bool FacadeAdapter::ifRoundOver(){
	return roundOver_;
}

void FacadeAdapter::checkGameOver(){
	int cardLeft = 0;
	for(int i = 0; i < 4; i++){
		cardLeft += players_[i]->getPlayerHand().size();
		if(players_[i]->getScore() >= 80){
			gameOver_ = true;
		}
	}
	roundOver_ = (cardLeft == 0);
}
