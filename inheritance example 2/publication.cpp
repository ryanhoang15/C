//
//  publication.cpp
//  lab 14
//
//  Created by ryan hoang on 11/30/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#include "publication.hpp"
#include <iostream>
#include <string>
using namespace std;

/**
 * This is getting the user info on the
 * book title and its price
 */
void publication :: getData(){
    cin.ignore();
    cout << "Input Title: ";
    cin.clear();
    getline(cin, title);
    cout << "Input Price: ";
    cin >> price;

}

/**
 *This is diplaying the name of the book
 *and how much the book cost
 */
void publication :: putData(){
    cout << "Title: " << title << endl;
    cout << "Price: $" << price << endl;
}
