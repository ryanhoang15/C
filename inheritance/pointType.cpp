//
//  pointType.cpp
//  lab 13
//
//  Created by ryan hoang on 11/30/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#include "pointType.hpp"
#include <iostream>
using namespace std;

void pointType::setPoint(double x, double y){
    xCoordinate = x;
    yCoordinate = y;
}

void pointType::print() const{
    cout << "(" << xCoordinate << ", " << yCoordinate << ")" << endl;
}

double pointType::getX() const{
    return xCoordinate;
}

double pointType::getY() const{
    return yCoordinate;
}

pointType::pointType(double x, double y){
    xCoordinate = x;
    yCoordinate = y;
}
