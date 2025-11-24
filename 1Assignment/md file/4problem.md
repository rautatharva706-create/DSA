# 📘 Assignment 1:Problem 4  

---

## Title  
Develop a program to **identify and efficiently store a sparse matrix** using compact representation and perform basic operations like **display** and **simple transpose**.

---

## Theory  
A **sparse matrix** is one in which the majority of elements are zero.  
To avoid wasting memory by storing all entries, we use a **compressed format** (also known as triplet representation):

- The first entry stores matrix size and the number of non-zero values.
- Each subsequent entry records the position and value as (row, column, value).

This technique saves storage space effectively.  
Using the compact form, operations like **displaying elements** and **computing the transpose** become faster and more memory-efficient.
---

## Algorithm  

1. Read `m_asr` (rows) and `n_asr` (columns).  
2. Dynamically allocate a 2D matrix and input elements.  
3. Count the non-zero elements.  
4. Create a compact sparse representation:  
   - Header row = {rows, cols, non-zero count}  
   - Each subsequent row = {row_index, col_index, value}  
5. Display the sparse matrix in triplet form.  
6. Compute **simple transpose** by swapping row and column indices of each triplet.  
7. Display the transposed sparse matrix.  
8. Free allocated memory.  

---

## Code  

```cpp
#include <iostream>
using namespace std;

typedef struct Sparse_asr {
    int row_asr, col_asr;
    float val_asr;
} SPR_asr;

int main() {
    int m_asr, n_asr; 
    float** matrix_asr = nullptr;
    SPR_asr* sparse_asr = nullptr;
    SPR_asr* transpose_asr = nullptr;
    int i_asr, j_asr;

    cout << "Enter the no of rows: ";
    cin >> m_asr;
    cout << "Enter the no of cols: ";
    cin >> n_asr;

    // Allocate 2D matrix
    matrix_asr = new float*[m_asr];
    for (i_asr = 0; i_asr < m_asr; i_asr++) {
        matrix_asr[i_asr] = new float[n_asr];
    }

    int counter_asr = 0;
    cout << "Enter the elements in the Matrix : \n";
    for (i_asr = 0; i_asr < m_asr; i_asr++) {
        for (j_asr = 0; j_asr < n_asr; j_asr++) {
            cin >> matrix_asr[i_asr][j_asr];
            if (matrix_asr[i_asr][j_asr] != 0.0f)
                counter_asr++;
        }
    }

    cout << "The Matrix is: \n";
    for (i_asr = 0; i_asr < m_asr; i_asr++) {
        for (j_asr = 0; j_asr < n_asr; j_asr++) {
            cout << matrix_asr[i_asr][j_asr] << "\t";
        }
        cout << endl;
    }

    // Sparse representation
    sparse_asr = new SPR_asr[counter_asr + 1];
    sparse_asr[0].row_asr = m_asr;
    sparse_asr[0].col_asr = n_asr;
    sparse_asr[0].val_asr = counter_asr;

    int k_asr = 1;
    for (i_asr = 0; i_asr < m_asr; i_asr++) {
        for (j_asr = 0; j_asr < n_asr; j_asr++) {
            if (matrix_asr[i_asr][j_asr] != 0.0f) {
                sparse_asr[k_asr].row_asr = i_asr;
                sparse_asr[k_asr].col_asr = j_asr;
                sparse_asr[k_asr].val_asr = matrix_asr[i_asr][j_asr];
                k_asr++;
            }
        }
    }

    cout << "\nSparse Matrix Representation (Row, Col, Value):\n";
    for (i_asr = 0; i_asr <= counter_asr; i_asr++) {
        cout << sparse_asr[i_asr].row_asr << "\t"
             << sparse_asr[i_asr].col_asr << "\t"
             << sparse_asr[i_asr].val_asr << endl;
    }

    // Simple Transpose
    transpose_asr = new SPR_asr[counter_asr + 1];
    transpose_asr[0].row_asr = sparse_asr[0].col_asr;
    transpose_asr[0].col_asr = sparse_asr[0].row_asr;
    transpose_asr[0].val_asr = sparse_asr[0].val_asr;

    for (i_asr = 1; i_asr <= counter_asr; i_asr++) {
        transpose_asr[i_asr].row_asr = sparse_asr[i_asr].col_asr;
        transpose_asr[i_asr].col_asr = sparse_asr[i_asr].row_asr;
        transpose_asr[i_asr].val_asr = sparse_asr[i_asr].val_asr;
    }

    cout << "\nTranspose of Sparse Matrix (Row, Col, Value):\n";
    for (i_asr = 0; i_asr <= counter_asr; i_asr++) {
        cout << transpose_asr[i_asr].row_asr << "\t"
             << transpose_asr[i_asr].col_asr << "\t"
             << transpose_asr[i_asr].val_asr << endl;
    }

    // Free memory
    for (i_asr = 0; i_asr < m_asr; i_asr++) {
        delete[] matrix_asr[i_asr];
    }
    delete[] matrix_asr;
    delete[] sparse_asr;
    delete[] transpose_asr;

    return 0;
}
```
## INPUT
Enter the no of rows: 3

Enter the no of cols: 3

Enter the elements in the Matrix :

1 0 0

0 2 0

3 0 4

## OUTPUT

The Matrix is:

1 0 0

0 2 0

3 0 4

Sparse Matrix Representation (Row, Col, Value):

3 3 4

0 0 1

1 1 2

2 0 3

2 2 4

Transpose of Sparse Matrix (Row, Col, Value):

3 3 4

0 0 1

1 1 2

0 2 3

2 2 4