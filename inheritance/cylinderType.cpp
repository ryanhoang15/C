//
//  cylinderType.cpp
//  lab 13
//
//  Created by ryan hoang on 11/30/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#include "cylinderType.hpp"
#include <iostream>
using namespace std;

/**
 *This is displaying the info of the cylinder and it calls circleType print() also
 *since it inherits from it
 */
void cylinderType :: print() const{
    cout << "Base Center: ";
    circleType::print();
    cout << endl;

    cout << "Cylinder height: " << height << endl;
    cout << "Cylinder surface area: " << getVolume() << endl;
    cout << "Cylinder volume: " << getSurfaceArea() << endl;
}


/**
 *Setting the height of the cylinder
 *@param h is the height of the cylinder
 */
void cylinderType :: setHeight(double h){
    height = h;
}

/**
 *This setting the cylinder's base centerto a certain number given by the users and
 *calling the pointType setPoint function since cylinderType inherits from circleType and circleType
 *inherits from pointType
 *@param x is the value of the x-coordinate
 *@param y is the value of the y-coordinate
 */
void cylinderType :: setBaseCenter(double x, double y){
    pointType::setPoint(x, y);
    
}


/**
 *This setting the cylinder's center,radius and height to a certain number given by the users and
 *calling the pointType setPoint function and circleType set radius function since cylinderType inherits from circleType and circleType
 *inherits from pointType
 *@param x is the value of the x-coordinate
 *@param y is the value of the y-coordinate
 *@param r is the radius
 *@param h is the height
 */
void cylinderType :: setCenterRadiusHeight(double x, double y,double r, double h){
    pointType::setPoint(x, y);
    circleType::setRadius(r);
    height = h;
}

/**
 *Retrieves the height of the cylinder
 *@return the height value of the cylinder
 */
double cylinderType :: getHeight() const{
    return height;
}

/**
 *Retrieves the volume of the cylineder
 *gets the radius from the circleType class since cylinderType inherits from circleType
 *@return the volume value of the cylinder
 */
double cylinderType :: getVolume() const{
    double radius = circleType::getRadius();
    return (3.1416 * radius * radius * height);
}

/**
 *Retrieves the surface area of the cylineder
 *gets the radius from the circleType class since cylinderType inherits from circleType
 *@return the surdace area value of the cylinder
*/
double cylinderType :: getSurfaceArea() const{
    return (2 * 3.1416 * circleType::getRadius() * height) + (2 * 3.1416 * circleType::getRadius() * circleType::getRadius());
    
}

/**
 *Overloading constructor and calling the circleType constructor and pass in
 *x, y, and r to the circleType class
 *@param x is the x-coordinate
 *@param y is the y-coordinate
 *@param r is the radius
 *@param h is the height
 */
cylinderType :: cylinderType(double x, double y, double r, double h):circleType(x,y,r){
    height = h;
}
