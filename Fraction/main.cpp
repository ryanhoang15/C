//
//  main.cpp
//  lab 3 Q#2
//
//  Created by ryan hoang on 9/14/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

/**
@author Ryan Hoang
@version Fall 2020
@date 9/21/2020
*/

#include "Fraction.hpp"
#include <iostream>
using namespace std;

// this function's purpose it to take two faction object
// @fr1 and @fr2 and multiply their numerators and denomerators together
// to get a new fraction and return that fraction
Fraction& multiplyFact(Fraction& fr1, Fraction& fr2){
    
    int newNumer = fr1.getNumer() * fr2.getNumer();
    int newDenom = fr1.getDenom() * fr2.getDenom();
    
    Fraction* multFract = new Fraction(newNumer, newDenom);

    return *multFract;
}


// this function is creating 5 fractions and is printing the fractions info
int main ( ){
    // Instantiation of some objects
    Fraction fract1 ;
    Fraction fract2 (14, 21);
    Fraction fract3 (11, -8);
    Fraction fract4 (fract3);
    Fraction fract5(2,0);

    // Printing the objects of the fractions which is printing the fraction itself
    cout << "Printing four fractions after constructed: " << endl;
    cout << "fract1: ";
    fract1. print();
    cout << "fract2: ";
    fract2. print();
    cout << "fract3: ";
    fract3. print();
    cout << "fract4: ";
    fract4. print();
    cout << "fract5: ";
    fract5.print();

    // Using mutators by changing the value
    cout << "Changing the first two fractions and printing them:";
    cout << endl;
    fract1.setNumer(4);
    cout << "fract1: ";
    fract1.print();
    fract2.setDenom(-5);
    cout << "fract2: ";
    fract2.print();

    // Using accessors and getting the values
    cout << "Testing the changes in two fractions:" << endl;
    cout << "fract1 numerator: " << fract1.getNumer() << endl;
    cout << "fract2 denominator: " << fract2.getDenom() << endl;
        
        
    //calling the multiplyFract function and return a value
    // from the 2 fractions multiply together
    cout << "Multiplying two fractions:" << endl;
    Fraction fract6(10,9);
    Fraction fract7(2,3);
    
    Fraction& result = multiplyFact(fract6, fract7);
    cout << "Multiply Fraction Result: ";
    result.print();

    return 0;
    
    
}
