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