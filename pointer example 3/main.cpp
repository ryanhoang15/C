//
//  main.cpp
//  lab 10 Q#1
//
//  Created by ryan hoang on 11/2/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

#include <iostream>
#include <vector>

#include<algorithm>

#include<numeric>//for accumulator operations

using namespace std;

/**
@author Ryan Hoang
@version Fall 2020
@date 11/9/2020
*/
 
/**
 This function's purpose is to understand how to use built in libary methods
 from algorithms, vector, and numeric
 */
int main(){
    
    /**
     an array of doubles
     */
    double arr[] = { 1.1, 2.2, 3.3, 2.2, 4.4 };
    

    /**
    Determine the array size and displaying it
     */
    int length = sizeof(arr) / sizeof(arr[0]);
    cout << "Array size is: " << length << endl;

   
    
    /**
     initialize vector v1 to array arr
     */
    vector<double> vector_1(arr, arr + length);
    cout << endl;
    
    /**
     Display the contents of vector v1
     */
    cout << "Displaying" << endl;
    for (int j = 0; j < vector_1.size(); j++){
        cout << vector_1[j] << endl;
    }
    cout << endl;
    
    /**
     sorting the Vector in Ascending order
     */
    sort(vector_1.begin(), vector_1.end());
    

    /**
     Display the content of vector v1 after sorting
     */
    cout << "Sorted" << endl;
    for (int k = 0; k < vector_1.size(); k++){
        cout << vector_1[k] << endl;
    }

    /**
     Reversing the Vector v1
     */
    reverse(vector_1.begin(), vector_1.end());
    cout << endl;
    
    /**
     Display the content of vector v1 after reversing it
     */
    cout << "Reverse" << endl;
    for (int k = 0; k < vector_1.size(); k++){
        cout << vector_1[k] << endl;
    }
    cout << endl;
    
    /**
     Display the maximum element of vector v1
     */
    double max = *max_element(vector_1.begin(), vector_1.end());
    cout << "Max element: " << max << endl;
    cout << endl;
    
    /**
     Display the minimum element of vector v1
     */
    double min = *min_element(vector_1.begin(), vector_1.end());
    cout << "Min element: " << min << endl;
    cout << endl;
    
    /**
     Display the accumulation of all elements in vector v1
     Starting the summation from 0
     */
    double sum = 0;
//    for (int x = 0; x < vector_1.size(); x++){
//        sum = sum + vector_1[x];
//    }
    cout << "Sum " << accumulate(vector_1.begin(), vector_1.end(), sum) << endl;
    

    /**
     Counts the occurrences of 2.2 from 1st to last element
     */
    long repeat = count(arr, arr + length, 2.2);

    /**
     Display the counts
     */
    cout << endl;
    cout << "The occurrences of 2.2 is " << repeat << endl;

    /**
     Delete second element of vector
     */
    vector_1.erase(vector_1.begin() + 1);
    cout << endl;
    
    /**
     Display the v1 after erasing the element
     */
    cout << "Displaying after deleting second element" << endl;
    for (int y = 0; y < vector_1.size(); y++){
        cout << vector_1[y] << endl;
    }
    cout << endl;
    
    /**
     Remove the duplicate occurrences and displaying it to show that it was removed
     */
    cout << "Displaying after removing the duplicate occurrences" << endl;
    double *begin = arr;
    double *end = arr + sizeof(arr) / sizeof(double);
    end = remove(begin, end, 2.2);
    
    double *ptr;

    for (ptr = begin; ptr != end; ptr++){
        cout << *ptr << endl;
    }

    return 0;

}
