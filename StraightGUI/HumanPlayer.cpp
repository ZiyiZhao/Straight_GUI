//
//  HumanPlayer.cpp
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//

#include "HumanPlayer.h"
//constructor
HumanPlayer::HumanPlayer(std::string playerName):Player(playerName){}

//check for legal command
Command* HumanPlayer::turn(std::vector<Card*> cardsOnTable) const{
    
    Command* command = new Command();
    bool legalPlay = false;
    do{
        legalPlay = false;
        std::cout << ">";
        std::cin>>*command;
        if(command->type == PLAY) {
            std::vector<Card*> legalCards = getLegalCards(cardsOnTable);
            
            //check if the offered card is one of the legal cards to play
            for(unsigned int index = 0; index < legalCards.size(); index++){
                if(command->card.getSuit() == legalCards[index]->getSuit() &&
                   command->card.getRank() == legalCards[index]->getRank()){
                    legalPlay = true;
                }
            }
        } else if(command->type == DISCARD) {
            
            //the set of legal playable cards should have a size of zero in this case
            std::vector<Card*> legalCards = getLegalCards(cardsOnTable);
            
            // discarding a card is allowed if there is no legal playable cards
            if(legalCards.size() == 0) {
                legalPlay = true;
            } else {
                std::cout << "You have a legal play. You may not discard." << std::endl;
            }
        } else if(command->type == QUIT){
            //quit is a legal command
            legalPlay = true;
        } else if(command->type == RAGEQUIT){
            //rage quit is a legal command
            legalPlay = true;
        } else if(command->type == DECK){
            //DECK is a legal command to check for the cards in the current deck
            legalPlay = true;
        }
        // handle if it is not a legal play
        if(!legalPlay && command->type != DISCARD){
            std::cout << "This is not a legal play." << std::endl;
        }
        
    } while(command->type == BAD_COMMAND || !legalPlay);
    
    return command;
}

//display the cards on the player's hand
void HumanPlayer::displayHand(std::vector<Card*> cardsOnTable) const{
    // Get the legal plays for the player
    std::vector<Card*> legalPlays = getLegalCards(cardsOnTable);
    
    // Display the current cards on the table and the avlaible options for player
    displayGameTable(cardsOnTable, legalPlays);
}

//display the cards
void HumanPlayer::displayGameTable(const std::vector<Card*> cardsOnTable, const std::vector<Card*> legalPlays) const{
    
    //prepare to display the cards that have already been played
    std::string displayMessage = "Cards on the table: ";
    
    std::vector<Card*> clubs;
    std::vector<Card*> diamonds;
    std::vector<Card*> hearts;
    std::vector<Card*> spades;
    
    for(unsigned int index = 0; index < cardsOnTable.size(); index++){
        //store the cards individually according to its suit
        switch (cardsOnTable[index]->getSuit()){
            case(CLUB):
                clubs.push_back(cardsOnTable[index]);
                break;
            case(DIAMOND):
                diamonds.push_back(cardsOnTable[index]);
                break;
            case(HEART):
                hearts.push_back(cardsOnTable[index]);
                break;
            case(SPADE):
                spades.push_back(cardsOnTable[index]);
                break;
            default:
                break;
        }
    }
    
    //sort each array of Suit
    std::string clubsSorted = sort(clubs);
    std::string diamondsSorted = sort(diamonds);
    std::string heartsSorted = sort(hearts);
    std::string spadesSorted = sort(spades);
    
    //prepare to display the cards on hand
    std::string playerHand = "Your hand:";
    
    for(unsigned int index = 0; index < playerData-> cardsInHand_.size(); index++){
        playerHand.append(" "+ranks[playerData->cardsInHand_[index]->getRank()]+suits[playerData->cardsInHand_[index]->getSuit()]);
    }
    
    //prepare the information of the list of legal plays on player's hand
    std::string playerLegalCards = "Legal plays:";
    for(unsigned int index = 0; index < playerData->cardsInHand_.size(); index++){
        for(unsigned int legalIndex = 0; legalIndex < legalPlays.size(); legalIndex++){
            if(playerData->cardsInHand_[index] == legalPlays[legalIndex]){
                playerLegalCards.append(" "+ranks[playerData->cardsInHand_[index]->getRank()]+suits[playerData->cardsInHand_[index]->getSuit()]);
            }
        }
    }
    
    //print out the prepared messages
    std::cout << displayMessage << std::endl;
    std::cout << "Clubs:" << clubsSorted << std::endl;
    std::cout << "Diamonds:" << diamondsSorted<<std::endl;
    std::cout << "Hearts:" << heartsSorted<<std::endl;
    std::cout << "Spades:" <<spadesSorted <<std::endl;
    std::cout << playerHand << std::endl;
    std::cout << playerLegalCards << std::endl;
    
    
}

//returns the string that contains the information of the sorted list of cards
std::string HumanPlayer::sort(const std::vector<Card*>& cards) const{
    std::string combine = "";
    for (int i = 0; i < 13; i ++){
        for (int j = 0; j < cards.size(); j++){
            // append the card rank to the string
            if (i == cards[j]->getRank())   combine.append(" "+ranks[cards[j]->getRank()]);
        }
    }
    return combine;
}
