//
//  Player.hpp
//  Prog 6 - MegaWar
//
//  Created by ryan hoang on 12/1/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "CardPile.hpp"
#include "Card.hpp"

class Player : public CardPile {
    
private:
    int playerPosition;
    int battle;
    int won;
  
public:
    Player(int num);
    void add(Card card);
    void addCard(Card card);
    int cardsLeft();
    Card playerDeal();
    Card removeCard();
    void display();
    void displayStats();
    double Fierceness();
    int playerHandSize();
    void battlePlayed();
    void battleWon();
    int getBattle() const;
    int getVictory() const;
    int topCard();
    int pileSize();
    int playerLeftToPlay();
    void addToBottom(Card card);
    int getPlayerPosition() const;

};

#endif /* Player_hpp */
