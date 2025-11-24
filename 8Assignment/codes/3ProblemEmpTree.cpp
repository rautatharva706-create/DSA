#include <iostream>
#include <string>
using namespace std;

// Structure for Employee node
struct Employee_asr {
    int emp_id_asr;
    string name_asr;
    string designation_asr;
    Employee_asr *left_asr, *right_asr;

    Employee_asr(int id_asr, string name_asr, string desg_asr) {
        emp_id_asr = id_asr;
        this->name_asr = name_asr;
        this->designation_asr = desg_asr;
        left_asr = right_asr = nullptr;
    }
};

// Insert employee into BST
Employee_asr* insertEmployee_asr(Employee_asr* root_asr, int id_asr, string name_asr, string desg_asr) {
    if (root_asr == nullptr)
        return new Employee_asr(id_asr, name_asr, desg_asr);

    if (id_asr < root_asr->emp_id_asr)
        root_asr->left_asr = insertEmployee_asr(root_asr->left_asr, id_asr, name_asr, desg_asr);
    else if (id_asr > root_asr->emp_id_asr)
        root_asr->right_asr = insertEmployee_asr(root_asr->right_asr, id_asr, name_asr, desg_asr);

    return root_asr;
}

// Search employee by ID
Employee_asr* searchEmployee_asr(Employee_asr* root_asr, int id_asr) {
    if (root_asr == nullptr || root_asr->emp_id_asr == id_asr)
        return root_asr;

    if (id_asr < root_asr->emp_id_asr)
        return searchEmployee_asr(root_asr->left_asr, id_asr);
    else
        return searchEmployee_asr(root_asr->right_asr, id_asr);
}

// Display employee records in ascending order
void inorderDisplay_asr(Employee_asr* root_asr) {
    if (root_asr == nullptr)
        return;

    inorderDisplay_asr(root_asr->left_asr);
    cout << "Emp ID: " << root_asr->emp_id_asr
         << " | Name: " << root_asr->name_asr
         << " | Designation: " << root_asr->designation_asr << endl;
    inorderDisplay_asr(root_asr->right_asr);
}

int main() {
    Employee_asr* root_asr = nullptr;
    int choice_asr, id_asr;
    string name_asr, desg_asr;
    cout << "\n--- Employee Record Management ---\n";
    cout << "1. Insert Employee\n2. Search Employee\n3. Display All (Sorted by Emp ID)\n4. Exit\n";

    while (true) {

        cout << "Enter your choice: ";
        cin >> choice_asr;

        switch (choice_asr) {
            case 1:
                cout << "Enter Employee ID: ";
                cin >> id_asr;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name_asr);
                cout << "Enter Designation: ";
                getline(cin, desg_asr);
                root_asr = insertEmployee_asr(root_asr, id_asr, name_asr, desg_asr);
                cout << "Employee record inserted successfully.\n";
                break;

            case 2:
                cout << "Enter Employee ID to search: ";
                cin >> id_asr;
                {
                    Employee_asr* result_asr = searchEmployee_asr(root_asr, id_asr);
                    if (result_asr)
                        cout << "Record Found -> ID: " << result_asr->emp_id_asr
                             << ", Name: " << result_asr->name_asr
                             << ", Designation: " << result_asr->designation_asr << endl;
                    else
                        cout << "Employee not found.\n";
                }
                break;

            case 3:
                cout << "\nEmployee Records (Sorted by ID):\n";
                inorderDisplay_asr(root_asr);
                break;

            case 4:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}