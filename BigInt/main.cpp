//
//  main.cpp
//  prog5
//
//  Created by ryan hoang on 11/21/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

/**
Ryan Hoang
CECS 282 - 01
Prog 5 - goldRabbits
11/23/2020
 
I certify that this program is my own original work. I did not copy any part of this program from
any other source. I further certify that I typed each and every line of code in this program.
 */


#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

class BigInt{
    
private:
    vector<char> storage;
    
public:
    BigInt(){
        storage.push_back(0);
    }
    
    BigInt(string num){
        int length = (int)num.length() - 1;
        for(int i = length; i >= 0; i--){
            storage.push_back(num[i] - '0');
        }
    }
    
    BigInt(int n){
        while(n > 9){
            int digit = n % 10;
            storage.push_back(digit);
            n = n / 10;
        }
        storage.push_back(n);
    }
    
    void print(){
        vector<char>::reverse_iterator riter;
        for(riter = storage.rbegin(); riter!=storage.rend(); riter++){
            cout << (int)*riter;
        }
        cout << endl;
    }
    
    BigInt operator-(int val){
        BigInt bigInt(val);
        BigInt temp(*this);
        int len = (int)temp.storage.size();
        int len2 = (int)bigInt.storage.size();
        int fluff = 0;
        
        if(len > len2){
            fluff = len - len2;
            for(int i = 0; i < fluff; i++){
                bigInt.storage.push_back(0);
            }
        }
        else if(len < len2){
            fluff = len2 - len;
            for(int j = 0; j < fluff; j++){
                temp.storage.push_back(0);
            }
        }
        
        for(int k = 0; k < bigInt.storage.size(); k++){
            if(k == bigInt.storage.size() - 1 && temp.storage[k] == 0 && bigInt.storage[k] == 0){
                temp.storage.erase(temp.storage.end() - 1);
                break;
            }
            
            temp.storage[k] = temp.storage[k] - bigInt.storage[k];
            if(temp.storage[k] < 0){
                temp.storage[k] = temp.storage[k] + 10;
                temp.storage[k+1] = temp.storage[k+1] - 1;
            }
        }
        return temp;
        
    }
    
    BigInt operator+(BigInt bigInt){
        BigInt temp(*this);
        int len = (int)temp.storage.size();
        int len_2 = (int)bigInt.storage.size();
        int fluff = 0;
        
        if(len > len_2){
            fluff = len - len_2;
            for(int i = 0; i < fluff; i++){
                bigInt.storage.push_back(0);
            }
        }
        else if(len < len_2){
            fluff = len_2 - len;
            for(int j = 0; j < fluff; j++){
                temp.storage.push_back(0);
            }
        }
        for(int k = 0; k < bigInt.storage.size(); k++){
            temp.storage[k] = temp.storage[k] + bigInt.storage[k];
            if(temp.storage[k] > 9){
                if(k == bigInt.storage.size() - 1){
                    temp.storage[k] = temp.storage[k] - 10;
                    temp.storage.push_back(1);
                }
                else{
                    temp.storage[k] = temp.storage[k] - 10;
                    temp.storage[k+1] = temp.storage[k+1] + 1;
                }
            }
        }
        return temp;
        
    }
    
    bool operator==(BigInt bigInt){
        int length = (int)this->storage.size();
        int length_2 = (int)bigInt.storage.size();
        
        if(length != length_2){
            return false;
        }
        
        else if(length == length_2){
            for(int i = length - 1; i>=0; i--){
               if(storage[i] != bigInt.storage[i]){
                   return false;
               }
            }
            return true;
        }
        return true;
    }
    
    bool operator<(const BigInt &bigInt)const{
        int len = (int)this->storage.size();
        int len2 = (int)bigInt.storage.size();
        BigInt temp = *this;

        if(len < len2){
            return true;
        }
        else if(len > len2){
            return false;
        }
        else if(len == len2){
            for(int i = (int)temp.storage.size()-1; i>=0; i--){
                if(temp.storage[i] < bigInt.storage[i]){
                    return true;
                }
                else if(temp.storage[i] > bigInt.storage[i]){
                    return false;
                }
            }
        }
        return false;
    }

    bool operator<=(int number){

        BigInt temp(number);

        if(*this == temp){
            return true;
        }
        else{
            return *this < temp;
        }
    }
    
    BigInt operator ++(int){
        BigInt temp(*this);
        temp = temp + 1;
        this->storage = temp.storage;
        return *this;
    }
    
    friend ostream &operator <<(ostream &out, const BigInt& bigInt){
        
        string strLength = to_string((int)bigInt.storage.size());
        BigInt temp(bigInt);
        string outPut = " ";
        int maxValue = INT_MAX;

        int indexLen = (int)bigInt.storage.size() - 1;
        int count = 0;
        if(!(temp <= maxValue)){
            outPut = to_string(bigInt.storage[indexLen]);
            outPut = outPut + ".";
            while(count < 10){
                indexLen--;
                outPut = outPut + to_string(bigInt.storage[indexLen]);
                count++;
            }
            outPut = outPut + "e" + strLength;
            out << outPut;
        }
        else{
            
            for(int i = (int)bigInt.storage.size()-1; i>=0; i--){
                out << to_string(bigInt.storage[i]);
            }
            
        }
        return out;
    }
};


int goldRabbits(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    else{
        int result = goldRabbits(n - 1) + goldRabbits(n - 2);
        if(result < 0){
            throw string("Overflow Error – goldRabbits overflowed using " + to_string(n));
        }
        return result;
    }
}

BigInt goldRabbits(BigInt n){
    
    static map<BigInt,BigInt> mapFib;
    BigInt zero(0);
    BigInt one(1);
    if(n == zero ||  n == one){
        BigInt temp(1);
        mapFib[n] = temp;
        return temp;
    }
    else {
        
        BigInt value = mapFib[n - 1] + mapFib[n - 2];
        mapFib[n] = value;
        return mapFib[n];
    }
}

void pause(){
    cout << "Press Enter to continue...";
    getchar();
}

int main() {
    
    BigInt b1("123456789123456789123456789123456789");
    BigInt b2(b1);
    BigInt max(INT_MAX);

    cout << "B1:"<< b1 << "\nB2:" << b2 << "\nMAX:" << max << endl;
    pause();
    cout << "\nB1:";
    b1.print();
    cout << endl;
    pause();

    for(BigInt i = 0; i <= 3000; i++){
        cout << "\ngoldRabbits("<< i <<") = " << goldRabbits(i);
    }
    cout << endl;
    pause();

    cout<< "\nThis is the value of goldRabbits(3000)\n\n";
    BigInt gR3000 =  goldRabbits(BigInt(3000));
    gR3000.print();

    pause();

    int n = 500;
    try{
        cout << "The value of goldRabbits(500) is:" << goldRabbits(n) << endl;
    }
    catch(string error){
        cout << error << endl;
        cout << "Transitioning to BigInt\n";
        cout << goldRabbits(BigInt(n));
        cout << endl;
    }

    pause();
    return 0;
}
