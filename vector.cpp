//
//  main.cpp
//  Lab 4 Q#3
//
//  Created by ryan hoang on 9/21/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

/**
@author Ryan Hoang
@version Fall 2020
@date 9/23/2020
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>


/**
 this function is printing out the element in the vector
 @param title is the string name
 @param v is the vector
 and there is the & which refers to reference
 */
void print(const string& title, const vector<T>& v) {
cout << title << " ";
for (int i = 0; i < v.size(); i++)
cout << v[i] << " ";
cout << endl;
}


/**
 this main function's purpose is to create a vector and add elements to it
 and than it is adding an element to a specific index and removing an element from the second to last
 also it is displaying the elements in sorted order and shuffling it by pasing it to the function print()
 and finding its max and min and checking if a value exist in this vector
 */
int main(){
    vector<int> v;
    for (int i = 0; i < 5; i++){
        v.push_back(i);
    }

//    FILL_CODE_OR_CLICK_ANSWER // Insert 20 at index 1
    v.insert(v.begin() + 1, 20);
//    FILL_CODE_OR_CLICK_ANSWER // Remove the second last element
    v.erase(v.end() - 2);
    
    
    print("The elements in vector:", v);

    sort(v.begin(), v.end()); // Sort the elements in v
    print("Sorted elements:", v);

    random_shuffle(v.begin(), v.end()); // Shuffle the elements in v
    print("After random shuffle:", v);

    cout << "The max element is " <<
    *max_element(v.begin(), v.end()) << endl;

    cout << "The min element is " <<
    *min_element(v.begin(), v.end()) << endl;

    int key = 45;
    
    if (find(v.begin(), v.end(), key) == v.end()){
        cout << key << " is not in the vector" << endl;
    
    }
    
    else{
        cout << key << " is in the vector" << endl;
    }

    return 0;
}
