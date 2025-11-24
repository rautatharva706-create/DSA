# Assignment No: 4 Problem:2

## Title: 
Write a C++ program to perform addition of two polynomials using a singly linked list.

---

### Theory

A polynomial can be represented using a **singly linked list**, where each node stores a single term of the polynomial. This structure is efficient for handling polynomials with varying sizes and eliminates the need for fixed-size arrays.

Each node in the polynomial linked list contains:
- **Coefficient** → Numerical value of the term  
- **Exponent** → Power of `x` for that term  
- **next** → Pointer to the next term in the list  

The polynomial terms are typically arranged in **descending order of exponents** for easier processing.

Example representation:

$$
P(x) = 3x^3 + 2x^2 + 4x + 5
$$

---

### Polynomial Addition

To add two polynomials:
1. Traverse both linked lists simultaneously  
2. If exponents are equal → Add coefficients  
3. If one has a higher exponent → Copy that term into result  
4. Continue until all terms are processed  

This approach ensures efficient memory usage and dynamic handling of polynomial sizes.

---

### Algorithm

1. **Start**  
2. Create two singly linked lists to represent the two polynomials.  
3. Each node contains two data fields: coefficient and exponent, and one pointer to the next node.  
4. Input terms for both polynomials in decreasing order of exponents.  
5. Traverse both lists:  
   - If exponents are equal, add coefficients and store in result list.  
   - If exponent of first polynomial is greater, copy that term to the result list.  
   - If exponent of second polynomial is greater, copy that term to the result list.  
6. Continue until both lists are fully traversed.  
7. Display the resultant polynomial.  
8. **Stop**

---

### C++ Code
```cpp
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

```

---

### Sample Output

```
Enter number of terms in first polynomial: 3
Enter terms for first polynomial (coeff exponent):
Term 1: 5
2
Term 2: 4 1
Term 3: 2 0

Enter number of terms in second polynomial: 2
Enter terms for second polynomial (coeff exponent):
Term 1: 5 1
Term 2: 5 0

First Polynomial: 5x^2 + 4x^1 + 2x^0
Second Polynomial: 5x^1 + 5x^0

Resultant Polynomial after Addition: 5x^2 + 9x^1 + 7x^0
```
