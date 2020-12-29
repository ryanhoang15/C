//
//  MegaDeck.cpp
//  Prog 6 - MegaWar
//
//  Created by ryan hoang on 12/1/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#include "MegaDeck.hpp"
#include "CardPile.hpp"
#include "Card.hpp"
#include "Deck.hpp"


MegaDeck :: MegaDeck(int num){
    while(num > 0){
        Deck tempDeck;
        while(tempDeck.pileSize() > 0){
            this->addCard(tempDeck.deal());
        }
        num--;
    }
}


Card MegaDeck :: deal(){
    Card temp = removeCard();
    return temp;
}


void MegaDeck :: shuffle(){
    srand(time(NULL));
    for(int i = 0; i < megaDeckSize(); i++){
        int randNum = rand() % megaDeckSize();
        Card temp = pile[i];
        pile[i] = pile[randNum];
        pile[randNum] = temp;
    }
}

int MegaDeck :: megaDeckSize(){
    return pileSize();
}

void MegaDeck :: addCard(Card card){
    pile.push_back(card);
}

Card MegaDeck :: removeCard(){
    Card temp = pile[pileSize() - 1];
    pile.pop_back();
    return temp;
}

void MegaDeck :: display(){
    for(int i = 0; i < pileSize(); i++){
        if(i != 0 && i % 13 == 0){
            cout << endl;
        }
        pile[i].display();
    }
}


int MegaDeck :: pileSize(){
    return (int)pile.size();
}


