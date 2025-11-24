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