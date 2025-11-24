#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node_asr {
    int bit_asr;
    Node_asr* prev_asr;
    Node_asr* next_asr;
};

void insertEnd_asr(Node_asr*& head_asr, Node_asr*& tail_asr, int bit_asr) {
    Node_asr* newNode_asr = new Node_asr{bit_asr, nullptr, nullptr};
    if (!head_asr) {
        head_asr = tail_asr = newNode_asr;
    } else {
        tail_asr->next_asr = newNode_asr;
        newNode_asr->prev_asr = tail_asr;
        tail_asr = newNode_asr;
    }
}

void display_asr(Node_asr* head_asr) {
    Node_asr* temp_asr = head_asr;
    while (temp_asr) {
        cout << temp_asr->bit_asr;
        temp_asr = temp_asr->next_asr;
    }
    cout << endl;
}

void onesComplement_asr(Node_asr* head_asr) {
    Node_asr* temp_asr = head_asr;
    while (temp_asr) {
        temp_asr->bit_asr = temp_asr->bit_asr == 0 ? 1 : 0;
        temp_asr = temp_asr->next_asr;
    }
}

void twosComplement_asr(Node_asr* head_asr, Node_asr* tail_asr) {
    onesComplement_asr(head_asr);
    Node_asr* temp_asr = tail_asr;
    int carry_asr = 1;
    while (temp_asr && carry_asr) {
        int sum_asr = temp_asr->bit_asr + carry_asr;
        temp_asr->bit_asr = sum_asr % 2;
        carry_asr = sum_asr / 2;
        temp_asr = temp_asr->prev_asr;
    }
    if (carry_asr) {
        Node_asr* newNode_asr = new Node_asr{1, nullptr, head_asr};
        head_asr->prev_asr = newNode_asr;
        head_asr = newNode_asr;
    }
}

Node_asr* addBinary_asr(Node_asr* head1_asr, Node_asr* tail1_asr, Node_asr* head2_asr, Node_asr* tail2_asr) {
    Node_asr* resultHead_asr = nullptr;
    Node_asr* resultTail_asr = nullptr;
    Node_asr* temp1_asr = tail1_asr;
    Node_asr* temp2_asr = tail2_asr;
    int carry_asr = 0;

    while (temp1_asr || temp2_asr || carry_asr) {
        int bit1_asr = temp1_asr ? temp1_asr->bit_asr : 0;
        int bit2_asr = temp2_asr ? temp2_asr->bit_asr : 0;
        int sum_asr = bit1_asr + bit2_asr + carry_asr;
        int bitSum_asr = sum_asr % 2;
        carry_asr = sum_asr / 2;
        insertEnd_asr(resultHead_asr, resultTail_asr, bitSum_asr);

        if (temp1_asr) temp1_asr = temp1_asr->prev_asr;
        if (temp2_asr) temp2_asr = temp2_asr->prev_asr;
    }

    Node_asr* prev_asr = nullptr;
    Node_asr* curr_asr = resultHead_asr;
    while (curr_asr) {
        Node_asr* next_asr = curr_asr->next_asr;
        curr_asr->next_asr = prev_asr;
        curr_asr->prev_asr = next_asr;
        prev_asr = curr_asr;
        curr_asr = next_asr;
    }
    resultHead_asr = prev_asr;
    return resultHead_asr;
}

int main() {
    srand(time(0));
    Node_asr *head1_asr = nullptr, *tail1_asr = nullptr;
    Node_asr *head2_asr = nullptr, *tail2_asr = nullptr;

    int n1_asr, n2_asr;
    cout << "Enter number of bits for first binary number: ";
    cin >> n1_asr;
    cout << "Enter binary number (MSB to LSB): ";
    for (int i = 0; i < n1_asr; i++) {
        int bit_asr;
        cin >> bit_asr;
        insertEnd_asr(head1_asr, tail1_asr, bit_asr);
    }

    cout << "Enter number of bits for second binary number: ";
    cin >> n2_asr;
    cout << "Enter binary number (MSB to LSB): ";
    for (int i = 0; i < n2_asr; i++) {
        int bit_asr;
        cin >> bit_asr;
        insertEnd_asr(head2_asr, tail2_asr, bit_asr);
    }

    cout << "\nFirst Binary Number: ";
    display_asr(head1_asr);

    cout << "1's Complement: ";
    onesComplement_asr(head1_asr);
    display_asr(head1_asr);

    cout << "2's Complement: ";
    twosComplement_asr(head1_asr, tail1_asr);
    display_asr(head1_asr);

    cout << "\nSecond Binary Number: ";
    display_asr(head2_asr);

    Node_asr* sumHead_asr = addBinary_asr(head1_asr, tail1_asr, head2_asr, tail2_asr);
    cout << "Sum of Binary Numbers: ";
    display_asr(sumHead_asr);

    return 0;
}