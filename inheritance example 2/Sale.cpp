//
//  Sales.cpp
//  lab 14
//
//  Created by ryan hoang on 11/30/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#include "Sale.hpp"
#include <iostream>
using namespace std;

/**
 *This is getting the information from the user and
 *storing it in the array
 */
void Sale :: getData(){
    for(int i = 0; i < 3; i++){
        cout << "Input data for sales " << (i+1) << " month(s) ago: ";
        cin >> saleArray[i];
    }
}

/**
 *This is displaying the information in the array
 */
void Sale :: putData(){
    for(int i = 0; i < 3; i++){
        cout << "Sales " << (i+1) << " month(s) ago: " << saleArray[i] << endl;
    }
}
