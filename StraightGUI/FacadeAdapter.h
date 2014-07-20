//
//  FaceAdapter.h
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//

/*
 * 	Player class - holds the information to display for the viewer class
 */


#ifndef MVC_FACADEADAPTER_H
#define MVC_FACADEADAPTER_H

#include "GameTable.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Deck.h"
#include "Card.h"

class FacadeAdapter {
public:
   	FacadeAdapter();	// Constructor(model, playerNum, score, discards, isAI)
   	~FacadeAdapter();

   	void startGame( bool*, int);

   	int* getTableHeart();
    int* getTableDiamond();
    int* getTableSpade();
    int* getTableClub();

    int getPlayerScore(int);
    int* getDiscardCards();

    int* getPlayerName();
   	
   	int* getPlayerHand();
    std::vector<char> getPlayerDiscardHand(int);
    std::vector<char> getAvailableCards();

   	bool playCard(int, int);

    int getCurrentPlayerNumber();
    int getCurrentPlayerType();

    bool ifGameOver();
    bool ifRoundOver();

    void rage();

    void checkNextPlayer();
private:
	
	// The playing table
	GameTable *gameTable_;

	// The 4 players
	Player *players_[4];

	// Current player number (0 - 3)
	int currentPlayer_;

  bool gameOver_;
  bool roundOver_;

  void checkGameOver();

};
#endif

