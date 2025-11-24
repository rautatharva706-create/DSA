# 📘 Assignment 1: Problem 3

---

## Title

Design and execute **matrix multiplication** while comparing the performance impact of **row-major and column-major memory access techniques**, demonstrating how memory organization influences cache efficiency.

---

## Theory

- **Matrix multiplication** is a key linear algebra process where multiplying matrix A (m×n) with matrix B (n×p) results in matrix C (m×p).
- In **row-major memory layout**, consecutive elements of the same row are placed next to each other in memory.
- In **column-major memory layout**, adjacent memory locations store elements from the same column.
- Cache utilization depends on how sequentially memory is accessed — accessing neighboring data is faster due to **spatial locality**.
- By running multiplication using both layouts, we can compare how each access pattern influences computation time due to cache behavior.


## Algorithm  

1. Initialize matrices A and B with random or given values.  
2. Create a result matrix C of appropriate size and initialize to zero.  
3. Perform **row-major multiplication**:
   - For each row `i` of A  
     - For each column `j` of B  
       - For each element `k`, multiply A[i][k] with B[k][j] and add to C[i][j]  
4. Measure the execution time for row-major order.  
5. Perform **column-major multiplication**:
   - For each column `j` of B  
     - For each row `i` of A  
       - For each element `k`, multiply A[i][k] with B[k][j] and add to C[i][j]  
6. Measure the execution time for column-major order.  
7. Compare execution times to understand the effect of memory layout on cache performance.  

---

## Code  

```cpp
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
```
## Output
**Matrix A:**
4	7	2
5	1	6
3	8	9

**Matrix B:**
1	3	2
6	4	5
7	2	8

**Result after row-major multiplication:**
32	37	36
49	33	47
101	58	91

**Result after column-major multiplication:**
32	37	36
49	33	47
101	58	91


