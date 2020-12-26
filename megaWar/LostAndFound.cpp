//
//  LostAndFound.cpp
//  Prog 6 - MegaWar
//
//  Created by ryan hoang on 12/1/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#include "LostAndFound.hpp"
#include "CardPile.hpp"
#include "Card.hpp"

void LostAndFound :: addCard(Card card){
    pile.push_back(card);
}

Card LostAndFound :: removeCard(){
    Card temp = pile[pileSize() - 1];
    pile.pop_back();
    return temp;
}

Card LostAndFound :: deal(){
    return removeCard();
}

void LostAndFound :: display(){
    for(int i = 0; i < pileSize(); i++){
        if(i != 0 && i % 13 == 0){
            cout << endl;
        }
        pile[i].display();
    }
}

int LostAndFound :: LostAndFoundPileSize(){
    return pileSize();
}


int LostAndFound :: pileSize(){
    return (int)pile.size();
}
