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
