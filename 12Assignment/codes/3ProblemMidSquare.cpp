#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const int SIZE_asr = 10;

// Employee structure
struct Employee_asr {
    int id_asr;
    string name_asr;
    string dept_asr;
    bool occupied_asr;
};

// Hash table as an array of structs
Employee_asr table_asr[SIZE_asr];

// Initialize table
void initTable_asr() {
    for (int i = 0; i < SIZE_asr; i++) {
        table_asr[i].occupied_asr = false;
    }
}

// Mid-square hash function
int midSquareHash_asr(int key_asr) {
    long long square_asr = (long long)key_asr * key_asr;
    string sqStr_asr = to_string(square_asr);
    int len_asr = sqStr_asr.length();
    int mid_asr = len_asr / 2;

    // Extract 2 middle digits
    string midDigits_asr = sqStr_asr.substr(max(0, mid_asr - 1), 2);
    int index_asr = stoi(midDigits_asr) % SIZE_asr;

    return index_asr;
}

// Insert employee
void insertRecord_asr(int id_asr, string name_asr, string dept_asr) {
    int index_asr = midSquareHash_asr(id_asr);
    int startIndex_asr = index_asr;

    while (table_asr[index_asr].occupied_asr) {
        index_asr = (index_asr + 1) % SIZE_asr;
        if (index_asr == startIndex_asr) {
            cout << "Hash Table is full!\n";
            return;
        }
    }

    table_asr[index_asr].id_asr = id_asr;
    table_asr[index_asr].name_asr = name_asr;
    table_asr[index_asr].dept_asr = dept_asr;
    table_asr[index_asr].occupied_asr = true;

    cout << "Record inserted successfully!\n";
}

// Search employee
void searchRecord_asr(int id_asr) {
    int index_asr = midSquareHash_asr(id_asr);
    int startIndex_asr = index_asr;

    while (table_asr[index_asr].occupied_asr) {
        if (table_asr[index_asr].id_asr == id_asr) {
            cout << "\nEmployee Found:\n";
            cout << "ID: " << table_asr[index_asr].id_asr << endl;
            cout << "Name: " << table_asr[index_asr].name_asr << endl;
            cout << "Department: " << table_asr[index_asr].dept_asr << endl;
            return;
        }
        index_asr = (index_asr + 1) % SIZE_asr;
        if (index_asr == startIndex_asr)
            break;
    }

    cout << "Employee not found!\n";
}

// Display table
void displayTable_asr() {
    cout << "\nEmployee Hash Table:\n";
    for (int i = 0; i < SIZE_asr; i++) {
        if (table_asr[i].occupied_asr)
            cout << "[" << i << "] " << table_asr[i].id_asr << " | "
                 << table_asr[i].name_asr << " | "
                 << table_asr[i].dept_asr << endl;
        else
            cout << "[" << i << "] Empty\n";
    }
}

int main() {
    initTable_asr();

    int choice_asr, id_asr;
    string name_asr, dept_asr;

    while (true) {
        cout << "\n--- Employee Database Menu ---\n";
        cout << "1. Insert Employee Record\n";
        cout << "2. Search Employee Record\n";
        cout << "3. Display Hash Table\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_asr;

        switch (choice_asr) {
        case 1:
            cout << "Enter Employee ID: ";
            cin >> id_asr;
            cout << "Enter Employee Name: ";
            cin >> name_asr;
            cout << "Enter Department: ";
            cin >> dept_asr;
            insertRecord_asr(id_asr, name_asr, dept_asr);
            break;

        case 2:
            cout << "Enter Employee ID to search: ";
            cin >> id_asr;
            searchRecord_asr(id_asr);
            break;

        case 3:
            displayTable_asr();
            break;

        case 4:
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
