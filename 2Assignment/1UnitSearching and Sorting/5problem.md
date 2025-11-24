# Assignment No.2: Problem 5

# Sorting Employees by Average of Height and Weight

---

## Title

Write a program to arrange the list of employees as per the **average of their height and weight** using **Merge Sort** and **Selection Sort** algorithms.
Analyse the sorting **pass by pass** and display the number of swaps performed.

---

## Theory  

Sorting plays a crucial role in data organization and retrieval within computer science. Two widely used sorting methods are:

### Selection Sort:

- This method repeatedly finds the smallest element from the unsorted section and places it at the correct position in the front.
- **Time Complexity**:
  - Best, Average, and Worst Cases: O(n²)
- **Space Complexity**: O(1)
- **Characteristics**: In-place algorithm but not stable

### Merge Sort:

- This approach follows divide-and-conquer: the array is split into two halves, each half is sorted recursively, and then merged back in order.
- **Time Complexity**:
  - Best, Average, and Worst Cases: O(n log n)
- **Space Complexity**: O(n)
- **Characteristics**: Stable but requires extra memory (not in-place)

**Conclusion:**  
Merge Sort is more efficient for larger datasets due to its O(n log n) time complexity, whereas Selection Sort involves more comparisons, resulting in O(n²) performance.

---

## Algorithm (Selection Sort)

1. Start.
2. Read number of employees `n_asr`.
3. Initialize employee names, heights, and weights arrays.
4. Calculate the average of height and weight for each employee.
5. For each pass, select the minimum average from the unsorted portion and swap with the current position.
6. Display the list after each pass along with the swaps.
7. Stop after sorting.

---

## Algorithm (Merge Sort)

1. Start.
2. Read number of employees `n_asr`.
3. Initialize employee names, heights, and weights arrays.
4. Calculate the average of height and weight for each employee.
5. Recursively divide the array into halves until single elements remain.
6. Merge halves in sorted order, counting swaps.
7. Display the list after each merge along with swaps.
8. Stop after sorting.

---

## Code

