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