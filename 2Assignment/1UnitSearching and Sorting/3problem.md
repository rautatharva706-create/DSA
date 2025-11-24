# Assignment No.2: Problem 3  

---

## Title  
Write a program to input marks of `n` students. Sort the marks in ascending order using the **Quick Sort** algorithm without using built-in library functions and analyse the sorting algorithm pass by pass. Find the minimum and maximum marks using **Divide and Conquer** recursively. Each mark is associated with a student name.

---

## Theory  

Sorting involves organizing elements in a collection into a defined order, typically ascending or descending.  
**Quick Sort** is a highly efficient sorting technique based on the divide-and-conquer principle:

- **Quick Sort Steps**:  
  1. Choose a pivot element from the list.  
  2. Rearrange elements so that all values smaller than the pivot come before it and all greater values come after it.  
  3. Apply the same process recursively to the left and right partitions until the entire array is sorted.

- **Divide and Conquer approach for Finding Min/Max**:  
  1. Split the array into two equal parts.  
  2. Recursively determine the minimum and maximum in each part.  
  3. Compare the results from both halves to obtain the final minimum and maximum values.

---

## Algorithm  

1. Start.  
2. Read number of students `n_asr`.  
3. Dynamically allocate arrays `marks_asr` and `namesIndex_asr` to store student marks and associated name indices.  
4. Generate or input student marks and assign names randomly from the predefined list.  
5. Display initial array of student records (Name & Marks).  
6. Apply **Quick Sort**:  
   - Partition the array around a pivot.  
   - Recursively sort left and right subarrays.  
   - Swap associated names along with marks.  
   - Display array after each partition (pass-by-pass analysis).  
7. Use **Divide and Conquer** to find minimum and maximum marks recursively.  
8. Display sorted array, minimum, and maximum marks along with student names.  
9. Stop.  

---

## Code  

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Quick Sort function
void quickSort_asr(int* arr_asr, const int* namesIndex_asr, int* namesIndexSorted_asr, int low_asr, int high_asr);
int partition_asr(int* arr_asr, int* namesIndexSorted_asr, int low_asr, int high_asr);

// Function to display student records
void display_asr(int* arr_asr, int* namesIndex_asr, const char* names_asr[], int n_asr);

// Divide and Conquer for min and max
void findMinMax_asr(int* arr_asr, int low_asr, int high_asr, int& min_asr, int& max_asr);

int main() {
    srand(time(0));

    int n_asr;
    cout << "Enter number of students: ";
    cin >> n_asr;

    int* marks_asr = new int[n_asr];
    int* namesIndexSorted_asr = new int[n_asr]; // will track name indices after sort

    const char* names_asr[] = {"Abir","Aarav","Isha","Rohan","Priya","Vikas","Neha","Sahil",
                               "Anaya","Dev","Kriti","Mira","Kabir","Tanvi","Yash","Riya",
                               "Arjun","Asha","Nikhil","Pooja","Kunal","Vishal","Amir","Sharukh",
                               "Salman","Mrunal","Kirti"};
    const int N_NAMES_asr = sizeof(names_asr) / sizeof(names_asr[0]);

    // Generate random marks and assign name indices
    for(int i_asr = 0; i_asr < n_asr; i_asr++) {
        marks_asr[i_asr] = rand() % 101; // 0-100 marks
        namesIndexSorted_asr[i_asr] = rand() % N_NAMES_asr; // random name index
    }

    cout << "\nInitial Student Records:\n";
    display_asr(marks_asr, namesIndexSorted_asr, names_asr, n_asr);

    // Quick Sort
    quickSort_asr(marks_asr, namesIndexSorted_asr, namesIndexSorted_asr, 0, n_asr - 1);

    cout << "\nSorted Student Records (Ascending Order):\n";
    display_asr(marks_asr, namesIndexSorted_asr, names_asr, n_asr);

    // Find min and max
    int min_asr, max_asr;
    findMinMax_asr(marks_asr, 0, n_asr - 1, min_asr, max_asr);
    cout << "\nMinimum Marks: " << min_asr << endl;
    cout << "Maximum Marks: " << max_asr << endl;

    delete[] marks_asr;
    delete[] namesIndexSorted_asr;
    return 0;
}

