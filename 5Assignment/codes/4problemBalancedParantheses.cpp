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