//
//  circleType.cpp
//  lab 13
//
//  Created by ryan hoang on 11/30/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#include "circleType.hpp"
#include <iostream>


using namespace std;

void circleType :: print() const{
    cout << "Center: ";
    pointType::print();
    cout << endl;

    cout << "Radius: " << radius << endl;
    cout << "Circumference: " << getCircumference() << endl;
    cout << "Area: " << getArea() << endl;
}

void circleType :: setRadius(double r){
    radius = r;
}

double circleType :: getRadius() const{
    return radius;
}

double circleType :: getCircumference() const{
    return (2 * 3.1416 * radius);
}

double circleType :: getArea() const{
    return (3.1416 * radius * radius);
}

circleType :: circleType(double x, double y, double r):pointType(x,y){
    radius = r;
}
