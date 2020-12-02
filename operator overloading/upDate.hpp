//
//  upDate.hpp
//  Prog 4 - Operator overloading
//
//  Created by ryan hoang on 10/27/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#ifndef upDate_hpp
#define upDate_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class upDate{
    
private:
    int *ptr;
    static int count;
    
public:
    upDate();
    upDate(int m, int d, int y);
    upDate(int j);
    ~upDate();
    void setDate(int m, int d, int y);
    int getMonth();
    int getDay();
    int getYear();
    int getJulian();
    string getMonthName();
    static int getDateCount();
    upDate(const upDate &date);
    upDate &operator=(const upDate &date);
    upDate &operator+=(int val);
    upDate &operator-=(int val);
    upDate &operator++();
    upDate &operator--();
    const upDate operator++(int dummy);
    const upDate operator--(int dummy);
    const upDate operator+(int val) const;
    const upDate operator-(int val) const;
    const int operator-(const upDate &date) const;
    bool operator==(const upDate &date) const;
    bool operator<(const upDate &date) const;
    bool operator>(const upDate &date) const;
    friend const upDate operator-(int val, const upDate &date);
    friend const upDate operator+(int val, const upDate &date);
    friend ostream& operator<<(ostream &out, const upDate &date);
    
    
};

#endif /* upDate_hpp */
