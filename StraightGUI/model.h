//
//  model.h
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//


#ifndef MVC_MODEL_H
#define MVC_MODEL_H

#include <iostream>
#include "subject.h"
#include "FacadeAdapter.h"


const int numFaces = 6;
const int numSuits = 4;
const int numCards = numFaces * numSuits;


class Model : public Subject {
public:
    Model();

    void setSeed(int);
    
    void newGame(bool*);

    void update();

    void playCard(int, int);

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

    // Game seed
    int seed_;

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
