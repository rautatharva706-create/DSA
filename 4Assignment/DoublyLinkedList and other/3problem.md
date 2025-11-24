# Assignment No: 4 Problem: 3

## Title: Implementation of Bubble Sort using Doubly Linked List

### Theory

Bubble Sort is a simple comparison-based sorting algorithm that repeatedly traverses the list, compares adjacent elements, and swaps them if they are in the wrong order. The process continues until the entire list becomes sorted.

When implemented using a **doubly linked list**, Bubble Sort allows efficient two-way traversal, making element swapping easier since both previous and next pointers are accessible.

During each pass through the list:
- Adjacent nodes are compared
- If they are in the wrong order, their data (or nodes) are swapped
- After every complete pass, the largest element settles at its correct position

The sorting stops when a full pass results in **no swaps**, indicating the list is completely sorted.

### Algorithm

1. Start with the head of the doubly linked list.
2. Initialize a `swapped_asr` flag as `true`.
3. Repeat the following until `swapped_asr` is `false`:

   * Set `swapped_asr` to `false`.
   * Traverse the list from the beginning.
   * Compare each node’s data with the next node’s data.
   * If the current node’s data is greater than the next node’s data, swap their values and set `swapped_asr = true`.
   * After each pass, display the list and show which values were swapped.
4. Stop when the list is completely sorted (no swaps in a pass).

### C++ Code

```cpp
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
```

### Output

```
Enter number of elements: 5
Initial List:
23 78 5 56 12 
After pass 1: 23 5 78 12 56 
After pass 2: 5 23 12 56 78 
After pass 3: 5 12 23 56 78 
After pass 4: 5 12 23 56 78 
Sorted List:
5 12 23 56 78
```
