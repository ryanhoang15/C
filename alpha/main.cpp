//
//  main.cpp
//  Lab 8 Q#1
//
//  Created by ryan hoang on 10/19/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#include <iostream>
#include "Alpha.hpp"
using namespace std;

int main() {
    Alpha a1(37);
    Alpha a2;

    a2 = a1; //invoke overloaded =
    cout << "a2=";
    a2.display(); //display a2

    Alpha a3(a1); //invoke copy constructor
    cout << "a3=";
    a3.display(); //display a3
    Alpha a4 = a1;
    cout << "a4=";
    a4.display();
    cout << endl;
    
    Alpha a5 = a1;
    
    return 0;
}
