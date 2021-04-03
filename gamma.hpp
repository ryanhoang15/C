//
//  gamma.hpp
//  lab 9 Q#2
//
//  Created by ryan hoang on 10/28/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#ifndef gamma_hpp
#define gamma_hpp

#include <stdio.h>

class gamma{
  
private:
    static int count;
    int id;
    
public:
    gamma();
    static void showtotal();
    void showid();
    ~gamma();
};

#endif /* gamma_hpp */
