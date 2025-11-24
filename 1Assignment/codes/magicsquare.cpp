#include <iostream>
#include <cstdlib>
using namespace std;

// Function to generate odd-order magic square
void generateOdd_asr(int n_asr, int** square_asr) {
    int num_asr = 1;
    int row_asr = 0, col_asr = n_asr / 2;
    int next_row_asr, next_col_asr;

    while (num_asr <= n_asr * n_asr) {
        square_asr[row_asr][col_asr] = num_asr++;
        next_row_asr = row_asr - 1;
        next_col_asr = col_asr + 1;
        if (next_row_asr < 0) next_row_asr = n_asr - 1;
        if (next_col_asr == n_asr) next_col_asr = 0;
        if (square_asr[next_row_asr][next_col_asr] != 0) {
            next_row_asr = (row_asr + 1) % n_asr;
            next_col_asr = col_asr;
        }
        row_asr = next_row_asr;
        col_asr = next_col_asr;
    }
}

// Function to generate doubly-even magic square (n divisible by 4)
void generateDoublyEven_asr(int n_asr, int** square_asr) {
    int num_asr = 1;
    for (int i_asr = 0; i_asr < n_asr; i_asr++)
        for (int j_asr = 0; j_asr < n_asr; j_asr++)
            square_asr[i_asr][j_asr] = num_asr++;

    for (int i_asr = 0; i_asr < n_asr; i_asr++) {
        for (int j_asr = 0; j_asr < n_asr; j_asr++) {
            if ((i_asr % 4 == j_asr % 4) || ((i_asr % 4 + j_asr % 4) == 3)) {
                square_asr[i_asr][j_asr] = n_asr * n_asr + 1 - square_asr[i_asr][j_asr];
            }
        }
    }
}

// Function to display the magic square
void display_asr(int n_asr, int** square_asr) {
    for (int i_asr = 0; i_asr < n_asr; i_asr++) {
        for (int j_asr = 0; j_asr < n_asr; j_asr++)
            cout << square_asr[i_asr][j_asr] << "\t";
        cout << endl;
    }
}

// Function to verify if the magic square is valid
bool verify_asr(int n_asr, int** square_asr) {
    int magic_sum_asr = n_asr * (n_asr * n_asr + 1) / 2;

    // Check rows
    for (int i_asr = 0; i_asr < n_asr; i_asr++) {
        int row_sum_asr = 0;
        for (int j_asr = 0; j_asr < n_asr; j_asr++)
            row_sum_asr += square_asr[i_asr][j_asr];
        if (row_sum_asr != magic_sum_asr) return false;
    }

    // Check columns
    for (int j_asr = 0; j_asr < n_asr; j_asr++) {
        int col_sum_asr = 0;
        for (int i_asr = 0; i_asr < n_asr; i_asr++)
            col_sum_asr += square_asr[i_asr][j_asr];
        if (col_sum_asr != magic_sum_asr) return false;
    }

    // Check diagonals
    int diag1_asr = 0, diag2_asr = 0;
    for (int i_asr = 0; i_asr < n_asr; i_asr++) {
        diag1_asr += square_asr[i_asr][i_asr];
        diag2_asr += square_asr[i_asr][n_asr - i_asr - 1];
    }
    if (diag1_asr != magic_sum_asr || diag2_asr != magic_sum_asr) return false;

    return true;
}

int main() {
    int n_asr;
    cout << "Enter the order of the magic square: ";
    cin >> n_asr;

    if (n_asr <= 0) {
        cout << "Order must be positive." << endl;
        return -1;
    }

    // Dynamic allocation
    int** magic_square_asr = (int**)malloc(n_asr * sizeof(int*));
    for (int i_asr = 0; i_asr < n_asr; i_asr++)
        magic_square_asr[i_asr] = (int*)malloc(n_asr * sizeof(int));

    // Initialize
    for (int i_asr = 0; i_asr < n_asr; i_asr++)
        for (int j_asr = 0; j_asr < n_asr; j_asr++)
            magic_square_asr[i_asr][j_asr] = 0;

    // Generate magic square
    if (n_asr % 2 == 1) {
        generateOdd_asr(n_asr, magic_square_asr);
    } else if (n_asr % 4 == 0) {
        generateDoublyEven_asr(n_asr, magic_square_asr);
    } else {
        cout << "Singly even order (n % 2 == 0 and n % 4 != 0) not implemented." << endl;
        return 0;
    }

    // Display
    cout << "\nMagic Square:\n";
    display_asr(n_asr, magic_square_asr);

    // Verify
    if (verify_asr(n_asr, magic_square_asr))
        cout << "The magic square is valid!\n";
    else
        cout << "The magic square is NOT valid!\n";

    // Free memory
    for (int i_asr = 0; i_asr < n_asr; i_asr++)
        free(magic_square_asr[i_asr]);
    free(magic_square_asr);

    return 0;
}
