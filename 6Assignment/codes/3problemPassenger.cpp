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