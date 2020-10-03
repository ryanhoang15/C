//
//  myDate.hpp
//  prog 2 - myDate
//
//  Created by ryan hoang on 9/15/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#ifndef myDate_hpp
#define myDate_hpp

#include <stdio.h>
#include <string>
using namespace std;

class myDate{
    
private:
    int month;
    int day;
    int year;
  
public:
    myDate(); // default constructor
    myDate(int M, int D, int Y); // overload constructor. This will set the date to the values passed in through the parameter list represented by Month, Day and Year.
    void display(); // display the date in the following format (May 11, 1959) Do NOT print a linefeed after the date.
    void increaseDate(int N); // increment the date by N days.
    void decreaseDate(int N); // decrement the date by N days.
    int daysBetween(myDate D); // return the number of days between this date and the date D.  If date D is a future date, the return value will be a positive int.  If date D is in the past, the return value will be a negative int.
    int getMonth(); // return the month in integer form
    int getDay(); // return the day of the month
    int getYear(); //return the year
    int dayOfYear(); // return the number of days since the current year began. Example Jan 1 is 1, Feb 1 is 32.
    string dayName(); // returns Monday, Tuesday, etc according to the day of the week.

    
};

#endif /* myDate_hpp */
