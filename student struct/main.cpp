//
//  main.cpp
//  Prog 3 - Student Struct
//
//  Created by ryan hoang on 9/29/20.
//  Copyright © 2020 ryan hoang. All rights reserved.
//

/**
Ryan Hoang
CECS 282 - 01
Prog 3 - Student Struct
10/12/2020
 
I certify that this program is my own original work. I did not copy any part of this program from
any other source. I further certify that I typed each and every line of code in this program.
 */

#include <iostream>
#include <string>
#include <cstring> // null terminated char array
#include <iomanip>
using namespace std;

class myDate{
    
private:
    int month;
    int day;
    int year;
  
public:
    // pass in the Month, Day, Year and return Julian number
    int Greg2Julian(int month, int day, int year){
        int I = year;
        int J = month;
        int K = day;
        
        int JD = K - 32075 + 1461 * (I + 4800 + (J - 14) / 12) / 4 + 367 * (J - 2 - (J - 14) / 12 * 12) / 12 - 3 * ((I + 4900 + (J - 14) / 12) / 100) / 4;
        
        return JD;
    }

    // pass in the Julian Date, and get the correct Month, Day and Year through the parameter list – pass by reference
    void Julian2Greg(int JD, int& month, int& day, int& year){
        int I;
        int J;
        int K;
        int L;
        int N;
        
        L = JD + 68569;
        N = (4 * L) / 146097;
        L = L - (146097 * N + 3 ) / 4;
        I = 4000 * (L + 1) / 1461001;
        L = L - ((1461 * I) / 4) + 31;
        J = (80 * L) / 2447;
        K = L - ((2447 * J) / 80);
        L = J / 11;
        J = J + 2 - 12 * L;
        I = 100 * (N - 49) + I + L;
        
        year = I;
        month = J;
        day = K;
        
    }

    myDate(){
        month = 5;
        day = 11;
        year = 1959;
    }

    myDate(int M, int D, int Y){
        int JD = Greg2Julian(M,D,Y);
        int m1 = M;
        int d1 = D;
        int y1 = Y;
        Julian2Greg(JD, m1, d1, y1);
        
        if(m1 != M || d1 != D || y1 != Y ){
            month = m1;
            day = d1;
            year = y1;
        }
        
        else{
            month = M;
            day = D;
            year = Y;
        }
    }

