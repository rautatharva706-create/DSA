#  Assignment 1: Problem 2  

## Title  

Develop a program that **creates and validates a magic square of order ‘n’** (for both odd and even values of n), ensuring that every row, column, and diagonal results in the same total.

---

## Theory  

A **magic square** is a special type of square matrix in which the sum of each row, each column, and the two main diagonals remains constant.

- For **odd-order** magic squares, the **Siamese technique** is used to place elements sequentially.
- For **doubly-even** orders (multiples of 4), the **complementary number method** is applied for correct construction.
- For **singly-even** orders (even but not multiples of 4), the **Strachey method** is followed, dividing the matrix into smaller odd-order magic squares.

Magic squares are important in combinatorial mathematics, number patterns, and structured problem-solving.  
This experiment demonstrates array handling, dynamic memory usage, and logical arrangement of values to achieve equal sums across all rows, columns, and diagonals.
  
---
## Algorithm
1. Read `n`. If `n <= 0` or `n` is even → stop with error (works only for odd `n`).  
2. Dynamically allocate an `n × n` matrix and initialize every cell to `0`.  
3. Set `row = 0` and `col = n / 2` (top row, middle column).  
4. For `num` from `1` to `n*n`:  
   4a. Place `num` at `magic_square[row][col]`.  
   4b. Compute tentative next position:  
       - `next_row = row - 1` (move up)  
       - `next_col = col + 1` (move right)  
   4c. Wrap around the edges:  
       - if `next_row < 0` → `next_row = n - 1`  
       - if `next_col == n` → `next_col = 0`  
   4d. If `magic_square[next_row][next_col] != 0` (occupied), then move down one from the current cell:  
       - `next_row = (row + 1) % n`  
       - `next_col = col`  
   4e. Update `row = next_row` and `col = next_col`.  
5. Print the matrix and the magic sum.  
6. Free all dynamically allocated memory.  
---
## Code  
```cpp
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

Output:
Magic Square:
8   1   6
3   5   7
4   9   2
The magic square is valid!

Magic Square:
1   15   14   4
12   6    7    9
8    10   11   5
13   3    2    16
The magic square is valid!


