//
//  main.cpp
//  Prog 6 - MegaWar
//
//  Created by ryan hoang on 12/1/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

/**
Ryan Hoang
CECS 282 - 01
Prog 6 - megaWar
12/7/2020
 
I certify that this program is my own original work. I did not copy any part of this program from
any other source. I further certify that I typed each and every line of code in this program.
 */


#include <iostream>
#include "Card.hpp"
#include "CardPile.hpp"
#include "Deck.hpp"
#include "Player.hpp"
#include "MegaDeck.hpp"
#include "WarPile.hpp"
#include "LostAndFound.hpp"
#include <vector>
#include <map>

using namespace std;


/**
 playing war if their is a tie
 */
void megaWar(vector<Player*>& playerWinners, LostAndFound& LostAndFound) {
    WarPile warPile;
    int lostPileSize = LostAndFound.LostAndFoundPileSize();
    
    /**
     add what is in the lost and found pile to the war pile
     */
    for(int i = 0; i < lostPileSize; i++){
        warPile.addCard(LostAndFound.deal());
    }
    
    /**
     store the cards values of each player
     */
    map<int, Card> playerCardsPlayed;
    
    int highestCardValue = 0;
    vector<Player*> warWinners;

    /**
     if the player does not have enough cards to play war just add it to the war pile
     */
    int playerHandSize;
    for(int i = 0; i < playerWinners.size(); i++){
        playerHandSize = playerWinners[i]->cardsLeft();
        if(playerHandSize < 4){
            for(int j = 0; j < playerHandSize; j++){
                warPile.addCard(playerWinners[i]->playerDeal());
            }
        }
        
    }

    /**
     if a player has no more cards left then removes them from warWinners vector
     */
    vector<Player*>::iterator iter;
    iter = playerWinners.begin();
    while(iter != playerWinners.end()){

        if((*iter)->cardsLeft() == 0){
            playerWinners.erase(iter);
        }
        else{
            iter++;
        }
    }


    /**
     adding the first three cards to the war pile
     */
    for(int i = 0; i < playerWinners.size(); i++){
        for (int j = 0; j < 3; j++) {
            warPile.addCard(playerWinners[i]->playerDeal());
        }
    }
    
    /**
     adding the fourth card to the map to store the value since that value is used to compare who won or if there is another tie
     */
    for(int i = 0; i < playerWinners.size(); i++){
        playerCardsPlayed[playerWinners[i]->getPlayerPosition()] = playerWinners[i]->playerDeal();
    }

                        
    /**
     checking who has the highest card value
     */
    map<int, Card>::iterator newIter;
    for(newIter = playerCardsPlayed.begin(); newIter != playerCardsPlayed.end(); newIter++){
        int value = newIter->second.getValue();
        if(value > highestCardValue){
            highestCardValue = value;
        }
    }

    /**
     checking who played the card that matches highest value and adds them to the winner list
     and then checks for the player that has the card to put in the war pile
     */
    for(newIter = playerCardsPlayed.begin(); newIter != playerCardsPlayed.end(); newIter++){
        if(newIter->second.getValue() == highestCardValue){
            for(int i = 0; i < playerWinners.size(); i++){
                if(playerWinners[i]->getPlayerPosition() == newIter->first){
                    warWinners.push_back(playerWinners[i]);
                }
            }
        }
    }


    /**
     adds cards in the remaining played pile to warPile
     */
    for(newIter = playerCardsPlayed.begin(); newIter != playerCardsPlayed.end(); newIter++){
        warPile.addCard(newIter->second);
    }


    /**
     if there is one winner in the vector of warWinner than one person won that game
     */
    int warPileSize = warPile.warPileCardsLeft();
    int oneWinnerIndex = 0;
    if(warWinners.size() == 1){
        warWinners[oneWinnerIndex]->battleWon();
        for(int i = 0; i < warPileSize; i++) {
            warWinners[oneWinnerIndex]->addToBottom(warPile.deal());
        }
    }

    /**
     if there are more than one winner in that war game than war is called again on those players won tied again
     */
    else{
        for(int i = 0; i < warPileSize; i++){
            LostAndFound.addCard(warPile.deal());
        }
        megaWar(warWinners, LostAndFound);
    }
}
    
