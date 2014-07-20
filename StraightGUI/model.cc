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
		tableHeart_[i*2] = -2;
		tableHeart_[i*2+1] = HEART;
		tableSpade_[i*2] = -2;
		tableSpade_[i*2+1] = SPADE;
		tableClub_[i*2] = -2;
		tableClub_[i*2+1] = CLUB;
		tableDiamond_[i*2] = -2;
		tableDiamond_[i*2+1] = DIAMOND;
	}
	
	for(int i = 0; i < 4; i++) {
		lastRoundScore_[i] = 0;
	}

	// Initalize player status
	for (int i = 0; i < 4; i++) {
		playerType_[i] = "Player";
		playerStatus_[i] = "Player Score:  0\nPlayer Discard Cards:  0";
	}

	// Initalize Player Hand
	for (int i = ACE; i < RANK_COUNT; i++) {
		playerHand_[i*2] = -2;
		playerHand_[i*2+1] = HEART;
	}
	infoForPlayer_ = "Welcome Player!";

}

Model::~Model(){
	delete game_;
}

void Model::setSeed(int seed) {
	seed_ = seed;
}

void Model::reset(){
	player1Discards_.clear();
	player2Discards_.clear();
	player3Discards_.clear();
	player4Discards_.clear();
	availableCards_.clear();
	roundOver_ = false;
	gameOver_ = false;
	infoForPlayer_ = "Welcome";

	for(int i = 0; i < 26; i++) {
		tableDiamond_[i] = -1;
		tableHeart_[i] = -1;
		tableSpade_[i] = -1;
		tableClub_[i] = -1;
		playerHand_[i] = -1;
	}


}

void Model::newRound(){
	std::cout << "newRound" << std::endl;
	game_->startGame(playerGene_, seed_);
	reset();
	update();
	notify();
}

void Model::newGame(bool* playerType) {
	for(int i = 0; i < 4; i++){
		playerGene_[i] = playerType[i];
	}
	game_->startGame(playerType, seed_);
	reset();
	for(int i = 0; i < 4; i++) {
		lastRoundScore_[i] = 0;
	}
	update();
	notify();
}

void Model::newGame(){
	game_->startGame(playerGene_, seed_);
	reset();
	for(int i = 0; i < 4; i++) {
		lastRoundScore_[i] = 0;
	}	
	update();
	notify();
}

void Model::updateRoundInfo(){
	std::cout << "updateRoundInfo" << std::endl;
	roundOver_ = game_->ifRoundOver();
	for(int i = 0; i < 4; i++){
		if(roundOver_ && ((currentRoundScore_[i] + lastRoundScore_[i])>=80)){
			gameOver_ = true;
		}
	}
	for(int i = 0; i < 4; i++) {
		currentRoundScore_[i] = game_->getPlayerScore(i);
	}
	player1Discards_ = game_->getPlayerDiscardHand(0);
	player2Discards_ = game_->getPlayerDiscardHand(1);
	player3Discards_ = game_->getPlayerDiscardHand(2);
	player4Discards_ = game_->getPlayerDiscardHand(3);
}

void Model::update() {
	std::cout << "in" << std::endl;
	updatePlayerStaus();
	updatePlayerHand();
	updateRoundInfo();
 	for(int i = 0; i < 26; i++) {
		tableHeart_[i] = game_->getTableHeart()[i];
		tableDiamond_[i] = game_->getTableDiamond()[i];
		tableSpade_[i] = game_->getTableSpade()[i];
		tableClub_[i] = game_->getTableClub()[i];
	}
	std::cout << "update" << std::endl;
	if(getRoundOver()){
		for(int i = 0; i < 4; i++){
			lastRoundScore_[i] += game_->getPlayerScore(i);
			std::cout << "lrs " <<lastRoundScore_[i] << std::endl;
		}
	}
}

void Model::updatePlayerHand(){
	int *cardsInHand = game_->getPlayerHand();
	for(int i = 0; i < 26; i++) {
		playerHand_[i] = cardsInHand[i];
	}
	currentPlayerType_ = game_->getCurrentPlayerType();
	currentPlayerNumber_ = game_->getCurrentPlayerNumber() + 1;
	availableCards_ = game_->getAvailableCards(); //get available cards
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
		oss2 << lastRoundScore_[i];//getPlayerScore()[i]
		oss2 << "\n";
		oss2 << "Player Discards:  ";
		oss2 << game_->getDiscardCards()[i];
		playerStatus_[i] = oss2.str();
	}
}

void Model::playCard(int rank, int suit) {
	if(game_->playCard(rank, suit)){
		infoForPlayer_ = "Your turn, Please choose a card.";
		update();
		notify();
	} else {
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
	update();
	int* playerName = game_->getPlayerName();
	for(int i = 0; i < 4; i++){
		if(playerName[i] == 1){
			playerGene_[i] = true;
		} else {
			playerGene_[i] = false;
		}
	}
	notify();
}

bool Model::getGameOver(){
	return gameOver_;
}

bool Model::getRoundOver(){
	return roundOver_;
}

std::vector<char> Model::getDiscardCards(const int index) const {
	if(index == 0) {
		return player1Discards_;
	} else if (index == 1) {
		return player2Discards_;
	} else if (index == 2) {
		return player3Discards_;
	} else {
		return player4Discards_;
	}
}

int Model::getLastRoundScore(int index) {
	return lastRoundScore_[index];
}

int Model::getCurrentRoundScore(int index){
	return currentRoundScore_[index];
}

