#include <iostream>
#include <string>
using namespace std;

const int SIZE_asr = 10;

// Structure to store student data
struct Student_asr {
    int roll_asr;
    string name_asr;
    float marks_asr;
    bool occupied_asr;
};

// Hash table implemented using struct (no classes)
struct HashTable_asr {
    Student_asr table_asr[SIZE_asr];

    // Initialize table
    void init_asr() {
        for (int i = 0; i < SIZE_asr; i++)
            table_asr[i].occupied_asr = false;
    }

    // Hash function
    int hashFunction_asr(int roll_asr) {
        return roll_asr % SIZE_asr;
    }

    // Insert record using linear probing
    void insertRecord_asr(int roll_asr, string name_asr, float marks_asr) {
        int index_asr = hashFunction_asr(roll_asr);
        int startIndex_asr = index_asr;

        while (table_asr[index_asr].occupied_asr) {
            index_asr = (index_asr + 1) % SIZE_asr;
            if (index_asr == startIndex_asr) {
                cout << "Hash table is full!" << endl;
                return;
            }
        }

        table_asr[index_asr].roll_asr = roll_asr;
        table_asr[index_asr].name_asr = name_asr;
        table_asr[index_asr].marks_asr = marks_asr;
        table_asr[index_asr].occupied_asr = true;

        cout << "Record inserted successfully!" << endl;
    }

    // Search record
    void searchRecord_asr(int roll_asr) {
        int index_asr = hashFunction_asr(roll_asr);
        int startIndex_asr = index_asr;

        while (table_asr[index_asr].occupied_asr) {
            if (table_asr[index_asr].roll_asr == roll_asr) {
                cout << "\nRecord Found:\n";
                cout << "Roll: " << table_asr[index_asr].roll_asr
                     << "\nName: " << table_asr[index_asr].name_asr
                     << "\nMarks: " << table_asr[index_asr].marks_asr << endl;
                return;
            }
            index_asr = (index_asr + 1) % SIZE_asr;
            if (index_asr == startIndex_asr)
                break;
        }

        cout << "Record not found!" << endl;
    }

    // Display all records
    void display_asr() {
        cout << "\nStored Records:\n";
        for (int i = 0; i < SIZE_asr; i++) {
            if (table_asr[i].occupied_asr) {
                cout << "Index " << i
                     << " -> Roll: " << table_asr[i].roll_asr
                     << ", Name: " << table_asr[i].name_asr
                     << ", Marks: " << table_asr[i].marks_asr << endl;
            } else {
                cout << "Index " << i << " -> Empty\n";
            }
        }
    }
};

int main() {
    HashTable_asr ht_asr;
    ht_asr.init_asr();

    int choice_asr;

    while (true) {
        cout << "\n1. Insert Record\n2. Search Record\n3. Display Records\n4. Exit\nEnter choice: ";
        cin >> choice_asr;

        if (choice_asr == 1) {
            int roll_asr;
            string name_asr;
            float marks_asr;
            cout << "Enter Roll No, Name, and Marks: ";
            cin >> roll_asr >> name_asr >> marks_asr;
            ht_asr.insertRecord_asr(roll_asr, name_asr, marks_asr);
        }
        else if (choice_asr == 2) {
            int roll_asr;
            cout << "Enter Roll No to search: ";
            cin >> roll_asr;
            ht_asr.searchRecord_asr(roll_asr);
        }
        else if (choice_asr == 3) {
            ht_asr.display_asr();
        }
        else if (choice_asr == 4) {
            break;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}