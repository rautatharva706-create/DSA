# Assignment No: 6

## Title: Set Operations using Linked Lists for Favorite Sports

### Theory:
In this assignment, we are dealing with two sets of students based on their favorite sports:

- **Set A**: Students who like **Cricket**
- **Set B**: Students who like **Football**

To store and process these sets, we use **Singly Linked Lists**. These structures support dynamic memory allocation and allow easy insertion, deletion, and traversal — which makes them suitable for implementing set operations.

We perform the following operations:

1. **Intersection**
   - Finds students who like **both Cricket and Football**.
2. **Symmetric Difference**
   - Finds students who like **either Cricket or Football but not both**.
3. **Complement**
   - Calculates the number of students who like **neither Cricket nor Football**.

This assignment helps understand practical implementation of set theory using linked lists and improves concepts of data structure traversal and manipulation.

---

### Algorithm:

**1. Intersection of Sets (Cricket ∩ Football)**
1. Traverse both linked lists.
2. Compare each student from Set A with students from Set B.
3. If a match is found, add the student to the intersection list.

**2. Symmetric Difference (Cricket ⊕ Football)**
1. Traverse Set A and add elements not in Set B.
2. Traverse Set B and add elements not in Set A.

**3. Complement (Neither Cricket nor Football)**
1. Total students = 27 (as per given names array)
2. Count students in intersection and union of sets.
3. Students in neither = Total - Union count.

**4. Display Function**
1. Traverse the linked list.
2. Print the student names.

---

### C++ Code:

```cpp
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct Student_asr {
    string name_asr;
    Student_asr* next_asr;
};

// Function to create a linked list from an array of names
Student_asr* createList_asr(const string* names_asr, int n_asr) {
    Student_asr* head_asr = nullptr;
    Student_asr* tail_asr = nullptr;
    for (int i_asr = 0; i_asr < n_asr; i_asr++) {
        Student_asr* newNode_asr = new Student_asr{names_asr[i_asr], nullptr};
        if (!head_asr) {
            head_asr = tail_asr = newNode_asr;
        } else {
            tail_asr->next_asr = newNode_asr;
            tail_asr = newNode_asr;
        }
    }
    return head_asr;
}

// Function to display linked list
void displayList_asr(Student_asr* head_asr) {
    Student_asr* temp_asr = head_asr;
    while (temp_asr) {
        cout << temp_asr->name_asr << " ";
        temp_asr = temp_asr->next_asr;
    }
    cout << endl;
}

// Function to find intersection
Student_asr* intersection_asr(Student_asr* headA_asr, Student_asr* headB_asr) {
    Student_asr* result_asr = nullptr;
    Student_asr* tail_asr = nullptr;
    for (Student_asr* a_asr = headA_asr; a_asr; a_asr = a_asr->next_asr) {
        for (Student_asr* b_asr = headB_asr; b_asr; b_asr = b_asr->next_asr) {
            if (a_asr->name_asr == b_asr->name_asr) {
                Student_asr* newNode_asr = new Student_asr{a_asr->name_asr, nullptr};
                if (!result_asr) result_asr = tail_asr = newNode_asr;
                else { tail_asr->next_asr = newNode_asr; tail_asr = newNode_asr; }
            }
        }
    }
    return result_asr;
}

// Function to find symmetric difference
Student_asr* symmetricDifference_asr(Student_asr* headA_asr, Student_asr* headB_asr) {
    Student_asr* result_asr = nullptr;
    Student_asr* tail_asr = nullptr;

    // Add elements in A not in B
    for (Student_asr* a_asr = headA_asr; a_asr; a_asr = a_asr->next_asr) {
        bool found_asr = false;
        for (Student_asr* b_asr = headB_asr; b_asr; b_asr = b_asr->next_asr) {
            if (a_asr->name_asr == b_asr->name_asr) {
                found_asr = true;
                break;
            }
        }
        if (!found_asr) {
            Student_asr* newNode_asr = new Student_asr{a_asr->name_asr, nullptr};
            if (!result_asr) result_asr = tail_asr = newNode_asr;
            else { tail_asr->next_asr = newNode_asr; tail_asr = newNode_asr; }
        }
    }

    // Add elements in B not in A
    for (Student_asr* b_asr = headB_asr; b_asr; b_asr = b_asr->next_asr) {
        bool found_asr = false;
        for (Student_asr* a_asr = headA_asr; a_asr; a_asr = a_asr->next_asr) {
            if (b_asr->name_asr == a_asr->name_asr) {
                found_asr = true;
                break;
            }
        }
        if (!found_asr) {
            Student_asr* newNode_asr = new Student_asr{b_asr->name_asr, nullptr};
            if (!result_asr) result_asr = tail_asr = newNode_asr;
            else { tail_asr->next_asr = newNode_asr; tail_asr = newNode_asr; }
        }
    }

    return result_asr;
}

// Function to count nodes in a linked list
int countList_asr(Student_asr* head_asr) {
    int count_asr = 0;
    for (Student_asr* temp_asr = head_asr; temp_asr; temp_asr = temp_asr->next_asr) count_asr++;
    return count_asr;
}

int main() {
    const char* names_asr[] = {"Abir","Aarav","Isha","Rohan","Priya","Vikas","Neha","Sahil",
                               "Anaya","Dev","Kriti","Mira","Kabir","Tanvi","Yash","Riya",
                               "Arjun","Asha","Nikhil","Pooja","Kunal","Vishal","Amir","Sharukh",
                               "Salman","Mrunal","Kirti"};
    const int N_NAMES_asr = sizeof(names_asr)/sizeof(names_asr[0]);
    srand(time(0));

    int nA_asr = rand() % N_NAMES_asr + 1; // Random size for set A
    int nB_asr = rand() % N_NAMES_asr + 1; // Random size for set B

    string namesA_asr[27], namesB_asr[27];
    for (int i_asr = 0; i_asr < nA_asr; i_asr++) namesA_asr[i_asr] = names_asr[rand() % N_NAMES_asr];
    for (int i_asr = 0; i_asr < nB_asr; i_asr++) namesB_asr[i_asr] = names_asr[rand() % N_NAMES_asr];

    Student_asr* setA_asr = createList_asr(namesA_asr, nA_asr);
    Student_asr* setB_asr = createList_asr(namesB_asr, nB_asr);

    cout << "Set A (Cricket): "; displayList_asr(setA_asr);
    cout << "Set B (Football): "; displayList_asr(setB_asr);

    Student_asr* intersect_asr = intersection_asr(setA_asr, setB_asr);
    cout << "\nStudents who like both Cricket and Football: "; displayList_asr(intersect_asr);

    Student_asr* symDiff_asr = symmetricDifference_asr(setA_asr, setB_asr);
    cout << "Students who like either Cricket or Football but not both: "; displayList_asr(symDiff_asr);

    int total_asr = N_NAMES_asr;
    int unionCount_asr = countList_asr(setA_asr) + countList_asr(setB_asr) - countList_asr(intersect_asr);
    cout << "Number of students who like neither Cricket nor Football: " << (total_asr - unionCount_asr) << endl;

    return 0;
}
```
# OUTPUT
```
Set A (Cricket): Abir Priya Vikas Neha Rohan 
Set B (Football): Vikas Neha Aarav Tanvi Kabir 

Students who like both Cricket and Football: Vikas Neha 
Students who like either Cricket or Football but not both: Abir Priya Rohan Aarav Tanvi Kabir 
Number of students who like neither Cricket nor Football: 19
```