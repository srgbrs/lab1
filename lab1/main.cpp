#include <iostream>
#include "Header.h"
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {

    ifstream input("/Users/apple/Desktop/lab1/lab1/students.csv");
    
    int q1 = studentsAmmount(input);
    int q2 = budgetStudentsAmount(q1);
    
    student *allStudents = new student[q1];
    readFile(input, q1, allStudents);
    
    student *budgetStudents = new student[q1];
    
    fillBudget(allStudents, budgetStudents, q1);
    sortStudents(q1, budgetStudents);
    
    showStipuha(budgetStudents, q2);
    
    return 0;
}
