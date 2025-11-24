#include <iostream>
#include <queue>
using namespace std;

// Node structure
struct Node_asr {
    int data_asr;
    Node_asr *left_asr, *right_asr;
    Node_asr(int val_asr) {
        data_asr = val_asr;
        left_asr = right_asr = nullptr;
    }
};

// Create Binary Tree using level-order input
Node_asr* createTree_asr(int n_asr) {
    if (n_asr <= 0) return nullptr;

    int val_asr;
    cout << "Enter value for root node: ";
    cin >> val_asr;

    Node_asr* root_asr = new Node_asr(val_asr);
    queue<Node_asr*> q_asr;
    q_asr.push(root_asr);
    int count_asr = 1;

    while (count_asr < n_asr) {
        Node_asr* curr_asr = q_asr.front();
        q_asr.pop();

        int leftVal_asr, rightVal_asr;

        cout << "Enter left child of " << curr_asr->data_asr << " (-1 for no child): ";
        cin >> leftVal_asr;
        if (leftVal_asr != -1) {
            curr_asr->left_asr = new Node_asr(leftVal_asr);
            q_asr.push(curr_asr->left_asr);
            count_asr++;
            if (count_asr == n_asr) break;
        }

        cout << "Enter right child of " << curr_asr->data_asr << " (-1 for no child): ";
        cin >> rightVal_asr;
        if (rightVal_asr != -1) {
            curr_asr->right_asr = new Node_asr(rightVal_asr);
            q_asr.push(curr_asr->right_asr);
            count_asr++;
        }
    }

    return root_asr;
}

// Recursive Inorder Traversal
void inorderTraversal_asr(Node_asr* root_asr) {
    if (root_asr == nullptr)
        return;
    inorderTraversal_asr(root_asr->left_asr);
    cout << root_asr->data_asr << " ";
    inorderTraversal_asr(root_asr->right_asr);
}

// Recursive Preorder Traversal
void preorderTraversal_asr(Node_asr* root_asr) {
    if (root_asr == nullptr)
        return;
    cout << root_asr->data_asr << " ";
    preorderTraversal_asr(root_asr->left_asr);
    preorderTraversal_asr(root_asr->right_asr);
}

// Count Leaf Nodes (Recursive)
int countLeafNodes_asr(Node_asr* root_asr) {
    if (root_asr == nullptr)
        return 0;
    if (root_asr->left_asr == nullptr && root_asr->right_asr == nullptr)
        return 1;
    return countLeafNodes_asr(root_asr->left_asr) + countLeafNodes_asr(root_asr->right_asr);
}

// Mirror Image (Recursive)
void mirrorImage_asr(Node_asr* root_asr) {
    if (root_asr == nullptr)
        return;
    swap(root_asr->left_asr, root_asr->right_asr);
    mirrorImage_asr(root_asr->left_asr);
    mirrorImage_asr(root_asr->right_asr);
}

int main() {
    int n_asr;
    cout << "Enter total number of nodes in the tree: ";
    cin >> n_asr;

    Node_asr* root_asr = createTree_asr(n_asr);

    cout << "\n--- Binary Tree Recursive Operations ---\n";

    cout << "Inorder Traversal: ";
    inorderTraversal_asr(root_asr);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorderTraversal_asr(root_asr);
    cout << endl;

    cout << "Number of Leaf Nodes: " << countLeafNodes_asr(root_asr) << endl;

    cout << "\nCreating Mirror Image of the Tree...\n";
    mirrorImage_asr(root_asr);

    cout << "Inorder Traversal of Mirror Image: ";
    inorderTraversal_asr(root_asr);
    cout << endl;

    return 0;
}