//
//  main.cpp
//  Lab 9 Q#1
//
//  Created by ryan hoang on 10/28/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

/**
@author Ryan Hoang
@version Fall 2020
@date 11/3/2020
*/
#include <iostream>
#include "time12.hpp"
#include "time24.hpp"
using namespace std;

/**
 This function's purpose is asking the the user to enter in military time
 and converting it back to regular time format 
 */
int main() {
    
    int h, m, s;

    while(true){ //get 24-hr time from user
        cout << "Enter 24-hour time: \n";
        cout << " Hours (0 to 23): ";
        cin >> h;
        if(h > 23) //quit if hours > 23
        return(1);
        cout << " Minutes: "; cin >> m;
        cout << " Seconds: "; cin >> s;

        time24 t24(h, m, s); //make a time24
        cout << "You entered: "; //display the time24
        t24.display();
        
        time12 t12 = t24; //convert time24 to time12

        cout << "\n12-hour time: "; //display equivalent time12
        t12.display();
        cout << "\n\n";
    }
        
    return 0;
}
