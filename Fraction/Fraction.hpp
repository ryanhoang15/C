//
//  Fraction.hpp
//  lab 3 Q#2
//
//  Created by ryan hoang on 9/14/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#ifndef Fraction_hpp
#define Fraction_hpp

#include <stdio.h>

class Fraction{
    
    //Data members
private:
    int numer;
    int denom;
    
// Helping private member functions

private:
    void normalize ();
    int gcd (int n, int m);
    
// Public member functions

public:

    // Constructors

    Fraction (int num, int den);

    Fraction ();

    Fraction (const Fraction& fract);

    ~Fraction ();

    // Accessors

    int getNumer () const;

    int getDenom () const;

    void print () const;
                        
    
    // Mutators

    void setNumer (int num);

    void setDenom (int den);
    
};

#endif /* Fraction_hpp */
