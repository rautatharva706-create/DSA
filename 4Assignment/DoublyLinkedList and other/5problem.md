# Assignment No: ___

## Title: Front-Back Split of a Linked List

### Theory

A **singly linked list** is a linear data structure in which each node contains data and a pointer to the next node.  
In this assignment, the objective is to **split a given singly linked list into two sublists**:

- **Front Sublist** → Contains the first half of the nodes  
- **Back Sublist** → Contains the remaining nodes  

When the list contains an **odd number of elements**, the **extra node is assigned to the front sublist**.  
This is typically achieved using the **slow and fast pointer approach**, where:
- The **fast pointer** moves two nodes at a time
- The **slow pointer** moves one node at a time  
→ When the fast pointer reaches the end, the slow pointer marks the **split point**.

Handling edge cases such as:
- **Empty list (0 nodes)**
- **Single node (1 node)**
- **Two nodes (2 nodes)**  
ensures proper splitting behavior for lists of all sizes.

### Algorithm

1. **Check for edge cases:**

   * If the list is empty (`head_asr == nullptr`) or has only one node, assign the entire list to `front_asr` and set `back_asr` to `nullptr`.

2. **Initialize two pointers:**

   * `slow_asr` → points to the head of the list.
   * `fast_asr` → points to the second node (`head_asr->next_asr`).

3. **Traverse the list:**

   * Move `fast_asr` two nodes at a time.
   * Move `slow_asr` one node at a time.
   * Continue until `fast_asr` reaches the end of the list.

4. **Split the list:**

   * `front_asr` → points to the head of the original list.
   * `back_asr` → points to the node after `slow_asr`.
   * Terminate the front list by setting `slow_asr->next_asr = nullptr`.

5. **Return:**

   * The front and back sublists (`front_asr` and `back_asr`).

### C++ Code

```cpp
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

```

### Output

```
Enter number of elements: 7
Original List: 23 56 12 89 44 67 10 
Front List: 23 56 12 89 
Back List: 44 67 10

```

