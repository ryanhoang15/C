//
//  WarPile.hpp
//  Prog 6 - MegaWar
//
//  Created by ryan hoang on 12/1/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#ifndef WarPile_hpp
#define WarPile_hpp

#include <stdio.h>
#include "CardPile.hpp"
#include "Card.hpp"


class WarPile : public CardPile {
  
public:
    void addCard(Card card);
    Card removeCard();
    void display();
    int warPileCardsLeft();
    int pileSize();
    Card deal();
};

#endif /* WarPile_hpp */
