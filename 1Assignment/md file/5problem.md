# Assignment No.1: Problem 5  
## Title: Develop a program to compute the fast transpose of a sparse matrix using its compact (triplet) representation efficiently.

---

## Theory  

A **sparse matrix** is defined as a matrix where the number of zero elements is significantly higher than the number of non-zero elements.  
To save memory, only the non-zero values are stored using a **compact (triplet) representation**.

In the triplet format, each stored entry contains:  
- Row position  
- Column position  
- The actual non-zero value  

### Fast Transpose  

The **fast transpose technique** provides a more optimized way to find the transpose of a sparse matrix.  
Instead of repeatedly searching the full matrix for transpose mapping, it counts how many elements appear in each column and uses that information to place values directly in their correct transposed positions.  
This results in a quicker and more efficient computation.

## Pseudocode  

1. Read the sparse matrix in compact form.  
2. Initialize an array `row_terms` to count the number of elements in each column.  
3. Initialize an array `starting_pos` to find the starting index for each column in the transposed matrix.  
4. Place each non-zero element directly into its position in the transposed matrix using `starting_pos`.  
5. Display the fast transposed sparse matrix.  

---

## Code  

```cpp
#include <iostream>
#include <vector>
using namespace std;

typedef struct Sparse_asr {
    int row_asr, col_asr;
    float val_asr;
} SPR_asr;

void fastTranspose_asr(vector<SPR_asr>& sparse_asr, vector<SPR_asr>& trans_asr) {
    int rows_asr = sparse_asr[0].row_asr;
    int cols_asr = sparse_asr[0].col_asr;
    int terms_asr = sparse_asr[0].val_asr;

    trans_asr[0].row_asr = cols_asr;
    trans_asr[0].col_asr = rows_asr;
    trans_asr[0].val_asr = terms_asr;

    if (terms_asr > 0) {
        vector<int> row_terms_asr(cols_asr, 0);
        vector<int> starting_pos_asr(cols_asr, 0);

        for (int i_asr = 1; i_asr <= terms_asr; i_asr++) {
            row_terms_asr[sparse_asr[i_asr].col_asr]++;
        }

        starting_pos_asr[0] = 1;
        for (int i_asr = 1; i_asr < cols_asr; i_asr++) {
            starting_pos_asr[i_asr] = starting_pos_asr[i_asr - 1] + row_terms_asr[i_asr - 1];
        }

        for (int i_asr = 1; i_asr <= terms_asr; i_asr++) {
            int col_asr = sparse_asr[i_asr].col_asr;
            int pos_asr = starting_pos_asr[col_asr];
            trans_asr[pos_asr].row_asr = sparse_asr[i_asr].col_asr;
            trans_asr[pos_asr].col_asr = sparse_asr[i_asr].row_asr;
            trans_asr[pos_asr].val_asr = sparse_asr[i_asr].val_asr;
            starting_pos_asr[col_asr]++;
        }
    }
}

int main() {
    int m_asr, n_asr;
    cout << "Enter the number of rows: ";
    cin >> m_asr;
    cout << "Enter the number of cols: ";
    cin >> n_asr;

    vector<vector<float>> matrix_asr(m_asr, vector<float>(n_asr, 0));
    cout << "Enter the elements in the Matrix : \n";

    int counter_asr = 0;
    for (int i_asr = 0; i_asr < m_asr; i_asr++) {
        for (int j_asr = 0; j_asr < n_asr; j_asr++) {
            cin >> matrix_asr[i_asr][j_asr];
            if (matrix_asr[i_asr][j_asr] != 0.0f)
                counter_asr++;
        }
    }

    cout << "\nThe Matrix is:\n";
    for (int i_asr = 0; i_asr < m_asr; i_asr++) {
        for (int j_asr = 0; j_asr < n_asr; j_asr++) {
            cout << matrix_asr[i_asr][j_asr] << "\t";
        }
        cout << "\n";
    }

    vector<SPR_asr> sparse_asr(counter_asr + 1);
    sparse_asr[0].row_asr = m_asr;
    sparse_asr[0].col_asr = n_asr;
    sparse_asr[0].val_asr = counter_asr;

    int k_asr = 1;
    for (int i_asr = 0; i_asr < m_asr; i_asr++) {
        for (int j_asr = 0; j_asr < n_asr; j_asr++) {
            if (matrix_asr[i_asr][j_asr] != 0.0f) {
                sparse_asr[k_asr].row_asr = i_asr;
                sparse_asr[k_asr].col_asr = j_asr;
                sparse_asr[k_asr].val_asr = matrix_asr[i_asr][j_asr];
                k_asr++;
            }
        }
    }

    cout << "\nSparse Matrix Representation (Row, Col, Value):\n";
    for (int i_asr = 0; i_asr <= counter_asr; i_asr++) {
        cout << sparse_asr[i_asr].row_asr << "\t"
             << sparse_asr[i_asr].col_asr << "\t"
             << sparse_asr[i_asr].val_asr << "\n";
    }

    vector<SPR_asr> trans_asr(counter_asr + 1);
    fastTranspose_asr(sparse_asr, trans_asr);

    cout << "\nFast Transpose (Row, Col, Value):\n";
    for (int i_asr = 0; i_asr <= counter_asr; i_asr++) {
        cout << trans_asr[i_asr].row_asr << "\t"
             << trans_asr[i_asr].col_asr << "\t"
             << trans_asr[i_asr].val_asr << "\n";
    }

    return 0;
}
```
Enter the number of rows: 3

Enter the number of cols: 3

Enter the elements in the Matrix :

1 0 0

0 2 0

3 0 4

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

Fast Transpose (Row, Col, Value):

3 3 4

0 0 1

1 1 2

0 2 3

2 2 4