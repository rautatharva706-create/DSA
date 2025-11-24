#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Node_asr {
    int data_asr;
    Node_asr *left_asr, *right_asr;

    Node_asr(int val_asr) {
        data_asr = val_asr;
        left_asr = right_asr = nullptr;
    }
};

// Create Binary Tree (Level Order)
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

        cout << "Enter left child of " << curr_asr->data_asr 
             << " (-1 for no child): ";
        cin >> leftVal_asr;

        if (leftVal_asr != -1) {
            curr_asr->left_asr = new Node_asr(leftVal_asr);
            q_asr.push(curr_asr->left_asr);
            count_asr++;
            if (count_asr == n_asr) break;
        }

        cout << "Enter right child of " << curr_asr->data_asr 
             << " (-1 for no child): ";
        cin >> rightVal_asr;

        if (rightVal_asr != -1) {
            curr_asr->right_asr = new Node_asr(rightVal_asr);
            q_asr.push(curr_asr->right_asr);
            count_asr++;
        }
    }

    return root_asr;
}

// Nonrecursive Inorder Traversal
void inorderTraversal_asr(Node_asr* root_asr) {
    stack<Node_asr*> s_asr;
    Node_asr* curr_asr = root_asr;

    cout << "Inorder Traversal: ";
    while (curr_asr != nullptr || !s_asr.empty()) {
        while (curr_asr != nullptr) {
            s_asr.push(curr_asr);
            curr_asr = curr_asr->left_asr;
        }
        curr_asr = s_asr.top();
        s_asr.pop();
        cout << curr_asr->data_asr << " ";
        curr_asr = curr_asr->right_asr;
    }
    cout << endl;
}

// Nonrecursive Preorder Traversal
void preorderTraversal_asr(Node_asr* root_asr) {
    if (!root_asr) return;

    stack<Node_asr*> s_asr;
    s_asr.push(root_asr);

    cout << "Preorder Traversal: ";
    while (!s_asr.empty()) {
        Node_asr* curr_asr = s_asr.top();
        s_asr.pop();

        cout << curr_asr->data_asr << " ";

        if (curr_asr->right_asr)
            s_asr.push(curr_asr->right_asr);
        if (curr_asr->left_asr)
            s_asr.push(curr_asr->left_asr);
    }
    cout << endl;
}

// Count Leaf Nodes
int countLeafNodes_asr(Node_asr* root_asr) {
    if (!root_asr) return 0;

    stack<Node_asr*> s_asr;
    s_asr.push(root_asr);

    int count_asr = 0;

    while (!s_asr.empty()) {
        Node_asr* curr_asr = s_asr.top();
        s_asr.pop();

        if (!curr_asr->left_asr && !curr_asr->right_asr)
            count_asr++;

        if (curr_asr->right_asr)
            s_asr.push(curr_asr->right_asr);
        if (curr_asr->left_asr)
            s_asr.push(curr_asr->left_asr);
    }

    return count_asr;
}

// Nonrecursive Mirror Image
void mirrorTree_asr(Node_asr* root_asr) {
    if (!root_asr) return;

    stack<Node_asr*> s_asr;
    s_asr.push(root_asr);

    while (!s_asr.empty()) {
        Node_asr* curr_asr = s_asr.top();
        s_asr.pop();

        // Swap left and right children
        swap(curr_asr->left_asr, curr_asr->right_asr);

        if (curr_asr->left_asr)
            s_asr.push(curr_asr->left_asr);
        if (curr_asr->right_asr)
            s_asr.push(curr_asr->right_asr);
    }
}

int main() {
    int n_asr;
    cout << "Enter total number of nodes in the tree: ";
    cin >> n_asr;

    Node_asr* root_asr = createTree_asr(n_asr);

    cout << "\n--- Binary Tree Operations ---\n";
    inorderTraversal_asr(root_asr);
    preorderTraversal_asr(root_asr);

    cout << "Number of Leaf Nodes: " 
         << countLeafNodes_asr(root_asr) << endl;

    cout << "\nCreating Mirror Image of the Tree...\n";
    mirrorTree_asr(root_asr);

    cout << "Inorder Traversal of Mirror Image: ";
    inorderTraversal_asr(root_asr);

    return 0;
}