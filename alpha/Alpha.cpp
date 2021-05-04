//
//  Alpha.cpp
//  Lab 8 Q#1
//
//  Created by ryan hoang on 10/19/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#include "Alpha.hpp"
#include <iostream>
using namespace std;

Alpha :: Alpha(){
    data = 0;
}

Alpha :: Alpha(int num){
    data = num;
}

Alpha :: Alpha(Alpha &a){
    cout << "copy" << endl;
    data = a.data;
}

void Alpha :: display(){
    cout << data << endl;
}


Alpha & Alpha :: operator=(Alpha &a){
    cout << "assign" << endl;
    data = a.data;
    int *ptr = new int(a.data);
    return *this;
}


