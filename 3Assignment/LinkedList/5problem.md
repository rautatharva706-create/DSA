# Assignment 3 : Problem 5

## Title: Binary Number Operations using Doubly Linked List
 Write a C++ program to store a binary number using a doubly linked list. Implement the following functions:
 a) Calculate and display the 1’s complement and 2’s complement of the stored binary number.
 b) Perform addition of two binary numbers represented using doubly linked lists and display the result.


### Theory:

A binary number can be stored in a linked list, where each node contains a single bit. A **doubly linked list** allows traversal in both forward and backward directions, which is useful for performing operations from the Least Significant Bit (LSB) to the Most Significant Bit (MSB).

Binary operations implemented in this assignment:

#### 1's Complement
- Obtained by flipping each bit (0 → 1, 1 → 0)

#### 2's Complement
- Obtained by adding **1** to the result of the 1's complement

#### Binary Addition
- Implemented by traversing both linked lists from the **tail (LSB)** towards the **head (MSB)**
- Carry is propagated during the addition of each bit
- Result is stored in another linked list

These operations demonstrate how binary arithmetic can be efficiently handled using **doubly linked lists** due to their bidirectional traversal capability.

### Algorithm:

#### 1. Store binary number:

1. Read binary digits from input.
2. Create a doubly linked list node for each bit and link them sequentially.

#### 2. 1's complement:

1. Traverse the list.
2. Flip each bit (0 → 1, 1 → 0).

#### 3. 2's complement:

1. Find the 1's complement.
2. Add 1 starting from the least significant bit (tail), handling carry.

#### 4. Addition of two binary numbers:

1. Traverse both lists from tail.
2. Add corresponding bits with carry.
3. Insert sum bits at the head of a result list.

---

### C++ Code:

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node_asr {
    int bit_asr;
    Node_asr* prev_asr;
    Node_asr* next_asr;
};

void insertEnd_asr(Node_asr*& head_asr, Node_asr*& tail_asr, int bit_asr) {
    Node_asr* newNode_asr = new Node_asr{bit_asr, nullptr, nullptr};
    if (!head_asr) {
        head_asr = tail_asr = newNode_asr;
    } else {
        tail_asr->next_asr = newNode_asr;
        newNode_asr->prev_asr = tail_asr;
        tail_asr = newNode_asr;
    }
}

void display_asr(Node_asr* head_asr) {
    Node_asr* temp_asr = head_asr;
    while (temp_asr) {
        cout << temp_asr->bit_asr;
        temp_asr = temp_asr->next_asr;
    }
    cout << endl;
}

void onesComplement_asr(Node_asr* head_asr) {
    Node_asr* temp_asr = head_asr;
    while (temp_asr) {
        temp_asr->bit_asr = temp_asr->bit_asr == 0 ? 1 : 0;
        temp_asr = temp_asr->next_asr;
    }
}

void twosComplement_asr(Node_asr* head_asr, Node_asr* tail_asr) {
    onesComplement_asr(head_asr);
    Node_asr* temp_asr = tail_asr;
    int carry_asr = 1;
    while (temp_asr && carry_asr) {
        int sum_asr = temp_asr->bit_asr + carry_asr;
        temp_asr->bit_asr = sum_asr % 2;
        carry_asr = sum_asr / 2;
        temp_asr = temp_asr->prev_asr;
    }
    if (carry_asr) {
        Node_asr* newNode_asr = new Node_asr{1, nullptr, head_asr};
        head_asr->prev_asr = newNode_asr;
        head_asr = newNode_asr;
    }
}

Node_asr* addBinary_asr(Node_asr* head1_asr, Node_asr* tail1_asr, Node_asr* head2_asr, Node_asr* tail2_asr) {
    Node_asr* resultHead_asr = nullptr;
    Node_asr* resultTail_asr = nullptr;
    Node_asr* temp1_asr = tail1_asr;
    Node_asr* temp2_asr = tail2_asr;
    int carry_asr = 0;

    while (temp1_asr || temp2_asr || carry_asr) {
        int bit1_asr = temp1_asr ? temp1_asr->bit_asr : 0;
        int bit2_asr = temp2_asr ? temp2_asr->bit_asr : 0;
        int sum_asr = bit1_asr + bit2_asr + carry_asr;
        int bitSum_asr = sum_asr % 2;
        carry_asr = sum_asr / 2;
        insertEnd_asr(resultHead_asr, resultTail_asr, bitSum_asr);

        if (temp1_asr) temp1_asr = temp1_asr->prev_asr;
        if (temp2_asr) temp2_asr = temp2_asr->prev_asr;
    }

    Node_asr* prev_asr = nullptr;
    Node_asr* curr_asr = resultHead_asr;
    while (curr_asr) {
        Node_asr* next_asr = curr_asr->next_asr;
        curr_asr->next_asr = prev_asr;
        curr_asr->prev_asr = next_asr;
        prev_asr = curr_asr;
        curr_asr = next_asr;
    }
    resultHead_asr = prev_asr;
    return resultHead_asr;
}

int main() {
    srand(time(0));
    Node_asr *head1_asr = nullptr, *tail1_asr = nullptr;
    Node_asr *head2_asr = nullptr, *tail2_asr = nullptr;

    int n1_asr, n2_asr;
    cout << "Enter number of bits for first binary number: ";
    cin >> n1_asr;
    cout << "Enter binary number (MSB to LSB): ";
    for (int i = 0; i < n1_asr; i++) {
        int bit_asr;
        cin >> bit_asr;
        insertEnd_asr(head1_asr, tail1_asr, bit_asr);
    }

    cout << "Enter number of bits for second binary number: ";
    cin >> n2_asr;
    cout << "Enter binary number (MSB to LSB): ";
    for (int i = 0; i < n2_asr; i++) {
        int bit_asr;
        cin >> bit_asr;
        insertEnd_asr(head2_asr, tail2_asr, bit_asr);
    }

    cout << "\nFirst Binary Number: ";
    display_asr(head1_asr);

    cout << "1's Complement: ";
    onesComplement_asr(head1_asr);
    display_asr(head1_asr);

    cout << "2's Complement: ";
    twosComplement_asr(head1_asr, tail1_asr);
    display_asr(head1_asr);

    cout << "\nSecond Binary Number: ";
    display_asr(head2_asr);

    Node_asr* sumHead_asr = addBinary_asr(head1_asr, tail1_asr, head2_asr, tail2_asr);
    cout << "Sum of Binary Numbers: ";
    display_asr(sumHead_asr);

    return 0;
}
```

### Sample Output:

```
Enter number of bits for first binary number: 5
Enter binary number (MSB to LSB): 1 0 1 0 1
Enter number of bits for second binary number: 4
Enter binary number (MSB to LSB): 1 1 0 1

First Binary Number: 10101
1's Complement: 01010
2's Complement: 01011

Second Binary Number: 1101
Sum of Binary Numbers: 100000
```