/**
 reutrn how many players are left that still has cards
 playerLeftToPlay() function return's 1 if the player hand size is greater than 0
 */
int playerInGameLeft(vector<Player*>& playersList) {
    int playersLeft = 0;
    for (int i = 0; i < playersList.size(); i++) {
        playersLeft = playersLeft + playersList[i]->playerLeftToPlay();
        
    }
    
    return playersLeft;
}

int main() {
    int deckSize;
    int playerSize;
    vector<Player*> playersList;
    LostAndFound LostAndFound;

    cout << "Mega War!" << endl;
    cout << "How many decks to use : ";
    cin >> deckSize;
    cout << "\nHow many players are there: ";
    cin >> playerSize;
    for(int i = 0; i < playerSize; i++){
        Player* player = new Player(i);
        playersList.push_back(player);
    }

    MegaDeck myDeck(deckSize);
    myDeck.shuffle();

    
    int deckSplit = myDeck.megaDeckSize() / playerSize;
    int cardRemainder = myDeck.megaDeckSize() % playerSize;
    for(int j = 0; j < playerSize; j++){
        for(int k = 0; k < deckSplit; k++){
            playersList[j]->add(myDeck.deal());
        }
    }

    while(cardRemainder > 0){
        playersList[0]->add(myDeck.deal());
        cardRemainder--;
    }

    int battlesPlayed = 1;
    while (playerInGameLeft(playersList) > 1){
        
        //to keep the players card value and which player played that cards
        map<int, Card> playerCardsPlayed;
        
        //to keep the players who won
        vector<Player*> playerWinners;
        
        //store the card that has the highest value
        int highestCardValue = 0;
        
        /**
         check if each player still has cards left in their hands to play
         if they do increment the numbers of battle they played
         and deal their first card
         */
        for(int i = 0; i < playersList.size(); i++){
            if(playersList[i]->playerLeftToPlay() == 1){
                playersList[i]->battlePlayed();
                playerCardsPlayed[playersList[i]->getPlayerPosition()] = playersList[i]->playerDeal();
            }
        }
        
        /**
         iterating through the map to find the highest card value
         */
        map<int, Card>::iterator iter;
        for(iter = playerCardsPlayed.begin(); iter != playerCardsPlayed.end(); iter++){
            int value = iter->second.getValue();
            if(value > highestCardValue){
                highestCardValue = value;
            }
        }

        /**
         after finding the highest card value iterate through the map to find the player or players  who had that highest card value
         and store the key value which is the player index in the the playerWinners vector
         */
        for(iter = playerCardsPlayed.begin(); iter != playerCardsPlayed.end(); iter++){
            if(iter->second.getValue() == highestCardValue){
                playerWinners.push_back(playersList[iter->first]);
            }
        }

        /**
         if there is one winner and add it to their pile
         */
        int oneWinnerIndex = 0;
        if(playerWinners.size() == 1){
            playerWinners[oneWinnerIndex]->battleWon();
            for(iter = playerCardsPlayed.begin(); iter != playerCardsPlayed.end(); iter++){
                playerWinners[oneWinnerIndex]->addToBottom(iter->second);
            }
        }

        /**
         if there is more than one winner then there is war
         */
        else{
            for(iter = playerCardsPlayed.begin(); iter != playerCardsPlayed.end(); iter++){
                LostAndFound.addCard(iter->second);
            }
            megaWar(playerWinners, LostAndFound);
        }
        
        /**
         display the round stats
         */
        cout << "Battle " << battlesPlayed++ << " stats: " << endl;
        for(int i = 0; i < playersList.size(); i++){
            playersList[i]->displayStats();
        }
    }
}

