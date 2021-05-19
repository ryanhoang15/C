//
//  pointType.hpp
//  lab 13
//
//  Created by ryan hoang on 11/30/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#ifndef pointType_hpp
#define pointType_hpp

#include <stdio.h>

class pointType{
public:
    void setPoint(double x, double y);
    void print() const;
    double getX() const;
    double getY() const;
    pointType(double x = 0.0, double y = 0.0);

protected:
    double xCoordinate;
    double yCoordinate;
};

#endif /* pointType_hpp */
