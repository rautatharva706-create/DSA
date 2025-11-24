#include <iostream>
using namespace std;

struct Node_asr {
    int data_asr;
    Node_asr* next_asr;
    Node_asr* prev_asr;
};

// Insert at beginning
void insertAtBegin_asr(Node_asr*& head_asr, int value_asr) {
    Node_asr* newNode_asr = new Node_asr{value_asr, head_asr, nullptr};
    if (head_asr)
        head_asr->prev_asr = newNode_asr;
    head_asr = newNode_asr;
}

// Insert at end
void insertAtEnd_asr(Node_asr*& head_asr, int value_asr) {
    Node_asr* newNode_asr = new Node_asr{value_asr, nullptr, nullptr};
    if (!head_asr) {
        head_asr = newNode_asr;
        return;
    }
    Node_asr* temp_asr = head_asr;
    while (temp_asr->next_asr) temp_asr = temp_asr->next_asr;
    temp_asr->next_asr = newNode_asr;
    newNode_asr->prev_asr = temp_asr;
}

// Insert after a particular element
void insertAfterElement_asr(Node_asr* head_asr, int target_asr, int value_asr) {
    Node_asr* temp_asr = head_asr;
    while (temp_asr && temp_asr->data_asr != target_asr)
        temp_asr = temp_asr->next_asr;
    if (!temp_asr) {
        cout << "Element not found.\n";
        return;
    }
    Node_asr* newNode_asr = new Node_asr{value_asr, temp_asr->next_asr, temp_asr};
    if (temp_asr->next_asr)
        temp_asr->next_asr->prev_asr = newNode_asr;
    temp_asr->next_asr = newNode_asr;
}

// Delete at beginning
void deleteAtBegin_asr(Node_asr*& head_asr) {
    if (!head_asr) return;
    Node_asr* temp_asr = head_asr;
    head_asr = head_asr->next_asr;
    if (head_asr)
        head_asr->prev_asr = nullptr;
    delete temp_asr;
}

// Delete at end
void deleteAtEnd_asr(Node_asr*& head_asr) {
    if (!head_asr) return;
    Node_asr* temp_asr = head_asr;
    while (temp_asr->next_asr) temp_asr = temp_asr->next_asr;
    if (temp_asr->prev_asr)
        temp_asr->prev_asr->next_asr = nullptr;
    else
        head_asr = nullptr;
    delete temp_asr;
}

// Delete after a particular element
void deleteAfterElement_asr(Node_asr* head_asr, int target_asr) {
    Node_asr* temp_asr = head_asr;
    while (temp_asr && temp_asr->data_asr != target_asr)
        temp_asr = temp_asr->next_asr;
    if (!temp_asr || !temp_asr->next_asr) {
        cout << "No element to delete after target.\n";
        return;
    }
    Node_asr* delNode_asr = temp_asr->next_asr;
    temp_asr->next_asr = delNode_asr->next_asr;
    if (delNode_asr->next_asr)
        delNode_asr->next_asr->prev_asr = temp_asr;
    delete delNode_asr;
}

// Display the list
void displayList_asr(Node_asr* head_asr) {
    if (!head_asr) {
        cout << "List is empty.\n";
        return;
    }
    Node_asr* temp_asr = head_asr;
    cout << "Doubly Linked List: ";
    while (temp_asr) {
        cout << temp_asr->data_asr << " ";
        temp_asr = temp_asr->next_asr;
    }
    cout << endl;
}

int main() {
    Node_asr* head_asr = nullptr;
    int choice_asr, value_asr, target_asr;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert After Element\n";
        cout << "4. Delete at Beginning\n5. Delete at End\n6. Delete After Element\n";
        cout << "7. Display List\n0. Exit\nEnter your choice: ";
        cin >> choice_asr;

        switch(choice_asr) {
            case 1:
                cout << "Enter value: "; cin >> value_asr;
                insertAtBegin_asr(head_asr, value_asr);
                break;
            case 2:
                cout << "Enter value: "; cin >> value_asr;
                insertAtEnd_asr(head_asr, value_asr);
                break;
            case 3:
                cout << "Enter target element: "; cin >> target_asr;
                cout << "Enter value to insert: "; cin >> value_asr;
                insertAfterElement_asr(head_asr, target_asr, value_asr);
                break;
            case 4:
                deleteAtBegin_asr(head_asr);
                break;
            case 5:
                deleteAtEnd_asr(head_asr);
                break;
            case 6:
                cout << "Enter target element: "; cin >> target_asr;
                deleteAfterElement_asr(head_asr, target_asr);
                break;
            case 7:
                displayList_asr(head_asr);
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while(choice_asr != 0);

    return 0;
}