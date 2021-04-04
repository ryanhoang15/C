//
//  main.cpp
//  Lab 7 Q#2
//
//  Created by ryan hoang on 10/12/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

/**
@author Ryan Hoang
@version Fall 2020
@date 10/19/2020
*/

#include <iostream>
#include "Distance.hpp"
using namespace std;

/**
 * This function is creating numerous Distance objects and is using the Overloading operations
 * to learn how it works
 */
int main() {
    
    Distance dist1, dist3, dist4; //define distances
    cin >> dist1;
    Distance dist2(12, 4); //define, initialize dist2
    dist3 = dist1 + dist2; //single '+' operator
    dist4 = dist1 - dist2; //friend '-' operators

//    display all lengths
    cout << "dist1 = ";
    cout << dist1 << endl;
    cout << "dist2 = ";
    cout << dist2 << endl;
    cout << "dist3 = ";
    cout << dist3 << endl;
    cout << "dist4 = ";
    cout << dist4 << endl;
    
    return 0;
}
