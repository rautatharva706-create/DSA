#include <iostream>
using namespace std;

// Structure for a BST node
struct Node_asr {
    int key_asr;
    Node_asr *left_asr, *right_asr;
    Node_asr(int val_asr) {
        key_asr = val_asr;
        left_asr = right_asr = nullptr;
    }
};

// Insert a new key into BST
Node_asr* insertNode_asr(Node_asr* root_asr, int key_asr) {
    if (root_asr == nullptr)
        return new Node_asr(key_asr);
    if (key_asr < root_asr->key_asr)
        root_asr->left_asr = insertNode_asr(root_asr->left_asr, key_asr);
    else if (key_asr > root_asr->key_asr)
        root_asr->right_asr = insertNode_asr(root_asr->right_asr, key_asr);
    return root_asr;
}

// Find minimum value node (used in deletion)
Node_asr* findMin_asr(Node_asr* node_asr) {
    Node_asr* current_asr = node_asr;
    while (current_asr && current_asr->left_asr != nullptr)
        current_asr = current_asr->left_asr;
    return current_asr;
}

// Delete a key from BST
Node_asr* deleteNode_asr(Node_asr* root_asr, int key_asr) {
    if (root_asr == nullptr)
        return root_asr;

    if (key_asr < root_asr->key_asr)
        root_asr->left_asr = deleteNode_asr(root_asr->left_asr, key_asr);
    else if (key_asr > root_asr->key_asr)
        root_asr->right_asr = deleteNode_asr(root_asr->right_asr, key_asr);
    else {
        // Node with one or no child
        if (root_asr->left_asr == nullptr) {
            Node_asr* temp_asr = root_asr->right_asr;
            delete root_asr;
            return temp_asr;
        } else if (root_asr->right_asr == nullptr) {
            Node_asr* temp_asr = root_asr->left_asr;
            delete root_asr;
            return temp_asr;
        }
        // Node with two children
        Node_asr* temp_asr = findMin_asr(root_asr->right_asr);
        root_asr->key_asr = temp_asr->key_asr;
        root_asr->right_asr = deleteNode_asr(root_asr->right_asr, temp_asr->key_asr);
    }
    return root_asr;
}

// Search a key in BST
bool searchNode_asr(Node_asr* root_asr, int key_asr) {
    if (root_asr == nullptr)
        return false;
    if (root_asr->key_asr == key_asr)
        return true;
    if (key_asr < root_asr->key_asr)
        return searchNode_asr(root_asr->left_asr, key_asr);
    else
        return searchNode_asr(root_asr->right_asr, key_asr);
}

// Inorder traversal (sorted order)
void inorder_asr(Node_asr* root_asr) {
    if (root_asr == nullptr)
        return;
    inorder_asr(root_asr->left_asr);
    cout << root_asr->key_asr << " ";
    inorder_asr(root_asr->right_asr);
}

int main() {
    Node_asr* root_asr = nullptr;
    int choice_asr, key_asr;
    cout << "\n--- Binary Search Tree Operations ---\n";
    cout << "1. Insert\n2. Delete\n3. Find\n4. Show (Inorder)\n5. Exit\n";
    while (true) {
        
        cout << "Enter your choice: ";
        cin >> choice_asr;

        switch (choice_asr) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key_asr;
                root_asr = insertNode_asr(root_asr, key_asr);
                cout << "Key inserted successfully.\n";
                cout<<"------\n";
                break;

            case 2:
                cout << "Enter key to delete: ";
                cin >> key_asr;
                root_asr = deleteNode_asr(root_asr, key_asr);
                cout << "Key deleted (if existed).\n";
                break;

            case 3:
                cout << "Enter key to find: ";
                cin >> key_asr;
                if (searchNode_asr(root_asr, key_asr))
                    cout << "Key found in BST.\n";
                else
                    cout << "Key not found.\n";
                break;

            case 4:
                cout << "BST elements (Inorder): ";
                inorder_asr(root_asr);
                cout << endl;
                break;

            case 5:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}