//
//  Card.hpp
//  Prog 6 - MegaWar
//
//  Created by ryan hoang on 12/1/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp

#include <stdio.h>

enum suits {DIAMOND, HEART, SPADE, CLUB};
enum ranks {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};

class Card {
  
private:
    suits suit;
    ranks rank;
    
public:
    Card();
    Card(ranks r, suits s);
    void display();
    int cardCompare(Card card2);
    int getValue() const;

};

#endif /* Card_hpp */
