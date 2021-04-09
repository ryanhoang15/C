//
//  pointData.hpp
//  Lab 8 Q#2
//
//  Created by ryan hoang on 10/19/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//


#ifndef pointerDataClass_hpp
#define pointerDataClass_hpp

#include <stdio.h>


class pointerDataClass{
    
private:
    int maxSize;//variable to store the maximum size of p
    int length;//variable to store the number of elements in p
    int *p;// pointer to an int array

public:
    
  //Constructor to create an array of the size specified by the parameter size.
    pointerDataClass(int size);

    pointerDataClass(const pointerDataClass &x);
    
    
  //Destructor to deallocate the memory space occupied by the array p
    ~pointerDataClass();

  //the function insertAt inserts num into array p at the position specified by
  //index
    void insertAt(int index, int num);

  //The function displayData displays all the array elements in p
    void displayData();
    
  // Display the value of p
    void get();
};

#endif /* pointerDataClass_hpp */
