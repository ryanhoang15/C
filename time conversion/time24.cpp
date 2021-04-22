//
//  time24.cpp
//  Lab 9 Q#1
//
//  Created by ryan hoang on 10/28/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#include "time24.hpp"
#include <iostream>
#include <string>
using namespace std;


/**
 Default constructor
 setting hours, minutes and seconds to 0
 */
time24 :: time24(){
    hours = 0;
    minutes = 0;
    seconds = 0;
}

/**
 Overload Constructor - setting hours, minutes and seconds to a specific number
 @param h is the hours begining assign to
 @param m is the minutes begining assign to
 @param s is the seconds begining assign to
 */
time24 :: time24(int h, int m, int s){
    hours = h;
    minutes = m;
    seconds = s;
}

/**
 displaying the time in the correct format by checking
 hours, minutes and seconds
 */
void time24 :: display() const{
    if(hours < 10){
        cout << "0";
    }
    cout << hours << ':';
    if(minutes < 10){
        cout << "0";
    }
    cout << minutes << ':';
    if(seconds < 10){
        cout << "0";
    }
    cout << seconds;
}

/**
 this is the conversion from time24 to time 12
 anything that is before 12 is in the am and
 anything after 12 is in the pm and it is being subtracted
 from 12 to covert it to 12 hour time format
 */
time24 :: operator time12(){
    bool pm = false;
    int newHour = hours;
    if(newHour == 0){
        newHour = 12;
        pm = false;
    }
    else if(newHour < 12){
        pm = false;
        newHour = hours;
    }
    else if(newHour == 12){
        newHour = 12;
        pm = true;
    }
    else{
        newHour = newHour - 12;
        pm = true;
    }
    return time12(pm, newHour, minutes);
}


