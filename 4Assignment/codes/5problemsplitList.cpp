#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node_asr {
    int data_asr;
    Node_asr* next_asr;
};

// Function to add a node at the end
void append_asr(Node_asr*& head_asr, int value_asr) {
    Node_asr* newNode_asr = new Node_asr{value_asr, nullptr};
    if (!head_asr) {
        head_asr = newNode_asr;
        return;
    }
    Node_asr* temp_asr = head_asr;
    while (temp_asr->next_asr)
        temp_asr = temp_asr->next_asr;
    temp_asr->next_asr = newNode_asr;
}

// Function to display list
void display_asr(Node_asr* head_asr) {
    Node_asr* temp_asr = head_asr;
    while (temp_asr) {
        cout << temp_asr->data_asr << " ";
        temp_asr = temp_asr->next_asr;
    }
    cout << endl;
}

// Function to perform Front-Back Split
void frontBackSplit_asr(Node_asr* source_asr, Node_asr*& front_asr, Node_asr*& back_asr) {
    if (!source_asr || !source_asr->next_asr) {
        front_asr = source_asr;
        back_asr = nullptr;
        return;
    }

    Node_asr* slow_asr = source_asr;
    Node_asr* fast_asr = source_asr->next_asr;

    while (fast_asr) {
        fast_asr = fast_asr->next_asr;
        if (fast_asr) {
            slow_asr = slow_asr->next_asr;
            fast_asr = fast_asr->next_asr;
        }
    }

    front_asr = source_asr;
    back_asr = slow_asr->next_asr;
    slow_asr->next_asr = nullptr;
}

int main() {
    srand((unsigned)time(nullptr));
    Node_asr* head_asr = nullptr;
    Node_asr* front_asr = nullptr;
    Node_asr* back_asr = nullptr;

    int n_asr;
    cout << "Enter number of elements: ";
    cin >> n_asr;

    // Generate random list
    for (int i = 0; i < n_asr; i++)
        append_asr(head_asr, rand() % 100 + 1);

    cout << "Original List: ";
    display_asr(head_asr);

    frontBackSplit_asr(head_asr, front_asr, back_asr);

    cout << "Front List: ";
    display_asr(front_asr);

    cout << "Back List: ";
    display_asr(back_asr);

    return 0;
}
