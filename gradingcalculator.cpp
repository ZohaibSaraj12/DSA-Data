#include <iostream>
using namespace std;

// Function to convert marks to Grade Points
double getGradePoint(int marks) {
    if (marks >= 85) return 4.00;
    else if (marks == 84) return 3.94;
    else if (marks == 83) return 3.87;
    else if (marks == 82) return 3.80;
    else if (marks == 81) return 3.74;
    else if (marks == 80) return 3.67;
    else if (marks == 79) return 3.60;
    else if (marks == 78) return 3.53;
    else if (marks == 77) return 3.47;
    else if (marks == 76) return 3.40;
    else if (marks == 75) return 3.34;
    else if (marks == 74) return 3.27;
    else if (marks == 73) return 3.20;
    else if (marks == 72) return 3.14;
    else if (marks == 71) return 3.07;
    else if (marks == 70) return 3.00;
    else if (marks == 69) return 2.95;
    else if (marks == 68) return 2.90;
    else if (marks == 67) return 2.85;
    else if (marks == 66) return 2.80;
    else if (marks == 65) return 2.75;
    else if (marks == 64) return 2.70;
    else if (marks == 63) return 2.63;
    else if (marks == 62) return 2.60;
    else if (marks == 61) return 2.55;
    else if (marks == 60) return 2.50;
    else if (marks == 59) return 2.40;
    else if (marks == 58) return 2.30;
    else if (marks == 57) return 2.20;
    else if (marks == 56) return 2.10;
    else if (marks == 55) return 2.00;
    else if (marks == 54) return 1.90;
    else if (marks == 53) return 1.80;
    else if (marks == 52) return 1.70;
    else if (marks == 51) return 1.60;
    else if (marks == 50) return 1.50;
    else return 0.00; // Below 50 = Fail
}

// Function to calculate GPA for Semester 3
double calculateSemester3GPA() {
    string subjects[] = {"Economics", "Statistics", "Software Engineering", "DSA", "Operating Systems"};
    int creditHours[] = {2, 3, 3, 4, 3}; // Credit hours for each subject
    int marks[5];
    double totalGradePoints = 0, totalCredits = 0;

    cout << "\nEnter marks for Semester 3:\n";
    for (int i = 0; i < 5; i++) {
        cout << subjects[i] << " (" << creditHours[i] << " credit hours): ";
        cin >> marks[i];

        totalGradePoints += getGradePoint(marks[i]) * creditHours[i];
        totalCredits += creditHours[i];
    }

    double gpa = totalGradePoints / totalCredits;
    return gpa;
}

int main() {
    cout << "===== Semester 3 GPA Calculator =====\n";

    char choice;
    int studentNumber = 1;

    do {
        cout << "\n=== Enter data for Student " << studentNumber << " ===\n";

        // Calculate GPA for Semester 3
        double gpa3 = calculateSemester3GPA();
        cout << "\nGPA for Semester 3: " << gpa3 << endl;

        cout << "\nDo you want to enter another student's data? (y/n): ";
        cin >> choice;
        studentNumber++;

    } while (choice == 'y' || choice == 'Y');

    cout << "\n===== Program Ended =====\n";

    return 0;
}
 
 
 
 
 

 
 