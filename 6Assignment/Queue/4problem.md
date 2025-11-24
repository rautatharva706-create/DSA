# Assignment No: 6 Problem:5

## Title: Implementation of Two Queues Using Arrays

### Theory

A queue is a linear data structure based on the FIFO (First In First Out) rule, where the element inserted first is the first one to be removed. Multiple queues can be created using arrays by using different arrays or separate queue structures for each one. Every queue supports basic operations such as:

Enqueue: Inserting a new element at the rear end
Dequeue: Removing an element from the front
Display: Showing all elements currently stored in the queue

In this assignment, two independent queues are implemented using arrays, so that each queue can perform its operations separately without affecting the other.

### Algorithm

1. **Define a structure** `Queue_asr` containing:

   * `front_asr` → index of front element
   * `rear_asr` → index of rear element
   * `capacity_asr` → size of the array
   * `arr_asr[]` → array to store elements

2. **Initialize two queues** `queue1_asr` and `queue2_asr` with a fixed size.

3. **Enqueue operation**:

   * Check for overflow (if `rear_asr == capacity_asr - 1`)
   * If not overflow, insert element at `rear_asr + 1`

4. **Dequeue operation**:

   * Check for underflow (if `front_asr > rear_asr`)
   * If not underflow, remove element at `front_asr` and increment `front_asr`

5. **Display operation**:

   * Print elements from `front_asr` to `rear_asr`

6. **Menu-driven program** to perform operations on either queue.

### C++ Code

```cpp
#include <iostream>
using namespace std;

void enqueue_asr(int* queue_asr, int& rear_asr, int size_asr, int value_asr) {
    if (rear_asr == size_asr - 1) {
        cout << "Queue is full.\n";
        return;
    }
    queue_asr[++rear_asr] = value_asr;
    cout << value_asr << " added to queue.\n";
}

void dequeue_asr(int* queue_asr, int& front_asr, int& rear_asr) {
    if (front_asr > rear_asr) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << queue_asr[front_asr++] << " removed from queue.\n";
}

void display_asr(int* queue_asr, int front_asr, int rear_asr) {
    if (front_asr > rear_asr) {
        cout << "Queue is empty.\n";
        return;
    }
    for (int i_asr = front_asr; i_asr <= rear_asr; i_asr++) {
        cout << queue_asr[i_asr] << " ";
    }
    cout << endl;
}

int main() {
    int size1_asr, size2_asr;
    cout << "Enter size of Queue 1: ";
    cin >> size1_asr;
    cout << "Enter size of Queue 2: ";
    cin >> size2_asr;

    int* queue1_asr = new int[size1_asr];
    int* queue2_asr = new int[size2_asr];

    int front1_asr = 0, rear1_asr = -1;
    int front2_asr = 0, rear2_asr = -1;

    int choice_asr, q_asr, value_asr;
    do {
        cout << "\nMenu:\n1. Enqueue\n2. Dequeue\n3. Display Queue\n0. Exit\nEnter choice: ";
        cin >> choice_asr;
        if (choice_asr == 0) break;

        cout << "Select Queue (1 or 2): ";
        cin >> q_asr;

        switch(choice_asr) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value_asr;
                if (q_asr == 1) enqueue_asr(queue1_asr, rear1_asr, size1_asr, value_asr);
                else enqueue_asr(queue2_asr, rear2_asr, size2_asr, value_asr);
                break;
            case 2:
                if (q_asr == 1) dequeue_asr(queue1_asr, front1_asr, rear1_asr);
                else dequeue_asr(queue2_asr, front2_asr, rear2_asr);
                break;
            case 3:
                cout << "Queue " << q_asr << ": ";
                if (q_asr == 1) display_asr(queue1_asr, front1_asr, rear1_asr);
                else display_asr(queue2_asr, front2_asr, rear2_asr);
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (true);

    delete[] queue1_asr;
    delete[] queue2_asr;
    return 0;
}


```

### Output

```
Enter size of Queue 1: 1
Enter size of Queue 2: 1

Menu:
1. Enqueue
2. Dequeue
3. Display Queue
0. Exit
Enter choice: 1
Select Queue (1 or 2): 1
Enter value to enqueue: 23
23 added to queue.

Menu:
1. Enqueue
2. Dequeue
3. Display Queue
0. Exit
Enter choice: 1
Select Queue (1 or 2): 1
Enter value to enqueue: 1
Queue is full.

Menu:
1. Enqueue
2. Dequeue
3. Display Queue
0. Exit
Enter choice: 1
Select Queue (1 or 2): 2
Enter value to enqueue: 34
34 added to queue.

Menu:
1. Enqueue
2. Dequeue
3. Display Queue
0. Exit
Enter choice: 3
Select Queue (1 or 2): 1
Queue 1: 23 

Menu:
1. Enqueue
2. Dequeue
3. Display Queue
0. Exit
Enter choice: 3
Select Queue (1 or 2): 2
Queue 2: 34 

Menu:
1. Enqueue
2. Dequeue
3. Display Queue
0. Exit
Enter choice: 0
```
