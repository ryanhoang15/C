//
//  main.cpp
//  Lab 4 Q#1
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
using namespace std;


/**
 this function is checking the values in the array is in order from least to greatest
 @param list[] is the array that stores the value and is a constant
 @param size is the size of the array
 @return returns true if it is in order or false if it is not in order
 */
bool isSorted(const int list[], int size){
    bool flag = false;
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(list[i] <= list[j]){
                flag = true;
            }
            else{
                return false;
            }
        }
    }
    return flag;
}



/**this function is asking the user to enter the size of the array and then to enter its value
 and after that the value is getting put into the array and than is getting sent to the isSorted function and
 the isSorted function will return a boolean true or false
 */
int main(int argc, const char * argv[]) {
    /**
     These are the variables created
     */
    const int size = 100;
    int num[size];
    int listSize;
    int count = 0;
    int value = 0;
    
    /**
     asking the user to enter the list size
     */
    cout << "Enter the size of the list: ";
    cin >> listSize;
    
    /**
     this is coping the size of the list to use for the loop
     */
    int copySize = listSize;
    
    /**
     this loop is for the user the enter the numbers in the list and is decreasing the
     copyList size to get out of the while loop
     and you use a copyList variable to copy the value because you are decrementing it and the copySize will be 0 when you exit the loop
     */
    while (copySize > 0){
        cout << "Enter number into list: ";
        cin >> value;
        num[count] = value;
        count++;
        copySize--;
    }
    
    //another way you can do it
//    for(int i = 0; i < listSize; i++){
//        cout << "Enter number into list: ";
//        cin >> value;
//        num[count] = value;
//        count++;
//    }
    
    /**
     is check if the return value is true or false to see if it is sorted or not
     */
    if(isSorted(num, listSize)){
        cout << "The list is sorted" << endl;
    }
    
    else{
        cout << "The list is not sorted" << endl;
    }
    
    return 0;
}
