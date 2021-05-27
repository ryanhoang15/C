//
//  Digital.hpp
//  lab 14
//
//  Created by ryan hoang on 11/30/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#ifndef Digital_hpp
#define Digital_hpp

#include <stdio.h>
#include "publication.hpp"
#include "Sale.hpp"

class Digital : public publication, public Sale{
    
private:
    int storage;
    
public:
    void getData();
    void putData();
};

#endif /* Digital_hpp */
