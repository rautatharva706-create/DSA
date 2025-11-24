# Assignment No: 6 Problem: 5

## Title: Call Center Queue System using Linked List

### Theory

In a call center environment, customer calls must be attended in the order they are received. A queue is a linear data structure that works on the First In First Out (FIFO) method, making it suitable for handling incoming calls fairly. By implementing the queue using a linked list, memory is allocated dynamically which allows efficient insertion and deletion of call records without any fixed size limitation. Each node in the linked list stores the details of one customer call. When a call comes in, it is added at the rear end of the queue, and customer support staff take calls from the front to assist customers. If there are no calls in the queue, the system simply waits for the next call.

### Algorithm

1. **Define a node structure** for a customer call containing a call ID or name and a pointer to the next node.
2. **Initialize** two pointers: `front_asr` and `rear_asr` as `nullptr`.
3. **Enqueue Operation:**

   * Create a new node for the arriving customer.
   * If the queue is empty, set both `front_asr` and `rear_asr` to the new node.
   * Otherwise, link the new node to the rear and update `rear_asr`.
4. **Dequeue Operation:**

   * If the queue is empty, display "No calls".
   * Otherwise, remove the node from the front and update `front_asr`.
5. **Display Queue:**

   * Traverse the linked list from `front_asr` to `rear_asr`, printing each customer call.
6. **Repeat** the enqueue, dequeue, and display operations as required.

### C++ Code

```cpp
#include <iostream>
#include <string>
using namespace std;

struct Customer_asr {
    string name_asr;
    Customer_asr* next_asr;
};

Customer_asr* front_asr = nullptr;
Customer_asr* rear_asr = nullptr;

void enqueue_asr(const string& name_asr) {
    Customer_asr* newCustomer_asr = new Customer_asr{name_asr, nullptr};
    if (!rear_asr) {
        front_asr = rear_asr = newCustomer_asr;
    } else {
        rear_asr->next_asr = newCustomer_asr;
        rear_asr = newCustomer_asr;
    }
    cout << "Enqueued: " << name_asr << endl;
}

void dequeue_asr() {
    if (!front_asr) {
        cout << "No calls in the queue." << endl;
        return;
    }
    Customer_asr* temp_asr = front_asr;
    cout << "Dequeued: " << temp_asr->name_asr << endl;
    front_asr = front_asr->next_asr;
    if (!front_asr) rear_asr = nullptr;
    delete temp_asr;
}

void displayQueue_asr() {
    if (!front_asr) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Current Queue: ";
    Customer_asr* temp_asr = front_asr;
    while (temp_asr) {
        cout << temp_asr->name_asr << " ";
        temp_asr = temp_asr->next_asr;
    }
    cout << endl;
}

int main() {
    int choice_asr;
    string name_asr;
    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue Customer Call\n";
        cout << "2. Dequeue Customer Call\n";
        cout << "3. Display Queue\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_asr;
        cin.ignore(); // clear input buffer

        switch(choice_asr) {
            case 1:
                cout << "Enter customer name: ";
                getline(cin, name_asr);
                enqueue_asr(name_asr);
                break;
            case 2:
                dequeue_asr();
                break;
            case 3:
                displayQueue_asr();
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice_asr != 0);

    return 0;
}
```

### Output

```
Menu:
1. Enqueue Customer Call
2. Dequeue Customer Call
3. Display Queue
0. Exit
Enter your choice: 1
Enter customer name: Prithviraj
Enqueued: Prithviraj

Menu:
1. Enqueue Customer Call
2. Dequeue Customer Call
3. Display Queue
0. Exit
Enter your choice: 1
Enter customer name: Shreeniket
Enqueued: Shreeniket

Menu:
1. Enqueue Customer Call
2. Dequeue Customer Call
3. Display Queue
0. Exit
Enter your choice: 3
Current Queue: Prithviraj Shreeniket 

Menu:
1. Enqueue Customer Call
2. Dequeue Customer Call
3. Display Queue
0. Exit
Enter your choice: 2
Dequeued: Prithviraj

Menu:
1. Enqueue Customer Call
2. Dequeue Customer Call
3. Display Queue
0. Exit
Enter your choice: 3
Current Queue: Shreeniket 

Menu:
1. Enqueue Customer Call
2. Dequeue Customer Call
3. Display Queue
0. Exit
Enter your choice: 0
Exiting program.
```
