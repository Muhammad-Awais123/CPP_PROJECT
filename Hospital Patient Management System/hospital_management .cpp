#include <iostream>
#include <string>
using namespace std;

int main() {

    // ===== HOSPITAL PATIENT MANAGEMENT SYSTEM =====

    int totalPatients;
    int totalDays = 7; // one week temperature record

    cout << "========================================" << endl;
    cout << "    CITY HOSPITAL MANAGEMENT SYSTEM     " << endl;
    cout << "========================================" << endl;

    // USER INPUT - How many patients
    cout << "Enter number of patients to admit (max 5): ";
    cin >> totalPatients;

    if (totalPatients < 1 || totalPatients > 5) {
        cout << "Invalid! Enter between 1 and 5." << endl;
        return 0;
    }

    // 1D Arrays
    string patientName[5];
    int patientAge[5];
    string disease[5];
    int wardNo[5];
    float dailyCharge[5];
    int daysAdmitted[5];
    float totalBill[5];

    // 2D Array - Daily Temperature [patient][day]
    float temperature[5][7];

    cout << endl;
    cout << "-------- ENTER PATIENT DATA ------------" << endl;

    // USER INPUT - Patient details and temperature readings
    for (int i = 0; i < totalPatients; i++) {
        cout << endl;
        cout << "=== Patient " << i + 1 << " ===" << endl;

        cout << "Name        : ";
        cin >> patientName[i];

        cout << "Age         : ";
        cin >> patientAge[i];

        cout << "Disease     : ";
        cin >> disease[i];

        cout << "Ward No (1-5): ";
        cin >> wardNo[i];

        if (wardNo[i] < 1 || wardNo[i] > 5) {
            cout << "Invalid ward! Setting to Ward 1." << endl;
            wardNo[i] = 1;
        }

        cout << "Daily Charge (Rs.): ";
        cin >> dailyCharge[i];

        cout << "Days Admitted : ";
        cin >> daysAdmitted[i];

        // Calculate bill
        totalBill[i] = daysAdmitted[i] * dailyCharge[i];

        // USER INPUT - 7 days temperature
        cout << "Enter 7-day temperature readings (in F) for " << patientName[i] << ":" << endl;
        for (int j = 0; j < totalDays; j++) {
            cout << "  Day " << j + 1 << ": ";
            cin >> temperature[i][j];
        }
    }

    // Display patient records
    cout << endl;
    cout << "========================================" << endl;
    cout << "          PATIENT RECORDS               " << endl;
    cout << "========================================" << endl;
    cout << "No. Name\t\tAge\tWard\tDisease\t\tDays\tBill" << endl;
    cout << "------------------------------------------------------------------------" << endl;

    for (int i = 0; i < totalPatients; i++) {
        cout << i + 1 << ".  " << patientName[i] << "\t\t" << patientAge[i] << "\t" << wardNo[i] << "\t" << disease[i] << "\t\t" << daysAdmitted[i] << "\tRs." << totalBill[i] << endl;
    }

    cout << "------------------------------------------------------------------------" << endl;

    // Display Temperature Chart using 2D array
    cout << endl;
    cout << "======== WEEKLY TEMPERATURE RECORD (F) ========" << endl;
    cout << "Patient Name\t\tD1\tD2\tD3\tD4\tD5\tD6\tD7" << endl;
    cout << "-------------------------------------------------------------------" << endl;

    for (int i = 0; i < totalPatients; i++) {
        cout << patientName[i] << "\t\t";
        for (int j = 0; j < totalDays; j++) {
            cout << temperature[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "-------------------------------------------------------------------" << endl;

    // Fever alert using 2D array
    cout << endl;
    cout << "======= FEVER ALERT REPORT =============" << endl;

    for (int i = 0; i < totalPatients; i++) {
        int feverDays = 0;
        float maxTemp = temperature[i][0];

        for (int j = 0; j < totalDays; j++) {
            if (temperature[i][j] > 100.0) {
                feverDays = feverDays + 1;
            }
            if (temperature[i][j] > maxTemp) {
                maxTemp = temperature[i][j];
            }
        }

        cout << patientName[i] << ": ";
        if (feverDays > 0) {
            cout << "Fever for " << feverDays << " day(s). Max: " << maxTemp << "F";
            if (maxTemp >= 103.0) {
                cout << " [CRITICAL]";
            } else if (maxTemp >= 101.0) {
                cout << " [HIGH]";
            } else {
                cout << " [MILD]";
            }
        } else {
            cout << "No fever. STABLE";
        }
        cout << endl;
    }

    cout << "========================================" << endl;

    // Financial summary
    float totalRevenue = 0;
    float highBill = totalBill[0];
    float lowBill = totalBill[0];
    int highIndex = 0;
    int lowIndex = 0;

    for (int i = 0; i < totalPatients; i++) {
        totalRevenue = totalRevenue + totalBill[i];
        if (totalBill[i] > highBill) {
            highBill = totalBill[i];
            highIndex = i;
        }
        if (totalBill[i] < lowBill) {
            lowBill = totalBill[i];
            lowIndex = i;
        }
    }

    // Ward count using 1D array
    int wardCount[6] = {0, 0, 0, 0, 0, 0}; // index 1-5 used

    for (int i = 0; i < totalPatients; i++) {
        wardCount[wardNo[i]] = wardCount[wardNo[i]] + 1;
    }

    cout << endl;
    cout << "======= HOSPITAL SUMMARY ===============" << endl;
    cout << "Total Patients  : " << totalPatients << endl;
    cout << "Total Revenue   : Rs." << totalRevenue << endl;
    cout << "Highest Bill    : " << patientName[highIndex] << " - Rs." << highBill << endl;
    cout << "Lowest Bill     : " << patientName[lowIndex] << " - Rs." << lowBill << endl;
    cout << endl;
    cout << "--- Ward Occupancy ---" << endl;
    for (int w = 1; w <= 5; w++) {
        cout << "Ward " << w << ": " << wardCount[w] << " patient(s)" << endl;
    }
    cout << "========================================" << endl;

    // Age group analysis using 1D array
    int youngCount = 0;
    int adultCount = 0;
    int seniorCount = 0;

    for (int i = 0; i < totalPatients; i++) {
        if (patientAge[i] < 30) {
            youngCount = youngCount + 1;
        } else if (patientAge[i] <= 50) {
            adultCount = adultCount + 1;
        } else {
            seniorCount = seniorCount + 1;
        }
    }

    cout << endl;
    cout << "======= AGE GROUP ANALYSIS =============" << endl;
    cout << "Young  (below 30)  : " << youngCount << " patient(s)" << endl;
    cout << "Adult  (30 to 50)  : " << adultCount << " patient(s)" << endl;
    cout << "Senior (above 50)  : " << seniorCount << " patient(s)" << endl;
    cout << "========================================" << endl;

    // USER INPUT - Search a patient by name
    cout << endl;
    cout << "------- SEARCH PATIENT -----------------" << endl;
    string searchName;
    cout << "Enter patient name to search: ";
    cin >> searchName;

    int found = -1;
    for (int i = 0; i < totalPatients; i++) {
        if (patientName[i] == searchName) {
            found = i;
        }
    }

    if (found == -1) {
        cout << "Patient \"" << searchName << "\" not found!" << endl;
    } else {
        cout << endl;
        cout << "==== Patient Found! ====" << endl;
        cout << "Name        : " << patientName[found] << endl;
        cout << "Age         : " << patientAge[found] << endl;
        cout << "Disease     : " << disease[found] << endl;
        cout << "Ward No     : " << wardNo[found] << endl;
        cout << "Days        : " << daysAdmitted[found] << endl;
        cout << "Total Bill  : Rs." << totalBill[found] << endl;
        cout << "Temperatures: ";
        for (int j = 0; j < totalDays; j++) {
            cout << temperature[found][j] << "F ";
        }
        cout << endl;
    }

    cout << "========================================" << endl;

    return 0;
}
