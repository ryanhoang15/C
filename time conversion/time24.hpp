//
//  time24.hpp
//  Lab 9 Q#1
//
//  Created by ryan hoang on 10/28/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#ifndef time24_hpp
#define time24_hpp

#include <stdio.h>
#include "time12.hpp"

class time24{
  
private:
    int hours;
    int minutes;
    int seconds;
    
public:
    //default constructor
    time24();
    //overload constructor
    time24(int h, int m, int s);
    //displaying the information
    void display() const;
    //retrieve the hours
    int getHours() const;
    //retrieve the minutes
    int getMinutes() const;
    //retrieve the seconds
    int getSeconds() const;
    operator class time12(); //from time24 to time12
    
};
#endif /* time24_hpp */
