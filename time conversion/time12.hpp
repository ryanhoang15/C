//
//  time12.hpp
//  Lab 9 Q#1
//
//  Created by ryan hoang on 10/28/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#ifndef time12_hpp
#define time12_hpp

#include <stdio.h>

class time12{
 
//private data members
private:
    bool pm;
    int hrs;
    int mins;
    
public:
    //defaut constructor
    time12();
    //overload constructor
    time12(bool ap, int h, int m);
    //displaying the correct time format
    void display() const;
    
};

#endif /* time12_hpp */
