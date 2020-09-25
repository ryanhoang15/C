//
//  main.cpp
//  Prog 1 - Solitaire Prime
//
//  Created by ryan hoang on 8/26/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

/**
Ryan Hoang
CECS 282 - 01
Prog 1 - Solitaire Prime
09/14/2020
 
I certify that this program is my own original work. I did not copy any part of this program from
any other source. I further certify that I typed each and every line of code in this program.
 */

#include <iostream>
#include "deck.hpp"
#include "card.hpp"
using namespace std;

void menu(){
    cout << "\nWelcome to Solitaire Prime!" << endl;
    cout << "Here is the Menu Options" << endl;
    cout << "1) New Deck" << endl;
    cout << "2) Display Deck" << endl;
    cout << "3) Shuffle Deck" << endl;
    cout << "4) Play Solitaire Prime" << endl;
    cout << "5) Exit" << endl;

}

bool isPrime(int num){
    if(num == 1){
        return false;
    }
    
    for(int i = 2; i <= num / 2; i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
    
}

void playSolitaire(Deck myDeck){
    cout << "Playing Solitaire Prime!!!" << endl;
    
    int sum = 0;
    int pile = 0;
    bool flag = true;
    Card c1;
    
    while(flag){
        
        c1 = myDeck.deal();
        sum = sum + c1.getValue();
        c1.showCard();
        
        if(isPrime(sum)){
            cout << "Prime: " << sum << endl;
            sum = 0;
            pile++;
        }
        
        if(myDeck.cardsLeft() == 0){
            flag = false;
        }
    }
    
    if(myDeck.cardsLeft() == 0){
        
        if(isPrime(sum)){
            cout << "Winner in " << pile << " piles";
            cout << endl;
        }
        
        else{
            cout << "Loser" << endl;
        }
        
    }
}


int main() {
    
    Deck myDeck;
    menu();
    int option;
    
    cout << "Enter in the number: ";
    cin >> option;
    cout << endl;

    while(option >= 1 && option <= 4){
        
        if(option == 1){
            
            myDeck.refreshDeck();
            menu();
            cout << "Enter in the number: ";
            cin >> option;
            cout << endl;
            
        }
        
        else if(option == 2){
            
            myDeck.showDeck();
            menu();
            cout << "Enter in the number: ";
            cin >> option;
            cout << endl;
            
        }
        
        else if(option == 3){
            
            myDeck.shuffle();
            menu();
            cout << "Enter in the number: ";
            cin >> option;
            cout << endl;
            
        }
        
        else if(option == 4){
            
            playSolitaire(myDeck);
            menu();
            cout << "Enter in the number: ";
            cin >> option;
            cout << endl;
        }
    }
}
