# Assignment No: 5 Problem: 3

## Title: Implementation of Multiple Stacks using Array

### Theory

A **stack** is a linear data structure that follows the **LIFO (Last In, First Out)** rule, meaning the most recently inserted element is the first one to be removed. In real-world applications, there are situations where **multiple stacks** need to operate simultaneously — such as managing multiple function calls, handling different expression evaluations, or dividing memory into separate stack segments.

To implement **multiple stacks using a single array**, the array is divided into fixed partitions, where each partition represents a separate stack. Every stack maintains its own pointers:
- `start_asr` → starting index of the stack segment  
- `end_asr` → ending index of the stack segment  
- `top_asr` → pointer to the current top element of that stack  

**Overflow** occurs when a stack exceeds its allocated segment, while **underflow** happens when a pop operation is attempted on a stack with no elements. This method ensures efficient use of memory while supporting multiple independent stacks within one array.

### Algorithm

**Step 1:** Start the program.

**Step 2:** Initialize variables:

* Define an array `stack_asr[MAX]` to store stack elements.
* Create arrays `top_asr[]`, `start_asr[]`, and `end_asr[]` to manage multiple stacks within the same array.
* Initialize `top_asr[i] = start_asr[i] - 1` for all stacks (indicating they are empty).

**Step 3:** **Push Operation**

1. Input the stack number `n_asr` and the element `val_asr` to be pushed.
2. Check for **Stack Overflow**:

   * If `top_asr[n_asr] == end_asr[n_asr]`, display "Stack Overflow" and return.
3. Otherwise, increment `top_asr[n_asr]` and assign `stack_asr[top_asr[n_asr]] = val_asr`.
4. Display message "Element pushed successfully."

**Step 4:** **Pop Operation**

1. Input the stack number `n_asr` from which to pop.
2. Check for **Stack Underflow**:

   * If `top_asr[n_asr] < start_asr[n_asr]`, display "Stack Underflow" and return.
3. Otherwise, retrieve the top element `val_asr = stack_asr[top_asr[n_asr]]`.
4. Decrement `top_asr[n_asr]` and display the popped value.

**Step 5:** **Display Operation**

1. Input the stack number `n_asr` to display.
2. Check if the stack is empty:

   * If `top_asr[n_asr] < start_asr[n_asr]`, display "Stack is empty."
3. Otherwise, print all elements from `top_asr[n_asr]` down to `start_asr[n_asr]`.

**Step 6:** **Menu-Driven Control**

1. Display menu options:

   * 1. Push
   * 2. Pop
   * 3. Display
   * 0. Exit
2. Use a loop to repeatedly ask for user choice and perform the corresponding operation until the user selects Exit.

**Step 7:** End the program.

### C++ Code

```cpp
#include <iostream>
using namespace std;

#define MAX_asr 50

int main() {
    int stack_asr[MAX_asr];
    int top_asr[3], start_asr[3], end_asr[3];
    int nStacks_asr = 3;
    int size_asr = MAX_asr / nStacks_asr;

    for (int i_asr = 0; i_asr < nStacks_asr; i_asr++) {
        start_asr[i_asr] = i_asr * size_asr;
        end_asr[i_asr] = start_asr[i_asr] + size_asr - 1;
        top_asr[i_asr] = start_asr[i_asr] - 1;
    }

    int choice_asr, stackNum_asr, val_asr;
    do {
        cout << "\n---Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Display\n0. Exit\nEnter your choice: ";
        cin >> choice_asr;

        switch (choice_asr) {
            case 1:
                cout << "Enter stack number (0-2): ";
                cin >> stackNum_asr;
                if (stackNum_asr < 0 || stackNum_asr >= nStacks_asr) {
                    cout << "Invalid stack number!\n";
                    break;
                }
                if (top_asr[stackNum_asr] == end_asr[stackNum_asr]) {
                    cout << "Stack Overflow in Stack " << stackNum_asr << "!\n";
                } else {
                    cout << "Enter value to push: ";
                    cin >> val_asr;
                    top_asr[stackNum_asr]++;
                    stack_asr[top_asr[stackNum_asr]] = val_asr;
                    cout << "Element pushed successfully!\n";
                }
                break;

            case 2:
                cout << "Enter stack number (0-2): ";
                cin >> stackNum_asr;
                if (stackNum_asr < 0 || stackNum_asr >= nStacks_asr) {
                    cout << "Invalid stack number!\n";
                    break;
                }
                if (top_asr[stackNum_asr] < start_asr[stackNum_asr]) {
                    cout << "Stack Underflow in Stack " << stackNum_asr << "!\n";
                } else {
                    cout << "Popped Element: " << stack_asr[top_asr[stackNum_asr]--] << "\n";
                }
                break;

            case 3:
                cout << "Enter stack number (0-2): ";
                cin >> stackNum_asr;
                if (stackNum_asr < 0 || stackNum_asr >= nStacks_asr) {
                    cout << "Invalid stack number!\n";
                    break;
                }
                if (top_asr[stackNum_asr] < start_asr[stackNum_asr]) {
                    cout << "Stack is empty.\n";
                } else {
                    cout << "Stack " << stackNum_asr << " contents: ";
                    for (int i_asr = top_asr[stackNum_asr]; i_asr >= start_asr[stackNum_asr]; i_asr--)
                        cout << stack_asr[i_asr] << " ";
                    cout << "\n";
                }
                break;

            case 0:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice_asr != 0);

    return 0;
}
```

### Output

```
--- Menu ---
1. Push
2. Pop
3. Display
0. Exit
Enter your choice: 1
Enter stack number (0-2): 0
Enter value to push: 10
Element pushed successfully!

Enter your choice: 1
Enter stack number (0-2): 0
Enter value to push: 20
Element pushed successfully!

Enter your choice: 3
Enter stack number (0-2): 0
Stack 0 contents: 20 10

Enter your choice: 2
Enter stack number (0-2): 0
Popped Element: 20

Enter your choice: 3
Enter stack number (0-2): 0
Stack 0 contents: 10

Enter your choice: 0
Exiting program.
```
