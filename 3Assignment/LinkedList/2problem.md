# Assignment No.3: Problem 2
# Ticket Reservation System

---

## Title

Implementation of a **Ticket Reservation System** for Galaxy Multiplex using a doubly circular linked list to manage seat bookings in 8 rows with 8 seats each.

---

## Algorithm

1. **Start**.
2. Initialize 8 rows with 8 seats each as a doubly circular linked list.
3. Randomly mark some seats as booked initially.
4. Store head pointers of each row in an array.
5. Display the current seating arrangement.
6. Allow user to:

   * Book one or more seats.
   * Cancel an existing booking.
   * View the current seat availability.
7. Update the linked list after each operation.
8. Repeat until user exits.
9. **Stop**.

### Characteristics:

* **Data Structure**: Doubly circular linked list
* **Operations**: Display, Book, Cancel
* **Space Complexity**: O(n) for n seats
* **Time Complexity**: O(1) for access per seat after locating row

---

## Code

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Seat_asr {
    int seatNo_asr;
    bool booked_asr;
    Seat_asr* next_asr;
    Seat_asr* prev_asr;
};

class Multiplex_asr {
    Seat_asr* rows_asr[8];
public:
    Multiplex_asr() {
        srand(time(0));
        for (int i_asr = 0; i_asr < 8; i_asr++) {
            rows_asr[i_asr] = nullptr;
            Seat_asr* prev_asr = nullptr;
            for (int j_asr = 1; j_asr <= 8; j_asr++) {
                Seat_asr* newSeat_asr = new Seat_asr{j_asr, rand()%2, nullptr, prev_asr};
                if (prev_asr) prev_asr->next_asr = newSeat_asr;
                else rows_asr[i_asr] = newSeat_asr;
                prev_asr = newSeat_asr;
            }
            // Making it circular
            prev_asr->next_asr = rows_asr[i_asr];
            rows_asr[i_asr]->prev_asr = prev_asr;
        }
    }

    void displaySeats_asr() {
        cout << "\nCurrent Seating Arrangement (0=Available,1=Booked):\n";
        for (int i_asr = 0; i_asr < 8; i_asr++) {
            cout << "Row " << i_asr + 1 << ": ";
            Seat_asr* temp_asr = rows_asr[i_asr];
            for (int j_asr = 0; j_asr < 8; j_asr++) {
                cout << temp_asr->booked_asr << " ";
                temp_asr = temp_asr->next_asr;
            }
            cout << endl;
        }
    }

    void bookSeat_asr(int row_asr, int seat_asr) {
        Seat_asr* temp_asr = rows_asr[row_asr-1];
        for (int i_asr = 1; i_asr < seat_asr; i_asr++) temp_asr = temp_asr->next_asr;
        if (temp_asr->booked_asr) cout << "Seat already booked!\n";
        else { temp_asr->booked_asr = true; cout << "Seat booked successfully.\n"; }
    }

    void cancelSeat_asr(int row_asr, int seat_asr) {
        Seat_asr* temp_asr = rows_asr[row_asr-1];
        for (int i_asr = 1; i_asr < seat_asr; i_asr++) temp_asr = temp_asr->next_asr;
        if (!temp_asr->booked_asr) cout << "Seat not booked yet!\n";
        else { temp_asr->booked_asr = false; cout << "Booking cancelled.\n"; }
    }
};

int main() {
    Multiplex_asr multiplex_asr;
    int choice_asr;
    do {
        cout << "\nMenu:\n1. Display Seats\n2. Book Seat\n3. Cancel Booking\n0. Exit\nEnter choice: ";
        cin >> choice_asr;
        switch(choice_asr) {
            case 1:
                multiplex_asr.displaySeats_asr();
                break;
            case 2: {
                int r_asr,s_asr;
                cout << "Enter row (1-8) and seat number (1-8) to book: ";
                cin >> r_asr >> s_asr;
                multiplex_asr.bookSeat_asr(r_asr,s_asr);
                break;
            }
            case 3: {
                int r_asr,s_asr;
                cout << "Enter row (1-8) and seat number (1-8) to cancel: ";
                cin >> r_asr >> s_asr;
                multiplex_asr.cancelSeat_asr(r_asr,s_asr);
                break;
            }
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while(choice_asr != 0);
    return 0;
}
```

---

## Output

```
Menu:
1. Display Seats
2. Book Seat
3. Cancel Booking
0. Exit
Enter choice: 1

Current Seating Arrangement (0=Available,1=Booked):
Row 1: 1 0 0 1 0 0 1 0
Row 2: 0 1 0 0 1 1 0 0
Row 3: 0 0 1 0 1 0 0 1
Row 4: 1 0 1 0 0 0 1 0
Row 5: 0 0 0 1 0 1 0 0
Row 6: 1 1 0 0 0 0 1 0
Row 7: 0 0 1 0 0 1 0 1
Row 8: 0 1 0 1 0 0 0 1

Enter choice: 2
Enter row (1-8) and seat number (1-8) to book: 1 2
Seat booked successfully.

Enter choice: 3
Enter row (1-8) and seat number (1-8) to cancel: 4 1
Booking cancelled.

Enter choice: 0
Exiting...
```
