//
//  Rectangle.hpp
//  lab 1 Q #2
//
//  Created by ryan hoang on 8/24/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

//guard
#ifndef Rectangle_hpp
#define Rectangle_hpp

/**
 header file
 This class is where the constructors, mutator, accessor functions are defined
 */

#include <stdio.h>

class rectangle{
    
    
// Instance variables
private:
    double width;
    double height;
    
public:
    rectangle();
    rectangle(double w, double h);
    void setWidth(double w); //setter or mutator
    void setHeight(double h); //setter or mutator
    double getWidth() const; //getter or accessor
    double getHeight() const; //getter or accessor
    double getArea();
    double getPerimeter();
    
    
};

#endif /* Rectangle_hpp */
