//
//  main.cpp
//  lab 14
//
//  Created by ryan hoang on 11/30/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#include "Sale.hpp"

#include "publication.hpp"

#include "Book.hpp"

#include "Digital.hpp"

#include <iostream>

#include <string>

using namespace std;

 

int main() {
    int count = 0;
    publication *pubArr[100];
    bool isValid = true;
    char pick = ' ';
    char answer = ' ';
    while(isValid){
        cout << "Enter data for book or digital book (b/d)? ";
        cin >> pick;
        if(pick == 'b'){
            pubArr[count] = new Book;
        }
        else{
            pubArr[count] = new Digital;

        }
        pubArr[count]->getData();
        count++;
        cout << "Enter another choice (y/n)? ";
        cin >> answer;
        if(answer == 'n'){
            isValid = false;
        }

    }
    cout << endl;
    for(int i = 0; i < count; i++){
        pubArr[i]->putData();
        cout << endl;
    }
    

//    Book book;
//
//    Digital digital;
//
//    book.getData();
//
//    book.putData();
//
//    cout << endl;
//    cout << endl;
//
//    digital.getData();
//
//    digital.putData();
//
//    cout << endl;
//
//    return 0;

}
