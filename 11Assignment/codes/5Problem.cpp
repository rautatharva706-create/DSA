#include <iostream>
#include <string>
using namespace std;

struct Faculty_asr {
    int id_asr;
    string name_asr;
    string department_asr;
    bool occupied_asr;
};

struct HashTable_asr {
    Faculty_asr table_asr[10];
    int size_asr;

    HashTable_asr() {
        size_asr = 10;
        for (int i = 0; i < size_asr; i++) {
            table_asr[i].occupied_asr = false;
        }
    }

    int hashFunction_asr(int key_asr) {
        return key_asr % size_asr;
    }

    void insertRecord_asr(int id_asr, string name_asr, string dept_asr) {
        int index_asr = hashFunction_asr(id_asr);
        int start_asr = index_asr;

        while (table_asr[index_asr].occupied_asr) {
            index_asr = (index_asr + 1) % size_asr;
            if (index_asr == start_asr) {
                cout << "Hash Table is full!" << endl;
                return;
            }
        }

        table_asr[index_asr].id_asr = id_asr;
        table_asr[index_asr].name_asr = name_asr;
        table_asr[index_asr].department_asr = dept_asr;
        table_asr[index_asr].occupied_asr = true;

        cout << "Record inserted successfully!" << endl;
    }

    void searchRecord_asr(int id_asr) {
        int index_asr = hashFunction_asr(id_asr);
        int start_asr = index_asr;

        while (table_asr[index_asr].occupied_asr) {
            if (table_asr[index_asr].id_asr == id_asr) {
                cout << "\nFaculty Found:\n";
                cout << "ID: " << table_asr[index_asr].id_asr << endl;
                cout << "Name: " << table_asr[index_asr].name_asr << endl;
                cout << "Department: " << table_asr[index_asr].department_asr << endl;
                return;
            }
            index_asr = (index_asr + 1) % size_asr;
            if (index_asr == start_asr)
                break;
        }

        cout << "Faculty not found!" << endl;
    }

    void displayTable_asr() {
        cout << "\nFaculty Hash Table:\n";
        for (int i = 0; i < size_asr; i++) {
            if (table_asr[i].occupied_asr)
                cout << "[" << i << "] "
                     << table_asr[i].id_asr << " | "
                     << table_asr[i].name_asr << " | "
                     << table_asr[i].department_asr << endl;
            else
                cout << "[" << i << "] Empty\n";
        }
    }
};

int main() {
    HashTable_asr ht_asr;
    int choice_asr, id_asr;
    string name_asr, dept_asr;

    while (true) {
        cout << "\n--- Faculty Database Menu ---\n";
        cout << "1. Insert Faculty Record\n";
        cout << "2. Search Faculty Record\n";
        cout << "3. Display Hash Table\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_asr;

        switch (choice_asr) {
        case 1:
            cout << "Enter Faculty ID: ";
            cin >> id_asr;
            cout << "Enter Faculty Name: ";
            cin >> name_asr;
            cout << "Enter Department: ";
            cin >> dept_asr;
            ht_asr.insertRecord_asr(id_asr, name_asr, dept_asr);
            break;

        case 2:
            cout << "Enter Faculty ID to search: ";
            cin >> id_asr;
            ht_asr.searchRecord_asr(id_asr);
            break;

        case 3:
            ht_asr.displayTable_asr();
            break;

        case 4:
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
