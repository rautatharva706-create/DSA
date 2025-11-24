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