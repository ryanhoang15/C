//
//  Employee.hpp
//  Lab 4 Q#2
//
//  Created by ryan hoang on 9/21/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

/**
 guard
 */
#ifndef Employee_hpp
#define Employee_hpp

/**
 header file
 This class is where the constructors, mutator, accessor functions are defined
 */

#include <stdio.h>
#include <iostream>
using namespace std;


class Employee{
    
//private instance variables
private:
    string name = "";
    long id;
    
    
public:
    Employee(); // default constructor
    void getData(); // accessor
    void putData(); // mutator
    
};

#endif /* Employee_hpp */
