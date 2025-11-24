#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node_asr {
    int data_asr;
    Node_asr* next_asr;
    Node_asr* prev_asr;
};

void display_asr(Node_asr* head_asr) {
    Node_asr* temp_asr = head_asr;
    while (temp_asr) {
        cout << temp_asr->data_asr << " ";
        temp_asr = temp_asr->next_asr;
    }
    cout << endl;
}

int main() {
    srand((unsigned)time(nullptr));
    int n_asr;
    cout << "Enter number of elements: ";
    cin >> n_asr;

    // Creating doubly linked list with random values
    Node_asr* head_asr = nullptr;
    Node_asr* tail_asr = nullptr;
    for (int i_asr = 0; i_asr < n_asr; i_asr++) {
        Node_asr* newNode_asr = new Node_asr;
        newNode_asr->data_asr = rand() % 100; // Random value between 0-99
        newNode_asr->next_asr = nullptr;
        newNode_asr->prev_asr = tail_asr;
        if (!head_asr) head_asr = newNode_asr;
        if (tail_asr) tail_asr->next_asr = newNode_asr;
        tail_asr = newNode_asr;
    }

    cout << "Initial List:\n";
    display_asr(head_asr);

    // Bubble Sort
    bool swapped_asr;
    int pass_asr = 1;
    do {
        swapped_asr = false;
        Node_asr* current_asr = head_asr;
        while (current_asr && current_asr->next_asr) {
            if (current_asr->data_asr > current_asr->next_asr->data_asr) {
                swap(current_asr->data_asr, current_asr->next_asr->data_asr);
                swapped_asr = true;
            }
            current_asr = current_asr->next_asr;
        }
        cout << "After pass " << pass_asr << ": ";
        display_asr(head_asr);
        pass_asr++;
    } while (swapped_asr);

    cout << "Sorted List:\n";
    display_asr(head_asr);

    // Free memory
    Node_asr* temp_asr = head_asr;
    while (temp_asr) {
        Node_asr* next_asr = temp_asr->next_asr;
        delete temp_asr;
        temp_asr = next_asr;
    }

    return 0;
}