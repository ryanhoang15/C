//
//  Alpha.hpp
//  Lab 8 Q#1
//
//  Created by ryan hoang on 10/19/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#ifndef Alpha_hpp
#define Alpha_hpp

#include <stdio.h>

class Alpha{
    
private:
    int data;
    
public:
    Alpha();
    Alpha(int num);
    Alpha(Alpha &a);
    void display();
    Alpha &operator=(Alpha &a);
};

#endif /* Alpha_hpp */
