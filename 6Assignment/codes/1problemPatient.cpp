#include <iostream>
#include <string>
using namespace std;

struct Node_asr {
    string name_asr;
    Node_asr* next_asr;
};

// Queue structure for each doctor
struct Queue_asr {
    Node_asr* front_asr;
    Node_asr* rear_asr;
};

// Initialize a new queue
void initQueue_asr(Queue_asr &q_asr) {
    q_asr.front_asr = q_asr.rear_asr = nullptr;
}

// Enqueue patient
void enqueue_asr(Queue_asr &q_asr, const string &name_asr) {
    Node_asr* newNode_asr = new Node_asr{name_asr, nullptr};
    if (!q_asr.rear_asr) {
        q_asr.front_asr = q_asr.rear_asr = newNode_asr;
    } else {
        q_asr.rear_asr->next_asr = newNode_asr;
        q_asr.rear_asr = newNode_asr;
    }
    cout << name_asr << " added to the queue.\n";
}

// Dequeue patient
void dequeue_asr(Queue_asr &q_asr, const string &doctor_asr) {
    if (!q_asr.front_asr) {
        cout << "No patients waiting for " << doctor_asr << ".\n";
        return;
    }
    Node_asr* temp_asr = q_asr.front_asr;
    cout << "Serving patient: " << temp_asr->name_asr << " for " << doctor_asr << "\n";
    q_asr.front_asr = q_asr.front_asr->next_asr;
    if (!q_asr.front_asr) q_asr.rear_asr = nullptr;
    delete temp_asr;
}

// Display queue
void display_asr(Queue_asr &q_asr, const string &doctor_asr) {
    if (!q_asr.front_asr) {
        cout << "No patients waiting for " << doctor_asr << ".\n";
        return;
    }
    cout << "Patients waiting for " << doctor_asr << ":\n";
    Node_asr* temp_asr = q_asr.front_asr;
    while (temp_asr) {
        cout << "- " << temp_asr->name_asr << "\n";
        temp_asr = temp_asr->next_asr;
    }
}

int main() {
    Queue_asr doctorA_asr, doctorB_asr;
    initQueue_asr(doctorA_asr);
    initQueue_asr(doctorB_asr);

    int choice_asr, doctorChoice_asr;
    string name_asr;

    do {
        cout << "\n===== Medical Clinic Queue System =====\n";
        cout << "1. Add Patient\n2. Serve Patient\n3. Display Waiting List\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_asr;

        switch (choice_asr) {
            case 1:
                cout << "Enter patient name: ";
                cin >> name_asr;
                cout << "Choose Doctor (1 - Dr. A, 2 - Dr. B): ";
                cin >> doctorChoice_asr;
                if (doctorChoice_asr == 1)
                    enqueue_asr(doctorA_asr, name_asr);
                else if (doctorChoice_asr == 2)
                    enqueue_asr(doctorB_asr, name_asr);
                else
                    cout << "Invalid choice.\n";
                break;

            case 2:
                cout << "Serve which doctor? (1 - Dr. A, 2 - Dr. B): ";
                cin >> doctorChoice_asr;
                if (doctorChoice_asr == 1)
                    dequeue_asr(doctorA_asr, "Dr. A");
                else if (doctorChoice_asr == 2)
                    dequeue_asr(doctorB_asr, "Dr. B");
                else
                    cout << "Invalid choice.\n";
                break;

            case 3:
                display_asr(doctorA_asr, "Dr. A");
                display_asr(doctorB_asr, "Dr. B");
                break;

            case 0:
                cout << "Exiting system. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice_asr != 0);

    return 0;
}