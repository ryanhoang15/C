//
//  main.cpp
//  Lab 8 Q#2
//
//  Created by ryan hoang on 10/19/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#include <iostream>
#include "pointerDataClass.hpp"
using namespace std;

int main() {
    pointerDataClass list1(10);
    list1.insertAt(0, 50);
    list1.insertAt(4, 30);
    list1.insertAt(8, 60);
    cout<<"List1: " <<endl;
    list1.displayData();
    cout << endl;
    cout<<"List 2: "<<endl;
    pointerDataClass list2(list1);
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
