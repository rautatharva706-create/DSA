#include <iostream>
#include <string>
using namespace std;

struct Faculty_asr {
    int id_asr;
    string name_asr;
    string dept_asr;
    bool occupied_asr;
};

struct FacultyHashTable_asr {
    static const int SIZE_asr = 10;
    Faculty_asr table_asr[SIZE_asr];

    FacultyHashTable_asr() {
        for (int i = 0; i < SIZE_asr; i++)
            table_asr[i].occupied_asr = false;
    }

    int hashFunction_asr(int key_asr) {
        return key_asr % SIZE_asr;
    }

    void insertFaculty_asr(int id_asr, string name_asr, string dept_asr) {
        int index_asr = hashFunction_asr(id_asr);

        if (!table_asr[index_asr].occupied_asr) {
            table_asr[index_asr] = {id_asr, name_asr, dept_asr, true};
            cout << "Faculty inserted successfully!\n";
            return;
        }

        int existingHash_asr = hashFunction_asr(table_asr[index_asr].id_asr);

        if (existingHash_asr != index_asr) {
            cout << "Collision! Applying chaining with replacement.\n";
            Faculty_asr temp_asr = table_asr[index_asr];
            table_asr[index_asr] = {id_asr, name_asr, dept_asr, true};
            insertFaculty_asr(temp_asr.id_asr, temp_asr.name_asr, temp_asr.dept_asr);
        } 
        else {
            int start_asr = index_asr;
            do {
                index_asr = (index_asr + 1) % SIZE_asr;
                if (!table_asr[index_asr].occupied_asr) {
                    table_asr[index_asr] = {id_asr, name_asr, dept_asr, true};
                    cout << "Faculty inserted successfully!\n";
                    return;
                }
            } while (index_asr != start_asr);

            cout << "Hash table is full. Cannot insert record.\n";
        }
    }

    void searchFaculty_asr(int id_asr) {
        int index_asr = hashFunction_asr(id_asr);
        int start_asr = index_asr;

        while (table_asr[index_asr].occupied_asr) {
            if (table_asr[index_asr].id_asr == id_asr) {
                cout << "\nFaculty Found:\n";
                cout << "ID: " << table_asr[index_asr].id_asr << endl;
                cout << "Name: " << table_asr[index_asr].name_asr << endl;
                cout << "Department: " << table_asr[index_asr].dept_asr << endl;
                return;
            }
            index_asr = (index_asr + 1) % SIZE_asr;
            if (index_asr == start_asr) break;
        }

        cout << "Faculty not found!\n";
    }

    void displayTable_asr() {
        cout << "\nFaculty Hash Table:\n";
        for (int i = 0; i < SIZE_asr; i++) {
            if (table_asr[i].occupied_asr)
                cout << "[" << i << "] " << table_asr[i].id_asr << " | "
                     << table_asr[i].name_asr << " | "
                     << table_asr[i].dept_asr << endl;
            else
                cout << "[" << i << "] Empty\n";
        }
    }
};

int main() {
    FacultyHashTable_asr hashTable_asr;
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
            hashTable_asr.insertFaculty_asr(id_asr, name_asr, dept_asr);
            break;

        case 2:
            cout << "Enter Faculty ID to search: ";
            cin >> id_asr;
            hashTable_asr.searchFaculty_asr(id_asr);
            break;

        case 3:
            hashTable_asr.displayTable_asr();
            break;

        case 4:
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}