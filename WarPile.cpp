//
//  WarPile.cpp
//  Prog 6 - MegaWar
//
//  Created by ryan hoang on 12/1/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#include "WarPile.hpp"
#include "CardPile.hpp"
#include "Card.hpp"

void WarPile :: addCard(Card card){
    pile.push_back(card);
}

Card WarPile :: removeCard(){
    Card temp = pile[pileSize() - 1];
    pile.pop_back();
    return temp;
}

void WarPile :: display(){
    for(int i = 0; i < pileSize(); i++){
        if(i != 0 && i % 13 == 0){
            cout << endl;
        }
        pile[i].display();
    }
}

int WarPile :: warPileCardsLeft(){
    return pileSize();
}

int WarPile :: pileSize(){
    return (int)pile.size();
}

Card WarPile :: deal(){
    return removeCard();
}
