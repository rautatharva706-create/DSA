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
        cout << endl;
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