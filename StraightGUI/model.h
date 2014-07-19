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


#ifndef MVC_MODEL_H
#define MVC_MODEL_H

#include <iostream>
#include "subject.h"
#include "FacadeAdapter.h"


const int numFaces = 6;
const int numSuits = 4;
const int numCards = numFaces * numSuits;

//enum Faces { /*NINE, TEN, JACK, QUEEN, KING, ACE, NOFACE*/ };
//enum Suits { /*DIAMOND, CLUB, HEART, SPADE, NOSUIT*/ };

class Model : public Subject {
public:
    Model();
    
    int* getTableHeart();
    int* getTableDiamond();
    int* getTableSpade();
    int* getTableClub();

    std::string* getPlayerType();
    std::string* getPlayerStatus();

    int* getPlayerHand();
    std::string getInfoForPlayer();
private:
	// Facade Design
    FacadeAdapter *game_;

    // Table Game Data
    int tableHeart_[26];
    int tableDiamond_[26];
    int tableSpade_[26];
    int tableClub_[26];

    // Players Status Data
    std::string playerType_[4];
    std::string playerStatus_[4];

    // Player's Current Hand
    int playerHand_[26];

    std::string infoForPlayer_;
};


#endif
