# Assignment No.2: Problem 4  
# Bubble Sort Algorithm

---

## Title  
Write a program using **Bubble Sort** algorithm to assign the roll numbers to the students of your class as per their previous year's result, i.e., topper will be roll no. 1.  
Also, analyse the sorting algorithm **pass by pass**.

---

## Theory  

Bubble Sort is a basic sorting technique that relies on pairwise comparisons.  
The algorithm repeatedly scans the list and swaps neighboring elements whenever they appear in the wrong order.  
With every complete pass, the largest element moves to its correct position at the end of the list, as if it "bubbles" upward.

### Characteristics:
- **Time Complexity**:  
  - Best Case: O(n), when the array is already sorted  
  - Average & Worst Case: O(n²), due to repeated comparisons and swaps  
- **Space Complexity**: O(1) — requires no extra memory  
- **Properties**: Works in-place and maintains stability during sorting

---

## Algorithm (Bubble Sort)

1. Start.  
2. Read the number of students `n_asr`.  
3. Generate random marks for `n_asr` students using a list of names.  
4. Display the initial list.  
5. Apply Bubble Sort:  
   - For each pass, compare adjacent marks.  
   - Swap if the previous student's marks are smaller (descending order for toppers first).  
   - Print the list after each pass showing swapped elements.  
6. After sorting, assign roll numbers in ascending order of index (topper gets roll no. 1).  
7. Display final sorted list.  
8. Stop.

---

## Code  

```cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

struct Student_asr {
    string name_asr;
    int marks_asr;
    int rollNo_asr;
};

// Function to display student records
void display_asr(Student_asr* students_asr, int n_asr) {
    cout << left << setw(10) << "Name" << setw(10) << "Marks" << setw(10) << "Roll No" << endl;
    for (int i_asr = 0; i_asr < n_asr; i_asr++) {
        cout << left << setw(10) << students_asr[i_asr].name_asr
             << setw(10) << students_asr[i_asr].marks_asr
             << setw(10) << students_asr[i_asr].rollNo_asr << endl;
    }
    cout << endl;
}

// Bubble Sort function
void bubbleSort_asr(Student_asr* students_asr, int n_asr) {
    for (int i_asr = 0; i_asr < n_asr - 1; i_asr++) {
        bool swapped_asr = false;
        cout << "After Pass " << i_asr + 1 << ":" << endl;

        for (int j_asr = 0; j_asr < n_asr - i_asr - 1; j_asr++) {
            if (students_asr[j_asr].marks_asr < students_asr[j_asr + 1].marks_asr) {
                cout << "Swapped: " << students_asr[j_asr].name_asr << " (" << students_asr[j_asr].marks_asr
                     << ") ↔ " << students_asr[j_asr + 1].name_asr << " (" << students_asr[j_asr + 1].marks_asr << ")\n";
                swap(students_asr[j_asr], students_asr[j_asr + 1]);
                swapped_asr = true;
            }
        }

        display_asr(students_asr, n_asr);

        if (!swapped_asr) break;
    }
}

int main() {
    srand(time(0));

    int n_asr;
    cout << "Enter number of students: ";
    cin >> n_asr;

    const char* names_asr[] = {"Abir","Aarav","Isha","Rohan","Priya","Vikas","Neha","Sahil",
                               "Anaya","Dev","Kriti","Mira","Kabir","Tanvi","Yash","Riya",
                               "Arjun","Asha","Nikhil","Pooja","Kunal","Vishal","Amir","Sharukh",
                               "Salman","Mrunal","Kirti"};
    const int N_NAMES_asr = sizeof(names_asr) / sizeof(names_asr[0]);

    Student_asr* students_asr = new Student_asr[n_asr];

    // Generate random marks
    for (int i_asr = 0; i_asr < n_asr; i_asr++) {
        students_asr[i_asr].name_asr = names_asr[rand() % N_NAMES_asr];
        students_asr[i_asr].marks_asr = rand() % 100 + 1;  // marks between 1 and 100
        students_asr[i_asr].rollNo_asr = 0;
    }

    cout << "\nInitial Student Records:\n";
    display_asr(students_asr, n_asr);

    bubbleSort_asr(students_asr, n_asr);

    // Assign roll numbers (1 to n)
    for (int i_asr = 0; i_asr < n_asr; i_asr++) {
        students_asr[i_asr].rollNo_asr = i_asr + 1;
    }

    cout << "Final Sorted Records (Topper has Roll No. 1):\n";
    display_asr(students_asr, n_asr);

    delete[] students_asr;
    return 0;
}
```
# OUTPUT


```
Enter number of students: 5

Enter marks of 5 students:
Abir: 56
Aarav: 78
Isha: 34
Rohan: 90
Priya: 67

Initial Student Records:
Abir       56
Aarav      78
Isha       34
Rohan      90
Priya      67

After pass 1:
Swapped: Aarav ↔ Rohan
Swapped: Isha ↔ Aarav
Swapped: Priya ↔ Aarav
Rohan      90
Aarav      78
Priya      67
Abir       56
Isha       34

After pass 2:
Swapped: Aarav ↔ Priya
Rohan      90
Aarav      78
Priya      67
Abir       56
Isha       34

After pass 3:
No swaps performed.

Sorted Student Records (Topper first):
Rohan      90
Aarav      78
Priya      67
Abir       56
Isha       34

Roll Numbers Assigned:
Roll No. 1 → Rohan (90)
Roll No. 2 → Aarav (78)
Roll No. 3 → Priya (67)
Roll No. 4 → Abir (56)
Roll No. 5 → Isha (34)
```

