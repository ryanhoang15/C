//
//  Employee.cpp
//  Lab 4 Q#2
//
//  Created by ryan hoang on 9/21/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#include "Employee.hpp"
#include <iostream>
using namespace std;

/**
 default constructor that creates a "John Doe"  employee
 */
Employee :: Employee(){
    name = "John Doe";
    id = 0;
}


/**
 this function is to display the employee's info
 */
void Employee :: putData(){
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
}


/**
 this function is to set the employee's info
 */
void Employee :: getData(){
    cout << "Enter your name: ";
    cin >> name;
    cout << "ID number: ";
    cin >> id;
    cout << endl;
}



