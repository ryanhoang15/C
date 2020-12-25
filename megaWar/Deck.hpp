//
//  Deck.hpp
//  Prog 6 - MegaWar
//
//  Created by ryan hoang on 12/1/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#ifndef Deck_hpp
#define Deck_hpp

#include <stdio.h>
#include "CardPile.hpp"
#include "Card.hpp"

class Deck : public CardPile {
    
public:
    Deck();
    Card deal();
    void display();
    void shuffle();
    int pileSize();
    Card removeCard();
    void addCard(Card card);
    
};

#endif /* Deck_hpp */
