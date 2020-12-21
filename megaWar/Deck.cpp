//
//  Deck.cpp
//  Prog 6 - MegaWar
//
//  Created by ryan hoang on 12/1/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#include "Deck.hpp"
#include "CardPile.hpp"
#include "Card.hpp"

Deck :: Deck(){
    for(suits s = DIAMOND; s <= CLUB; s = suits(s + 1)){
        for(ranks r = ACE; r <= KING; r = ranks(r + 1)){
            Card card(r,s);
            addCard(card);
        }
    }
}

void Deck :: addCard(Card card){
    pile.push_back(card);
}

Card Deck :: deal(){
    return removeCard();
}

Card Deck :: removeCard(){
    Card temp = pile[pileSize() - 1];
    pile.pop_back();
    return temp;
}

void Deck :: display(){
    for(int i = 0; i < pileSize(); i++){
        if(i != 0 && i % 13 == 0){
            cout << endl;
        }
        pile[i].display();
    }
}

int Deck :: pileSize(){
    return (int)pile.size();
    
}

void Deck :: shuffle(){
    
    srand(time(NULL));
    for(int i = 0; i < 52; i++){
        int randNum = rand() % 52;
        Card temp = pile[i];
        pile[i] = pile[randNum];
        pile[randNum] = temp;
    }
}

