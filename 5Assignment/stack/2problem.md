# Assignment No: 8

## Title
Conversion of Infix Expression to Postfix Expression using Stack

---

### Theory

#### Introduction
Arithmetic expressions can be written in **three different notations** —  
**Infix**, **Prefix (Polish Notation)**, and **Postfix (Reverse Polish Notation)**.

- **Infix Notation:** Operator appears **between operands**.  
  Example: `A + B * C`  
  (Requires parentheses and precedence rules to understand order.)

- **Prefix Notation:** Operator appears **before operands**.  
  Example: `+ A * B C`

- **Postfix Notation:** Operator appears **after operands**.  
  Example: `A B C * +`

Compilers and interpreters prefer **postfix expressions** because:
1. No parentheses are needed
2. Operator precedence and associativity issues are removed
3. Easy and efficient evaluation using stacks

#### Why use a Stack for Conversion?
Stacks follow the **Last-In-First-Out (LIFO)** rule.  
This is ideal for storing operators temporarily while scanning an infix expression since:
- Operators with higher precedence should be processed first
- Recent operators must be handled before older ones

#### Operator Precedence and Associativity
| Operator | Precedence | Associativity |
|---------|------------|---------------|
| `*`, `/` | High       | Left-to-Right |
| `+`, `-` | Medium     | Left-to-Right |

Operators with higher precedence execute earlier in postfix.

#### Working Principle
To convert **infix ➝ postfix**, we:
1. Scan the expression **from left to right**
2. If the character is an **operand** → add to postfix output
3. If it is an **operator**:
   - Remove operators from stack that have **higher or equal precedence**
   - Then push the current operator
4. Push `(` into the stack
5. On encountering `)` → pop until `(` is found
6. At the end, pop all remaining operators from the stack into postfix

#### Example
Infix Expression:  
`a - b * c - d / e + f`

Conversion Logic:
- Output operands directly
- Manage operators on stack using precedence
- Remove parentheses properly

Final Postfix Expression:  
**`abc*-de/-f+`**

---

Postfix notation ensures **unambiguous evaluation** and is widely used in expression processing, compilers, and stack-based processor designs.

---

### Algorithm

1. **Initialize** an empty stack for operators.
2. **Scan** the infix expression from left to right.
3. **If** the symbol is an **operand**, append it to postfix.
4. **If** the symbol is an **operator**:
   - While the stack is **not empty** and the top of the stack has **higher or equal precedence**,  
     pop it and append to postfix.
   - Push the current operator onto the stack.
5. **If** the symbol is `'('`, push it onto the stack.
6. **If** the symbol is `')'`, pop until `'('` is found.
7. **After the expression ends**, pop all remaining operators from the stack to postfix.
8. Display the final postfix expression.

---

### C++ Code
```cpp
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check precedence
int precedence_asr(char op_asr) {
    if (op_asr == '+' || op_asr == '-') return 1;
    if (op_asr == '*' || op_asr == '/') return 2;
    return 0;
}

// Function to convert infix to postfix
string infixToPostfix_asr(const string& infix_asr) {
    stack<char> st_asr;
    string postfix_asr = "";

    cout << "Step-by-Step Stack Operations:\n";
    cout << "------------------------------------------\n";
    cout << "Symbol\t\tAction\t\t\tStack\t\tPostfix\n";
    cout << "------------------------------------------\n";

    for (char c_asr : infix_asr) {
        if (isalnum(c_asr)) {
            postfix_asr += c_asr;
            cout << c_asr << "\t\tOperand → Add to postfix\t";
        } 
        else if (c_asr == '(') {
            st_asr.push(c_asr);
            cout << c_asr << "\t\t'(' → Push to stack\t\t";
        } 
        else if (c_asr == ')') {
            while (!st_asr.empty() && st_asr.top() != '(') {
                postfix_asr += st_asr.top();
                st_asr.pop();
            }
            if (!st_asr.empty()) st_asr.pop();
            cout << c_asr << "\t\t')' → Pop till '('\t\t";
        } 
        else {
            while (!st_asr.empty() && precedence_asr(st_asr.top()) >= precedence_asr(c_asr)) {
                postfix_asr += st_asr.top();
                st_asr.pop();
            }
            st_asr.push(c_asr);
            cout << c_asr << "\t\tOperator → Push to stack\t";
        }

        // Display current stack
        stack<char> temp_asr = st_asr;
        string stkContent_asr = "";
        while (!temp_asr.empty()) {
            stkContent_asr = temp_asr.top() + stkContent_asr;
            temp_asr.pop();
        }
        cout << stkContent_asr << "\t\t" << postfix_asr << endl;
    }

    while (!st_asr.empty()) {
        postfix_asr += st_asr.top();
        st_asr.pop();
    }

    cout << "------------------------------------------\n";
    cout << "Final Postfix Expression: " << postfix_asr << endl;

    return postfix_asr;
}

int main() {
    string infix_asr = "a-b*c-d/e+f";
    cout << "Infix Expression: " << infix_asr << endl;
    string postfix_asr = infixToPostfix_asr(infix_asr);
    cout << "\nPostfix Expression: " << postfix_asr << endl;
    return 0;
}
```
# OUTPUT
```
Infix Expression: a-b*c-d/e+f

Step-by-Step Stack Operations:
------------------------------------------
Symbol    Action                      Stack        Postfix
------------------------------------------
a         Operand → Add to postfix                a
-         Operator → Push to stack      -          a
b         Operand → Add to postfix      -          ab
*         Operator → Push to stack      -*         ab
c         Operand → Add to postfix      -*         abc
-         Operator → Push to stack      -          abc*-
d         Operand → Add to postfix      -          abc*-d
/         Operator → Push to stack      -/         abc*-d
e         Operand → Add to postfix      -/         abc*-de
+         Operator → Push to stack      +          abc*-de/-
f         Operand → Add to postfix      +          abc*-de/-f
------------------------------------------
Final Postfix Expression: abc*-de/-f+
```