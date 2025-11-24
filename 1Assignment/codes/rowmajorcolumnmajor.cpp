#include <iostream>
#include <vector>
#include <cstdlib> // for rand()
#include <ctime>   // for seeding rand()
using namespace std;

// Row-major matrix multiplication
void rowMajorMultiply_asr(vector<vector<int>>& A_asr, vector<vector<int>>& B_asr, vector<vector<int>>& C_asr) {
    int m_asr = A_asr.size();
    int n_asr = A_asr[0].size();
    int p_asr = B_asr[0].size();

    for (int i_asr = 0; i_asr < m_asr; i_asr++) {
        for (int j_asr = 0; j_asr < p_asr; j_asr++) {
            C_asr[i_asr][j_asr] = 0;
            for (int k_asr = 0; k_asr < n_asr; k_asr++) {
                C_asr[i_asr][j_asr] += A_asr[i_asr][k_asr] * B_asr[k_asr][j_asr];
            }
        }
    }
}

// Column-major matrix multiplication
void colMajorMultiply_asr(vector<vector<int>>& A_asr, vector<vector<int>>& B_asr, vector<vector<int>>& C_asr) {
    int m_asr = A_asr.size();
    int n_asr = A_asr[0].size();
    int p_asr = B_asr[0].size();

    for (int j_asr = 0; j_asr < p_asr; j_asr++) {
        for (int i_asr = 0; i_asr < m_asr; i_asr++) {
            C_asr[i_asr][j_asr] = 0;
            for (int k_asr = 0; k_asr < n_asr; k_asr++) {
                C_asr[i_asr][j_asr] += A_asr[i_asr][k_asr] * B_asr[k_asr][j_asr];
            }
        }
    }
}

// Function to display a matrix
void displayMatrix_asr(vector<vector<int>>& M_asr) {
    int rows_asr = M_asr.size();
    int cols_asr = M_asr[0].size();
    for (int i_asr = 0; i_asr < rows_asr; i_asr++) {
        for (int j_asr = 0; j_asr < cols_asr; j_asr++) {
            cout << M_asr[i_asr][j_asr] << "\t";
        }
        cout << endl;
    }
}

int main() {
    srand(time(0)); // seed for random numbers

    int m_asr, n_asr, p_asr;
    cout << "Enter dimensions m n p for matrices A(m x n) and B(n x p): ";
    cin >> m_asr >> n_asr >> p_asr;

    vector<vector<int>> A_asr(m_asr, vector<int>(n_asr));
    vector<vector<int>> B_asr(n_asr, vector<int>(p_asr));
    vector<vector<int>> C_asr(m_asr, vector<int>(p_asr, 0));

    // Initialize matrices with random numbers between 1 and 10
    for (int i_asr = 0; i_asr < m_asr; i_asr++)
        for (int j_asr = 0; j_asr < n_asr; j_asr++)
            A_asr[i_asr][j_asr] = rand() % 10 + 1;

    for (int i_asr = 0; i_asr < n_asr; i_asr++)
        for (int j_asr = 0; j_asr < p_asr; j_asr++)
            B_asr[i_asr][j_asr] = rand() % 10 + 1;

    cout << "\nMatrix A:\n";
    displayMatrix_asr(A_asr);

    cout << "\nMatrix B:\n";
    displayMatrix_asr(B_asr);

    // Row-major multiplication
    rowMajorMultiply_asr(A_asr, B_asr, C_asr);
    cout << "\nResult after row-major multiplication:\n";
    displayMatrix_asr(C_asr);

    // Column-major multiplication
    colMajorMultiply_asr(A_asr, B_asr, C_asr);
    cout << "\nResult after column-major multiplication:\n";
    displayMatrix_asr(C_asr);

    return 0;
}
