#include <iostream>
using namespace std;

struct Node_asr {
    int data_asr;
    Node_asr* left_asr;
    Node_asr* right_asr;
};

// Create new node
Node_asr* createNode_asr(int value_asr) {
    Node_asr* newNode_asr = new Node_asr();
    newNode_asr->data_asr = value_asr;
    newNode_asr->left_asr = newNode_asr->right_asr = nullptr;
    return newNode_asr;
}

// Insert in BST
Node_asr* insertNode_asr(Node_asr* root_asr, int value_asr) {
    if (root_asr == nullptr) {
        root_asr = createNode_asr(value_asr);
    } 
    else if (value_asr < root_asr->data_asr) {
        root_asr->left_asr = insertNode_asr(root_asr->left_asr, value_asr);
    } 
    else {
        root_asr->right_asr = insertNode_asr(root_asr->right_asr, value_asr);
    }
    return root_asr;
}

// Find Minimum
int findMin_asr(Node_asr* root_asr) {
    if (root_asr == nullptr) {
        cout << "Tree is empty!";
        return -1;
    }
    while (root_asr->left_asr != nullptr) {
        root_asr = root_asr->left_asr;
    }
    return root_asr->data_asr;
}

// Find Maximum
int findMax_asr(Node_asr* root_asr) {
    if (root_asr == nullptr) {
        cout << "Tree is empty!";
        return -1;
    }
    while (root_asr->right_asr != nullptr) {
        root_asr = root_asr->right_asr;
    }
    return root_asr->data_asr;
}

int main() {
    Node_asr* root_asr = nullptr;
    int n_asr, value_asr;

    cout << "Enter number of nodes: ";
    cin >> n_asr;

    cout << "Enter values:\n";
    for (int i = 0; i < n_asr; i++) {
        cin >> value_asr;
        root_asr = insertNode_asr(root_asr, value_asr);
    }

    cout << "Minimum value in BST: " << findMin_asr(root_asr) << endl;
    cout << "Maximum value in BST: " << findMax_asr(root_asr) << endl;

    return 0;
}
