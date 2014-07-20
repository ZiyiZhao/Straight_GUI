//
//  model.cc
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//


#include "model.h"
#include <iostream>

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

}


void Model::update() {
	for(int i = 0; i < 26; i++) {
		tableHeart_[i] = game_->getTableHeart()[i];
		tableDiamond_[i] = game_->getTableDiamond()[i];
		tableSpade_[i] = game_->getTableSpade()[i];
		tableClub_[i] = game_->getTableClub()[i];
	}

	int *cardsInHand = game_->getPlayerHand();
	for(int i = 0; i < 26; i++) {
		playerHand_[i] = cardsInHand[i];
	}

	notify();
}

void Model::playCard(int rank, int suit) {
	if(game_->playCard(rank, suit)){
		infoForPlayer_ = "Your turn, Please choose a card.";
		std::cout << "Done playing card, updating"<<std::endl;
		Model::update();
	} else {
		std::cout << "invalid play"<<std::endl;
		infoForPlayer_ = "Invalid play! Please choose another card!";
	}

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