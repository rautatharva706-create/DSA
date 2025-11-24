#include <iostream>
#include <string>
using namespace std;

struct Order_asr {
    int orderId_asr;
    string item_asr;
};

int main() {
    int n_asr, choice_asr;
    cout << "Enter maximum number of orders: ";
    cin >> n_asr;

    Order_asr* orders_asr = new Order_asr[n_asr]; // Dynamic array for orders
    int front_asr = -1, rear_asr = -1;
    int nextOrderId_asr = 1; // Auto-increment order ID

    do {
        cout << "\n--- Pizza Menu ---\n";
        cout << "1. Place Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Orders\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_asr;

        switch (choice_asr) {
            case 1: {
                // Check if circular queue is full
                if ((front_asr == 0 && rear_asr == n_asr - 1) || (rear_asr + 1) % n_asr == front_asr) {
                    cout << "Order queue is full. Cannot place more orders.\n";
                    break;
                }

                string item_asr;
                cout << "Enter pizza item: ";
                cin >> item_asr;

                if (front_asr == -1) { // First order
                    front_asr = rear_asr = 0;
                } else {
                    rear_asr = (rear_asr + 1) % n_asr; // Move rear circularly
                }

                orders_asr[rear_asr].orderId_asr = nextOrderId_asr++;
                orders_asr[rear_asr].item_asr = item_asr;
                cout << "Order placed successfully! Order ID: " << orders_asr[rear_asr].orderId_asr << "\n";
                break;
            }
            case 2: {
                if (front_asr == -1) {
                    cout << "No orders to serve.\n";
                    break;
                }

                cout << "Serving Order ID: " << orders_asr[front_asr].orderId_asr
                     << ", Item: " << orders_asr[front_asr].item_asr << "\n";

                if (front_asr == rear_asr) { // Only one order
                    front_asr = rear_asr = -1;
                } else {
                    front_asr = (front_asr + 1) % n_asr; // Move front circularly
                }
                break;
            }
            case 3: {
                if (front_asr == -1) {
                    cout << "No pending orders.\n";
                    break;
                }
                cout << "Current Orders in Queue:\n";
                int i_asr = front_asr;
                while (true) {
                    cout << "Order ID: " << orders_asr[i_asr].orderId_asr
                         << ", Item: " << orders_asr[i_asr].item_asr << "\n";
                    if (i_asr == rear_asr) break;
                    i_asr = (i_asr + 1) % n_asr;
                }
                break;
            }
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice_asr != 0);

    delete[] orders_asr;
    return 0;
}
