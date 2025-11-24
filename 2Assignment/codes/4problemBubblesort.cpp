
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

struct Student_asr {
    string name_asr;
    int marks_asr;
    int rollNo_asr;
};

// Function to display student records
void display_asr(Student_asr* students_asr, int n_asr) {
    cout << left << setw(10) << "Name" << setw(10) << "Marks" << setw(10) << "Roll No" << endl;
    for (int i_asr = 0; i_asr < n_asr; i_asr++) {
        cout << left << setw(10) << students_asr[i_asr].name_asr
             << setw(10) << students_asr[i_asr].marks_asr
             << setw(10) << students_asr[i_asr].rollNo_asr << endl;
    }
    cout << endl;
}

// Bubble Sort function
void bubbleSort_asr(Student_asr* students_asr, int n_asr) {
    for (int i_asr = 0; i_asr < n_asr - 1; i_asr++) {
        bool swapped_asr = false;
        cout << "After Pass " << i_asr + 1 << ":" << endl;

        for (int j_asr = 0; j_asr < n_asr - i_asr - 1; j_asr++) {
            if (students_asr[j_asr].marks_asr < students_asr[j_asr + 1].marks_asr) {
                cout << "Swapped: " << students_asr[j_asr].name_asr << " (" << students_asr[j_asr].marks_asr
                     << ") ↔ " << students_asr[j_asr + 1].name_asr << " (" << students_asr[j_asr + 1].marks_asr << ")\n";
                swap(students_asr[j_asr], students_asr[j_asr + 1]);
                swapped_asr = true;
            }
        }

        display_asr(students_asr, n_asr);

        if (!swapped_asr) break;
    }
}

int main() {
    srand(time(0));

    int n_asr;
    cout << "Enter number of students: ";
    cin >> n_asr;

    const char* names_asr[] = {"Abir","Aarav","Isha","Rohan","Priya","Vikas","Neha","Sahil",
                               "Anaya","Dev","Kriti","Mira","Kabir","Tanvi","Yash","Riya",
                               "Arjun","Asha","Nikhil","Pooja","Kunal","Vishal","Amir","Sharukh",
                               "Salman","Mrunal","Kirti"};
    const int N_NAMES_asr = sizeof(names_asr) / sizeof(names_asr[0]);

    Student_asr* students_asr = new Student_asr[n_asr];

    // Generate random marks
    for (int i_asr = 0; i_asr < n_asr; i_asr++) {
        students_asr[i_asr].name_asr = names_asr[rand() % N_NAMES_asr];
        students_asr[i_asr].marks_asr = rand() % 100 + 1;  // marks between 1 and 100
        students_asr[i_asr].rollNo_asr = 0;
    }

    cout << "\nInitial Student Records:\n";
    display_asr(students_asr, n_asr);

    bubbleSort_asr(students_asr, n_asr);

    // Assign roll numbers (1 to n)
    for (int i_asr = 0; i_asr < n_asr; i_asr++) {
        students_asr[i_asr].rollNo_asr = i_asr + 1;
    }

    cout << "Final Sorted Records (Topper has Roll No. 1):\n";
    display_asr(students_asr, n_asr);

    delete[] students_asr;
    return 0;
}