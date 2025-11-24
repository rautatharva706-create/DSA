#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// Structure for Product node
struct Product_asr {
    string code_asr, name_asr, date_received_asr, expiry_date_asr;
    float price_asr;
    int quantity_asr;
    Product_asr *left_asr, *right_asr;

    Product_asr(string c_asr, string n_asr, float p_asr, int q_asr, string dr_asr, string ed_asr) {
        code_asr = c_asr;
        name_asr = n_asr;
        price_asr = p_asr;
        quantity_asr = q_asr;
        date_received_asr = dr_asr;
        expiry_date_asr = ed_asr;
        left_asr = right_asr = nullptr;
    }
};

// Convert "YYYY-MM-DD" to time_t
time_t convertToTime_asr(string date_asr) {
    tm t = {};
    sscanf(date_asr.c_str(), "%d-%d-%d", &t.tm_year, &t.tm_mon, &t.tm_mday);
    t.tm_year -= 1900;
    t.tm_mon -= 1;
    return mktime(&t);
}

// Insert product based on name
Product_asr* insertProduct_asr(Product_asr* root_asr, string code_asr, string name_asr, float price_asr, int qty_asr, string dr_asr, string ed_asr) {
    if (root_asr == nullptr)
        return new Product_asr(code_asr, name_asr, price_asr, qty_asr, dr_asr, ed_asr);

    if (name_asr < root_asr->name_asr)
        root_asr->left_asr = insertProduct_asr(root_asr->left_asr, code_asr, name_asr, price_asr, qty_asr, dr_asr, ed_asr);
    else if (name_asr > root_asr->name_asr)
        root_asr->right_asr = insertProduct_asr(root_asr->right_asr, code_asr, name_asr, price_asr, qty_asr, dr_asr, ed_asr);

    return root_asr;
}

// Inorder display (sorted)
void inorderDisplay_asr(Product_asr* root_asr) {
    if (root_asr == nullptr)
        return;

    inorderDisplay_asr(root_asr->left_asr);
    cout << "Code: " << root_asr->code_asr
         << " | Name: " << root_asr->name_asr
         << " | Price: " << root_asr->price_asr
         << " | Quantity: " << root_asr->quantity_asr
         << " | Received: " << root_asr->date_received_asr
         << " | Expiry: " << root_asr->expiry_date_asr << endl;
    inorderDisplay_asr(root_asr->right_asr);
}

// List expired products in preorder
void listExpiredItems_asr(Product_asr* root_asr) {
    if (root_asr == nullptr)
        return;

    time_t now = time(0);
    time_t expDate = convertToTime_asr(root_asr->expiry_date_asr);

    if (difftime(expDate, now) < 0) {
        cout << "Expired -> " << root_asr->name_asr
             << " | Code: " << root_asr->code_asr
             << " | Expired on: " << root_asr->expiry_date_asr << endl;
    }

    listExpiredItems_asr(root_asr->left_asr);
    listExpiredItems_asr(root_asr->right_asr);
}

int main() {
    Product_asr* root_asr = nullptr;
    int choice_asr;
    string code_asr, name_asr, dr_asr, ed_asr;
    float price_asr;
    int qty_asr;

    while (true) {
        cout << "\n--- Product Inventory Management ---\n";
        cout << "1. Insert Product\n2. Display All Products (Inorder)\n3. List Expired Products (Preorder)\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_asr;

        switch (choice_asr) {
            case 1:
                cout << "Enter Product Code: ";
                cin >> code_asr;
                cout << "Enter Product Name: ";
                cin.ignore();
                getline(cin, name_asr);
                cout << "Enter Price: ";
                cin >> price_asr;
                cout << "Enter Quantity: ";
                cin >> qty_asr;
                cout << "Enter Date Received (YYYY-MM-DD): ";
                cin >> dr_asr;
                cout << "Enter Expiration Date (YYYY-MM-DD): ";
                cin >> ed_asr;
                root_asr = insertProduct_asr(root_asr, code_asr, name_asr, price_asr, qty_asr, dr_asr, ed_asr);
                cout << "Product inserted successfully.\n";
                break;

            case 2:
                cout << "\n--- Product Inventory (Sorted by Name) ---\n";
                inorderDisplay_asr(root_asr);
                break;

            case 3:
                cout << "\n--- Expired Products ---\n";
                listExpiredItems_asr(root_asr);
                break;

            case 4:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}