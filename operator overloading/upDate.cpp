//
//  upDate.cpp
//  Prog 4 - Operator overloading
//
//  Created by ryan hoang on 10/27/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#include "upDate.hpp"
#include <iostream>
using namespace std;

// pass in the Month, Day, Year and return Julian number
int Greg2Julian(int month, int day, int year){
    int I = year;
    int J = month;
    int K = day;
    
    int JD = K - 32075 + 1461 * (I + 4800 + (J - 14) / 12) / 4 + 367 * (J - 2 - (J - 14) / 12 * 12) / 12 - 3 * ((I + 4900 + (J - 14) / 12) / 100) / 4;
    
    return JD;
}

// pass in the Julian Date, and get the correct Month, Day and Year through the parameter list – pass by reference
void Julian2Greg(int JD, int& month, int& day, int& year){
    int I;
    int J;
    int K;
    int L;
    int N;
    
    L = JD + 68569;
    N = (4 * L) / 146097;
    L = L - (146097 * N + 3 ) / 4;
    I = 4000 * (L + 1) / 1461001;
    L = L - ((1461 * I) / 4) + 31;
    J = (80 * L) / 2447;
    K = L - ((2447 * J) / 80);
    L = J / 11;
    J = J + 2 - 12 * L;
    I = 100 * (N - 49) + I + L;
    
    year = I;
    month = J;
    day = K;
    
}

upDate :: upDate(){
    ptr = new int[3];
    *(ptr) = 5;
    *(ptr + 1) = 11;
    *(ptr + 2) = 1959;
    count++;
}

upDate :: upDate(int m, int d, int y){
    ptr = new int[3];
//    setDate(m, d, y);
    int JD = Greg2Julian(m, d, y);
    int m1 = m;
    int d1 = d;
    int y1 = y;
    Julian2Greg(JD, m1, d1, y1);
    if(m1 != m || d1 != d || y1 != y){
        *(ptr) = 5;
        *(ptr + 1) = 11;
        *(ptr + 2) = 1959;
    }
    else{
        *(ptr) = m;
        *(ptr + 1) = d;
        *(ptr + 2) = y;
    }
    count++;
}


upDate :: upDate(int j){
    int month = 5;
    int day = 11;
    int year = 1959;
    ptr = new int[3];
    Julian2Greg(j, month, day, year);
    *(ptr) = month;
    *(ptr + 1) = day;
    *(ptr + 2) = year;
    count++;
}


upDate :: ~upDate(){
    delete[] ptr;
    count--;
}

void upDate :: setDate(int m, int d, int y){
    int JD = Greg2Julian(m, d, y);
    int m1 = m;
    int d1 = d;
    int y1 = y;
    Julian2Greg(JD, m1, d1, y1);
    if(m1 != m || d1 != d || y1 != y){
        *(ptr) = 5;
        *(ptr + 1) = 11;
        *(ptr + 2) = 1959;
    }
    else{
        *(ptr) = m;
        *(ptr + 1) = d;
        *(ptr + 2) = y;
    }
    count++;
}

int upDate :: getMonth(){
    return *(ptr);
}

int upDate :: getDay(){
    return *(ptr + 1);
}

int upDate :: getYear(){
    return *(ptr + 2);
}

int upDate :: getJulian(){
    return Greg2Julian(*(ptr), *(ptr + 1), *(ptr + 2));
}

