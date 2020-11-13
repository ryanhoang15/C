//
//  main.cpp
//  Lab 2 Q#1
//
//  Created by ryan hoang on 8/31/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

/**
@author Ryan Hoang
@version Fall 2020
@date 8/31/2020
*/

#include <iostream>

#include <ctime>

#include <cstdlib>

#include <string>

using namespace std;

 
/**
This function purpose is to create the deck of cards, shuffle it and display the first four cards
it uses the srand() and rand() function
*/

int main()

{

  const int NUMBER_OF_CARDS = 52;

  int deck[NUMBER_OF_CARDS];

  string suits[] = {"Spades", "Hearts", "Diamonds", "Clubs"};

  string ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",

    "10", "Jack", "Queen", "King"};

 

  // Initialize cards

    for (int i = 0; i < NUMBER_OF_CARDS; i++){
        deck[i] = i;
    }

 

  // Shuffle the cards
  //YOUR CODE

    srand(time(NULL));
    for(int i = 0; i < 52; i++){
        int randNum = rand() % 52;
        int temp = deck[i];
        deck[i] = deck[randNum];
        deck[randNum] = temp;
    }
    
    // printing the deck of cards shuffle
    cout << "Deck of Cards Shuffled: " << endl;
    for(int k = 0; k < 52; k++){
           cout << deck[k] << " ";
       }
    cout << endl;
    
    
  // Display the first four cards
  //YOUR CODE
    int indexValue = 4;
    for(int j = 0 ; j < indexValue; j++){
        cout << ranks[deck[j] % 13] << " of " << suits[deck[j] / 13] << endl;
    }
}


