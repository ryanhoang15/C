//
//  Card.cpp
//  Prog 6 - MegaWar
//
//  Created by ryan hoang on 12/1/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#include "Card.hpp"
#include <iostream>
using namespace std;


Card :: Card(){
    suit = DIAMOND;
    rank = ACE;
}

Card :: Card(ranks r, suits s){
    suit = s;
    rank = r;

}

int Card :: getValue() const{
    
    if(ACE == this->rank){
        return 1;
    }
    else if(TWO == this->rank){
        return 2;
    }
    else if(THREE == this->rank){
        return 3;
    }
    else if(FOUR == this->rank){
        return 4;
    }
    else if(FIVE == this->rank){
        return 5;
    }
    else if(SIX == this->rank){
        return 6;
    }
    else if(SEVEN == this->rank){
        return 7;
    }
    else if(EIGHT == this->rank){
        return 8;
    }
    else if(NINE == this->rank){
        return 9;
    }
    else if(TEN == this->rank){
        return 10;
    }
    else if(JACK == this->rank){
        return 11;
    }
    else if(QUEEN == this->rank){
        return 12;
    }
    else{
        return 13;
    }
}

void Card :: display(){
    string rankNum = " ";
    string suitType = " ";
    
    if(DIAMOND == this->suit){
        suitType = "D";
    }
    else if(CLUB == this->suit){
        suitType = "C";
    }
    else if(SPADE == this->suit){
        suitType = "S";
    }
    else if(HEART == this->suit){
        suitType = "H";
    }
    
    if(ACE == this->rank){
        rankNum = "A";
    }
    else if(TWO == this->rank){
        rankNum = "2";
    }
    else if(THREE == this->rank){
        rankNum = "3";
    }
    else if(FOUR == this->rank){
        rankNum = "4";
    }
    else if(FIVE == this->rank){
        rankNum = "5";
    }
    else if(SIX == this->rank){
        rankNum = "6";
    }
    else if(SEVEN == this->rank){
        rankNum = "7";
    }
    else if(EIGHT == this->rank){
        rankNum = "8";
    }
    else if(NINE == this->rank){
        rankNum = "9";
    }
    else if(TEN == this->rank){
        rankNum = "10";
    }
    else if(JACK == this->rank){
        rankNum = "J";
    }
    else if(QUEEN == this->rank){
        rankNum = "Q";
    }
    else if(KING == this->rank){
        rankNum = "K";
    }
    cout << rankNum << suitType << " ";
}

/**
 if (string1 > string2) it returns a positive value.
 if both the strings are equal lexicographically
 i.e.(string1 == string2) it returns 0.
 if (string1 < string2) it returns a negative value.
 */
int Card :: cardCompare(Card card2){
    int cardValue = this->getValue();
    int card2_Value = card2.getValue();
    int result = 0;
    
    if(cardValue > card2_Value){
       result = 1;
    }
    else if(cardValue < card2_Value){
        result =  -1;
    }
    else if(cardValue == card2_Value){
        result = 0;
    }
    return result;
}


