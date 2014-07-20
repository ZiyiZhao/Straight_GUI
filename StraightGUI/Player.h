//
//  Deck.h
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//

#ifndef __Straights__Player__
#define __Straights__Player__

#include <iostream>
#include "Card.h"
#include "Command.h"
#include <vector>

class Player{
public:
    Player(std::string playerName);                             // Constructor
    ~Player();                                                  //destructor
    int getScore() const;                                       // Responds to score request
    void setScore(const int &);                                 // Set score
    int calculateScore() const;                                 // Calculate score after each round
    void getDeltCards(Card*);                                   // Add a card to the hand
    bool hasSevenSpade() const;                                 // Checks if the player has the seven of spade
    void printDiscardedCards() const;                           // Print the list of discarded cards
    void clearHand();                                           //clear the cards without deleting the objects that it points to
    virtual Command* turn(std::vector<Card*>) const = 0;        //check for legal plays from the command
    virtual void displayHand(std::vector<Card*>) const = 0;     //display the current cards on hand
    Card* playCard(const Suit, const Rank);                     //operations to play the card
    Card* playCard(int,int);
    void discardCard(const Suit, const Rank);                   //operations to discard the card
    void discardCard(int,int);
    std::vector<Card*> getPlayerHand();
    int playCardType(int, int, const std::vector<Card*>);       // 1 if valid play, 0 if valid discard, -1 if invalid play
private:
    Player& operator=(Player&);                                 // Prohibited assignment operator
    void displayGameTable(const std::vector<Card*>, const std::vector<Card*>);
                                                                //display the cards that have already been played
    
protected:
    Player(const Player&);                                      // Cope constructor that is used for AI/Human copying
    
    struct PlayerData{
        const std::string playerName_;
        int playerScore_;
        std::vector<Card*> cardsInHand_;
        std::vector<Card*> discardedCards_;
        
        PlayerData(const std::string);
        PlayerData(const PlayerData& playerData);
    };                                                          // Data hiding
    PlayerData* playerData;                                     // Data hiding
    
    static const std::string suits[SUIT_COUNT];                 // Array of string that corresponds to the suit
    static const std::string ranks[RANK_COUNT];                 // Array of string that corresponds to the rank
    std::vector<Card*> getLegalCards(const std::vector<Card*>) const;
    Card* removeCardFromHand(const Suit, const Rank);           // Returns a card from hand
    bool checkCardPlayable(const Card*, const std::vector<Card*>) const;
                                                                //helper function to check whether is a legal play
    
};

#endif
