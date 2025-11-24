#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Appointment_asr {
    int hour_asr;
    int minute_asr;
    string period_asr; // "AM" or "PM"
    int duration_asr; // in minutes
    Appointment_asr* next_asr;
};

void displayTime_asr(int hour_asr, int minute_asr, string period_asr) {
    cout << hour_asr << ":" << setw(2) << setfill('0') << minute_asr << " " << period_asr;
}

void displayAppointments_asr(Appointment_asr* head_asr) {
    if (!head_asr) {
        cout << "No appointments scheduled.\n";
        return;
    }
    cout << "Start Time\tDuration\n";
    Appointment_asr* temp_asr = head_asr;
    while (temp_asr) {
        displayTime_asr(temp_asr->hour_asr, temp_asr->minute_asr, temp_asr->period_asr);
        cout << "\t" << temp_asr->duration_asr << " min\n";
        temp_asr = temp_asr->next_asr;
    }
}

bool compareTime_asr(Appointment_asr* a_asr, Appointment_asr* b_asr) {
    int hour1_asr = a_asr->hour_asr % 12 + (a_asr->period_asr == "PM" ? 12 : 0);
    int hour2_asr = b_asr->hour_asr % 12 + (b_asr->period_asr == "PM" ? 12 : 0);
    if (hour1_asr != hour2_asr) return hour1_asr < hour2_asr;
    return a_asr->minute_asr < b_asr->minute_asr;
}

void bookAppointment_asr(Appointment_asr*& head_asr) {
    int hour_asr, minute_asr, duration_asr;
    string period_asr;
    cout << "Enter start time (HH MM AM/PM): ";
    cin >> hour_asr >> minute_asr >> period_asr;
    cout << "Enter duration in minutes: ";
    cin >> duration_asr;

    Appointment_asr* new_asr = new Appointment_asr{hour_asr, minute_asr, period_asr, duration_asr, nullptr};

    if (!head_asr || compareTime_asr(new_asr, head_asr)) {
        new_asr->next_asr = head_asr;
        head_asr = new_asr;
        cout << "Appointment booked.\n";
        return;
    }

    Appointment_asr* temp_asr = head_asr;
    while (temp_asr->next_asr && compareTime_asr(temp_asr->next_asr, new_asr) == false)
        temp_asr = temp_asr->next_asr;

    new_asr->next_asr = temp_asr->next_asr;
    temp_asr->next_asr = new_asr;
    cout << "Appointment booked.\n";
}

void cancelAppointment_asr(Appointment_asr*& head_asr) {
    int hour_asr, minute_asr;
    string period_asr;
    cout << "Enter start time of appointment to cancel (HH MM AM/PM): ";
    cin >> hour_asr >> minute_asr >> period_asr;

    if (!head_asr) {
        cout << "No appointments.\n";
        return;
    }

    if (head_asr->hour_asr == hour_asr && head_asr->minute_asr == minute_asr && head_asr->period_asr == period_asr) {
        Appointment_asr* toDelete_asr = head_asr;
        head_asr = head_asr->next_asr;
        delete toDelete_asr;
        cout << "Appointment canceled.\n";
        return;
    }

    Appointment_asr* temp_asr = head_asr;
    while (temp_asr->next_asr &&
          !(temp_asr->next_asr->hour_asr == hour_asr &&
            temp_asr->next_asr->minute_asr == minute_asr &&
            temp_asr->next_asr->period_asr == period_asr))
        temp_asr = temp_asr->next_asr;

    if (temp_asr->next_asr) {
        Appointment_asr* toDelete_asr = temp_asr->next_asr;
        temp_asr->next_asr = temp_asr->next_asr->next_asr;
        delete toDelete_asr;
        cout << "Appointment canceled.\n";
    } else {
        cout << "Appointment not found.\n";
    }
}

void sortByPointer_asr(Appointment_asr*& head_asr) {
    if (!head_asr || !head_asr->next_asr) return;
    Appointment_asr* sorted_asr = nullptr;

    while (head_asr) {
        Appointment_asr* current_asr = head_asr;
        head_asr = head_asr->next_asr;
        if (!sorted_asr || compareTime_asr(current_asr, sorted_asr)) {
            current_asr->next_asr = sorted_asr;
            sorted_asr = current_asr;
        } else {
            Appointment_asr* temp_asr = sorted_asr;
            while (temp_asr->next_asr && compareTime_asr(temp_asr->next_asr, current_asr) == false)
                temp_asr = temp_asr->next_asr;
            current_asr->next_asr = temp_asr->next_asr;
            temp_asr->next_asr = current_asr;
        }
    }
    head_asr = sorted_asr;
}

int main() {
    Appointment_asr* head_asr = nullptr;
    int choice_asr;

    do {
        cout << "\nMenu:\n";
        cout << "1. Display Appointments\n";
        cout << "2. Book Appointment\n";
        cout << "3. Cancel Appointment\n";
        cout << "4. Sort by Pointer\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice_asr;

        switch (choice_asr) {
            case 1: displayAppointments_asr(head_asr); break;
            case 2: bookAppointment_asr(head_asr); break;
            case 3: cancelAppointment_asr(head_asr); break;
            case 4: sortByPointer_asr(head_asr); cout << "Appointments sorted by pointer.\n"; break;
            case 0: cout << "Exiting.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice_asr != 0);

    return 0;
}