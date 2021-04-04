//
//  Distance.hpp
//  Lab 7 Q#2
//
//  Created by ryan hoang on 10/12/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#ifndef Distance_hpp
#define Distance_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Distance{//English Distance class
    
private:
    //private data members
    int feet;
    float inches;
public:
    //constructor (no args)
    Distance();
    //constructor (two args)
    Distance(int ft, float in);
    
    //Overloading operator the output of cout when its called
    // the friend function is a binary operator that requires 2 parameters
    friend ostream &operator<<(ostream &output, const Distance &dist);

    //Overloading operator the input of cin when its called
    // the friend function is a binary operator that requires 2 parameters
    friend istream &operator>>(istream &input, Distance &dist);

    //Overloading operator minus is used to subtract the values of the two objects
    // the friend function is a binary operator that requires 2 parameters
    friend const Distance operator-(const Distance &dist, const Distance &dist2);

    //Overloading operator add is use to add the value of the object
    // the member function is unary and had one argument
    const Distance operator+(const Distance &dist) const;

};

#endif /* Distance_hpp */
