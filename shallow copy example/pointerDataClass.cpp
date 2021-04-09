//
//  pointData.cpp
//  Lab 8 Q#2
//
//  Created by ryan hoang on 10/19/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#include "pointerDataClass.hpp"
#include<iostream>
using namespace std;


/**
 *This function is creating an array and is a pointer
 *The constructor to create an array of the size specified by the parameter size.
 *The maxSize is set to the size to know how big the array is
 * This is demonstrating SHALLOW COPY
 *@size is how big the array is
 */
pointerDataClass :: pointerDataClass(int size){
    cout << "default" << endl;
    maxSize = size;
    p = new int[size];
    length = 0;
}

pointerDataClass :: pointerDataClass(const pointerDataClass &x){
    cout << "shallow" << endl;
    maxSize = x.maxSize;
    length = x.length;
    p = new int[x.maxSize];
    p = x.p;
}

/**
 * This function is the Destructor to deallocate the memory space occupied by the array p
 */
pointerDataClass :: ~pointerDataClass(){
    delete[] p;

}

/**
 * The function insertAt inserts num into array p at the position specified by index
 * @index is the spot to put the value in
 * @num is the value to put in the array
 */
void pointerDataClass :: insertAt(int index, int num){
    if(length < maxSize && index < length){
        for(int i = length - 1; i >= index; i--){
            *(p + i + 1) = *(p + i);
        }
        *(p + index) = num;
        length++;
        
    }
    else{

        if(index < maxSize){
            *(p + length) = num;
            length++;
        }
        else{
            cout << "This list is full" << endl;
        }

    }
    
}

/**
 * This function is displaying the values in the array
 */
void pointerDataClass :: displayData(){
    for(int i = 0; i < maxSize; i++){
        cout << *(p + i) << " ";
    }
}


/**
 * This function display the address of p
 */
void pointerDataClass :: get(){
   cout << p;
}