string upDate :: getMonthName(){
    string monthNames[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    return monthNames[*(ptr) - 1];
}

int upDate :: getDateCount(){
    return count;
}

int upDate :: count = 0;

upDate :: upDate(const upDate &date){
//    cout << "Copy constructor" << endl;
    ptr = new int[3];
    for(int i = 0; i < 3; i++){
        *(ptr + i) = *(date.ptr + i);
    }
    count++;
}

upDate & upDate :: operator=(const upDate &date){
//    cout << "Member Function Overloading Assignment= \'upDate = upDate\'" << endl;
    ptr = new int[3];
    for(int i = 0; i < 3; i++){
        *(ptr + i) = *(date.ptr + i);
    }
    return *this;
}

upDate & upDate :: operator+=(int val){
//    cout << "Member Function Operation+= \'upDate += integer\'" << endl;
    int jd = Greg2Julian(*(ptr), *(ptr + 1), *(ptr + 2));
    jd = jd + val;
    Julian2Greg(jd, *(ptr), *(ptr + 1), *(ptr + 2));
    return *this;
}

upDate & upDate :: operator-=(int val){
//    cout << "Member Function Operation-= \'upDate -= integer\'" << endl;
    int jd = Greg2Julian(*(ptr), *(ptr + 1), *(ptr + 2));
    jd = jd - val;
    Julian2Greg(jd, *(ptr), *(ptr + 1), *(ptr + 2));
    return *this;
    
}

upDate & upDate :: operator++(){
//    cout << "Member Function Overload ++Prefix" << endl;
    int jd = Greg2Julian(*(ptr), *(ptr + 1), *(ptr + 2));
    ++jd;
    Julian2Greg(jd, *(ptr), *(ptr + 1), *(ptr + 2));
    return *this;
}

const upDate upDate :: operator++(int dummy){
//    cout << "Member Function Overload Postfix++" << endl;
    upDate temp(*this);
    int jd = Greg2Julian(*(ptr), *(ptr + 1), *(ptr + 2));
    jd++;
    Julian2Greg(jd, *(ptr), *(ptr + 1), *(ptr + 2));
    return temp;

}

upDate & upDate :: operator--(){
//    cout << "Member Function Overload --Prefix" << endl;
    int jd = Greg2Julian(*(ptr), *(ptr + 1), *(ptr + 2));
    --jd;
    Julian2Greg(jd, *(ptr), *(ptr + 1), *(ptr + 2));
    return *this;
}

const upDate upDate :: operator--(int dummy){
//    cout << "Member Function Overload Postfix--" << endl;
    upDate temp(*this);
    int jd = Greg2Julian(*(ptr), *(ptr + 1), *(ptr + 2));
    jd--;
    Julian2Greg(jd, *(ptr), *(ptr + 1), *(ptr + 2));
    return temp;
}

const upDate upDate :: operator+(int val) const{
//    cout << "Member Function operator+ \'upDate + integer\'" << endl;
    int jd = Greg2Julian(*(ptr), *(ptr + 1), *(ptr + 2));
    jd = jd + val;
    int month = *(ptr);
    int day = *(ptr + 1);
    int year = *(ptr + 2);
    Julian2Greg(jd, month, day, year);
    return upDate(month, day, year);
}

const upDate upDate :: operator-(int val) const{
//    cout << "Member Function operator- \'upDate - integer\'" << endl;
    int jd = Greg2Julian(*(ptr), *(ptr + 1), *(ptr + 2));
    jd = jd - val;
    int month = *(ptr);
    int day = *(ptr + 1);
    int year = *(ptr + 2);
    Julian2Greg(jd, month, day, year);
    return upDate(month, day, year);
}

const int upDate :: operator-(const upDate &date) const{
//    cout << "Member Function operator- \'upDate - upDate\'" << endl;
    int jd = Greg2Julian(*(ptr), *(ptr + 1), *(ptr + 2));
    int jd_2 = Greg2Julian(*(date.ptr), *(date.ptr + 1), *(date.ptr + 2));
    return jd - jd_2;
    
}

bool upDate :: operator==(const upDate &date) const{
    int sameMonth = *(ptr);
    int sameDay = *(ptr + 1);
    int sameYear = *(ptr + 2);
    if(sameYear == *(date.ptr + 2)){
        if(sameDay == *(date.ptr + 1)){
            if(sameMonth == *(date.ptr)){
                return true;
            }
        }
    }
    return false;
}

bool upDate :: operator<(const upDate &date) const{
    bool isValid = false;
    int thisMonth = *(ptr);
    int thisDay = *(ptr + 1);
    int thisYear = *(ptr + 2);
    if(thisYear < *(date.ptr + 2)){
        isValid = true;
    }
    else if (thisYear > *(date.ptr + 2)){
        isValid = false;
    }
    else{
        if(thisMonth < *(date.ptr)){
            isValid = true;
        }
        else if(thisMonth > *(date.ptr)){
            isValid = false;
        }
        else{
            if(thisDay < *(date.ptr + 1)){
                isValid = true;
            }
        }
    }
    
    return isValid;
}

bool upDate :: operator>(const upDate &date) const{
    bool isValid = false;
    int thisMonth = *(ptr);
    int thisDay = *(ptr + 1);
    int thisYear = *(ptr + 2);
    if(thisYear > *(date.ptr + 2)){
        isValid = true;
    }
    else if (thisYear < *(date.ptr + 2)){
        isValid = false;
    }
    else{
        if(thisMonth > *(date.ptr)){
            isValid = true;
        }
        else if(thisMonth < *(date.ptr)){
            isValid = false;
        }
        else{
            if(thisDay > *(date.ptr + 1)){
                isValid = true;
            }
        }
    }
    return isValid;
}

const upDate operator+(int val, const upDate &date){
//    cout << "Friend Function operator+ \' integer + upDate\'" << endl;
    int jd = Greg2Julian(*(date.ptr), *(date.ptr + 1), *(date.ptr + 2));
    jd = jd + val;
    int month = *(date.ptr);
    int day = *(date.ptr + 1);
    int year = *(date.ptr + 2);
    Julian2Greg(jd, month, day, year);
    return upDate(month, day, year);
}

const upDate operator-(int val, const upDate &date){
//    cout << "Friend Function operator- \' integer - upDate\'" << endl;
    int jd = Greg2Julian(*(date.ptr), *(date.ptr + 1), *(date.ptr + 2));
    jd = jd - val;
    int month = *(date.ptr);
    int day = *(date.ptr + 1);
    int year = *(date.ptr + 2);
    Julian2Greg(jd, month, day, year);
    return upDate(month, day, year);

}

ostream& operator<<(ostream &out, const upDate &date){
//    cout << "Friend Function operator <<" << endl;
    out << *(date.ptr) << "/" << *(date.ptr + 1) << "/" << *(date.ptr + 2);
    return out;
}




