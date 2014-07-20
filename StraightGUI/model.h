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
    ~Model();

    void setSeed(int);
    
    void newGame(bool*);

    void update();

    void playCard(int, int);

    int* getTableHeart();
    int* getTableDiamond();
    int* getTableSpade();
    int* getTableClub();

    void updatePlayerStaus();
    void updatePlayerHand();
    void updateRoundInfo();

    void rage();

    std::string* getPlayerType();
    std::string* getPlayerStatus();

    int* getPlayerHand();
    std::string getInfoForPlayer();

    int getCurrentPlayerType();
    int getCurrentPlayerNumber();

    bool getGameOver();
    bool getRoundOver();

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

    int currentPlayerType_;
    int currentPlayerNumber_;

    std::string infoForPlayer_;
    bool gameOver_;
    bool roundOver_;

    int lastRoundScore_[4];
    int lastRoundDiscards_[4];

    int currentRoundScore_[4];
    std::vector<char> player1Discards_;
    std::vector<char> player2Discards_;
    std::vector<char> player3Discards_;
    std::vector<char> player4Discards_;

    std::vector<char> availableCards_;

};


#endif
