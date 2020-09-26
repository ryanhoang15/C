//
//  deck.hpp
//  Prog 1 - Solitaire Prime
//
//  Created by ryan hoang on 8/26/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#ifndef deck_hpp
#define deck_hpp

#include <stdio.h>
#include "card.hpp"


class Deck{
    
private:
    char suit[4] = {'S', 'H', 'D', 'C'};
    char rank[13] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    Card deck[52];
    int topIndex = 0;
    
public:
    Deck();
    void refreshDeck();
    Card deal();
    void shuffle();
    int cardsLeft();
    void showDeck();
    
};
    

#endif /* deck_hpp */
