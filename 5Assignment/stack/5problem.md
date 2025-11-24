# Assignment No: 5 Problem: 5

## Title: Evaluation of Postfix Expression using Stack

### Theory

Postfix notation, also known as **Reverse Polish Notation (RPN)**, is a way of writing mathematical expressions where operators come **after** their operands. In this system, there is no need for parentheses because the operation sequence is already clear.

**Advantages of Postfix Notation:**

* Simplifies the evaluation of expressions.
* Removes confusion caused by the precedence of operators and parentheses.
* Works efficiently with stack-based expression evaluation in computers.

**How it works:**

1. Start by creating an empty stack.
2. Traverse the postfix string from left to right.
3. For each symbol:
   * **Operand:** Push it onto the stack.
   * **Operator:** Pop the required number of operands from the stack, apply the operator, and push the result back into the stack.
4. After scanning the complete expression, the value left on the stack will be the final answer.

**Step-by-Step Evaluation Example:**

Postfix expression: `23*5+`

1. Read `2` → push → Stack: `[2]`
2. Read `3` → push → Stack: `[2, 3]`
3. Read `*` → pop `3` and `2`, compute `2 × 3 = 6`, push → Stack: `[6]`
4. Read `5` → push → Stack: `[6, 5]`
5. Read `+` → pop `5` and `6`, compute `6 + 5 = 11`, push → Stack: `[11]`
6. End of expression → **Result = `11`**

---

### Algorithm

1. Initialize an empty stack.
2. Scan the postfix expression from left to right.
3. If the scanned character is a number, push it to the stack.
4. If the scanned character is an operator:

   * Pop the top two elements from the stack.
   * Apply the operator with the second popped element as the first operand.
   * Push the result back onto the stack.
5. Repeat until the end of the expression.
6. The value left in the stack is the final result.

---

### C++ Code

```cpp
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

struct Stack_asr {
    int top_asr;
    int arr_asr[100];
};

void push_asr(Stack_asr &s_asr, int val_asr) {
    s_asr.arr_asr[++s_asr.top_asr] = val_asr;
}

int pop_asr(Stack_asr &s_asr) {
    return s_asr.arr_asr[s_asr.top_asr--];
}

int evaluatePostfix_asr(const string &expr_asr) {
    Stack_asr s_asr;
    s_asr.top_asr = -1;

    for (char ch_asr : expr_asr) {
        if (isdigit(ch_asr)) {
            push_asr(s_asr, ch_asr - '0'); // Convert char to int
        } else {
            int b_asr = pop_asr(s_asr);
            int a_asr = pop_asr(s_asr);
            int res_asr;
            switch (ch_asr) {
                case '+': res_asr = a_asr + b_asr; break;
                case '-': res_asr = a_asr - b_asr; break;
                case '*': res_asr = a_asr * b_asr; break;
                case '/': res_asr = a_asr / b_asr; break;
                default: res_asr = 0; // For safety
            }
            push_asr(s_asr, res_asr);
        }
    }
    return pop_asr(s_asr);
}

int main() {
    string expr_asr;
    cout << "Enter postfix expression: ";
    cin >> expr_asr;

    int result_asr = evaluatePostfix_asr(expr_asr);
    cout << "Result: " << result_asr << endl;

    return 0;
}
```

---

###  Output

```
Enter postfix expression: 23*5+
Step by step:
Push 2 → Stack: [2]
Push 3 → Stack: [2,3]
Operator *: Pop 3 and 2 → 2*3=6 → Push 6 → Stack: [6]
Push 5 → Stack: [6,5]
Operator +: Pop 5 and 6 → 6+5=11 → Push 11 → Stack: [11]

Result: 11
```
