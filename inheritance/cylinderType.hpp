//
//  cylinderType.hpp
//  lab 13
//
//  Created by ryan hoang on 11/30/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#ifndef cylinderType_hpp
#define cylinderType_hpp

#include <stdio.h>
#include "circleType.hpp"

class cylinderType: public circleType{
    
public:
    void print() const;
    void setHeight(double h);
    void setBaseCenter(double x, double y);
    void setCenterRadiusHeight(double x, double y,
    double r, double h);

    double getHeight() const;
    double getVolume() const;
    double getSurfaceArea() const;
    cylinderType(double x = 0.0, double y = 0.0,
    double r = 0.0, double h = 0.0);

protected:
    double height;
};

#endif /* cylinderType_hpp */
