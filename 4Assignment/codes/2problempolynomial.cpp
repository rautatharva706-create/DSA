#include <iostream>
using namespace std;

struct Node_asr {
    int coeff_asr;
    int exp_asr;
    Node_asr* next_asr;
};

Node_asr* createNode_asr(int c_asr, int e_asr) {
    Node_asr* newNode_asr = new Node_asr();
    newNode_asr->coeff_asr = c_asr;
    newNode_asr->exp_asr = e_asr;
    newNode_asr->next_asr = NULL;
    return newNode_asr;
}

void insertTerm_asr(Node_asr** poly_asr, int c_asr, int e_asr) {
    Node_asr* newNode_asr = createNode_asr(c_asr, e_asr);
    if (*poly_asr == NULL)
        *poly_asr = newNode_asr;
    else {
        Node_asr* temp_asr = *poly_asr;
        while (temp_asr->next_asr != NULL)
            temp_asr = temp_asr->next_asr;
        temp_asr->next_asr = newNode_asr;
    }
}

void displayPoly_asr(Node_asr* poly_asr) {
    if (!poly_asr) {
        cout << "No polynomial entered.\n";
        return;
    }
    while (poly_asr != NULL) {
        cout << poly_asr->coeff_asr << "x^" << poly_asr->exp_asr;
        if (poly_asr->next_asr != NULL)
            cout << " + ";
        poly_asr = poly_asr->next_asr;
    }
    cout << endl;
}

Node_asr* addPoly_asr(Node_asr* poly1_asr, Node_asr* poly2_asr) {
    Node_asr* result_asr = NULL;

    while (poly1_asr != NULL && poly2_asr != NULL) {
        if (poly1_asr->exp_asr > poly2_asr->exp_asr) {
            insertTerm_asr(&result_asr, poly1_asr->coeff_asr, poly1_asr->exp_asr);
            poly1_asr = poly1_asr->next_asr;
        }
        else if (poly1_asr->exp_asr < poly2_asr->exp_asr) {
            insertTerm_asr(&result_asr, poly2_asr->coeff_asr, poly2_asr->exp_asr);
            poly2_asr = poly2_asr->next_asr;
        }
        else {
            int sumCoeff_asr = poly1_asr->coeff_asr + poly2_asr->coeff_asr;
            insertTerm_asr(&result_asr, sumCoeff_asr, poly1_asr->exp_asr);
            poly1_asr = poly1_asr->next_asr;
            poly2_asr = poly2_asr->next_asr;
        }
    }

    while (poly1_asr != NULL) {
        insertTerm_asr(&result_asr, poly1_asr->coeff_asr, poly1_asr->exp_asr);
        poly1_asr = poly1_asr->next_asr;
    }

    while (poly2_asr != NULL) {
        insertTerm_asr(&result_asr, poly2_asr->coeff_asr, poly2_asr->exp_asr);
        poly2_asr = poly2_asr->next_asr;
    }

    return result_asr;
}

int main() {
    Node_asr* poly1_asr = NULL;
    Node_asr* poly2_asr = NULL;
    Node_asr* result_asr = NULL;
    int n1_asr, n2_asr;
    int coeff_asr, exp_asr;

    cout << "Enter number of terms in first polynomial: ";
    cin >> n1_asr;
    cout << "Enter terms for first polynomial (coeff exponent):\n";
    for (int i_asr = 0; i_asr < n1_asr; i_asr++) {
        cout << "Term " << i_asr + 1 << ": ";
        cin >> coeff_asr >> exp_asr;
        insertTerm_asr(&poly1_asr, coeff_asr, exp_asr);
    }

    cout << "\nEnter number of terms in second polynomial: ";
    cin >> n2_asr;
    cout << "Enter terms for second polynomial (coeff exponent):\n";
    for (int i_asr = 0; i_asr < n2_asr; i_asr++) {
        cout << "Term " << i_asr + 1 << ": ";
        cin >> coeff_asr >> exp_asr;
        insertTerm_asr(&poly2_asr, coeff_asr, exp_asr);
    }

    cout << "\nFirst Polynomial: ";
    displayPoly_asr(poly1_asr);

    cout << "Second Polynomial: ";
    displayPoly_asr(poly2_asr);

    result_asr = addPoly_asr(poly1_asr, poly2_asr);

    cout << "\nResultant Polynomial after Addition: ";
    displayPoly_asr(result_asr);

    return 0;
}
