//
//  Deck.h
//  Straights
//
//  Created by Jack,Errin on 2014-06-14.
//  Copyright (c) 2014 Jack,Errin. All rights reserved.
//

#include "ComputerPlayer.h"

//create a commmand object with appropriate command type and card
Command* ComputerPlayer::turn(std::vector<Card*> cardsOnTable) const{
    // create a new command
    Command* command = new Command();
    
    std::vector<Card*> legalCards = getLegalCards(cardsOnTable);
    // if there is a legal playable card, the command have the type PLAY to play the maximum legal card
    if(legalCards.size() >0){
        command->type = PLAY;
        
        //we want to play the max rank of the cards on hand
        int maximum = 0;
        Rank maxRank = legalCards[0]->getRank();
        //iterate through the array to find the max rank
        for (int i = 0; i < legalCards.size(); i++){
            // if the next rank is larger than the current rank
            if (legalCards[i]->getRank() > maxRank) {
                // reset the current rank to be the large of the two
                maxRank = legalCards[i]->getRank();
                maximum = i;
            }
        }
        // play the maximum
        command->card = *legalCards[maximum];
    } else {
        // if there is no legal playable card, the command will be DISCARD to discard the minimum card on hand
        command->type = DISCARD;
        
        //we want to play the min rank of cards on hand
        int minimum = 0;
        Rank minRank = playerData->cardsInHand_[0]->getRank();
        //iterate through the array to find the min rank
        for (int i = 0; i < playerData->cardsInHand_.size(); i++){
            // if the next rank is smaller than the current rank
            if (playerData->cardsInHand_[i]->getRank() < minRank) {
                // reset the current rank to be the smaller of the two
                minRank = playerData->cardsInHand_[i]->getRank();
                minimum = i;
            }
        }
        //discard the minimum
        command->card = *playerData->cardsInHand_[minimum];
    }
    return command;
}

//create a commmand object with appropriate command type and card
Card* ComputerPlayer::comPlayCard(std::vector<Card*> cardsOnTable) const{
    
    Command* command = new Command();
    
    std::vector<Card*> legalCards = getLegalCards(cardsOnTable);
    // if there is a legal playable card, the command have the type PLAY to play the maximum legal card
    if(legalCards.size() >0){
        command->type = PLAY;
        
        //we want to play the max rank of the cards on hand
        int maximum = 0;
        Rank maxRank = legalCards[0]->getRank();
        //iterate through the array to find the max rank
        for (int i = 0; i < legalCards.size(); i++){
            // if the next rank is larger than the current rank
            if (legalCards[i]->getRank() > maxRank) {
                // reset the current rank to be the large of the two
                maxRank = legalCards[i]->getRank();
                maximum = i;
            }
        }
        // play the maximum
        command->card = *legalCards[maximum];
    } else {
        // if there is no legal playable card, the command will be DISCARD to discard the minimum card on hand
        command->type = DISCARD;
        
        //we want to play the min rank of cards on hand
        int minimum = 0;
        Rank minRank = playerData->cardsInHand_[0]->getRank();
        //iterate through the array to find the min rank
        for (int i = 0; i < playerData->cardsInHand_.size(); i++){
            // if the next rank is smaller than the current rank
            if (playerData->cardsInHand_[i]->getRank() < minRank) {
                // reset the current rank to be the smaller of the two
                minRank = playerData->cardsInHand_[i]->getRank();
                minimum = i;
            }
        }
        //discard the minimum
        command->card = *playerData->cardsInHand_[minimum];
    }

    return &(command->card);
}