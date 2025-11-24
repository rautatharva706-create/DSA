# Assignment No: 5 Problem: 4

## Title: Balanced Parentheses Check Using Stack

### Theory

A string containing parentheses, brackets, or braces is said to be **balanced** when every opening symbol has a matching closing symbol of the same type, and the order of closing is correct. Ensuring balanced parentheses is crucial in areas like programming language syntax checking, expression parsing, and compiler design to maintain structural correctness.

The most effective approach to validate balanced symbols is by using a **stack**, since it follows the Last-In-First-Out (LIFO) principle:

- Scan the string from left to right.
- When an opening symbol is encountered, **push** it onto the stack.
- When a closing symbol appears:
  - Check if the stack is not empty and the top element is the corresponding opening symbol.
  - If it matches, **pop** the top element.
  - Otherwise, the string is immediately marked as unbalanced.
- After processing the entire string:
  - If the stack is empty → the expression is **balanced**.
  - If not → one or more symbols are unmatched → **unbalanced**.

This stack-based approach ensures both **correct matching** and **proper nesting** of symbols.

### Algorithm

1. Initialize an empty stack.
2. Traverse each character `ch_asr` in the string:

   * If `ch_asr` is an opening bracket `(`, `{`, or `[`, push it onto the stack.
   * If `ch_asr` is a closing bracket `)`, `}`, or `]`:

     * If the stack is empty, return unbalanced.
     * Otherwise, pop the top element from the stack.
     * Check if the popped element matches the type of `ch_asr`. If not, return unbalanced.
3. After traversal:

   * If the stack is empty, the string is balanced.
   * If the stack is not empty, return unbalanced.
4. End.

**Notes:**

* The stack ensures **Last-In-First-Out (LIFO)** order, which guarantees proper nesting.
* This algorithm runs in **O(n)** time, where `n` is the length of the string.
* Space complexity is **O(n)** for the stack.

### C++ Code

```cpp
#include <iostream>
#include <string>
using namespace std;

struct StackNode_asr {
    char data_asr;
    StackNode_asr* next_asr;
};

struct Stack_asr {
    StackNode_asr* top_asr;
};

void push_asr(Stack_asr &stack_asr, char ch_asr) {
    StackNode_asr* newNode_asr = new StackNode_asr{ch_asr, stack_asr.top_asr};
    stack_asr.top_asr = newNode_asr;
}

char pop_asr(Stack_asr &stack_asr) {
    if (!stack_asr.top_asr) return '\0';
    StackNode_asr* temp_asr = stack_asr.top_asr;
    char ch_asr = temp_asr->data_asr;
    stack_asr.top_asr = stack_asr.top_asr->next_asr;
    delete temp_asr;
    return ch_asr;
}

char peek_asr(Stack_asr &stack_asr) {
    return stack_asr.top_asr ? stack_asr.top_asr->data_asr : '\0';
}

bool isEmpty_asr(Stack_asr &stack_asr) {
    return stack_asr.top_asr == nullptr;
}

bool isBalanced_asr(const string &expr_asr) {
    Stack_asr stack_asr{nullptr};
    for (char ch_asr : expr_asr) {
        if (ch_asr == '(' || ch_asr == '{' || ch_asr == '[') {
            push_asr(stack_asr, ch_asr);
        } else if (ch_asr == ')' || ch_asr == '}' || ch_asr == ']') {
            if (isEmpty_asr(stack_asr)) return false;
            char top_asr = pop_asr(stack_asr);
            if ((ch_asr == ')' && top_asr != '(') ||
                (ch_asr == '}' && top_asr != '{') ||
                (ch_asr == ']' && top_asr != '['))
                return false;
        }
    }
    return isEmpty_asr(stack_asr);
}

int main() {
    string expr_asr;
    cout << "Enter a string of parentheses: ";
    cin >> expr_asr;
    
    if (isBalanced_asr(expr_asr))
        cout << "The expression is balanced.\n";
    else
        cout << "The expression is NOT balanced.\n";
    
    return 0;
}
```

### Output

```
Enter a string of parentheses: Prithviraj
The expression is balanced.
Enter a string of parentheses: {Prithviraj
The expression is NOT balanced.
```
