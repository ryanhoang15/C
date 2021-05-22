//
//  Book.cpp
//  lab 14
//
//  Created by ryan hoang on 11/30/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#include "Book.hpp"
#include "publication.hpp"
#include "Sale.hpp"
#include <iostream>
using namespace std;

/**
 *This is calling the publication getData() and Sale getData() function since
 *Book inherits from both of them and is also asking the
 *user to enter how many pages the book has
 */
void Book :: getData(){
    publication::getData();
    Sale::getData();
    cout << "Input number of pages: ";
    cin >> pages;

}


/**
 *This is calling the publication putData() and Sale putData() function to display
 *the info since Book inherits from both of them and is also
 *displaying how many pages there are
 */
void Book :: putData(){
    publication::putData();
    Sale::putData();
    cout << "Number of pages: " << pages;
    
}
