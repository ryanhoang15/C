//
//  pointDataDeep.cpp
//  Lab 8 Q#3
//
//  Created by ryan hoang on 10/24/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#include "pointDataDeep.hpp"
#include<iostream>
using namespace std;


/**
 *This function is creating an array and is a pointer
 *The constructor to create an array of the size specified by the parameter size.
 *The maxSize is set to the size to know how big the array is
 *@size is how big the array is
 */
pointDataDeep :: pointDataDeep(int size){

    maxSize = size;
    p = new int[size];
    length = 0;
}

/**
 *This function is creating an array and is a pointer
 *The constructor is using deep copy
 *The maxSize is set to the pointDataDeep object maxSize
 *The length  is set to the pointDataDeep object length
 *@x is a pointDataDeep object that is getting passed in and is a reference
 */
pointDataDeep :: pointDataDeep(const pointDataDeep &x){
    maxSize = x.maxSize;
    length = x.length;
    p = new int[x.maxSize];
    for(int i = 0; i < length; i++){
        *(p + i) = *(x.p + i);
    }
}


/**
 * This function is the Destructor to deallocate the memory space occupied by the array p
 */
pointDataDeep :: ~pointDataDeep(){
    delete[] p;

}


/**
 * The function insertAt inserts num into array p at the position specified by index
 * @index is the spot to put the value in
 * @num is the value to put in the array
 */
void pointDataDeep :: insertAt(int index, int num){
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
void pointDataDeep :: displayData(){
    for(int i = 0; i < length; i++){
        cout << *(p + i) << " ";
    }
}


/**
 * This function  prints the data??
 */
void pointDataDeep :: get(){
    displayData();
//    cout << *p << endl;
}