// Quick Sort functions
int partition_asr(int* arr_asr, int* namesIndexSorted_asr, int low_asr, int high_asr) {
    int pivot_asr = arr_asr[high_asr];
    int i_asr = low_asr - 1;
    for(int j_asr = low_asr; j_asr < high_asr; j_asr++) {
        if(arr_asr[j_asr] <= pivot_asr) {
            i_asr++;
            swap(arr_asr[i_asr], arr_asr[j_asr]);
            swap(namesIndexSorted_asr[i_asr], namesIndexSorted_asr[j_asr]);
        }
    }
    swap(arr_asr[i_asr + 1], arr_asr[high_asr]);
    swap(namesIndexSorted_asr[i_asr + 1], namesIndexSorted_asr[high_asr]);
    return i_asr + 1;
}

void quickSort_asr(int* arr_asr, const int* namesIndex_asr, int* namesIndexSorted_asr, int low_asr, int high_asr) {
    if(low_asr < high_asr) {
        int pi_asr = partition_asr(arr_asr, namesIndexSorted_asr, low_asr, high_asr);
        cout << "\nAfter pass (pivot index " << pi_asr << "):\n";
        display_asr(arr_asr, namesIndexSorted_asr, namesIndex_asr, high_asr + 1);
        quickSort_asr(arr_asr, namesIndex_asr, namesIndexSorted_asr, low_asr, pi_asr - 1);
        quickSort_asr(arr_asr, namesIndex_asr, namesIndexSorted_asr, pi_asr + 1, high_asr);
    }
}

void display_asr(int* arr_asr, int* namesIndex_asr, const char* names_asr[], int n_asr) {
    cout << "Name\tMarks\n";
    for(int i_asr = 0; i_asr < n_asr; i_asr++) {
        cout << names_asr[namesIndex_asr[i_asr]] << "\t" << arr_asr[i_asr] << endl;
    }
}

// Divide and Conquer to find min and max
void findMinMax_asr(int* arr_asr, int low_asr, int high_asr, int& min_asr, int& max_asr) {
    if(low_asr == high_asr) { // only one element
        min_asr = max_asr = arr_asr[low_asr];
    } else if(high_asr == low_asr + 1) { // two elements
        if(arr_asr[low_asr] < arr_asr[high_asr]) {
            min_asr = arr_asr[low_asr];
            max_asr = arr_asr[high_asr];
        } else {
            min_asr = arr_asr[high_asr];
            max_asr = arr_asr[low_asr];
        }
    } else {
        int mid_asr = (low_asr + high_asr)/2;
        int min1_asr, max1_asr, min2_asr, max2_asr;
        findMinMax_asr(arr_asr, low_asr, mid_asr, min1_asr, max1_asr);
        findMinMax_asr(arr_asr, mid_asr+1, high_asr, min2_asr, max2_asr);
        min_asr = (min1_asr < min2_asr) ? min1_asr : min2_asr;
        max_asr = (max1_asr > max2_asr) ? max1_asr : max2_asr;
    }
}
```
# OUTPUT
```

Enter number of students: 5

Initial Student Records:

Riya    34

Dev     78

Tanvi   56

Kriti   90

Kabir   12

After pass (pivot index 4):

Riya    34

Tanvi   56

Kabir   12

Dev     78

Kriti   90

After pass (pivot index 2):

Kabir   12

Riya    34

Tanvi   56

Dev     78

Kriti   90

After pass (pivot index 1):

Kabir   12

Riya    34

Tanvi   56

Dev     78

Kriti   90

Sorted Student Records (Ascending Order):

Kabir   12

Riya    34

Tanvi   56

Dev     78

Kriti   90

Minimum Marks: 12

Maximum Marks: 90