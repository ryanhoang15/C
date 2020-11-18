//
//  Rectangle.cpp
//  lab 1 Q #2
//
//  Created by ryan hoang on 8/24/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#include "Rectangle.hpp"

/**
 This constructors set value to the origin
 */

rectangle :: rectangle(){
    width = 1;
    height = 1;
    
}

/**
 This constructors set values to the variable width and height
 @param w is width
 @param h is height
 */

rectangle :: rectangle(double w, double h){
    width = w;
    height = h;
}

/**
 These functions below are setting the value of width and height and/or changing the value of the width and height
 Also there are fuctions that returns the area and perimeter of the rectangle
 */

void rectangle :: setWidth(double w){
    width = w;
}

void rectangle :: setHeight(double h){
    height = h;
}

double rectangle :: getWidth() const{
    return width;
}

double rectangle :: getHeight() const{
    return height;
}

double rectangle :: getArea(){
    return width * height;
}

double rectangle :: getPerimeter(){
    return (2 * width) + (2 * height);
    
}










