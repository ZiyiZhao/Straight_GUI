//
//  Deck.h
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//

/*
 To do
 - display order - smallest to largest
 */



#include "Game.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <memory>

//constructor
Game::Game(){
    deck_ = new Deck();
}

//destructor
Game::~Game(){
    
    // Delete players in array
    for(int index = 0; index < 4; index++){
        delete players_[index];
    }
    
    // Delete deck
    delete deck_;
};

//function to start the game
void Game::startGame(){
    
    // Invite players
    invitePlayers();
    
    bool gameEnd = false;
    
    //perform operations while it is not the end of the game
    while(!gameEnd){
    
        // Reset the game
        // Shuffle the deck
        deck_->shuffle();
        cardsOnTable_.clear();
        
    
        // Deal the cards
        for(int playerIndex = 0; playerIndex < 4; playerIndex ++){
            players_[playerIndex]->clearHand();
            
            //every player gets 13 cards stored in their hand
            for(int cardI = 0; cardI < 13; cardI++){
                players_[playerIndex]->getDeltCards(deck_->getNextCard());
            }
        }
    
        // Get the player that should go first, has 7 of spade
        for(int playerIndex = 0; playerIndex < 4; playerIndex++){
            if(players_[playerIndex]->hasSevenSpade()){
                startingPlayer_ = playerIndex;
                break;
            }
        }
    
        // Start of the game
        std::cout << "A new round begins. It's player " << (startingPlayer_+1) << "'s turn to play."<<std::endl;
        for(int turnIndex = startingPlayer_; turnIndex < startingPlayer_+52; turnIndex++){
            
            //displays information about the current turn
            players_[turnIndex%4]->displayHand(cardsOnTable_);
            
            //inputs player's command
            Command *command = players_[turnIndex%4]->turn(cardsOnTable_);
        
            if(command->type == DECK){
                do{
                    //display total deck
                    deck_->displayDeck();
                    command = players_[turnIndex%4]->turn(cardsOnTable_);
                }while(command->type == DECK);
            }
        
            if(command->type == PLAY) {
                do{
                    try{
                        // play the card and add the card to the current played cards
                        cardsOnTable_.push_back(players_[turnIndex%4]->playCard(command->card.getSuit(), command->card.getRank()));
                    break;
                    }catch(std::runtime_error& e){
                        std::cout << e.what() << std::endl;
                        command = players_[turnIndex%4]->turn(cardsOnTable_);
                        turnIndex--;
                    }
                }while(true);
            } else if(command->type == DISCARD){
                
                // discard the card if no legal plays
                players_[turnIndex%4]->discardCard(command->card.getSuit(), command->card.getRank());
            }else if(command->type == QUIT){
                
                // quit the game immediately
                delete command;
                return;
            } else if(command->type == RAGEQUIT) {
                std::cout << "Player " << (turnIndex%4)+1 << " ragequits. A computer will now take over." << std::endl;
                
                //player rage quits, and the computer takes over
                Player *player = new ComputerPlayer(*players_[turnIndex%4]);
                delete players_[turnIndex%4];
                
                // resign the player with computer player
                players_[turnIndex%4] = player;
                turnIndex--;
            }
        
            delete command;
        }
        
        // All players have played their cards, calculate the score
        for(int index = 0; index < 4; index++){
            // print discarded cards for a player
            players_[index]->printDiscardedCards();
            // calculate the score for current round
            int roundScore = players_[index]->calculateScore();
            
            std::cout << "Player " << (index + 1) << "'s score: " << (players_[index]->getScore()) << " + "
            << roundScore << " = ";
            
            //reset the score of the player with the new round score added
            players_[index]->setScore((roundScore + players_[index]->getScore()));
            std::cout << players_[index]->getScore() << std::endl;
            
            //if any player's score is at least 80, end the game
            if(players_[index]->getScore() >= 80) {
                gameEnd = true;
            }
        }
    }
    
    
    int min = players_[0]->getScore();
    // Declear winner!
    for(int index = 1; index < 4; index++){
        //find the winner with minimum score
        if(players_[index]->getScore() < min) {
            min = players_[index]->getScore();
        }
    }
    for (int index = 0; index < 4; index ++){
        if (players_[index]->getScore()== min){
            std::cout << "Player " << index+1 << " wins!" << std::endl;
        }
    }
}




// invite 4 players of either human or computer at the beginning of a game
void Game::invitePlayers(){
    std::string playerType;
    
    for(int index = 0; index < 4; index++){
        std::cout << "Is player "<<(index+1)<<" a human(h) or a computer(c)?" << std::endl << ">";
        std::cin >> playerType;
        
        std::ostringstream oss;
        oss << (index+1);
        
        if(std::cin.eof()){
            std::exit(0);
        }
        
        // create a human or a computer player for the game
        if(playerType == "h"){
            players_[index] = new HumanPlayer(oss.str());
        } else if(playerType == "c"){
            players_[index] = new ComputerPlayer(oss.str());
        }
    }
}

