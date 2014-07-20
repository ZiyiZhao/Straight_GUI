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
    
    Command* command = new Command();
    
    std::vector<Card*> legalCards = getLegalCards(cardsOnTable);
    // if there is a legal playable card, the command have the type PLAY to play the maximum legal card
    if(legalCards.size() >0){
        command->type = PLAY;
        
        int maximum = 0;
        Rank maxRank = legalCards[0]->getRank();
        for (int i = 0; i < legalCards.size(); i++){
            if (legalCards[i]->getRank() > maxRank) {
                maxRank = legalCards[i]->getRank();
                maximum = i;
            }
        }
        command->card = *legalCards[maximum];
    } else {
        // if there is no legal playable card, the command will be DISCARD to discard the minimum card on hand
        command->type = DISCARD;
        
        int minimum = 0;
        Rank minRank = playerData->cardsInHand_[0]->getRank();
        for (int i = 0; i < playerData->cardsInHand_.size(); i++){
            if (playerData->cardsInHand_[i]->getRank() < minRank) {
                minRank = playerData->cardsInHand_[i]->getRank();
                minimum = i;
            }
        }
        command->card = *playerData->cardsInHand_[minimum];
    }
    return command;
}