# Assignment No: 4 Problem : 4

## Title: Doubly Linked List Operations (Insert & Delete)

### Theory

A **doubly linked list (DLL)** is a type of linked list in which each node contains three components:
- A **data field** to store the value
- A **pointer to the next node**
- A **pointer to the previous node**

This bidirectional linkage allows traversal in **both forward and backward** directions, making insertions and deletions more flexible compared to a singly linked list.

In this assignment, dynamic memory allocation is used to create nodes at runtime. The following operations are performed using a **menu-driven program**:
- **Insertion**:
  - At the beginning
  - At the end
  - After a given element
- **Deletion**:
  - From the beginning
  - From the end
  - After a given element

A doubly linked list provides efficient manipulation of data with minimal pointer adjustments during these operations.

### Algorithm

**Step 1: Initialize the Doubly Linked List**

1.  Create a struct Node\_asr with fields data\_asr, prev\_asr, and next\_asr.
    
2.  Initialize a pointer head\_asr to nullptr to represent an empty list.
    

**Step 2: Menu-Driven Program**

1.  Display options for insertion, deletion, display, and exit.
    
2.  Take the user’s choice and call the respective function.
    

**Step 3: Insertion Operations**

**a) Insert at Beginning:**

1.  Create a new node newNode\_asr.
    
2.  Assign newNode\_asr->data\_asr the value entered by the user.
    
3.  Set newNode\_asr->next\_asr = head\_asr and newNode\_asr->prev\_asr = nullptr.
    
4.  If the list is not empty, update head\_asr->prev\_asr = newNode\_asr.
    
5.  Update head\_asr = newNode\_asr.
    

**b) Insert at End:**

1.  Create a new node newNode\_asr.
    
2.  If the list is empty, make it the head node.
    
3.  Otherwise, traverse the list to the last node.
    
4.  Set the last node’s next\_asr to newNode\_asr and newNode\_asr->prev\_asr to the last node.
    

**c) Insert After a Particular Node:**

1.  Traverse the list to find the node with the target value.
    
2.  If found, create newNode\_asr.
    
3.  Adjust the next\_asr and prev\_asr pointers of the surrounding nodes to insert newNode\_asr after the target node.
    

**Step 4: Deletion Operations**

**a) Delete at Beginning:**

1.  If the list is empty, display “List is empty”.
    
2.  Otherwise, save head\_asr in a temporary pointer.
    
3.  Update head\_asr = head\_asr->next\_asr.
    
4.  If the new head exists, set head\_asr->prev\_asr = nullptr.
    
5.  Delete the temporary node.
    

**b) Delete at End:**

1.  Traverse to the last node.
    
2.  Update the previous node’s next\_asr to nullptr.
    
3.  Delete the last node.
    

**c) Delete After a Particular Node:**

1.  Traverse to the node with the given value.
    
2.  If the node exists and has a next node, adjust pointers to skip the next node.
    
3.  Delete the skipped node.
    

**Step 5: Display the List**

1.  Traverse from head\_asr to the end, printing each data\_asr.
    
2.  Optionally, traverse backward from the last node to demonstrate the doubly linked nature.
    

**Step 6: Repeat Until Exit**

*   The program loops back to the menu until the user chooses the exit option.

### C++ Code

