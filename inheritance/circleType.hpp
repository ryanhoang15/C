//
//  circleType.hpp
//  lab 13
//
//  Created by ryan hoang on 11/30/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#ifndef circleType_hpp
#define circleType_hpp

#include <stdio.h>
#include "pointType.hpp"

class circleType: public pointType{
public:
    void print() const;
    void setRadius(double r);
    double getRadius() const;
    double getCircumference() const;
    double getArea() const;
    circleType(double x = 0.0, double y = 0.0, double r = 0.0);

protected:
    double radius;
};

#endif /* circleType_hpp */
