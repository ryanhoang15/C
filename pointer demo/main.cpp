//
//  main.cpp
//  MON 9/14 - LEC
//
//  Created by ryan hoang on 9/14/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#include <iostream>
using namespace std;

void swapPassByValue(int x, int y){
    
    // x and y make copies of parameters
    int temp = x;
    x = y;
    y = temp;
    
}

void swapPassByRefWithRefParameter(int& x, int& y){
    
    int temp = x;
    x = y;
    y = temp;
    
}

void swapPassByRefWithPtrParameter(int * x, int * y){
    
    int temp = * x;
    * x = * y;
    * y = temp;
    
}

int& increment(int& x){
    x++;
    return x;
}

int* incrementPtr(int* x){
    *x = *x + 1;
    return x;
}


int main() {
    
//    int g = 10;
//    cout << "Value g: " << g << endl;
//
//    int& result = increment(g);
//
//    cout << endl;
//    cout << "Value g: " << g << endl;
//    cout << "Value result: " << result << endl;
    
//    int g = 10;
//    cout << "Value g: " << g << endl;
//    
//    int* result = incrementPtr(&g);
//    
//    cout << endl;
//    cout << "Value g: " << g << endl;
//    cout << "Value result: " << *result << endl;
    
    
//    int a = 10;
//    int b = 100;
//    cout << "Value of a: " << a << endl;
//    cout << "Value of b: " << b << endl;
//    cout << endl;
//
//    swapPassByValue(a,b);
//
//    cout << "Value of a: " << a << endl;
//    cout << "Value of b: " << b << endl;
//
//    cout << endl;
//
//    int c = 2;
//    int d = 14;
//
//    cout << "Value of c: " << c << endl;
//    cout << "Value of d: " << d << endl;
//    cout << endl;
//
//    swapPassByRefWithRefParameter(c,d);
//
//    cout << "Value of c: " << c << endl;
//    cout << "Value of d: " << d << endl;
//
//    cout << endl;
//
//    int e = 30;
//    int f = 45;
//
//    cout << "Value of e: " << e << endl;
//    cout << "Value of f: " << f << endl;
//    cout << endl;
//
//    swapPassByRefWithPtrParameter(&e, &f);
//
//    cout << "Value of e: " << e << endl;
//    cout << "Value of f: " << f << endl;
    
    
//    int x = 90;
//    double y = 100.09;
//    bool z = true;
//
//    // variable that stores addresses
//    int * ptrX = &x;
//    cout << "Address of x: " << ptrX << endl;
//    cout << "Address of prt_x: " << &ptrX << endl;
//    cout << "Value pointed to by ptr_X: " << *ptrX << endl;
//
//    cout << endl;
//
//     * ptrX = 10000;
//    cout << "Address of x: " << ptrX << endl;
//    cout << "Address of prt_x: " << &ptrX << endl;
//    // gets the updated value of 10000 and not 90 anymore
//    cout << "Value pointed to by ptr_X: " << *ptrX << endl;
//    // gets the updated value of 10000 and not 90 anymore
//    cout << "Updated Value pointed to x: " << x << endl;
//
//    // store the address of a pointer into another pointer
//    int ** ptr_ptrX = &ptrX;
    
//    double * ptrY = &y;
//
//    int * ptrX1 = NULL;
//
//    //Dereferencing gives u the value inside the address location
//    cout << "Value pointed to by ptr_X: " << *ptrX << endl;
////     cout << "Value pointed to by ptr_X1" << *ptrX1 << endl;
    
//    int x = 90;
//    int& refX = x; // allias int * ptr - &x;
//
//    cout << "Value of refX: " << refX << endl; // equivlant to *ptr
//    cout << "Value of x: " << x << endl;
//
//    cout << endl;
//
//
//    refX = 1000;
//
//    cout << "Value of refX: " << refX << endl;
//    cout << "Value of x: " << x << endl;
//
//    cout << endl;
//
//    refX = 500;
//
//    cout << "Value of refX: " << refX << endl;
//    cout << "Value of x: " << x << endl;
//
//    cout << endl;
//
//    x = 14;
//
//    cout << "Value of refX: " << refX << endl;
//    cout << "Value of x: " << x << endl;
 
    return 0;
}
