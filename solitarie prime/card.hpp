//
//  card.hpp
//  Prog 1 - Solitaire Prime
//
//  Created by ryan hoang on 8/26/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#ifndef card_hpp
#define card_hpp

#include <stdio.h>

class Card{
    
private:
    char suit;
    char rank;

public:
    Card();
    Card(char r, char s);
    void setCard(char r, char s);
    int getValue();
    void showCard();
    
};

#endif /* card_hpp */
