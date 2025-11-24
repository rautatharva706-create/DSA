#include <iostream>
#include <string>
using namespace std;

struct Student_asr {
    int roll_asr;
    string name_asr;
    int marks_asr;
    Student_asr* next_asr;
};

const int TABLE_SIZE_asr = 10;
Student_asr* hashTable_asr[TABLE_SIZE_asr];

void initTable_asr() {
    for (int i = 0; i < TABLE_SIZE_asr; i++) {
        hashTable_asr[i] = nullptr;
    }
}

int hashFunction_asr(int roll_asr) {
    return roll_asr % TABLE_SIZE_asr;
}

void insertStudent_asr(int roll_asr, string name_asr, int marks_asr) {
    int index_asr = hashFunction_asr(roll_asr);

    Student_asr* newNode_asr = new Student_asr();
    newNode_asr->roll_asr = roll_asr;
    newNode_asr->name_asr = name_asr;
    newNode_asr->marks_asr = marks_asr;
    newNode_asr->next_asr = hashTable_asr[index_asr];

    hashTable_asr[index_asr] = newNode_asr;

    cout << "Record inserted successfully.\n";
}

void searchStudent_asr(int roll_asr) {
    int index_asr = hashFunction_asr(roll_asr);
    Student_asr* temp_asr = hashTable_asr[index_asr];

    while (temp_asr != nullptr) {
        if (temp_asr->roll_asr == roll_asr) {
            cout << "Record Found!\n";
            cout << "Roll: " << temp_asr->roll_asr << "\nName: " << temp_asr->name_asr
                 << "\nMarks: " << temp_asr->marks_asr << endl;
            return;
        }
        temp_asr = temp_asr->next_asr;
    }
    cout << "Record Not Found.\n";
}

void deleteStudent_asr(int roll_asr) {
    int index_asr = hashFunction_asr(roll_asr);
    Student_asr* temp_asr = hashTable_asr[index_asr];
    Student_asr* prev_asr = nullptr;

    while (temp_asr != nullptr) {
        if (temp_asr->roll_asr == roll_asr) {
            if (prev_asr == nullptr)
                hashTable_asr[index_asr] = temp_asr->next_asr;
            else
                prev_asr->next_asr = temp_asr->next_asr;

            delete temp_asr;
            cout << "Record deleted successfully.\n";
            return;
        }
        prev_asr = temp_asr;
        temp_asr = temp_asr->next_asr;
    }
    cout << "Record Not Found.\n";
}

void displayTable_asr() {
    for (int i = 0; i < TABLE_SIZE_asr; i++) {
        cout << "Index " << i << ": ";
        Student_asr* temp_asr = hashTable_asr[i];
        while (temp_asr != nullptr) {
            cout << "[Roll: " << temp_asr->roll_asr 
                 << ", Name: " << temp_asr->name_asr
                 << ", Marks: " << temp_asr->marks_asr << "] -> ";
            temp_asr = temp_asr->next_asr;
        }
        cout << "NULL\n";
    }
}

int main() {
    initTable_asr();
    int choice_asr, roll_asr, marks_asr;
    string name_asr;

    while (true) {
        cout << "\n--- Student Database Menu ---\n";
        cout << "1. Insert Student\n2. Search Student\n3. Delete Student\n4. Display Table\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice_asr;

        switch (choice_asr) {
            case 1:
                cout << "Enter Roll: ";
                cin >> roll_asr;
                cout << "Enter Name: ";
                cin >> name_asr;
                cout << "Enter Marks: ";
                cin >> marks_asr;
                insertStudent_asr(roll_asr, name_asr, marks_asr);
                break;

            case 2:
                cout << "Enter Roll to Search: ";
                cin >> roll_asr;
                searchStudent_asr(roll_asr);
                break;

            case 3:
                cout << "Enter Roll to Delete: ";
                cin >> roll_asr;
                deleteStudent_asr(roll_asr);
                break;

            case 4:
                displayTable_asr();
                break;

            case 5:
                return 0;

            default:
                cout << "Invalid choice.\n";
        }
    }
}
