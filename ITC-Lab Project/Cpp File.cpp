#include <string>
#include <iostream>

using namespace std;

int main() {
    const int MAX_STUDENTS = 100;
    const int NUM_SUBJECTS = 5;
    
    string studentUsernames[MAX_STUDENTS];
    string studentPasswords[MAX_STUDENTS];
    string studentNames[MAX_STUDENTS];
    int studentRollNos[MAX_STUDENTS];
    int studentAttendance[MAX_STUDENTS];
    int studentMarks[MAX_STUDENTS][NUM_SUBJECTS];
    int studentCount = 0;
    
    string teacherUsername = "teacher";
    string teacherPassword = "teacher123";
    
    string subjects[NUM_SUBJECTS] = {"Maths", "Physics", "Chemistry", "English", "Computer"};
    
    string username, password, name;
    int rollNo, attendance;
    int marks[NUM_SUBJECTS];
    int choice, subChoice, index;
    bool found;
    
    // Add sample students
    studentUsernames[0] = "awais";
    studentPasswords[0] = "123";
    studentNames[0] = "Awais Zafar";
    studentRollNos[0] = 101;
    studentAttendance[0] = 85;
    studentMarks[0][0] = 85;
    studentMarks[0][1] = 78;
    studentMarks[0][2] = 92;
    studentMarks[0][3] = 88;
    studentMarks[0][4] = 90;
    studentCount++;
    
    studentUsernames[1] = "abdulrehman";
    studentPasswords[1] = "456";
    studentNames[1] = "Abdul Rehman Chishti";
    studentRollNos[1] = 102;
    studentAttendance[1] = 92;
    studentMarks[1][0] = 92;
    studentMarks[1][1] = 85;
    studentMarks[1][2] = 88;
    studentMarks[1][3] = 95;
    studentMarks[1][4] = 89;
    studentCount++;
    
    bool exitProgram = false;
    
    while (!exitProgram) {
        cout << "\n================================\n";
        cout << "STUDENT-TEACHER PORTAL\n";
        cout << "================================\n";
        cout << "1. Student Login\n";
        cout << "2. Teacher Login\n";
        cout << "3. Student Registration\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 1) {  // Student Login
            cout << "\n--- STUDENT LOGIN ---\n";
            cout << "Enter Username: ";
            cin >> username;
            cout << "Enter Password: ";
            cin >> password;
            
            found = false;
            index = -1;
            
            for (int i = 0; i < studentCount; i++) {
                if (studentUsernames[i] == username && studentPasswords[i] == password) {
                    found = true;
                    index = i;
                    break;
                }
            }
            
            if (found) {
                cout << "\nWelcome, " << studentNames[index] << "!\n";
                
                bool studentLoggedIn = true;
                while (studentLoggedIn) {
                    cout << "\n--- STUDENT MENU ---\n";
                    cout << "1. View Attendance\n";
                    cout << "2. View Marks\n";
                    cout << "3. View Profile\n";
                    cout << "4. Logout\n";
                    cout << "Enter choice: ";
                    cin >> subChoice;
                    
                    if (subChoice == 1) {  // View Attendance
                        cout << "\n--- ATTENDANCE ---\n";
                        cout << "Name: " << studentNames[index] << endl;
                        cout << "Roll No: " << studentRollNos[index] << endl;
                        cout << "Attendance: " << studentAttendance[index] << "%\n";
                        
                        if (studentAttendance[index] >= 75) {
                            cout << "Status: Good\n";
                        } else {
                            cout << "Status: Low\n";
                        }
                    }
                    else if (subChoice == 2) {  // View Marks
                        cout << "\n--- MARKS ---\n";
                        cout << "Name: " << studentNames[index] << endl;
                        cout << "Roll No: " << studentRollNos[index] << endl;
                        
                        int total = 0;
                        for (int i = 0; i < NUM_SUBJECTS; i++) {
                            cout << subjects[i] << ": " << studentMarks[index][i] << "/100\n";
                            total += studentMarks[index][i];
                        }
                        
                        cout << "Total: " << total << "/500\n";
                        cout << "Average: " << (total/NUM_SUBJECTS) << "/100\n";
                        
                        // Simple grade calculation
                        int average = total / NUM_SUBJECTS;
                        cout << "Grade: ";
                        if (average >= 90) cout << "A+";
                        else if (average >= 80) cout << "A";
                        else if (average >= 70) cout << "B";
                        else if (average >= 60) cout << "C";
                        else if (average >= 50) cout << "D";
                        else cout << "F";
                        cout << endl;
                    }
                    else if (subChoice == 3) {  // View Profile
                        cout << "\n--- PROFILE ---\n";
                        cout << "Name: " << studentNames[index] << endl;
                        cout << "Username: " << studentUsernames[index] << endl;
                        cout << "Roll No: " << studentRollNos[index] << endl;
                        cout << "Attendance: " << studentAttendance[index] << "%\n";
                        
                        int total = 0;
                        for (int i = 0; i < NUM_SUBJECTS; i++) {
                            total += studentMarks[index][i];
                        }
                        cout << "Average Marks: " << (total/NUM_SUBJECTS) << "/100\n";
                    }
                    else if (subChoice == 4) {  // Logout
                        cout << "\nLogging out...\n";
                        studentLoggedIn = false;
                    }
                    else {
                        cout << "Invalid choice!\n";
                    }
                }
            } else {
                cout << "Invalid login!\n";
            }
        }
        else if (choice == 2) {  // Teacher Login
            cout << "\n--- TEACHER LOGIN ---\n";
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;
            
            if (username == teacherUsername && password == teacherPassword) {
                cout << "\nWelcome Teacher!\n";
                
                bool teacherLoggedIn = true;
                while (teacherLoggedIn) {
                    cout << "\n--- TEACHER MENU ---\n";
                    cout << "1. Update Attendance\n";
                    cout << "2. Update Marks\n";
                    cout << "3. View All Students\n";
                    cout << "4. Add New Student\n";
                    cout << "5. Logout\n";
                    cout << "Enter choice: ";
                    cin >> subChoice;
                    
                    if (subChoice == 1) {  // Update Attendance
                        if (studentCount == 0) {
                            cout << "No students!\n";
                        } else {
                            cout << "\n--- UPDATE ATTENDANCE ---\n";
                            cout << "Student List:\n";
                            for (int i = 0; i < studentCount; i++) {
                                cout << (i+1) << ". " << studentNames[i] << " (Roll: " << studentRollNos[i] << ")\n";
                            }
                            
                            int studentNo;
                            cout << "Enter student number: ";
                            cin >> studentNo;
                            
                            if (studentNo > 0 && studentNo <= studentCount) {
                                cout << "Current attendance: " << studentAttendance[studentNo-1] << "%\n";
                                cout << "Enter new attendance: ";
                                cin >> attendance;
                                
                                if (attendance >= 0 && attendance <= 100) {
                                    studentAttendance[studentNo-1] = attendance;
                                    cout << "Updated!\n";
                                } else {
                                    cout << "Invalid!\n";
                                }
                            } else {
                                cout << "Invalid student number!\n";
                            }
                        }
                    }
                    else if (subChoice == 2) {  // Update Marks
                        if (studentCount == 0) {
                            cout << "No students!\n";
                        } else {
                            cout << "\n--- UPDATE MARKS ---\n";
                            cout << "Student List:\n";
                            for (int i = 0; i < studentCount; i++) {
                                cout << (i+1) << ". " << studentNames[i] << " (Roll: " << studentRollNos[i] << ")\n";
                            }
                            
                            int studentNo;
                            cout << "Enter student number: ";
                            cin >> studentNo;
                            
                            if (studentNo > 0 && studentNo <= studentCount) {
                                int idx = studentNo - 1;
                                cout << "Updating marks for " << studentNames[idx] << ":\n";
                                
                                for (int i = 0; i < NUM_SUBJECTS; i++) {
                                    cout << subjects[i] << " (current: " << studentMarks[idx][i] << "): ";
                                    cin >> marks[i];
                                    
                                    if (marks[i] >= 0 && marks[i] <= 100) {
                                        studentMarks[idx][i] = marks[i];
                                    } else {
                                        cout << "Invalid! Keeping old marks.\n";
                                    }
                                }
                                cout << "Marks updated!\n";
                            } else {
                                cout << "Invalid student number!\n";
                            }
                        }
                    }
                    else if (subChoice == 3) {  // View All Students
                        if (studentCount == 0) {
                            cout << "No students!\n";
                        } else {
                            cout << "\n--- ALL STUDENTS ---\n";
                            cout << "Total: " << studentCount << " students\n";
                            
                            for (int i = 0; i < studentCount; i++) {
                                cout << "\nStudent " << (i+1) << ":\n";
                                cout << "Name: " << studentNames[i] << endl;
                                cout << "Roll No: " << studentRollNos[i] << endl;
                                cout << "Attendance: " << studentAttendance[i] << "%\n";
                                cout << "Marks: ";
                                
                                int total = 0;
                                for (int j = 0; j < NUM_SUBJECTS; j++) {
                                    cout << subjects[j] << ":" << studentMarks[i][j] << " ";
                                    total += studentMarks[i][j];
                                }
                                cout << "\nAverage: " << (total/NUM_SUBJECTS) << "/100\n";
                            }
                        }
                    }
                    else if (subChoice == 4) {  // Add New Student
                        if (studentCount >= MAX_STUDENTS) {
                            cout << "Maximum students reached!\n";
                        } else {
                            cout << "\n--- ADD NEW STUDENT ---\n";
                            
                            bool usernameExists;
                            do {
                                usernameExists = false;
                                cout << "Username: ";
                                cin >> username;
                                
                                for (int i = 0; i < studentCount; i++) {
                                    if (studentUsernames[i] == username) {
                                        cout << "Username taken! Try again.\n";
                                        usernameExists = true;
                                        break;
                                    }
                                }
                                
                                if (username == teacherUsername) {
                                    cout << "Username taken! Try again.\n";
                                    usernameExists = true;
                                }
                            } while (usernameExists);
                            
                            cout << "Password: ";
                            cin >> password;
                            cout << "Name: ";
                            cin >> name;
                            cout << "Roll Number: ";
                            cin >> rollNo;
                            
                            studentUsernames[studentCount] = username;
                            studentPasswords[studentCount] = password;
                            studentNames[studentCount] = name;
                            studentRollNos[studentCount] = rollNo;
                            studentAttendance[studentCount] = 0;
                            
                            for (int i = 0; i < NUM_SUBJECTS; i++) {
                                studentMarks[studentCount][i] = 0;
                            }
                            
                            studentCount++;
                            cout << "Student added!\n";
                        }
                    }
                    else if (subChoice == 5) {  // Logout
                        cout << "\nLogging out...\n";
                        teacherLoggedIn = false;
                    }
                    else {
                        cout << "Invalid choice!\n";
                    }
                }
            } else {
                cout << "Invalid login!\n";
            }
        }
        else if (choice == 3) {  // Student Registration
            if (studentCount >= MAX_STUDENTS) {
                cout << "Maximum students reached!\n";
            } else {
                cout << "\n--- STUDENT REGISTRATION ---\n";
                
                bool usernameExists;
                do {
                    usernameExists = false;
                    cout << "Username: ";
                    cin >> username;
                    
                    for (int i = 0; i < studentCount; i++) {
                        if (studentUsernames[i] == username) {
                            cout << "Username taken! Try again.\n";
                            usernameExists = true;
                            break;
                        }
                    }
                    
                    if (username == teacherUsername) {
                        cout << "Username taken! Try again.\n";
                        usernameExists = true;
                    }
                } while (usernameExists);
                
                cout << "Password: ";
                cin >> password;
                cout << "Name: ";
                cin >> name;
                cout << "Roll Number: ";
                cin >> rollNo;
                
                studentUsernames[studentCount] = username;
                studentPasswords[studentCount] = password;
                studentNames[studentCount] = name;
                studentRollNos[studentCount] = rollNo;
                studentAttendance[studentCount] = 0;
                
                for (int i = 0; i < NUM_SUBJECTS; i++) {
                    studentMarks[studentCount][i] = 0;
                }
                
                studentCount++;
                cout << "Registration successful!\n";
            }
        }
        else if (choice == 4) {  // Exit
            cout << "\nThank you for using the portal!\n";
            exitProgram = true;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }
    
    return 0;
}
