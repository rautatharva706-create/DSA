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

// Insert product based on Product Code
Product_asr* insertProduct_asr(Product_asr* root_asr, string code_asr, string name_asr,
                               float price_asr, int qty_asr, string dr_asr, string ed_asr) {
    if (root_asr == nullptr)
        return new Product_asr(code_asr, name_asr, price_asr, qty_asr, dr_asr, ed_asr);

    if (code_asr < root_asr->code_asr)
        root_asr->left_asr = insertProduct_asr(root_asr->left_asr, code_asr, name_asr, price_asr, qty_asr, dr_asr, ed_asr);
    else if (code_asr > root_asr->code_asr)
        root_asr->right_asr = insertProduct_asr(root_asr->right_asr, code_asr, name_asr, price_asr, qty_asr, dr_asr, ed_asr);

    return root_asr;
}

// Find minimum node
Product_asr* findMin_asr(Product_asr* root_asr) {
    while (root_asr && root_asr->left_asr != nullptr)
        root_asr = root_asr->left_asr;
    return root_asr;
}

// Delete a product by code
Product_asr* deleteByCode_asr(Product_asr* root_asr, string code_asr) {
    if (root_asr == nullptr)
        return root_asr;

    if (code_asr < root_asr->code_asr)
        root_asr->left_asr = deleteByCode_asr(root_asr->left_asr, code_asr);
    else if (code_asr > root_asr->code_asr)
        root_asr->right_asr = deleteByCode_asr(root_asr->right_asr, code_asr);
    else {
        if (root_asr->left_asr == nullptr) {
            Product_asr* temp = root_asr->right_asr;
            delete root_asr;
            return temp;
        } 
        else if (root_asr->right_asr == nullptr) {
            Product_asr* temp = root_asr->left_asr;
            delete root_asr;
            return temp;
        }

        Product_asr* temp = findMin_asr(root_asr->right_asr);

        root_asr->code_asr = temp->code_asr;
        root_asr->name_asr = temp->name_asr;
        root_asr->price_asr = temp->price_asr;
        root_asr->quantity_asr = temp->quantity_asr;
        root_asr->date_received_asr = temp->date_received_asr;
        root_asr->expiry_date_asr = temp->expiry_date_asr;

        root_asr->right_asr = deleteByCode_asr(root_asr->right_asr, temp->code_asr);
    }

    return root_asr;
}

// Delete all expired products
Product_asr* deleteExpired_asr(Product_asr* root_asr) {
    if (root_asr == nullptr)
        return nullptr;

    root_asr->left_asr = deleteExpired_asr(root_asr->left_asr);
    root_asr->right_asr = deleteExpired_asr(root_asr->right_asr);

    time_t now_asr = time(0);
    time_t expDate_asr = convertToTime_asr(root_asr->expiry_date_asr);

    if (difftime(expDate_asr, now_asr) < 0) {
        cout << "Deleting expired product: " << root_asr->name_asr 
             << " (" << root_asr->code_asr << ")\n";

        root_asr = deleteByCode_asr(root_asr, root_asr->code_asr);
    }

    return root_asr;
}

// Display products
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

int main() {
    Product_asr* root_asr = nullptr;
    int choice_asr;
    string code_asr, name_asr, dr_asr, ed_asr;
    float price_asr;
    int qty_asr;

    while (true) {
        cout << "\n--- Product Inventory System (Deletion Operations) ---\n";
        cout << "1. Insert Product\n2. Display All Products\n3. Delete Product by Code\n4. Delete All Expired Products\n5. Exit\n";
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
                cout << "\n--- Current Inventory ---\n";
                inorderDisplay_asr(root_asr);
                break;

            case 3:
                cout << "Enter Product Code to delete: ";
                cin >> code_asr;
                root_asr = deleteByCode_asr(root_asr, code_asr);
                cout << "Deletion completed.\n";
                break;

            case 4:
                root_asr = deleteExpired_asr(root_asr);
                cout << "Expired products deleted successfully.\n";
                break;

            case 5:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
