//
//  main.cpp
//  Lab 6 Q#2
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
 *this function is printing the values of the array 
 *@param *arr is the array that stores the value and is a pointer
 *@param size is the size of the array
 */
void display(int * arr, int size){
    for(int i = 0; i < size; i++){
        cout << *arr << " ";
        arr++;
    }
}


/**
 *this function is finding the max number in the array
 *@param *arr is the array that stores the value and is a pointer
 *@param size is the size of the array
 *@return max is the biggest number in the array
 */
int max(int * arr, int size){
    int max = *arr;
    for(int i = 1; i < size; i++){
        if(max < *(arr + i)){
            max = *(arr + i);
        }
    }
    return max;
}



/**this function is asking the user to enter the size of the array and then to enter its value
 and after that the value is getting put into the array and than is getting sent to the display function and
 the max function will return the max value
 */
int main() {
    /**
     These are the variables created
     */
    int listSize;
    int value = 0;
    
    /**
     asking the user to enter the list size
     */
    cout << "Enter the size of the list: ";
    cin >> listSize;
    
    
    int *ptr = new int[listSize];
    
//    /**
//     assign a pointer to the array
//     */
//    int *ptr = arr;
    
    /**
     this loop is for the user the enter the numbers in the list
     */
    for(int i = 0; i < listSize; i++){
        cout << "Enter number into list: ";
        cin >> value;
        *(ptr + i) = value;
    }
    
    display(ptr,listSize);
    cout << endl;
    cout <<"Max: " << max(ptr, listSize) << endl;
    
    
    return 0;
}
