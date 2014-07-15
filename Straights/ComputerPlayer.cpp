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
    // if there is a legal playable card, the command have the type PLAY to play the first legal card
    if(legalCards.size() >0){
        command->type = PLAY;
        command->card = *legalCards[0];
    } else {
        // if there is no legal playable card, the command will be DISCARD to discard the first card on hand
        command->type = DISCARD;
        command->card = *playerData->cardsInHand_[0];
    }
    return command;
}