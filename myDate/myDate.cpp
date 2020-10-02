//
//  myDate.cpp
//  prog 2 - myDate
//
//  Created by ryan hoang on 9/15/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#include "myDate.hpp"
#include <iostream>
#include <string>
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

myDate :: myDate(){
    month = 5;
    day = 11;
    year = 1959;
}

myDate :: myDate(int M, int D, int Y){
    int JD = Greg2Julian(M,D,Y);
    int m1 = M;
    int d1 = D;
    int y1 = Y;
    Julian2Greg(JD, m1, d1, y1);
    
    if(m1 != M || d1 != D || y1 != Y ){
        month = 5;
        day = 11;
        year = 1959;
    }
    
    else{
        month = M;
        day = D;
        year = Y;
    }
}

void myDate :: display(){
    string monthNames[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    
    cout << monthNames[month - 1] << " " << day << ", " << year << " ";
}

void myDate :: increaseDate(int N){
    day = day + N;
    int jd = Greg2Julian(month, day, year);
    Julian2Greg(jd, month, day, year);
}

void myDate :: decreaseDate(int N){
    day = day - N;
    int jd = Greg2Julian(month, day, year);
    Julian2Greg(jd, month, day, year);
}

int myDate :: daysBetween(myDate D){
    int julianDate1 = Greg2Julian(month, day, year);
    int julianDate2 = Greg2Julian(D.getMonth(), D.getDay(), D.getYear());

    return julianDate2 - julianDate1;
}

int myDate :: getMonth(){
    return month;
    
}

int myDate :: getDay(){
    return day;
}

int myDate :: getYear(){
    return year;
}


int myDate :: dayOfYear(){
    int julianDate = Greg2Julian(month, day, year);
    int julianDate2 = Greg2Julian(1, 1, year);
    return julianDate - julianDate2 + 1;
}


string myDate :: dayName(){
    string dayNames[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    
    int jD = Greg2Julian(month, day, year);

    return dayNames[(jD % 7)];
}




