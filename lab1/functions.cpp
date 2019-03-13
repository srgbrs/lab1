#include <stdio.h>
#include "Header.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int studentsAmmount(ifstream &input) {
    if (input.is_open())
    {
        string line;
        getline(input, line);
        return stoi(line);
    } else {
        cout << "Input file is unreachable" << endl;
        exit(1);
    }
}

int budgetStudentsAmount(int &studentsAmmount) {
    return floor(studentsAmmount*0.4);
}

