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
            cout << c_asr << "\t\tOperand  Add to postfix\t";
        } 
        else if (c_asr == '(') {
            st_asr.push(c_asr);
            cout << c_asr << "\t\t'('  Push to stack\t\t";
        } 
        else if (c_asr == ')') {
            while (!st_asr.empty() && st_asr.top() != '(') {
                postfix_asr += st_asr.top();
                st_asr.pop();
            }
            if (!st_asr.empty()) st_asr.pop();
            cout << c_asr << "\t\t')'  Pop till '('\t\t";
        } 
        else {
            while (!st_asr.empty() && precedence_asr(st_asr.top()) >= precedence_asr(c_asr)) {
                postfix_asr += st_asr.top();
                st_asr.pop();
            }
            st_asr.push(c_asr);
            cout << c_asr << "\t\tOperator  Push to stack\t";
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