# Assignment No.2: Problem 1  

---

## Title  
 In Computer Engg. Dept. of VIT there are S.Y., T.Y., and B.Tech. students. Assume that all these students are on ground for a function. We need to identify a student of S.Y. div. (X) whose name is "XYZ" and roll no. is "17". Apply appropriate Searching method to identify the required student.
---

## Theory  

Searching refers to locating a specific element within a given dataset.  

- **Linear Search**: Examines each element one-by-one until the required value is found or the entire list has been checked. It can be applied to data in any order.
- **Binary Search**: A faster searching approach that works only on sorted collections by repeatedly dividing the list into halves and narrowing down the search range.

As the student records are not sorted, **linear search** is the appropriate method to use in this case.

---

## Algorithm (Linear Search)  

1. Start.  
2. Read the number of students `n`.  
3. Input each student’s details: **Name, Division, Roll No., Year**.  
4. Store them in an array of structures.  
5. Input the search criteria (Name = "XYZ", Div = "X", Roll No = 17).  
6. Traverse the array from index `0` to `n-1`:  
   - If all fields match, return the index (student found).  
7. If traversal completes without finding, report "Not Found".  
8. Display result.  
9. Stop.  

---

## Code  

```cpp
#include <iostream>
#include <string>
#include <cstdlib>  // rand, srand
#include <ctime>    // time
using namespace std;

struct Student_asr {
    string name_asr;
    string div_asr;
    int rollNo_asr;
    string year_asr;  // SY, TY, B.Tech
};

int main() {
    srand(time(0)); // seed for rand

    int n_asr, choice_asr;
    cout << "Enter the Number of Student Records you want to create: ";
    cin >> n_asr;

    Student_asr* students_asr = new Student_asr[n_asr];

    // Sample arrays for random generation
    const string names_asr[] = { "Abir","Aarav","Isha","Rohan","Priya","Vikas","Neha","Sahil","Anaya","Dev","Kriti",
        "Mira","Kabir","Tanvi","Yash","Riya","Arjun","Asha","Nikhil","Pooja","Kunal", "Vishal","Amir","Sharukh","Salman","Mrunal","Kirti" };
    const int N_NAMES = sizeof(names_asr) / sizeof(names_asr[0]);

    const string divs_asr[] = { "A","B","C","D" };
    const int N_DIVS = sizeof(divs_asr) / sizeof(divs_asr[0]);

    const string years_asr[] = { "SY","TY","B.Tech" };
    const int N_YEARS = sizeof(years_asr) / sizeof(years_asr[0]);

    // Fill records randomly
    for(int i_asr = 0; i_asr < n_asr; i_asr++) {
        students_asr[i_asr].rollNo_asr = i_asr + 1;
        students_asr[i_asr].name_asr = names_asr[rand() % N_NAMES];
        students_asr[i_asr].div_asr = divs_asr[rand() % N_DIVS];
        students_asr[i_asr].year_asr = years_asr[rand() % N_YEARS];
    }

    // Print all records
    cout << "\n====== All Student Records ======\n";
    cout << "Roll\tName\tDivision\tYear\n";
    for(int i_asr = 0; i_asr < n_asr; i_asr++) {
        cout << students_asr[i_asr].rollNo_asr << "\t"
             << students_asr[i_asr].name_asr << "\t"
             << students_asr[i_asr].div_asr << "\t\t"
             << students_asr[i_asr].year_asr << "\n";
    }

    // Menu loop
    do {
        cout << "\n--- MENU ---\n";
        cout << "1) Search by Roll\n";
        cout << "2) Search by Name\n";
        cout << "3) Print All Records\n";
        cout << "0) Exit\n";
        cout << "Enter choice: ";
        cin >> choice_asr;

        switch(choice_asr) {
            case 1: {
                int rollSearch_asr;
                cout << "Enter Roll No to search: ";
                cin >> rollSearch_asr;
                bool found_asr = false;
                for(int i_asr = 0; i_asr < n_asr; i_asr++) {
                    if(students_asr[i_asr].rollNo_asr == rollSearch_asr) {
                        cout << "Record Found:\n";
                        cout << "Roll: " << students_asr[i_asr].rollNo_asr
                             << " | Name: " << students_asr[i_asr].name_asr
                             << " | Division: " << students_asr[i_asr].div_asr
                             << " | Year: " << students_asr[i_asr].year_asr << "\n";
                        found_asr = true;
                        break;
                    }
                }
                if(!found_asr) cout << "Record NOT FOUND.\n";
                break;
            }
            case 2: {
                string nameSearch_asr;
                cout << "Enter EXACT Name to search (case-sensitive): ";
                cin >> nameSearch_asr;
                bool found_asr = false;
                cout << "Matching Records:\n";
                for(int i_asr = 0; i_asr < n_asr; i_asr++) {
                    if(students_asr[i_asr].name_asr == nameSearch_asr) {
                        cout << "Roll: " << students_asr[i_asr].rollNo_asr
                             << " | Name: " << students_asr[i_asr].name_asr
                             << " | Division: " << students_asr[i_asr].div_asr
                             << " | Year: " << students_asr[i_asr].year_asr << "\n";
                        found_asr = true;
                    }
                }
                if(!found_asr) cout << "Record NOT FOUND.\n";
                break;
            }
            case 3: {
                cout << "\n====== All Student Records ======\n";
                cout << "Roll\tName\tDivision\tYear\n";
                for(int i_asr = 0; i_asr < n_asr; i_asr++) {
                    cout << students_asr[i_asr].rollNo_asr << "\t"
                         << students_asr[i_asr].name_asr << "\t"
                         << students_asr[i_asr].div_asr << "\t\t"
                         << students_asr[i_asr].year_asr << "\n";
                }
                break;
            }
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid Choice.\n";
        }
    } while(choice_asr != 0);

    delete[] students_asr;
    return 0;
}
```
## OUTPUT
Enter the Number of Student Records you want to create: 5

\====== All Student Records ======

Roll Name Division Year

1 Riya B SY

2 Tanvi C TY

3 Dev D SY

4 Kriti A B.Tech

5 Arjun B TY

\--- MENU ---

1) Search by Roll

2) Search by Name

3) Print All Records

0) Exit

Enter choice: 1

Enter Roll No to search: 3

Record Found:

Roll: 3 | Name: Dev | Division: D | Year: SY

\--- MENU ---

1) Search by Roll

2) Search by Name

3) Print All Records

0) Exit

Enter choice: 2

Enter EXACT Name to search (case-sensitive): Kriti

Matching Records:

Roll: 4 | Name: Kriti | Division: A | Year: B.Tech

\--- MENU ---

1) Search by Roll

2) Search by Name

3) Print All Records

0) Exit

Enter choice: 2

Enter EXACT Name to search (case-sensitive): Raj

Record NOT FOUND.

\--- MENU ---

1) Search by Roll

2) Search by Name

3) Print All Records

0) Exit

Enter choice: 3

\====== All Student Records ======

Roll Name Division Year

1 Riya B SY

2 Tanvi C TY

3 Dev D SY

4 Kriti A B.Tech

5 Arjun B TY

\--- MENU ---

1) Search by Roll

2) Search by Name

3) Print All Records

0) Exit

Enter choice: 0

Exiting...
