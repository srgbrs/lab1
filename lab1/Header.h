
#ifndef Header_h
#define Header_h

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct student {
    string name;
    bool isContract;
    int *marks = new int[5];
    
    float averageMark;
};

int studentsAmmount(ifstream &input);
int budgetStudentsAmount(int &studentsAmmount);

#endif /* Header_h */
