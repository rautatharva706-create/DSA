# Assignment No: 6 Problem: 1

## Title

Implementation of a Patient Queue Management System Using Structures (Two Doctor Queues)

### Theory

A queue is a linear data structure that works on the First In First Out (FIFO) rule. In this patient queue management system, two queues are used separately for Dr. A and Dr. B so that patients are attended in the same order in which they arrive. Each queue is implemented using a linked list of structures without using any C++ STL containers. When a patient comes, they choose the doctor by entering 1 for Dr. A or 2 for Dr. B and their name is added at the end of the selected doctor’s queue. The doctor then serves patients starting from the front of the queue, which provides a fair and well-organized system for managing patient flow.

### Algorithm

1. **Start**
2. Define a structure `Node_asr` containing:

   * `string name_asr`
   * `Node_asr* next_asr`
3. Initialize two queue heads and tails: `frontA_asr`, `rearA_asr` for Dr. A and `frontB_asr`, `rearB_asr` for Dr. B.
4. Define the following operations:

   * **enqueue_asr()**: Add a patient to the selected doctor's queue.
   * **dequeue_asr()**: Remove a patient from the selected doctor's queue.
   * **display_asr()**: Display all patients waiting for each doctor.
5. Create a menu-driven program with options:

   * 1. Add Patient
   * 2. Serve Patient
   * 3. Display Waiting List
   * 0. Exit
6. Based on user input, perform the respective queue operation.
7. **End**

### C++ Code

```cpp
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
```

### Output

```
===== Medical Clinic Queue System =====
1. Add Patient
2. Serve Patient
3. Display Waiting List
0. Exit
Enter your choice: 1
Enter patient name: Neha
Choose Doctor (1 - Dr. A, 2 - Dr. B): 1
Neha added to the queue.

Enter your choice: 1
Enter patient name: Rohan
Choose Doctor (1 - Dr. A, 2 - Dr. B): 2
Rohan added to the queue.

Enter your choice: 3
Patients waiting for Dr. A:
- Neha
Patients waiting for Dr. B:
- Rohan

Enter your choice: 2
Serve which doctor? (1 - Dr. A, 2 - Dr. B): 1
Serving patient: Neha for Dr. A

Enter your choice: 0
Exiting system. Goodbye!
```