    void display(){
        string monthNames[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
        
        cout << monthNames[month - 1] << " " << day << ", " << year << " ";
    }

    void increaseDate(int N){
        day = day + N;
        int jd = Greg2Julian(month, day, year);
        Julian2Greg(jd, month, day, year);
    }

    void decreaseDate(int N){
        day = day - N;
        int jd = Greg2Julian(month, day, year);
        Julian2Greg(jd, month, day, year);
    }

    int daysBetween(myDate D){
        int julianDate1 = Greg2Julian(month, day, year);
        int julianDate2 = Greg2Julian(D.getMonth(), D.getDay(), D.getYear());

        return julianDate2 - julianDate1;
    }

    int getMonth(){
        return month;
        
    }

    int getDay(){
        return day;
    }

    int getYear(){
        return year;
    }


    int dayOfYear(){
        int julianDate = Greg2Julian(month, day, year);
        int julianDate2 = Greg2Julian(1, 1, year);
        return julianDate - julianDate2 + 1;
    }


    string dayName(){
        string dayNames[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
        
        int jD = Greg2Julian(month, day, year);

        return dayNames[(jD % 7)];
    }
    
    string toString(){
        string monthNames[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
        
        string dayBorn = monthNames[month - 1] + " " + to_string(day) + ", " + to_string(year);
        
        return dayBorn;
        
    }
    
//    myDate birthDate(){
//        int randMonth = rand() % 12 + 1;
//        int randDay = rand() % 31 + 1;
//        int randYear = rand() % 6 + 2000;
//        myDate yourBday(randMonth,randDay,randYear);
//        return yourBday;
//    }
};


/**
 *This is the structure of the student, meaning what info each student's have
 */
struct Student{
    char name[10]; // cstring or null terminated char array
    int SID;
    char grade;
    myDate bday;
    string homeTown;
};


/**
 * This function is randomly creating a birthdate for the student in a range from 1/1/2000 to 12/31/2005
 */
myDate birthDate(){
    int randMonth = rand() % 12 + 1;
    int randDay = rand() % 31 + 1;
    int randYear = rand() % 6 + 2000;
    myDate yourBday(randMonth,randDay,randYear);
    return yourBday;

}

/**
 * This function is checking each character of the student's name and comparing it to determine the alphabetical order
 * @param name1 is the name of the first student
 * @param name2  iis the name of the second student
 */
int stringCmp(const char name1[], const char name2[]){
    int nameValue = 0;
    int nameValue2 = 0;
    
    for(int i = 0; name1[i] != '\0' || name2[i] != '\0'; i++){
        if(name1[i] == name2[i]){
            continue;
        }
        else{
            nameValue = nameValue + int(name1[i]);
            nameValue2 = nameValue2 + int(name2[i]);
            break;
        }
    }
    
    return nameValue - nameValue2;
}


/**
 * This function is copying the characters in one array to another array;
 * @param target where the info is copying too
 * @param source is the info that is used to copy
 */
void stringCpy(char target[], const char source[]){
    int i = 0;
    while(source[i] != '\0'){
        target[i] = source[i];
        i++;
    }
    target[i] = '\0';
}


/**
 *this function is assiging each student with a name, ID, grade, birthday, and hometown
 *@param stuPtr is the array that stores the value and is a pointer
 *@param size is the size of the array
 */
void populate(Student * stuPtr, int size){
    string names[] = {"Ryan","Tony","Bruce","Leo","Brad","Nick","Joker","Peter","MJ","Lebron","AD","Tobey","Robert","Thor","Odin","Loki"};
    char grades[] = {'A','B','C','D','F'};
    string home[] = {"Bikini Bottom", "Small Ville", "Mumbai", "Huntington Beach", "Venice", "Hidden Hills", "New York", "Hollywood", "Paris", "Athens", "Milian","Malibu", "Barcelona", "Calabases", "Havana", "Bel Air", "Newport Beach", "Beverly Hills", "Gotham", "Laguna Beach", "San Diego", "San Francisco"};

    
    srand(time(NULL));
    for(int i = 0; i < size; i++){
        int randID = rand() % 9000 + 1000;
        int randGrade = rand() % 5;
        int randTown = rand() % 22;
        stringCpy(stuPtr->name, names[i].c_str());
        stuPtr->SID = randID;
        stuPtr->grade = grades[randGrade];
        stuPtr->homeTown = home[randTown];
        stuPtr->bday = birthDate();
        stuPtr++;
        
        // this is for if the myDate birthDate() is in the myDate class itself
//        myDate birth = stuPtr[i].bday.birthDate();
//        stuPtr[i].bday = birth;
    }
}


/**
 * This is showing the menu to the user and letting them pick what function to call
 */
int displayMenu(){
    cout << "Here is the menu options" << endl;
    cout << "1) Display list sorted by Name" << endl;
    cout << "2) Display list sorted by Student ID" << endl;
    cout << "3) Display list sorted by Grade" << endl;
    cout << "4) Display list sorted by Birthday" << endl;
    cout << "5) Display list sorted by Home Town" << endl;
    cout << "6) Exit" << endl;
    int pick;
    cout << "Pick a number ";
    cin >> pick;
    return pick;

}


 /**
  *this function is displaying the student's information
  *@param stuPtr is the array that stores the value and is a pointer
  *@param size is the size of the array
  */
void display(Student *stuPtr, int size){
    cout << setw(14) << left << "Name" <<setw(20) << "Student ID" << setw(15) << "Grade" << setw(20) << "Birthday" << setw(20) << "Hometown" << endl;
    cout << setw(14) << left << "_____" << setw(20) << "___________" << setw(15) << "______" << setw(20) << "_________" << setw(20) << "_________" << endl;
    for(int j = 0; j < size; j++){
        cout << setw(14) << left << stuPtr[j].name  << setw(20) << stuPtr[j].SID << setw(15) << stuPtr[j].grade << setw(20) << stuPtr[j].bday.toString() << setw(20) << stuPtr[j].homeTown << endl;
        
        cout << endl;
    }
}

/**
 *this function is checking the names in the array and rearranging it in alphabetical order
 *@param stuPtr is the array that stores the value and is a pointer
 *@param size is the size of the array
 */
void sortName(Student *stuPtr, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - 1; j++){
            int nameValue = stringCmp(stuPtr[j].name, stuPtr[j + 1].name);
            if(nameValue > 0){
                Student temp = *(stuPtr + j);
                *(stuPtr + j) = *(stuPtr + j + 1);
                *(stuPtr + j + 1) = temp;
            }
        }
    }
}


/**
 *this function is checking the values of the student ID in the array if its in order from least to greatest
 *@param stuPtr is the array that stores the value and is a pointer
 *@param size is the size of the array
 */
void sortID(Student *stuPtr, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - 1; j++){
            if(stuPtr[j].SID > stuPtr[j + 1].SID){
                Student temp = *(stuPtr + j);
                *(stuPtr + j) = *(stuPtr + j + 1);
                *(stuPtr + j + 1) = temp;
            }
        }
    }
}


