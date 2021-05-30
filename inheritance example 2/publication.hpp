//
//  publication.hpp
//  lab 14
//
//  Created by ryan hoang on 11/30/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#ifndef publication_hpp
#define publication_hpp
#include <stdio.h>
#include <iostream>
using namespace std;

class publication{
    
private:
    string title;
    double price;
    
public:
    virtual void getData() = 0;
    virtual void putData() = 0;
    
};

#endif /* publication_hpp */
