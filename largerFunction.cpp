//
//  main.cpp
//  Lab 3 Q#1
//
//  Created by ryan hoang on 9/14/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

/**
@author Ryan Hoang
@version Fall 2020
@date 9/21/2020
*/


#include <iostream>
using namespace std;

// this function's purpose is to demostrate pass by value
// where anything that happens in the function stays locally in the function
int& largerNum(int& num1, int& num2){
    int* bigNum = new int(0);
    // if num1 is greater than num2
    if(num1 > num2){
        *bigNum = num1;
    }
    // if num1 is smaller than num2
    else if(num1 < num2){
        *bigNum = num2;
    }
    // if both numbers are the same
    else{
        *bigNum = num1;
    }
    return *bigNum;
    
}

// this function's purpose is to demostrate pass by reference
// meaning that anything that changes in the function that has
// an & sign than it will affect where it was called.
int& largestNumByRef(int& num1, int& num2, int& num3){
//    largerNum(num1, num2);
    int* largestNum = new int(largerNum(largerNum(num1, num2),num3));
    return *largestNum;
}



//this main function's purpose is to create integer and pass it to
// the largerNum function which is pass by value and
// the largestNumbyRef is to pass by ref and return by ref

int main() {
    int num = 10;
    int num2 = 30;
    
    int& value = largerNum(num, num2);
    cout << "The larger number between " << num << " and " << num << " is: " << value << endl;
    
    int num3 = 100;
    int num4 = 100;
    int num5 = 100;
    cout << endl;
    
    int& result = largestNumByRef(num3, num4, num5);
    cout << "Value of result from passbyRef is: " << result << endl;
    cout << endl;
    
    
    int num6 = 60;
    int num7 = 30;
    int num8 = 80;
    cout << endl;
      
    int& result2 = largestNumByRef(num6, num7, num8);
    cout << "Value of result2 from passbyRef is: " << result2 << endl;
    cout << endl;
    
    return 0;
}
