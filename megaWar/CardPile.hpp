//
//  CardPile.hpp
//  Prog 6 - MegaWar
//
//  Created by ryan hoang on 12/1/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#ifndef CardPile_hpp
#define CardPile_hpp

#include <stdio.h>
#include <vector>
#include "Card.hpp"
#include <iostream>
using namespace std;

class CardPile {
    
protected:
    vector<Card> pile;
    
public:
    virtual void addCard(Card card) = 0;
    virtual Card removeCard() = 0;
    virtual void display() = 0;
    virtual int pileSize() = 0;
    
};
#endif /* CardPile_hpp */
