#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

enum Speciality {
    CS,     // Computer Science
    IT,     // Informatics
    ME,     // Mathematics and Economics
    PI,     // Physics and Informatics
    LT      // Labor Training
};

string specialityToString(Speciality sp) {
    switch (sp) {
    case CS: return "Computer Science";
    case IT: return "Informatics";
    case ME: return "Mathematics and Economics";
    case PI: return "Physics and Informatics";
    case LT: return "Labor Training";
    default: return "Unknown";
    }
}

// Level A
struct StudentA {
    string lastName;
    int course;
    Speciality speciality;
    int physics;
    int math;
    int informatics;
};

void inputStudentA(vector<StudentA>& students, int n) {
    for (int i = 0; i < n; i++) {
        StudentA s;
        cout << "\nStudent #" << (i + 1) << endl;
        cout << "Last name: ";
        cin >> s.lastName;
        cout << "Course: ";
        cin >> s.course;

        int spec;
        cout << "Speciality (0-CS, 1-IT, 2-ME, 3-PI, 4-LT): ";
        cin >> spec;
        s.speciality = static_cast<Speciality>(spec);

        cout << "Physics grade: ";
        cin >> s.physics;
        cout << "Math grade: ";
        cin >> s.math;
        cout << "Informatics grade: ";
        cin >> s.informatics;

        students.push_back(s);
    }
}

void printTableA(const vector<StudentA>& students) {
    cout << "\nStudent Table (Level A):\n";
    cout << left << setw(5) << "#"
        << setw(15) << "Last Name"
        << setw(6) << "Course"
        << setw(25) << "Speciality"
        << setw(8) << "Physics"
        << setw(10) << "Math"
        << setw(13) << "Informatics" << endl;

    for (size_t i = 0; i < students.size(); i++) {
        const StudentA& s = students[i];
        cout << setw(5) << (i + 1)
            << setw(15) << s.lastName
            << setw(6) << s.course
            << setw(25) << specialityToString(s.speciality)
            << setw(8) << s.physics
            << setw(10) << s.math
            << setw(13) << s.informatics << endl;
    }
}

void calculateAveragesA(const vector<StudentA>& students, double& avgPhys, double& avgMath, double& avgInfo) {
    int totalPhys = 0, totalMath = 0, totalInfo = 0;
    for (const auto& s : students) {
        totalPhys += s.physics;
        totalMath += s.math;
        totalInfo += s.informatics;
    }
    int n = students.size();
    avgPhys = (double)totalPhys / n;
    avgMath = (double)totalMath / n;
    avgInfo = (double)totalInfo / n;
}

int countGoodStudentsA(const vector<StudentA>& students) {
    int count = 0;
    for (const auto& s : students) {
        if (s.physics == 4 || s.physics == 5)
            count++;
    }
    return count;
}

// Level B
union ThirdMark {
    int programming;
    int numericalMethods;
    int pedagogy;
};

struct StudentB {
    string lastName;
    int course;
    Speciality speciality;
    int physics;
    int math;
    ThirdMark third;
};

void inputStudentB(vector<StudentB>& students, int n) {
    for (int i = 0; i < n; i++) {
        StudentB s;
        cout << "\nStudent #" << (i + 1) << endl;
        cout << "Last name: ";
        cin >> s.lastName;
        cout << "Course: ";
        cin >> s.course;

        int spec;
        cout << "Speciality (0-CS, 1-IT, 2-ME, 3-PI, 4-LT): ";
        cin >> spec;
        s.speciality = static_cast<Speciality>(spec);

        cout << "Physics grade: ";
        cin >> s.physics;
        cout << "Math grade: ";
        cin >> s.math;

        if (s.speciality == CS) {
            cout << "Programming grade: ";
            cin >> s.third.programming;
        }
        else if (s.speciality == IT) {
            cout << "Numerical methods grade: ";
            cin >> s.third.numericalMethods;
        }
        else {
            cout << "Pedagogy grade: ";
            cin >> s.third.pedagogy;
        }

        students.push_back(s);
    }
}

void printTableB(const vector<StudentB>& students) {
    cout << "\nStudent Table (Level B):\n";
    cout << left << setw(5) << "#"
        << setw(15) << "Last Name"
        << setw(6) << "Course"
        << setw(25) << "Speciality"
        << setw(8) << "Physics"
        << setw(10) << "Math"
        << setw(10) << "Prog."
        << setw(10) << "NumMeth"
        << setw(10) << "Pedagogy" << endl;

    for (size_t i = 0; i < students.size(); i++) {
        const StudentB& s = students[i];
        cout << setw(5) << (i + 1)
            << setw(15) << s.lastName
            << setw(6) << s.course
            << setw(25) << specialityToString(s.speciality)
            << setw(8) << s.physics
            << setw(10) << s.math;

        if (s.speciality == CS)
            cout << setw(10) << s.third.programming << setw(10) << "-" << setw(10) << "-";
        else if (s.speciality == IT)
            cout << setw(10) << "-" << setw(10) << s.third.numericalMethods << setw(10) << "-";
        else
            cout << setw(10) << "-" << setw(10) << "-" << setw(10) << s.third.pedagogy;

        cout << endl;
    }
}

void calculateAveragesB(const vector<StudentB>& students, double& avgPhys, double& avgMath) {
    int totalPhys = 0, totalMath = 0;
    for (const auto& s : students) {
        totalPhys += s.physics;
        totalMath += s.math;
    }
    int n = students.size();
    avgPhys = (double)totalPhys / n;
    avgMath = (double)totalMath / n;
}

int countGoodStudentsB(const vector<StudentB>& students) {
    int count = 0;
    for (const auto& s : students) {
        if (s.physics == 4 || s.physics == 5)
            count++;
    }
    return count;
}

int main() {
    int level;
    cout << "Choose level (1 - A, 2 - B): ";
    cin >> level;

    int n;
    cout << "Number of students: ";
    cin >> n;

    if (level == 1) {
        vector<StudentA> students;
        inputStudentA(students, n);
        printTableA(students);

        double avgPhys, avgMath, avgInfo;
        calculateAveragesA(students, avgPhys, avgMath, avgInfo);
        cout << fixed << setprecision(2);
        cout << "\nAverage grades:\nPhysics: " << avgPhys << "\nMath: " << avgMath << "\nInformatics: " << avgInfo << endl;

        int good = countGoodStudentsA(students);
        cout << "Number of students with grade 4 or 5 in physics: " << good << endl;

    }
    else {
        vector<StudentB> students;
        inputStudentB(students, n);
        printTableB(students);

        double avgPhys, avgMath;
        calculateAveragesB(students, avgPhys, avgMath);
        cout << fixed << setprecision(2);
        cout << "\nAverage grades:\nPhysics: " << avgPhys << "\nMath: " << avgMath << endl;

        int good = countGoodStudentsB(students);
        cout << "Number of students with grade 4 or 5 in physics: " << good << endl;
    }

    return 0;
}