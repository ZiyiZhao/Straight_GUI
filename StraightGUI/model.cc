/*
 * MVC example of GTKmm program
 *
 * Model class.  Is responsible keeping track of the deck of cards.  
 * It knows nothing about views or controllers.
 *
 *  Created by Jo Atlee on 06/07/09.
 *  Copyright 2009 UW. All rights reserved.
 *
 */


#include "model.h"

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