```cpp
#include <iostream>
using namespace std;

struct Node_asr {
    int data_asr;
    Node_asr* next_asr;
    Node_asr* prev_asr;
};

// Insert at beginning
void insertAtBegin_asr(Node_asr*& head_asr, int value_asr) {
    Node_asr* newNode_asr = new Node_asr{value_asr, head_asr, nullptr};
    if (head_asr)
        head_asr->prev_asr = newNode_asr;
    head_asr = newNode_asr;
}

// Insert at end
void insertAtEnd_asr(Node_asr*& head_asr, int value_asr) {
    Node_asr* newNode_asr = new Node_asr{value_asr, nullptr, nullptr};
    if (!head_asr) {
        head_asr = newNode_asr;
        return;
    }
    Node_asr* temp_asr = head_asr;
    while (temp_asr->next_asr) temp_asr = temp_asr->next_asr;
    temp_asr->next_asr = newNode_asr;
    newNode_asr->prev_asr = temp_asr;
}

// Insert after a particular element
void insertAfterElement_asr(Node_asr* head_asr, int target_asr, int value_asr) {
    Node_asr* temp_asr = head_asr;
    while (temp_asr && temp_asr->data_asr != target_asr)
        temp_asr = temp_asr->next_asr;
    if (!temp_asr) {
        cout << "Element not found.\n";
        return;
    }
    Node_asr* newNode_asr = new Node_asr{value_asr, temp_asr->next_asr, temp_asr};
    if (temp_asr->next_asr)
        temp_asr->next_asr->prev_asr = newNode_asr;
    temp_asr->next_asr = newNode_asr;
}

// Delete at beginning
void deleteAtBegin_asr(Node_asr*& head_asr) {
    if (!head_asr) return;
    Node_asr* temp_asr = head_asr;
    head_asr = head_asr->next_asr;
    if (head_asr)
        head_asr->prev_asr = nullptr;
    delete temp_asr;
}

// Delete at end
void deleteAtEnd_asr(Node_asr*& head_asr) {
    if (!head_asr) return;
    Node_asr* temp_asr = head_asr;
    while (temp_asr->next_asr) temp_asr = temp_asr->next_asr;
    if (temp_asr->prev_asr)
        temp_asr->prev_asr->next_asr = nullptr;
    else
        head_asr = nullptr;
    delete temp_asr;
}

// Delete after a particular element
void deleteAfterElement_asr(Node_asr* head_asr, int target_asr) {
    Node_asr* temp_asr = head_asr;
    while (temp_asr && temp_asr->data_asr != target_asr)
        temp_asr = temp_asr->next_asr;
    if (!temp_asr || !temp_asr->next_asr) {
        cout << "No element to delete after target.\n";
        return;
    }
    Node_asr* delNode_asr = temp_asr->next_asr;
    temp_asr->next_asr = delNode_asr->next_asr;
    if (delNode_asr->next_asr)
        delNode_asr->next_asr->prev_asr = temp_asr;
    delete delNode_asr;
}

// Display the list
void displayList_asr(Node_asr* head_asr) {
    if (!head_asr) {
        cout << "List is empty.\n";
        return;
    }
    Node_asr* temp_asr = head_asr;
    cout << "Doubly Linked List: ";
    while (temp_asr) {
        cout << temp_asr->data_asr << " ";
        temp_asr = temp_asr->next_asr;
    }
    cout << endl;
}

int main() {
    Node_asr* head_asr = nullptr;
    int choice_asr, value_asr, target_asr;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert After Element\n";
        cout << "4. Delete at Beginning\n5. Delete at End\n6. Delete After Element\n";
        cout << "7. Display List\n0. Exit\nEnter your choice: ";
        cin >> choice_asr;

        switch(choice_asr) {
            case 1:
                cout << "Enter value: "; cin >> value_asr;
                insertAtBegin_asr(head_asr, value_asr);
                break;
            case 2:
                cout << "Enter value: "; cin >> value_asr;
                insertAtEnd_asr(head_asr, value_asr);
                break;
            case 3:
                cout << "Enter target element: "; cin >> target_asr;
                cout << "Enter value to insert: "; cin >> value_asr;
                insertAfterElement_asr(head_asr, target_asr, value_asr);
                break;
            case 4:
                deleteAtBegin_asr(head_asr);
                break;
            case 5:
                deleteAtEnd_asr(head_asr);
                break;
            case 6:
                cout << "Enter target element: "; cin >> target_asr;
                deleteAfterElement_asr(head_asr, target_asr);
                break;
            case 7:
                displayList_asr(head_asr);
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while(choice_asr != 0);

    return 0;
}
```

### Sample Output

```
Menu:
1. Insert at Beginning
2. Insert at End
3. Insert After Element
4. Delete at Beginning
5. Delete at End
6. Delete After Element
7. Display List
0. Exit
Enter your choice: 1
Enter value: 10

Enter your choice: 2
Enter value: 20

Enter your choice: 3
Enter target element: 10
Enter value to insert: 15

Enter your choice: 7
Doubly Linked List: 10 15 20

Enter your choice: 4
Enter your choice: 7
Doubly Linked List: 15 20

Enter your choice: 0
Exiting program.
```
