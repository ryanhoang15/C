//
//  Player.cpp
//  Prog 6 - MegaWar
//
//  Created by ryan hoang on 12/1/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#include "Player.hpp"
#include "CardPile.hpp"
#include "Card.hpp"
#include <iomanip>

Player :: Player(int num){
    playerPosition = num;
    battle = 0;
    won = 0;
}

void Player :: addCard(Card card){
    pile.push_back(card);
}

Card Player :: removeCard(){
    Card temp = pile[pileSize() - 1];
    pile.pop_back();
    return temp;
}

void Player :: display(){
    cout << setw(3) << left << "Player " << setw(3) << getPlayerPosition() + 1 << ": Fierceness: "  << setprecision(3) << setw(5) << Fierceness() << " Cards: " << setw(5) << pileSize() << " Battles: " << setw(5) << getBattle() << " Wins: " << getVictory() << endl;
}

void Player :: displayStats(){
    display();
}


int Player :: pileSize(){
    return (int)pile.size();
}

void Player :: add(Card card){
    addCard(card);
}

int Player :: cardsLeft(){
    return (int)pileSize();
}

Card Player :: playerDeal(){
    Card playerCard = removeCard();
    return playerCard;
}

double Player :: Fierceness(){
    double sum = 0.0;
    double size = pileSize();
    if(size == 0){
        return 0;
    }
    for(int i = 0; i < size; i++){
        sum = sum + this->pile[i].getValue();
    }

    return (sum / size);
}



int Player :: topCard(){
    return this->pile[pileSize() - 1].getValue();
}

int Player :: playerLeftToPlay(){
    if(pileSize() > 0){
        return 1;
    }
    return 0;
}

void Player :: addToBottom(Card card) { //ads card to bottom of hand
    pile.insert(pile.begin(), card);
}

int Player :: getPlayerPosition() const {
    return playerPosition;
}
int Player :: getBattle() const{
    return battle;
}
int Player :: getVictory() const{
    return won;
}

void Player :: battlePlayed(){
    battle++;
}

void Player :: battleWon(){
    won++;
}


