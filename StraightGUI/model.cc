//
//  model.cc
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//


#include "model.h"
#include <iostream>
#include <sstream>

Model::Model(){
	game_ = new FacadeAdapter();
	// Initalize game table
	
	for (int i = ACE; i < RANK_COUNT; i++) {
		tableHeart_[i*2] = i;
		tableHeart_[i*2+1] = HEART;
		tableSpade_[i*2] = i;
		tableSpade_[i*2+1] = SPADE;
		tableClub_[i*2] = i;
		tableClub_[i*2+1] = CLUB;
		tableDiamond_[i*2] = i;
		tableDiamond_[i*2+1] = DIAMOND;
	}
	

	// Initalize player status
	for (int i = 0; i < 4; i++) {
		playerType_[i] = "Player";
		playerStatus_[i] = "Player Score:  0\nPlayer Discard Cards:  0";
	}

	// Initalize Player Hand
	for (int i = ACE; i < RANK_COUNT; i++) {
		playerHand_[i*2] = i;
		playerHand_[i*2+1] = HEART;
	}
	infoForPlayer_ = "Welcome Player!";

}

void Model::setSeed(int seed) {
	seed_ = seed;
}

void Model::newGame(bool* playerType) {
	game_->startGame(playerType, seed_);

	update();
	updatePlayerStaus();
	updatePlayerHand();
	notify();
}


void Model::update() {
	for(int i = 0; i < 26; i++) {
		tableHeart_[i] = game_->getTableHeart()[i];
		tableDiamond_[i] = game_->getTableDiamond()[i];
		tableSpade_[i] = game_->getTableSpade()[i];
		tableClub_[i] = game_->getTableClub()[i];
	}
}

void Model::updatePlayerHand(){
	int *cardsInHand = game_->getPlayerHand();
	for(int i = 0; i < 26; i++) {
		playerHand_[i] = cardsInHand[i];
	}
	currentPlayerType_ = game_->getCurrentPlayerType();
	currentPlayerNumber_ = game_->getCurrentPlayerNumber() + 1;
}

void Model::updatePlayerStaus(){

	for(int i = 0; i < 4; i++){
		std::ostringstream oss;
		std::ostringstream oss2;
		if(game_->getPlayerName()[i] == 1){
			oss << "Player ";
		} else {
			oss << "Computer ";
		}
		oss << (i+1);
		playerType_[i] = oss.str();
		oss2 << "Player Score:  ";
		oss2 << game_->getPlayerScore()[i];
		oss2 << "\n";
		oss2 << "Player Discards:  ";
		oss2 << game_->getDiscardCards()[i];
		playerStatus_[i] = oss2.str();
	}
}

void Model::playCard(int rank, int suit) {
	if(game_->playCard(rank, suit)){
		infoForPlayer_ = "Your turn, Please choose a card.";
		std::cout << "Done playing card, updating"<<std::endl;
		updatePlayerStaus();
		updatePlayerHand();
		Model::update();
		notify();
	} else {
		std::cout << "invalid play"<<std::endl;
		infoForPlayer_ = "Invalid play! Please choose another card!";
		notify();
	}

}

int Model::getCurrentPlayerType(){
	return currentPlayerType_;
}

int Model::getCurrentPlayerNumber(){
	return currentPlayerNumber_;
}

int* Model::getTableHeart(){
	return tableHeart_;
}

int* Model::getTableDiamond(){
	return tableDiamond_;
}

int* Model::getTableSpade(){
	return tableSpade_;
}

int* Model::getTableClub(){
	return tableClub_;
}

std::string* Model::getPlayerType(){
	return playerType_;
}

std::string* Model::getPlayerStatus(){
	return playerStatus_;
}

int* Model::getPlayerHand(){
	return playerHand_;
}

std::string Model::getInfoForPlayer(){
	return infoForPlayer_;
}

void Model::rage(){
	game_->rage();
	updatePlayerHand();
	updatePlayerStaus();
	notify();
}