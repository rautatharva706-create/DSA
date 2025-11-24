#include <iostream>
using namespace std;

struct Node_asr {
    int data_asr;
    Node_asr* left_asr;
    Node_asr* right_asr;
};

// Create new node
Node_asr* createNode_asr(int value_asr) {
    Node_asr* temp_asr = new Node_asr();
    temp_asr->data_asr = value_asr;
    temp_asr->left_asr = temp_asr->right_asr = NULL;
    return temp_asr;
}

// Insert into BST
Node_asr* insertNode_asr(Node_asr* root_asr, int value_asr) {
    if (root_asr == NULL)
        return createNode_asr(value_asr);

    if (value_asr < root_asr->data_asr)
        root_asr->left_asr = insertNode_asr(root_asr->left_asr, value_asr);
    else if (value_asr > root_asr->data_asr)
        root_asr->right_asr = insertNode_asr(root_asr->right_asr, value_asr);

    return root_asr;
}

// Count total nodes
int countNodes_asr(Node_asr* root_asr) {
    if (root_asr == NULL)
        return 0;
    return 1 + countNodes_asr(root_asr->left_asr) + countNodes_asr(root_asr->right_asr);
}

// Height of BST
int height_asr(Node_asr* root_asr) {
    if (root_asr == NULL)
        return 0;

    int leftHeight_asr = height_asr(root_asr->left_asr);
    int rightHeight_asr = height_asr(root_asr->right_asr);

    return (leftHeight_asr > rightHeight_asr ? leftHeight_asr : rightHeight_asr) + 1;
}

// Mirror of BST
void mirror_asr(Node_asr* root_asr) {
    if (root_asr == NULL)
        return;

    mirror_asr(root_asr->left_asr);
    mirror_asr(root_asr->right_asr);

    Node_asr* temp_asr = root_asr->left_asr;
    root_asr->left_asr = root_asr->right_asr;
    root_asr->right_asr = temp_asr;
}

// Inorder traversal
void inorder_asr(Node_asr* root_asr) {
    if (root_asr == NULL)
        return;

    inorder_asr(root_asr->left_asr);
    cout << root_asr->data_asr << " ";
    inorder_asr(root_asr->right_asr);
}

int main() {
    Node_asr* root_asr = NULL;
    int choice_asr, value_asr;
    cout << "\n\nBinary Search Tree OPerations\n";
    cout << "1. Insert Node\n";
    cout << "2. Count Total Nodes\n";
    cout << "3. Height of BST\n";
    cout << "4. Inorder Traversal\n";
    cout << "5. Mirror Image of BST\n";
    cout << "6. Exit\n";

    do {
     
        cout << "Enter your choice: ";
        cin >> choice_asr;

        switch (choice_asr) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value_asr;
                root_asr = insertNode_asr(root_asr, value_asr);
                cout << "Node inserted.\n";
                cout<<"--------\n";
                break;

            case 2:
                cout << "Total Nodes: " << countNodes_asr(root_asr) << endl;
                break;

            case 3:
                cout << "Height of BST: " << height_asr(root_asr) << endl;
                break;

            case 4:
                cout << "Inorder Traversal: ";
                inorder_asr(root_asr);
                cout << endl;
                break;

            case 5:
                mirror_asr(root_asr);
                cout << "Mirror image created.\n";
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice_asr != 6);

    return 0;
}
