//
//  time12.cpp
//  Lab 9 Q#1
//
//  Created by ryan hoang on 10/28/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#include "time12.hpp"
#include <iostream>
#include <string>
using namespace std;


/**
 default constructor - setting pm to true and hours and minutes to 0
 */
time12 :: time12(){
    pm = true;
    hrs = 0;
    mins = 0;
}

/**
 overload constructor - setting the variables to a specific value
 @param ap is a boolean use to determine if its am or pm
 @param h is the value that hrs is being set to
 @param m is the value that mins is being set to
 */
time12 :: time12(bool ap, int h, int m){
    pm = ap;
    hrs = h;
    mins = m;
}

/**
 displaying the time in the correct format by checking
 hours, minutes and am or pm
 */
void time12 :: display() const{
    cout << hrs << ":";
    if(mins < 10){
        cout << "0";
    }
    cout << mins << " ";
    string am_pm = pm ? "pm." : "am.";
    cout << am_pm;
    
}

    
