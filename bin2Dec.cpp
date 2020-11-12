//
//  main.cpp
//  Lab 1
//
//  Created by ryan hoang on 8/24/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//
/**
 @author Ryan Hoang 017680115
 @Lab Sec - 02
 @version Fall 2020
 @date 8/24/2020
 */


#include <iostream>

using namespace std;

// these 2 function are declare at the top and definiton in the function are written below
int bin2Dec(const string& binaryStrin);//prototype
int power(int base, int pow); // prototype


/**
 This function converts binary string to a decimal number
 @param binaryString string of binary representation
 @return the decimal version of the given binary string
 */

int bin2Dec(const string& binaryString){
    
    int pow = 0;
    int base = 2;
    int decimal = 0;
    int count = 0;
    
    // This is looping to see how many characters are in the string
    for(int j = 0; j < binaryString.length(); j++){
           count++;
       }
    

    // This loop is use to check the index of the string from right to left to see if there is a 1 at each index
    // If there is a one then it is passed to the power function I made from scratch to calcute the decimal
    for(int i = count; i > 0; i--){
        if(binaryString[i - 1] == '1'){
            decimal = decimal + power(base,pow);
            pow++;
        }
        else{
            pow++;
        }

    }
    
    return decimal;
}

/**
This function is calculating the value of 2^n
There are 2 base cases and 1 general case
@return the value of 2^n
*/

int power(int base, int pow){
    
    if(pow == 0){
        return 1;
    }
    else if(pow == 1){
        return base;
    }
    else{
        return power(base,pow - 1) * base;
    }

}


/**
This is the main function it is use to call the other 2 functions on top
 In this function it is asking the user the enter a binary number and it looping until the user does not
 want to enter a binary number any
*/

int main() {
    
    string strBin;
    char answer;
    bool truth = true;

    while(truth){
        cout << "Enter a binary number: ";
        cin >> strBin;
        cout << bin2Dec(strBin) << endl;

        cout << "Would you like to enter again (y/n): ";
        cin >> answer;
        cout << endl;

        if(answer == 'n' || answer == 'N'){
            truth = false;
        }
    }
    
    return 0;

}


