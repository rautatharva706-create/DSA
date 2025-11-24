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