```cpp
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Employee_asr {
    string name_asr;
    double height_asr;
    double weight_asr;
    double avg_asr;
};

// Function to display employee records
void display_asr(Employee_asr* employees_asr, int n_asr) {
    cout << left << setw(10) << "Name"
         << setw(10) << "Height"
         << setw(10) << "Weight"
         << setw(10) << "Average" << endl;
    for (int i_asr = 0; i_asr < n_asr; i_asr++) {
        cout << left << setw(10) << employees_asr[i_asr].name_asr
             << setw(10) << employees_asr[i_asr].height_asr
             << setw(10) << employees_asr[i_asr].weight_asr
             << setw(10) << employees_asr[i_asr].avg_asr << endl;
    }
    cout << endl;
}

// Selection Sort function
void selectionSort_asr(Employee_asr* employees_asr, int n_asr) {
    int totalSwaps_asr = 0;
    for (int i_asr = 0; i_asr < n_asr - 1; i_asr++) {
        int min_idx_asr = i_asr;
        for (int j_asr = i_asr + 1; j_asr < n_asr; j_asr++) {
            if (employees_asr[j_asr].avg_asr < employees_asr[min_idx_asr].avg_asr) {
                min_idx_asr = j_asr;
            }
        }
        if (min_idx_asr != i_asr) {
            cout << "After pass " << i_asr + 1 << ": Swapped "
                 << employees_asr[i_asr].name_asr << " ↔ "
                 << employees_asr[min_idx_asr].name_asr << endl;
            swap(employees_asr[i_asr], employees_asr[min_idx_asr]);
            totalSwaps_asr++;
        } else {
            cout << "After pass " << i_asr + 1 << ": No swaps performed." << endl;
        }
        display_asr(employees_asr, n_asr);
    }
    cout << "Total swaps (Selection Sort): " << totalSwaps_asr << endl;
}

// Merge function for Merge Sort (counts swaps as inversions)
int merge_asr(Employee_asr* arr_asr, int l_asr, int m_asr, int r_asr) {
    int swaps_asr = 0;
    int n1_asr = m_asr - l_asr + 1;
    int n2_asr = r_asr - m_asr;

    Employee_asr* L_asr = new Employee_asr[n1_asr];
    Employee_asr* R_asr = new Employee_asr[n2_asr];

    for (int i_asr = 0; i_asr < n1_asr; i_asr++) L_asr[i_asr] = arr_asr[l_asr + i_asr];
    for (int j_asr = 0; j_asr < n2_asr; j_asr++) R_asr[j_asr] = arr_asr[m_asr + 1 + j_asr];

    int i_asr = 0, j_asr = 0, k_asr = l_asr;
    while (i_asr < n1_asr && j_asr < n2_asr) {
        if (L_asr[i_asr].avg_asr <= R_asr[j_asr].avg_asr) {
            arr_asr[k_asr++] = L_asr[i_asr++];
        } else {
            arr_asr[k_asr++] = R_asr[j_asr++];
            swaps_asr += n1_asr - i_asr; // Count inversions as swaps
        }
    }

    while (i_asr < n1_asr) arr_asr[k_asr++] = L_asr[i_asr++];
    while (j_asr < n2_asr) arr_asr[k_asr++] = R_asr[j_asr++];

    delete[] L_asr;
    delete[] R_asr;
    return swaps_asr;
}

// Merge Sort function
int mergeSort_asr(Employee_asr* arr_asr, int l_asr, int r_asr) {
    int totalSwaps_asr = 0;
    if (l_asr < r_asr) {
        int m_asr = l_asr + (r_asr - l_asr) / 2;
        totalSwaps_asr += mergeSort_asr(arr_asr, l_asr, m_asr);
        totalSwaps_asr += mergeSort_asr(arr_asr, m_asr + 1, r_asr);
        totalSwaps_asr += merge_asr(arr_asr, l_asr, m_asr, r_asr);
    }
    return totalSwaps_asr;
}

int main() {
    const char* names_asr[] = {"Abir","Aarav","Isha","Rohan","Priya","Vikas","Neha","Sahil",
                               "Anaya","Dev","Kriti","Mira","Kabir","Tanvi","Yash","Riya",
                               "Arjun","Asha","Nikhil","Pooja","Kunal","Vishal","Amir","Sharukh",
                               "Salman","Mrunal","Kirti"};
    const int N_NAMES_asr = sizeof(names_asr) / sizeof(names_asr[0]);

    int n_asr;
    cout << "Enter number of employees: ";
    cin >> n_asr;

    srand(time(0));

    Employee_asr* original_asr = new Employee_asr[n_asr];

    // Generate random employee data
    for (int i_asr = 0; i_asr < n_asr; i_asr++) {
        original_asr[i_asr].name_asr = names_asr[i_asr % N_NAMES_asr];
        original_asr[i_asr].height_asr = 150 + rand() % 41;  
        original_asr[i_asr].weight_asr = 50 + rand() % 51;   
        original_asr[i_asr].avg_asr = (original_asr[i_asr].height_asr + original_asr[i_asr].weight_asr) / 2;
    }

    cout << "\nInitial Employee Records:\n";
    display_asr(original_asr, n_asr);

    // Selection Sort
    Employee_asr* sel_asr = new Employee_asr[n_asr];
    for (int i_asr = 0; i_asr < n_asr; i_asr++) sel_asr[i_asr] = original_asr[i_asr];

    cout << "\n--- Selection Sort ---\n";
    selectionSort_asr(sel_asr, n_asr);

    // Merge Sort
    Employee_asr* merge_asr_arr = new Employee_asr[n_asr];
    for (int i_asr = 0; i_asr < n_asr; i_asr++) merge_asr_arr[i_asr] = original_asr[i_asr];

    cout << "\n--- Merge Sort ---\n";
    int mergeSwaps_asr = mergeSort_asr(merge_asr_arr, 0, n_asr - 1);
    cout << "Sorted Employee Records (Merge Sort):\n";
    display_asr(merge_asr_arr, n_asr);
    cout << "Total swaps (Merge Sort): " << mergeSwaps_asr << endl;

    delete[] original_asr;
    delete[] sel_asr;
    delete[] merge_asr_arr;
    return 0;
}

```

---

##  OUTPUT

```
Enter number of employees: 4

Initial Employee Records:
Name      Height    Weight    Average
Abir      171       68        119.5
Aarav     170       94        132
Isha      167       57        112
Rohan     156       72        114


--- Selection Sort ---
After pass 1: Swapped Abir Γåö Isha
Name      Height    Weight    Average
Isha      167       57        112
Aarav     170       94        132
Abir      171       68        119.5
Rohan     156       72        114

After pass 2: Swapped Aarav Γåö Rohan
Name      Height    Weight    Average
Isha      167       57        112
Rohan     156       72        114
Abir      171       68        119.5
Aarav     170       94        132

After pass 3: No swaps performed.
Name      Height    Weight    Average
Isha      167       57        112
Rohan     156       72        114       
Abir      171       68        119.5
Aarav     170       94        132

Total swaps (Selection Sort): 2

--- Merge Sort ---
Sorted Employee Records (Merge Sort):
Name      Height    Weight    Average
Isha      167       57        112
Rohan     156       72        114
Abir      171       68        119.5
Aarav     170       94        132

Total swaps (Merge Sort): 4
```
