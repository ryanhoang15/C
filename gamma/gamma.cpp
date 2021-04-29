//
//  gamma.cpp
//  lab 9 Q#2
//
//  Created by ryan hoang on 10/28/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#include <iostream>
#include "gamma.hpp"
using namespace std;

gamma :: gamma(){
    count++;
    id = count;
}

int gamma :: count = 0;

void gamma :: showtotal(){
    cout << "Total is: " << count << endl;
}

void gamma :: showid(){
    cout << "ID number is: " << id << endl;
}

gamma :: ~gamma(){
    cout << "Destroying ID number: " << id << endl;
    id--;
}
