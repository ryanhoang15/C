//
//  main.cpp
//  Lab 4 Q#2
//
//  Created by ryan hoang on 9/21/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

/**
@author Ryan Hoang
@version Fall 2020
@date 9/23/2020
*/

#include <iostream>
#include "Employee.hpp"
using namespace std;

/**
 this main function's purpose is to create 3 employees in an array and get their info from
 the user and display it 
 */

int main() {
    
    /**
     variables names
     */
    const int size = 3;

    
    /**
     an array for the employees
     */
    Employee list[size];
    
    
    /**
     this loop is for the user to enter the name and id of the employee's
     */
    for(int i = 0; i < size; i++){
        list[i].getData();
        
    }
    
    
    /**
     this loop is for displaying the employee's info 
     */
    for(int i = 0; i < size; i++){
        cout << "Employee " << i + 1 << endl;
        list[i].putData();
        cout << endl;
    }
    
    
    
    
    
}
