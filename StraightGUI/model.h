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

class Model : public Subject {
public:
    Model();                                    //constructor
    ~Model();                                   //destructor

    void setSeed(int);                          //mutator of seed_
    
    void newGame();
    void newGame(bool*);                        //constructs a new game

    void update();                              //updates self contained information from changed logic by user events

    void playCard(int, int);                    //a card is played
    
                                                //accessor of table content
    int* getTableHeart();                       //hearts
    int* getTableDiamond();                     //diamonds
    int* getTableSpade();                       //spade
    int* getTableClub();                        //clubs

    void updatePlayerStaus();                   //updates player status info
    void updatePlayerHand();                    //updates player hand info
    void updateRoundInfo();                     //updates round info info

    void rage();                                //handles rage quits

    std::string* getPlayerType();               //accessor of player type
    std::string* getPlayerStatus();             //accessor of player status

    int* getPlayerHand();                       //accessor of player current cards
    std::string getInfoForPlayer();             //accessor of player message

    int getCurrentPlayerType();                 //determine the player type
    int getCurrentPlayerNumber();               //determine the player id number


    int getCurrentRoundScore(int);
    int getLastRoundScore(int);

    bool getGameOver();                         //check if game over
    bool getRoundOver();                        //check if round over


    void reset();                               // resets the model

    std::vector<char> getDiscardCards(const int) const;

private:
    FacadeAdapter *game_;                       // Facade Design

    int seed_;                                  // Game seed

                                                // Table Game Data
    int tableHeart_[26];                        // hearts on table
    int tableDiamond_[26];                      // diamonds on table
    int tableSpade_[26];                        // spades on table
    int tableClub_[26];                         // clubs on table

                                                // Players Status Data
    std::string playerType_[4];                 // stores player type
    std::string playerStatus_[4];               

                                                // Player's Current Hand
    int playerHand_[26];

    int currentPlayerType_;                     // current player type
    int currentPlayerNumber_;                   // current player ID

    std::string infoForPlayer_;                 // message for player
    bool gameOver_;                             // contains check for game over
    bool roundOver_;                            // contains check for round over

    int lastRoundScore_[4];                     // round score array
    int currentRoundScore_[4];                  // round score array
    
                                                //array for each player's discarded cards
    std::vector<char> player1Discards_;
    std::vector<char> player2Discards_;
    std::vector<char> player3Discards_;
    std::vector<char> player4Discards_;

    std::vector<char> availableCards_;          // set of available cards
    bool playerGene_[4];

};


#endif
