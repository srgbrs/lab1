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

bool isNumber(string &line) {
    char a;
    if (line == "") return false;
    
    for (int i=0; i<line.length(); i++)
    {
        a = line[i];
        if (!isdigit(a))
            return false;
    }
    return true;
}

student scanLine(string line) {
    student p;
    string lexem;
    int counter = 0;
    p.averageMark = 0.0;
    
    for (int i=0; i<=line.length(); i++) {
        if (line[i] == ',' || line[i] == '\0')
        {
            if (isNumber(lexem))
            {
                p.marks[counter++] = stoi(lexem);
                p.averageMark = p.averageMark + stoi(lexem);
            }
            else if (lexem == "TRUE" || lexem == "FALSE")
            {
                p.isContract = (lexem == "TRUE" ? true : false);
            }
            else
            {
                p.name = lexem;
            }
            lexem = "";
        }
        else
            lexem += line[i];
    }
    p.averageMark = p.averageMark / 5;
    return p;
}

void readFile(ifstream &input, int ammount, student *allStudents) {
    string l;
    getline(input, l);
    for (int i=0; i<ammount; i++) {
        getline(input, l);
        allStudents[i] = scanLine(l);
    }
}
