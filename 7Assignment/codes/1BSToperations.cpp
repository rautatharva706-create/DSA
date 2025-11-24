#include <iostream>
#include <queue>
using namespace std;

struct Nodeasr {
    int data;
    Nodeasr* left;
    Nodeasr* right;
};


Nodeasr* createNodeasr(int valueasr) {
    Nodeasr* newNodeasr = new Nodeasr();
    newNodeasr->data = valueasr;
    newNodeasr->left = newNodeasr->right = NULL;
    return newNodeasr;
}


Nodeasr* insertasr(Nodeasr* rootasr, int valueasr) {
    if (rootasr == NULL) {
        rootasr = createNodeasr(valueasr);
    } 
    else if (valueasr < rootasr->data) {
        rootasr->left = insertasr(rootasr->left, valueasr);
    } 
    else {
        rootasr->right = insertasr(rootasr->right, valueasr);
    }
    return rootasr;
}


Nodeasr* minValueNodeasr(Nodeasr* nodeasr) {
    Nodeasr* currentasr = nodeasr;
    while (currentasr && currentasr->left != NULL)
        currentasr = currentasr->left;
    return currentasr;
}

Nodeasr* deleteNodeasr(Nodeasr* rootasr, int keyasr) {
    if (rootasr == NULL)
        return rootasr;

    if (keyasr < rootasr->data)
        rootasr->left = deleteNodeasr(rootasr->left, keyasr);

    else if (keyasr > rootasr->data)
        rootasr->right = deleteNodeasr(rootasr->right, keyasr);

    else {

        if (rootasr->left == NULL && rootasr->right == NULL) {
            delete rootasr;
            return NULL;
        }

        else if (rootasr->left == NULL) {
            Nodeasr* tempasr = rootasr->right;
            delete rootasr;
            return tempasr;
        } 
        else if (rootasr->right == NULL) {
            Nodeasr* tempasr = rootasr->left;
            delete rootasr;
            return tempasr;
        }
       
        Nodeasr* tempasr = minValueNodeasr(rootasr->right);
        rootasr->data = tempasr->data;
        rootasr->right = deleteNodeasr(rootasr->right, tempasr->data);
    }
    return rootasr;
}


void levelOrderasr(Nodeasr* rootasr) {
    if (rootasr == NULL) return;

    queue<Nodeasr*> qasr;
    qasr.push(rootasr);

    while (!qasr.empty()) {
        Nodeasr* tempasr = qasr.front();
        qasr.pop();
        cout << tempasr->data << " ";

        if (tempasr->left != NULL)
            qasr.push(tempasr->left);
        if (tempasr->right != NULL)
            qasr.push(tempasr->right);
    }
}
void printTreeasr(Nodeasr* rootasr, int spaceasr = 0, int heightasr = 10) {
    if (rootasr == NULL)
        return;

   spaceasr += heightasr;
    printTreeasr(rootasr->right, spaceasr);
    cout << endl;
    for (int i = heightasr; i < spaceasr; i++)
        cout << " ";
    cout << rootasr->data << "\n";
    printTreeasr(rootasr->left, spaceasr);
}
int main() {
    Nodeasr* rootasr = NULL;
    int choiceasr, valueasr;

    do {
        cout << "\n\n--- BST Operations Menu ---\n";
        cout << "1. Insert\n2. Delete\n3. Level-wise Display\n4. Exit\n5. Tree-shaped Display\n";
        cout << "Enter your choice: ";
        cin >> choiceasr;

        switch (choiceasr) {
            case 1:
                cout << "Enter values to insert (enter -1 to stop): \n";
                while (true) {
                    cin >> valueasr;
                    if (valueasr == -1)
                        break;
                    rootasr = insertasr(rootasr, valueasr);
                }
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> valueasr;
                rootasr = deleteNodeasr(rootasr, valueasr);
                break;
            case 3:
                cout << "BST Level-wise Display: ";
                levelOrderasr(rootasr);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            case 5:
                cout << "BST Tree-Shaped Display:\n";
                printTreeasr(rootasr);
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choiceasr != 4);

    return 0;
}