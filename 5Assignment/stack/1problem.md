# Assignment No: 5 Problem: 1

## Title: Stock Price Tracker Using Stack (Linked List Implementation)

### Theory

A **stack** is a linear data structure based on the **Last-In-First-Out (LIFO)** concept, where the latest inserted element is the first to be removed. In this assignment, the stack is implemented using a **singly linked list** to maintain stock prices dynamically. Each node stores a price entry along with a pointer to the next element in the stack.

Users can:
- **Push** a new stock price onto the stack
- **Pop** the most recent price
- **Peek** to view the current top price
- Check whether the stack is **empty**

Using a linked list for stack implementation offers flexibility, as memory is allocated only when needed and there is no fixed-size limitation unlike arrays.  
The menu-driven structure enables user-friendly interaction with stack operations, providing a practical demonstration of dynamic data handling and the LIFO behavior.


### Algorithm

**Algorithm: Stock Price Tracker Using Stack**

1. **Start**
2. Initialize the top pointer `top_asr` as `NULL`.
3. Display a menu with the following options:

   * Record a new price
   * Remove the most recent price
   * View the latest price
   * Check if the stack is empty
   * Exit
4. **If the user selects Record:**

   * Create a new node.
   * Read the stock price from the user.
   * Set the `data_asr` of the new node to the entered price.
   * Point the `next_asr` of the new node to `top_asr`.
   * Update `top_asr` to the new node.
5. **If the user selects Remove:**

   * Check if `top_asr` is `NULL`. If yes, display “No prices to remove.”
   * Else, store the price in a temporary variable, move `top_asr` to the next node, and delete the old node.
   * Display the removed price.
6. **If the user selects Latest:**

   * Check if `top_asr` is `NULL`. If yes, display “No prices recorded.”
   * Else, display the `data_asr` value of `top_asr`.
7. **If the user selects Check Empty:**

   * If `top_asr` is `NULL`, display “Stack is empty.”
   * Else, display “Stack is not empty.”
8. Repeat steps 3–7 until the user selects Exit.
9. **Stop**

### C++ Code

```cpp
#include <iostream>
#include <cstdlib>
using namespace std;

struct Node_asr {
    int data_asr;
    Node_asr* next_asr;
};

Node_asr* top_asr = NULL;

void record_asr(int price_asr) {
    Node_asr* newNode_asr = new Node_asr();
    newNode_asr->data_asr = price_asr;
    newNode_asr->next_asr = top_asr;
    top_asr = newNode_asr;
    cout << "Recorded price: " << price_asr << endl;
}

void remove_asr() {
    if (top_asr == NULL) {
        cout << "No prices to remove!" << endl;
        return;
    }
    Node_asr* temp_asr = top_asr;
    cout << "Removed latest price: " << temp_asr->data_asr << endl;
    top_asr = top_asr->next_asr;
    delete temp_asr;
}

void latest_asr() {
    if (top_asr == NULL) {
        cout << "No prices recorded!" << endl;
        return;
    }
    cout << "Latest recorded price: " << top_asr->data_asr << endl;
}

void isEmpty_asr() {
    if (top_asr == NULL)
        cout << "Stack is empty." << endl;
    else
        cout << "Stack is not empty." << endl;
}

int main() {
    int choice_asr, price_asr;

    while (true) {
        cout << "\n===== Stock Price Tracker =====" << endl;
        cout << "1. Record new price" << endl;
        cout << "2. Remove latest price" << endl;
        cout << "3. View latest price" << endl;
        cout << "4. Check if stack is empty" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice_asr;

        switch (choice_asr) {
            case 1:
                cout << "Enter stock price: ";
                cin >> price_asr;
                record_asr(price_asr);
                break;

            case 2:
                remove_asr();
                break;

            case 3:
                latest_asr();
                break;

            case 4:
                isEmpty_asr();
                break;

            case 5:
                cout << "Exiting program..." << endl;
                exit(0);

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}
```

### Output

```

1. Record new price
2. Remove latest price
3. View latest price
4. Check if stack is empty
5. Exit
Enter your choice: 1
Enter stock price: 1500
Recorded price: 1500

Enter your choice: 1
Enter stock price: 1520
Recorded price: 1520

Enter your choice: 3
Latest recorded price: 1520

Enter your choice: 2
Removed latest price: 1520

Enter your choice: 4
Stack is not empty.

Enter your choice: 5
Exiting program...
```
