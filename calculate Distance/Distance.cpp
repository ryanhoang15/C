//
//  Distance.cpp
//  Lab 7 Q#2
//
//  Created by ryan hoang on 10/12/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#include "Distance.hpp"
#include <iostream>
using namespace std;

/**
 * This creates a default object of 0 feet and 0 inches
 */
Distance :: Distance(){
    feet = 0;
    inches = 0.0;
}

/**
 *This is an overloading constructor to set the feet and inches to a specific number
 *@Param ft is the value feet is being set too
 *@Param in is the value inches get set to
 */
Distance :: Distance(int ft, float in){
    feet = ft;
    inches = in;
    while(inches > 12){
        inches = inches - 12;
        feet++;
    }
    
    while(inches < 0){
        inches = inches + 12;
        feet--;
    }
}

/**
 *This a overloading operator add and its a member function
 *the member function is unary and had one argument
 *@param dist is the distance object being passed into
 *@Return combined is the new distance with the values of the two distance object combined
 */
const Distance Distance :: operator+(const Distance &dist) const{
    Distance combined;
    int ft;
    float inch;
    ft = this->feet + dist.feet;
    inch = this->inches + dist.inches;
    
    return Distance(ft,inch);
}


/**
 *This a overloading operator subtract and its a friend function
 *the friend function is bianry and has two argument
 *@param dist is the object distance 1 being passed into and its a reference
 *@param dist2 is the object distance 2 being passed into and its a reference
 *@Return apart is the new distance with the values of the two distance object subtracted from one another
 */
const Distance operator-(const Distance &dist, const Distance &dist2){
    Distance apart;
    int ft;
    float in;
    if(dist.feet < dist2.feet || dist.inches < dist2.inches){
        ft = dist2.feet - dist.feet;
        in = dist2.inches - dist.inches;
    }
    else{
        ft = dist.feet - dist2.feet;
        in = dist.inches - dist2.inches;
    }
    
    
    return Distance(ft,in);
}
    

/**
 *This a overloading operator cin (>>)  and its a friend function
 *the friend function is bianry and has two argument
 *@param input is the input that gets the values  and its a reference
 *@param dist is the object distance being passed into and its a reference
 *@Return input is the info that was gotten from the user
 */
istream &operator>>(istream &input, Distance &dist){
    Distance *temp;
    int ft;
    float inch;
    input >> ft >> inch;
    temp = new Distance(ft,inch);
    dist = *temp;
    
    return input;
}

/**
 *This a overloading operator cout (<<)  and its a friend function
 *the friend function is bianry and has two argument
 *@param output is the output that retrieves the values and its a reference
 *@param dist is the object distance being passed into and its a reference and a constant
 *@Return output is the info that is stored to be displayed
 */
ostream &operator<<(ostream &output, const Distance &dist){
    output << "Feet: " <<dist.feet << "\'"<< " Inches: " << dist.inches << "\"";
    return output;
}
