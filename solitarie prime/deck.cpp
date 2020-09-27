//
//  deck.cpp
//  Prog 1 - Solitaire Prime
//
//  Created by ryan hoang on 8/26/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#include <iostream>
#include "deck.hpp"
using namespace std;

// constructor which creates a deck of 52 cards. Ace of Spades on top, followed by the rest of the spades in order, followed by Hearts, Diamonds and Clubs.
Deck :: Deck(){
    int count = 0;
    for(int i = 0; i < 4; i++ ){
        for(int j = 0; j < 13; j++){
            deck[count].setCard(rank[j],suit[i]);
            count++;
        }
    }
}


// reset the deck so it looks like a new deck.
void Deck :: refreshDeck(){
    int count = 0;
    for(int i = 0; i < 4; i++ ){
        for(int j = 0; j < 13; j++){
            deck[count].setCard(rank[j],suit[i]);
            count++;
        }
    }
}

// deal a card from the top of the deck.
Card Deck :: deal(){
    Card dealt = deck[topIndex];
    topIndex++;
    return dealt;
}

// shuffle the cards in the deck.
void Deck :: shuffle(){
    
    srand(time(NULL));
    for(int i = 0; i < 52; i++){
        int randNum = rand() % 52;
        Card temp = deck[i];
        deck[i] = deck[randNum];
        deck[randNum] = temp;
    }
}


// return the number of cards left in the deck
int Deck :: cardsLeft(){
    int cardsRemain = 52 - topIndex;
    return cardsRemain;
}


// show all the cards in the deck: 13 columns and 4 rows.
void Deck :: showDeck(){
    for(int i = 0; i < 52; i++){
        if(i != 0 && i % 13 == 0){
            cout << endl;
        }
        deck[i].showCard();
    }
    cout << endl;
}
