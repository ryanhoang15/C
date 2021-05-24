//
//  Book.hpp
//  lab 14
//
//  Created by ryan hoang on 11/30/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#ifndef Book_hpp
#define Book_hpp

#include <stdio.h>
#include "publication.hpp"
#include "Sale.hpp"

class Book : public publication, public Sale{
  
private:
    int pages;
    
public:
    void getData();
    void putData();
    
};


#endif /* Book_hpp */
