//
//  main.cpp
//  Lab 6 Q#1
//
//  Created by ryan hoang on 10/5/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

/**
@author Ryan Hoang
@version Fall 2020
@date 10/13/2020
*/


#include <iostream>
using namespace std;

/**
 This main function's purpose is too create two long variables and a long pointer that points to value1 with a & in front
 display the address of vlaue1, address of longPtr, and value pointed by longPtr
 */
int main() {
    long value1 = 200000;
    long value2;
    
    long *longPtr = &value1;
    value2 = *longPtr;
    
    cout << "Address of value1: " << &value1 << endl;
    cout << "Address of longPtr: " << longPtr << endl;
    cout << "Value pointed to value1 by longPtr: " << *longPtr << endl;
    cout << "Value of value2: " << value2 << endl;
    
    return 0;
}
