# Assignment No: 1

## Title: Pizza Parlour Order Management Using Circular Queue

### Theory

In a pizza shop, many customers place their food orders one after another. To handle these orders properly, especially when there is a fixed limit on the number of orders that can be accepted at a time, a circular queue data structure is used. A circular queue helps in reusing the space of completed orders, which removes the issue of unused memory that occurs in a normal linear queue.

This ordering system follows the First Come First Serve (FCFS) rule, meaning the order that is placed first will be served first. Once an order is entered into the system, it cannot be removed or canceled. The circular queue ensures that the maximum order capacity is never exceeded, and a new order will be accepted only when there is space available in the queue.

**Advantages of circular queue in this scenario:**

* Efficient memory utilization as the queue is circular.
* Easy to implement FCFS order serving.
* Handles a fixed maximum number of orders without overflow issues.

### Algorithm

1. **Initialize Queue:**

   * Define a structure `Order_asr` with fields `orderId_asr` and `orderName_asr`.
   * Use an array of `Order_asr` of size `n_asr`, where `n_asr` is the maximum number of orders.
   * Initialize `front_asr` and `rear_asr` to -1 to indicate an empty queue.

2. **Enqueue Operation (Place Order):**

   * Check if the queue is full: `(rear_asr + 1) % n_asr == front_asr`.
   * If not full, increment `rear_asr` circularly: `rear_asr = (rear_asr + 1) % n_asr`.
   * Insert the new order at `orders_asr[rear_asr]`.
   * If queue was empty, set `front_asr = 0`.

3. **Dequeue Operation (Serve Order):**

   * Check if the queue is empty: `front_asr == -1`.
   * Serve the order at `orders_asr[front_asr]`.
   * Increment `front_asr` circularly: `front_asr = (front_asr + 1) % n_asr`.
   * If after serving, `front_asr == rear_asr + 1`, reset `front_asr` and `rear_asr` to -1.

4. **Display Orders:**

   * Traverse from `front_asr` to `rear_asr` circularly.
   * Print all the orders in the queue in FCFS order.

5. **User Interaction:**

   * Present a menu for the user to place orders, serve orders, display current orders, or exit.
   * Ensure the system respects the maximum number of orders (`n_asr`).

### C++ Code

```cpp
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


```

### Output

```
Enter maximum number of orders: 2

--- Pizza Menu ---
1. Place Order
2. Serve Order
3. Display Orders
0. Exit
Enter your choice: 1
Enter pizza item: q
Order placed successfully! Order ID: 1

--- Pizza Menu ---
1. Place Order
2. Serve Order
3. Display Orders
0. Exit
Enter your choice: 1
Enter pizza item: w
Order placed successfully! Order ID: 2

--- Pizza Menu ---
1. Place Order
2. Serve Order
3. Display Orders
0. Exit
Enter your choice: 1
Order queue is full. Cannot place more orders.

--- Pizza Menu ---
1. Place Order
2. Serve Order
3. Display Orders
0. Exit
Enter your choice: 2
Serving Order ID: 1, Item: q

--- Pizza Menu ---
1. Place Order
2. Serve Order
3. Display Orders
0. Exit
Enter your choice: 3
Current Orders in Queue:
Order ID: 2, Item: w

--- Pizza Menu ---
1. Place Order
2. Serve Order
3. Display Orders
0. Exit
Enter your choice: 0
Exiting...

```
