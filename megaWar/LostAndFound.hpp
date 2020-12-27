//
//  LostAndFound.hpp
//  Prog 6 - MegaWar
//
//  Created by ryan hoang on 12/1/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#ifndef LostAndFound_hpp
#define LostAndFound_hpp

#include <stdio.h>
#include "CardPile.hpp"


class LostAndFound : public CardPile {
    
public:
    void addCard(Card card);
    Card removeCard();
    void display();
//    bool isEmpty();
    int LostAndFoundPileSize();
    int pileSize();
    Card deal();
    
};
#endif /* LostAndFound_hpp */
