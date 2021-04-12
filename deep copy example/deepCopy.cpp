//
//  main.cpp
//  Lab 8 Q#3
//
//  Created by ryan hoang on 10/24/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#include <iostream>
#include "pointDataDeep.hpp"
using namespace std;

int main() {
    pointDataDeep list1(10);
    list1.insertAt(0, 50);
    list1.insertAt(4, 30);
    list1.insertAt(8, 60);
    cout<<"List1: " <<endl;
    list1.displayData();
    cout << endl;
    cout<<"List 2: "<<endl;
    pointDataDeep list2(list1);
    list2.displayData();
    cout << endl;
    list1.insertAt(4,100);
    cout<<"List1: (after insert 100 at indext 4) " <<endl;
    list1.displayData();
    cout << endl;
    cout<<"List 2: "<<endl;
    list2.displayData();
    cout << endl;
    list1.get();
    cout << endl;
    list2.get();
    cout << endl;
    
    
  
    return 0;
}
