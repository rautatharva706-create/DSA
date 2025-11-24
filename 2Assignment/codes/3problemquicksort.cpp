#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

void display_fun(int arr_asr[], const string names_asr[], int n_asr) {
    cout << "\nRoll\tName\tMarks\n";
    for(int i_asr = 0; i_asr < n_asr; i_asr++) {
        cout << i_asr + 1 << "\t" << names_asr[i_asr] << "\t" << arr_asr[i_asr] << endl;
    }
}

int partition_fun(int arr_asr[], int low_asr, int high_asr, int pass_asr) {
    int pivot_asr = arr_asr[high_asr];
    int i_asr = low_asr - 1;

    for(int j_asr = low_asr; j_asr < high_asr; j_asr++) {
        if(arr_asr[j_asr] <= pivot_asr) {
            i_asr++;
            swap(arr_asr[i_asr], arr_asr[j_asr]);
        }
    }
    swap(arr_asr[i_asr + 1], arr_asr[high_asr]);

    cout << "After Pass " << pass_asr << ": ";
    for(int k_asr = 0; k_asr <= high_asr; k_asr++)
        cout << arr_asr[k_asr] << " ";
    cout << endl;

    return (i_asr + 1);
}

void quickSort_fun(int arr_asr[], int low_asr, int high_asr, int &pass_asr) {
    if(low_asr < high_asr) {
        int pi_asr = partition_fun(arr_asr, low_asr, high_asr, pass_asr);
        pass_asr++;
        quickSort_fun(arr_asr, low_asr, pi_asr - 1, pass_asr);
        quickSort_fun(arr_asr, pi_asr + 1, high_asr, pass_asr);
    }
}

pair<int, int> minMax_fun(int arr_asr[], int low_asr, int high_asr) {
    if(low_asr == high_asr) {
        return {arr_asr[low_asr], arr_asr[low_asr]};
    }
    if(high_asr == low_asr + 1) {
        if(arr_asr[low_asr] < arr_asr[high_asr])
            return {arr_asr[low_asr], arr_asr[high_asr]};
        else
            return {arr_asr[high_asr], arr_asr[low_asr]};
    }

    int mid_asr = (low_asr + high_asr) / 2;
    pair<int, int> left_asr = minMax_fun(arr_asr, low_asr, mid_asr);
    pair<int, int> right_asr = minMax_fun(arr_asr, mid_asr + 1, high_asr);

    int minVal_asr = (left_asr.first < right_asr.first) ? left_asr.first : right_asr.first;
    int maxVal_asr = (left_asr.second > right_asr.second) ? left_asr.second : right_asr.second;

    return {minVal_asr, maxVal_asr};
}

int main() {
    srand(time(0));

    int n_asr;
    cout << "Enter number of students: ";
    cin >> n_asr;

    int* marks_asr = new int[n_asr];

    const char* namesArr_asr[] = {"Abir","Aarav","Isha","Rohan","Priya","Vikas","Neha","Sahil",
                               "Anaya","Dev","Kriti","Mira","Kabir","Tanvi","Yash","Riya",
                               "Arjun","Asha","Nikhil","Pooja","Kunal","Vishal","Amir","Sharukh",
                               "Salman","Mrunal","Kirti"};
    const int N_NAMES_asr = sizeof(namesArr_asr) / sizeof(namesArr_asr[0]);
    string* names_asr = new string[n_asr];

    // Assign random names and marks
    for(int i_asr = 0; i_asr < n_asr; i_asr++) {
        names_asr[i_asr] = namesArr_asr[rand() % N_NAMES_asr];
        marks_asr[i_asr] = rand() % 101; // 0 to 100 marks
    }

    cout << "\n===== Original Student Marks =====";
    display_fun(marks_asr, names_asr, n_asr);

    int pass_asr = 1;
    quickSort_fun(marks_asr, 0, n_asr - 1, pass_asr);

    cout << "\n===== Sorted Student Marks (Ascending) =====";
    display_fun(marks_asr, names_asr, n_asr);

    pair<int, int> result_asr = minMax_fun(marks_asr, 0, n_asr - 1);
    cout << "\nMinimum Marks: " << result_asr.first;
    cout << "\nMaximum Marks: " << result_asr.second << endl;

    delete[] marks_asr;
    delete[] names_asr;

    return 0;
}