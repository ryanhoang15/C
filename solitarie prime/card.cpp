//
//  card.cpp
//  Prog 1 - Solitaire Prime
//
//  Created by ryan hoang on 8/26/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#include "card.hpp"
#include <iostream>
#include <string>
using namespace std;


// create a “blank” card
Card :: Card(){
    rank = 'z';
    suit = 'z';
    cout << endl;
}

// constructor to create a card, setting the rank and suit
Card :: Card(char r, char s){
    rank = r;
    suit = s;
}

// set an existing blank card to a particular value
void Card :: setCard(char r, char s){
    rank = r;
    suit = s;
}

// return the point value of the card. Ace = 1, 2 thru 10, Jack = 10, Queen = 10, King = 10
int Card :: getValue(){
    char zero = '0';
    if(rank == 'A'){
        return 1;
    }
    else if(rank == 'T'|| rank == 'K' || rank == 'Q' || rank == 'J'){
        return 10;
    }
    else{
        int rankValue = (int) rank;
        return rankValue - (int) zero;
    }
   
}

// display the card using 2 fields… Ace of Spade:AS, Ten of Diamond:10D, Queen of Heart:QH, Three of Club:3C.
void Card :: showCard(){
    
    cout << rank << suit << ", ";
}

