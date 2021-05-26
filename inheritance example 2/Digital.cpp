//
//  Digital.cpp
//  lab 14
//
//  Created by ryan hoang on 11/30/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#include "Digital.hpp"
#include "publication.hpp"
#include "Sale.hpp"
#include <iostream>
using namespace std;

/**
 *This is calling the publication getData() and Sale getData() function since
 *Digital inherits from both of them and is also asking the
 *user to enter how many MB this digial has
 */
void Digital :: getData(){
    publication::getData();
    Sale::getData();
    cout << "Input storage size(MB): ";
    cin >> storage;
}

/**
 *This is calling the publication putData() and Sale putData() function to display
 *the info since Digital inherits from both of them and is also
 *displaying how many MB this digital has
 */
void Digital :: putData(){
    publication::putData();
    Sale::putData();
    cout << "Storage size (MB): " << storage;
    
}
