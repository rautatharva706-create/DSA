# Assignment No: 6 Problem: 3

## Title: Passenger Queue Management System

### Theory

A queue is a linear data structure that works on the First In First Out (FIFO) concept, where the passenger who arrives first will also be served first. In a passenger ticket booking system, a queue helps in maintaining proper order so that each passenger is handled fairly. New passengers are added at the rear end of the queue, and passengers who get their tickets are removed from the front. The queue is implemented using a struct to manually store and manage passenger details without using any built-in C++ STL queue functions.
### Algorithm

1. **Initialize** an empty queue.
2. **Insert Passenger at Rear**:

   * Create a new node for the passenger.
   * If the queue is empty, set both front and rear pointers to this node.
   * Otherwise, link the new node to the rear and update the rear pointer.
3. **Display Passenger at Front**:

   * Check if the queue is empty.
   * Display the data of the node at the front pointer.
4. **Remove Passenger from Front**:

   * Check if the queue is empty.
   * Remove the node at the front pointer and update the front pointer.
5. **Display Remaining Passengers**:

   * Count nodes from front to rear before termination.

### C++ Code

```cpp
#include <iostream>
#include <string>
using namespace std;

struct Passenger_asr {
    string name_asr;
    Passenger_asr* next_asr;
};

struct Queue_asr {
    Passenger_asr* front_asr;
    Passenger_asr* rear_asr;
};

void initializeQueue_asr(Queue_asr &q_asr) {
    q_asr.front_asr = nullptr;
    q_asr.rear_asr = nullptr;
}

void enqueue_asr(Queue_asr &q_asr, const string &name_asr) {
    Passenger_asr* newPassenger_asr = new Passenger_asr{name_asr, nullptr};
    if (!q_asr.rear_asr) {
        q_asr.front_asr = q_asr.rear_asr = newPassenger_asr;
    } else {
        q_asr.rear_asr->next_asr = newPassenger_asr;
        q_asr.rear_asr = newPassenger_asr;
    }
    cout << "Passenger " << name_asr << " added to the queue.\n";
}

void dequeue_asr(Queue_asr &q_asr) {
    if (!q_asr.front_asr) {
        cout << "Queue is empty.\n";
        return;
    }
    Passenger_asr* temp_asr = q_asr.front_asr;
    cout << "Passenger " << temp_asr->name_asr << " served and removed from the queue.\n";
    q_asr.front_asr = q_asr.front_asr->next_asr;
    if (!q_asr.front_asr) q_asr.rear_asr = nullptr;
    delete temp_asr;
}

void displayFront_asr(Queue_asr &q_asr) {
    if (!q_asr.front_asr) {
        cout << "Queue is empty.\n";
    } else {
        cout << "Passenger at front: " << q_asr.front_asr->name_asr << "\n";
    }
}

int countPassengers_asr(Queue_asr &q_asr) {
    int count_asr = 0;
    Passenger_asr* temp_asr = q_asr.front_asr;
    while (temp_asr) {
        count_asr++;
        temp_asr = temp_asr->next_asr;
    }
    return count_asr;
}

int main() {
    Queue_asr q_asr;
    initializeQueue_asr(q_asr);
    int choice_asr;
    string name_asr;

    do {
        cout << "\nMenu:\n1. Add Passenger\n2. Display Front Passenger\n3. Serve Passenger\n0. Exit\nEnter your choice: ";
        cin >> choice_asr;
        switch(choice_asr) {
            case 1:
                cout << "Enter passenger name: ";
                cin >> name_asr;
                enqueue_asr(q_asr, name_asr);
                break;
            case 2:
                displayFront_asr(q_asr);
                break;
            case 3:
                dequeue_asr(q_asr);
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while(choice_asr != 0);

    cout << "Passengers left in the queue: " << countPassengers_asr(q_asr) << "\n";
    return 0;
}
```

### Output

```
Menu:
1. Add Passenger
2. Display Front Passenger
3. Serve Passenger
0. Exit
Enter your choice: 1
Enter passenger name: Abir
Passenger Abir added to the queue.

Enter your choice: 1
Enter passenger name: Priya
Passenger Priya added to the queue.

Enter your choice: 2
Passenger at front: Abir

Enter your choice: 3
Passenger Abir served and removed from the queue.

Enter your choice: 0
Exiting program.
Passengers left in the queue: 1
```
