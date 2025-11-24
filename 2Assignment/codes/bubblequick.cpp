#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct Student_asr {
    string student_name_asr;
    int student_roll_no_asr;
    int total_marks_asr;
};

// Bubble Sort
int bubbleSort_asr(Student_asr* arr_asr, int n_asr) {
    int swapCount_asr = 0;
    for (int i_asr = 0; i_asr < n_asr - 1; i_asr++) {
        for (int j_asr = 0; j_asr < n_asr - i_asr - 1; j_asr++) {
            if (arr_asr[j_asr].student_roll_no_asr > arr_asr[j_asr + 1].student_roll_no_asr) {
                swap(arr_asr[j_asr], arr_asr[j_asr + 1]);
                swapCount_asr++;
            }
        }
    }
    return swapCount_asr;
}

// Partition for Quick Sort
int partition_asr(Student_asr* arr_asr, int low_asr, int high_asr, int &swapCount_asr) {
    int pivot_asr = arr_asr[high_asr].student_roll_no_asr;
    int i_asr = low_asr - 1;
    for (int j_asr = low_asr; j_asr < high_asr; j_asr++) {
        if (arr_asr[j_asr].student_roll_no_asr <= pivot_asr) {
            i_asr++;
            swap(arr_asr[i_asr], arr_asr[j_asr]);
            swapCount_asr++;
        }
    }
    swap(arr_asr[i_asr + 1], arr_asr[high_asr]);
    swapCount_asr++;
    return i_asr + 1;
}

// Quick Sort
void quickSort_asr(Student_asr* arr_asr, int low_asr, int high_asr, int &swapCount_asr) {
    if (low_asr < high_asr) {
        int pi_asr = partition_asr(arr_asr, low_asr, high_asr, swapCount_asr);
        quickSort_asr(arr_asr, low_asr, pi_asr - 1, swapCount_asr);
        quickSort_asr(arr_asr, pi_asr + 1, high_asr, swapCount_asr);
    }
}

// Print array
void printArray_asr(Student_asr* arr_asr, int n_asr) {
    cout << "Roll No\tName\t\tMarks\n";
    for (int i_asr = 0; i_asr < n_asr; i_asr++) {
        cout << arr_asr[i_asr].student_roll_no_asr << "\t"
             << arr_asr[i_asr].student_name_asr << "\t\t"
             << arr_asr[i_asr].total_marks_asr << endl;
    }
}

int main() {
    int n_asr;
    cout << "Enter number of students: ";
    cin >> n_asr;

    Student_asr* students_asr = new Student_asr[n_asr];

    // Sample names
    const char* names_asr[] = {"Abir","Aarav","Isha","Rohan","Priya","Vikas","Neha","Sahil",
                               "Anaya","Dev","Kriti","Mira","Kabir","Tanvi","Yash","Riya",
                               "Arjun","Asha","Nikhil","Pooja","Kunal","Vishal","Amir","Sharukh",
                               "Salman","Mrunal","Kirti"};
    const int N_NAMES_asr = sizeof(names_asr) / sizeof(names_asr[0]);

    // Assign random values
    for (int i_asr = 0; i_asr < n_asr; i_asr++) {
        students_asr[i_asr].student_name_asr = names_asr[rand() % N_NAMES_asr];
        students_asr[i_asr].student_roll_no_asr = rand() % 100 + 1;
        students_asr[i_asr].total_marks_asr = rand() % 101;
    }

    // Copies for sorting
    Student_asr* arrBubble_asr = new Student_asr[n_asr];
    Student_asr* arrQuick_asr = new Student_asr[n_asr];
    for (int i_asr = 0; i_asr < n_asr; i_asr++) {
        arrBubble_asr[i_asr] = students_asr[i_asr];
        arrQuick_asr[i_asr] = students_asr[i_asr];
    }

    int bubbleSwaps_asr = bubbleSort_asr(arrBubble_asr, n_asr);
    int quickSwaps_asr = 0;
    quickSort_asr(arrQuick_asr, 0, n_asr - 1, quickSwaps_asr);

    cout << "\nRandomly Generated Student Records:\n";
    printArray_asr(students_asr, n_asr);

    cout << "\nBubble Sort Result:\n";
    printArray_asr(arrBubble_asr, n_asr);
    cout << "Number of swaps in Bubble Sort: " << bubbleSwaps_asr << endl;

    cout << "\nQuick Sort Result:\n";
    printArray_asr(arrQuick_asr, n_asr);
    cout << "Number of swaps in Quick Sort: " << quickSwaps_asr << endl;

    delete[] students_asr;
    delete[] arrBubble_asr;
    delete[] arrQuick_asr;

    return 0;
}