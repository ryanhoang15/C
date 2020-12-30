//
//  MegaDeck.hpp
//  Prog 6 - MegaWar
//
//  Created by ryan hoang on 12/1/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#ifndef MegaDeck_hpp
#define MegaDeck_hpp

#include <stdio.h>
#include "CardPile.hpp"
#include "Card.hpp"


class MegaDeck : public CardPile{
    
public:
    MegaDeck(int num);
    Card deal();
    void display();
    void shuffle();
    int megaDeckSize();
    void addCard(Card card);
    Card removeCard();    
    int pileSize();
   
    
};


#endif /* MegaDeck_hpp */