/**
 *this function is checking the grades of the student in the array and rearranging it in alphabetical order
 *@param stuPtr is the array that stores the value and is a pointer
 *@param size is the size of the array
 */
void sortGrade(Student *stuPtr, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - 1; j++){
            int gradeValue = stuPtr[j].grade;
            int gradeValue2 = stuPtr[j + 1].grade;
            if(gradeValue > gradeValue2){
                Student temp = *(stuPtr + j);
                *(stuPtr + j) = *(stuPtr + j + 1);
                *(stuPtr + j + 1) = temp;
            }
        }
    }
}

/**
 *this function is checking the birthdates  of the student in the array and rearranging it in order by checking the juilan value of each birthdate
 *to see which is greater.
 *@param stuPtr is the array that stores the value and is a pointer
 *@param size is the size of the array
 */
void sortBirthDay(Student *stuPtr, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - 1; j++){
            int studentJD = stuPtr[j].bday.Greg2Julian(stuPtr[j].bday.getMonth(), stuPtr[j].bday.getDay(), stuPtr[j].bday.getYear());
            int studentJD_2 = stuPtr[j + 1].bday.Greg2Julian(stuPtr[j + 1].bday.getMonth(), stuPtr[j + 1].bday.getDay(), stuPtr[j + 1].bday.getYear());
            if(studentJD > studentJD_2){
                Student temp = *(stuPtr + j);
                *(stuPtr + j) = *(stuPtr + j + 1);
                *(stuPtr + j + 1) = temp;
            }
        }
    }
}

/**
 *this function is checking the howetown in the array and rearranging it in alphabetical order
 *@param stuPtr is the array that stores the value and is a pointer
 *@param size is the size of the array
 */
void sortHomeTown(Student *stuPtr, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - 1; j++){
            int homeTownValue = stringCmp(stuPtr[j].homeTown.c_str(), stuPtr[j + 1].homeTown.c_str());
            if(homeTownValue > 0){
                Student temp = *(stuPtr + j);
                *(stuPtr + j) = *(stuPtr + j + 1);
                *(stuPtr + j + 1) = temp;
            }
        }
    }
}


/**
 * This function's purpose is to initialized an array of 10 student's and passing it into the populate() function to assign info to the student
 *  then it ask the user how they want to display the student's info
 */
int main(){
    int size = 10;
    
    Student *stuPtr = new Student[size];
    populate(stuPtr, size);

    int choice = displayMenu();
    while(choice >= 1 && choice <= 5){
        if(choice == 1){
            sortName(stuPtr, size);
            display(stuPtr, size);
            choice = displayMenu();
        }
        else if(choice == 2){
            sortID(stuPtr, size);
            display(stuPtr, size);
            choice = displayMenu();
        }
        else if(choice == 3){
            sortGrade(stuPtr, size);
            display(stuPtr, size);
            choice = displayMenu();
        }
        else if(choice == 4){
            sortBirthDay(stuPtr, size);
            display(stuPtr, size);
            choice = displayMenu();
        }
        else{
            sortHomeTown(stuPtr, size);
            display(stuPtr, size);
            choice = displayMenu();
        }
    }

    return 0;
}
