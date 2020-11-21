//
//  main.cpp
//  lab 1 Q #2
//
//  Created by ryan hoang on 8/24/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

/**
@author Ryan Hoang
@version Fall 2020
@date 8/24/2020
*/

#include <iostream>
#include "Rectangle.hpp"

using namespace std;


/**
 This function prints the width, height, area, and perimeter of the rectangle
 @rectNoArg  is creating the default rectangle
 @rect1(4,40) is creating the first rectangle
 @rect2(3.5,35.9) is creating the second rectangle
 */

int main() {
    
    rectangle rectNoArg;
    rectangle rect1(4,40);
    rectangle rect2(3.5,35.9);
    
    cout << "\nDisplaying the stats of the default rectangle\n";
       
    cout << "Width: " << rectNoArg.getWidth() << endl;
    cout << "Height: " << rectNoArg.getHeight() << endl;
    cout << "Area: " << rectNoArg.getArea() << endl;
    cout << "Perimeter: " << rectNoArg.getPerimeter() << endl;
    
    cout << "Displaying the stats of the first rectangle\n";
    
    cout << "Width: " << rect1.getWidth() << endl;
    cout << "Height: " << rect1.getHeight() << endl;
    cout << "Area: " << rect1.getArea() << endl;
    cout << "Perimeter: " << rect1.getPerimeter() << endl;
    
    
    cout << "\nDisplaying the stats of the second rectangle\n";
    
    cout << "Width: " << rect2.getWidth() << endl;
    cout << "Height: " << rect2.getHeight() << endl;
    cout << "Area: " << rect2.getArea() << endl;
    cout << "Perimeter: " << rect2.getPerimeter() << endl;
    
    
    
    return 0;
}
