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
