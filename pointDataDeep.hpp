//
//  pointDataDeep.hpp
//  Lab 8 Q#3
//
//  Created by ryan hoang on 10/24/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#ifndef pointDataDeep_hpp
#define pointDataDeep_hpp

#include <stdio.h>

class pointDataDeep{
private:
    int maxSize;//variable to store the maximum size of p
    int length;//variable to store the number of elements in p
    int *p;// pointer to an int array

public:
  //Constructor to create an array of the size specified by the parameter size.
    pointDataDeep(int size);
    
    pointDataDeep(const pointDataDeep &x);

//  Destructor to deallocate the memory space occupied by the array p
    ~pointDataDeep();

  //the function insertAt inserts num into array p at the position specified by
  //index
    void insertAt(int index, int num);

  //The function displayData displays all the array elements in p
    void displayData();
    
  // Display the value of p
    void get();
    
    
};

#endif /* pointDataDeep_hpp */
