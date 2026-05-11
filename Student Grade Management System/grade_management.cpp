#include <iostream>
#include <string>
using namespace std;

int main() {

    // ===== STUDENT GRADE MANAGEMENT SYSTEM =====

    int totalStudents;
    int totalSubjects = 4;

    // 1D Array - Subject Names (fixed)
    string subjectNames[4] = {"Math", "Physics", "English", "Computer"};

    cout << "========================================" << endl;
    cout << "    STUDENT GRADE MANAGEMENT SYSTEM     " << endl;
    cout << "========================================" << endl;

    // USER INPUT - How many students
    cout << "How many students do you want to enter? (max 10): ";
    cin >> totalStudents;

    if (totalStudents < 1 || totalStudents > 10) {
        cout << "Invalid number! Please enter between 1 and 10." << endl;
        return 0;
    }

    // 1D Arrays - declared with max size 10
    string studentNames[10];
    int totalMarks[10];
    float percentage[10];
    char grade[10];

    // 2D Array - Marks [student][subject]
    int marks[10][4];

    cout << endl;
    cout << "-------- ENTER STUDENT DATA ------------" << endl;

    // USER INPUT - Student names and marks
    for (int i = 0; i < totalStudents; i++) {
        cout << endl;
        cout << "Student " << i + 1 << " Name: ";
        cin >> studentNames[i];

        cout << "Enter marks for " << studentNames[i] << " (out of 100 each):" << endl;

        for (int j = 0; j < totalSubjects; j++) {
            cout << "  " << subjectNames[j] << ": ";
            cin >> marks[i][j];

            if (marks[i][j] < 0 || marks[i][j] > 100) {
                cout << "  Invalid! Setting to 0." << endl;
                marks[i][j] = 0;
            }
        }
    }

    // Calculate total marks, percentage, and grade
    for (int i = 0; i < totalStudents; i++) {
        totalMarks[i] = 0;

        for (int j = 0; j < totalSubjects; j++) {
            totalMarks[i] = totalMarks[i] + marks[i][j];
        }

        percentage[i] = (totalMarks[i] / 400.0) * 100;

        if (percentage[i] >= 90) {
            grade[i] = 'A';
        } else if (percentage[i] >= 80) {
            grade[i] = 'B';
        } else if (percentage[i] >= 70) {
            grade[i] = 'C';
        } else if (percentage[i] >= 60) {
            grade[i] = 'D';
        } else {
            grade[i] = 'F';
        }
    }

    // Display result table
    cout << endl;
    cout << "========================================" << endl;
    cout << "              RESULT CARD               " << endl;
    cout << "========================================" << endl;
    cout << "Name\t\t";
    for (int j = 0; j < totalSubjects; j++) {
        cout << subjectNames[j] << "\t";
    }
    cout << "Total\tPercent\tGrade" << endl;
    cout << "-----------------------------------------------------------------------" << endl;

    for (int i = 0; i < totalStudents; i++) {
        cout << studentNames[i] << "\t\t";
        for (int j = 0; j < totalSubjects; j++) {
            cout << marks[i][j] << "\t";
        }
        cout << totalMarks[i] << "\t" << percentage[i] << "%\t" << grade[i] << endl;
    }

    cout << "-----------------------------------------------------------------------" << endl;

    // Find highest and lowest scoring student
    int highestMarks = totalMarks[0];
    int highestIndex = 0;
    int lowestMarks = totalMarks[0];
    int lowestIndex = 0;

    for (int i = 1; i < totalStudents; i++) {
        if (totalMarks[i] > highestMarks) {
            highestMarks = totalMarks[i];
            highestIndex = i;
        }
        if (totalMarks[i] < lowestMarks) {
            lowestMarks = totalMarks[i];
            lowestIndex = i;
        }
    }

    // Count pass / fail
    int passCount = 0;
    int failCount = 0;

    for (int i = 0; i < totalStudents; i++) {
        if (percentage[i] >= 60) {
            passCount = passCount + 1;
        } else {
            failCount = failCount + 1;
        }
    }

    // Summary
    cout << endl;
    cout << "============ RESULT SUMMARY ============" << endl;
    cout << "Top Student    : " << studentNames[highestIndex] << " (" << percentage[highestIndex] << "%)" << endl;
    cout << "Lowest Student : " << studentNames[lowestIndex] << " (" << percentage[lowestIndex] << "%)" << endl;
    cout << "Total Pass     : " << passCount << " student(s)" << endl;
    cout << "Total Fail     : " << failCount << " student(s)" << endl;
    cout << "========================================" << endl;

    // Subject-wise topper using 2D array
    cout << endl;
    cout << "======= SUBJECT WISE TOPPER ============" << endl;

    for (int j = 0; j < totalSubjects; j++) {
        int highest = marks[0][j];
        int topperIndex = 0;

        for (int i = 1; i < totalStudents; i++) {
            if (marks[i][j] > highest) {
                highest = marks[i][j];
                topperIndex = i;
            }
        }

        cout << subjectNames[j] << " Topper: " << studentNames[topperIndex] << " with " << highest << " marks" << endl;
    }

    cout << "========================================" << endl;

    // USER INPUT - Search a student by name
    cout << endl;
    cout << "------- SEARCH STUDENT -----------------" << endl;
    string searchName;
    cout << "Enter student name to search: ";
    cin >> searchName;

    int found = -1;
    for (int i = 0; i < totalStudents; i++) {
        if (studentNames[i] == searchName) {
            found = i;
        }
    }

    if (found == -1) {
        cout << "Student \"" << searchName << "\" not found!" << endl;
    } else {
        cout << endl;
        cout << "==== Student Found! ====" << endl;
        cout << "Name       : " << studentNames[found] << endl;
        cout << "Total Marks: " << totalMarks[found] << " / 400" << endl;
        cout << "Percentage : " << percentage[found] << "%" << endl;
        cout << "Grade      : " << grade[found] << endl;
        cout << "Subject Marks:" << endl;
        for (int j = 0; j < totalSubjects; j++) {
            cout << "  " << subjectNames[j] << ": " << marks[found][j] << endl;
        }
    }

    cout << "========================================" << endl;

    return 0;
}
