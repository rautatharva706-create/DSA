# Assignment No: 12 Problem:5

## Title: Design and Implementation of a Smart College Placement Portal Using Advanced Hashing Techniques


## Theory

A smart college placement portal requires efficient storage and retrieval of student placement records, especially under dynamic data growth. Traditional linear hashing or naive storage causes collisions, poor performance, and slow lookups as the dataset grows.

To overcome these issues, double hashing is used. It provides:

- Low collision probability
- Uniform key distribution
- Fast search, insert, and display operations
- High scalability with automatic rehashing
- O(1) average time complexity

Key Concepts:

1. Hash Function 1: index = key % size  
2. Hash Function 2: offset = prime - (key % prime)  
3. Double Hashing Probe: (index1 + i * index2) % size  
4. Load Factor Trigger = 0.7  
5. Rehashing doubles the table size and reinserts all records  

---

## Algorithm

### Algorithm: Smart Placement Portal Using Double Hashing

1. Start  
2. Initialize hash table with a default size.  
3. Mark all records as empty.  
4. For Insert:  
   - Compute load factor.  
   - If load factor > 0.7 → Rehash.  
   - Compute index using hash function 1.  
   - Compute offset using hash function 2.  
   - Probe using double hashing until empty slot found.  
   - Insert the new record.  
5. For Search:  
   - Compute index using hash function 1.  
   - Compute offset using hash function 2.  
   - Probe until record found or empty slot reached.  
6. For Display:  
   - Traverse entire table and print occupied entries.  
7. Repeat menu until user selects Exit.  
8. Stop.  

---

## C++ Code

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Structure for placement record
struct PlacementRecord_asr {
    int studentID_asr;
    string studentName_asr;
    string companyName_asr;
    string status_asr;
    bool occupied_asr;

    PlacementRecord_asr() {
        occupied_asr = false;
    }
};

// Structure for hash table
struct PlacementHashTable_asr {
    vector<PlacementRecord_asr> table_asr;
    int size_asr;
    int count_asr;

    PlacementHashTable_asr(int initialSize_asr = 10) {
        size_asr = initialSize_asr;
        count_asr = 0;
        table_asr.resize(size_asr);
    }
};

// Hash function 1
int hashFunction1_asr(int key_asr, int size_asr) {
    return key_asr % size_asr;
}

// Hash function 2
int hashFunction2_asr(int key_asr) {
    return 7 - (key_asr % 7);
}

// Load factor
float loadFactor_asr(PlacementHashTable_asr &portal_asr) {
    return (float)portal_asr.count_asr / portal_asr.size_asr;
}

// Forward declaration
void rehash_asr(PlacementHashTable_asr &portal_asr);

// Insert record function
void insertRecord_asr(PlacementHashTable_asr &portal_asr,
                      int id_asr, string name_asr,
                      string company_asr, string status_asr) {

    if (loadFactor_asr(portal_asr) > 0.7)
        rehash_asr(portal_asr);

    int index1_asr = hashFunction1_asr(id_asr, portal_asr.size_asr);
    int index2_asr = hashFunction2_asr(id_asr);

    int i = 0;
    while (portal_asr.table_asr[(index1_asr + i * index2_asr) % portal_asr.size_asr].occupied_asr) {
        i++;
        if (i >= portal_asr.size_asr) {
            cout << "Hash table is full! Cannot insert.\n";
            return;
        }
    }

    int finalIndex_asr = (index1_asr + i * index2_asr) % portal_asr.size_asr;
    portal_asr.table_asr[finalIndex_asr].studentID_asr = id_asr;
    portal_asr.table_asr[finalIndex_asr].studentName_asr = name_asr;
    portal_asr.table_asr[finalIndex_asr].companyName_asr = company_asr;
    portal_asr.table_asr[finalIndex_asr].status_asr = status_asr;
    portal_asr.table_asr[finalIndex_asr].occupied_asr = true;
    portal_asr.count_asr++;

    cout << "Record inserted at index " << finalIndex_asr << "!\n";
}

// Rehash function
void rehash_asr(PlacementHashTable_asr &portal_asr) {
    cout << "\nRehashing triggered! Expanding table...\n";

    vector<PlacementRecord_asr> oldTable_asr = portal_asr.table_asr;
    portal_asr.size_asr *= 2;
    portal_asr.count_asr = 0;
    portal_asr.table_asr.clear();
    portal_asr.table_asr.resize(portal_asr.size_asr);

    for (auto &rec : oldTable_asr) {
        if (rec.occupied_asr) {
            insertRecord_asr(portal_asr, rec.studentID_asr,
                             rec.studentName_asr,
                             rec.companyName_asr,
                             rec.status_asr);
        }
    }

    cout << "Rehashing complete. New size: " << portal_asr.size_asr << endl;
}

// Search record
void searchRecord_asr(PlacementHashTable_asr &portal_asr, int id_asr) {
    int index1_asr = hashFunction1_asr(id_asr, portal_asr.size_asr);
    int index2_asr = hashFunction2_asr(id_asr);

    int i = 0;
    while (portal_asr.table_asr[(index1_asr + i * index2_asr) % portal_asr.size_asr].occupied_asr) {
        int index_asr = (index1_asr + i * index2_asr) % portal_asr.size_asr;

        if (portal_asr.table_asr[index_asr].studentID_asr == id_asr) {
            cout << "\nRecord Found:\n";
            cout << "Student ID: " << portal_asr.table_asr[index_asr].studentID_asr << endl;
            cout << "Name: " << portal_asr.table_asr[index_asr].studentName_asr << endl;
            cout << "Company: " << portal_asr.table_asr[index_asr].companyName_asr << endl;
            cout << "Status: " << portal_asr.table_asr[index_asr].status_asr << endl;
            return;
        }
        i++;
        if (i >= portal_asr.size_asr)
            break;
    }

    cout << "Record not found!\n";
}

// Display table
void displayTable_asr(PlacementHashTable_asr &portal_asr) {
    cout << "\nPlacement Hash Table:\n";
    for (int i = 0; i < portal_asr.size_asr; i++) {
        cout << "[" << i << "] ";
        if (portal_asr.table_asr[i].occupied_asr)
            cout << portal_asr.table_asr[i].studentID_asr << " | "
                 << portal_asr.table_asr[i].studentName_asr << " | "
                 << portal_asr.table_asr[i].companyName_asr << " | "
                 << portal_asr.table_asr[i].status_asr << endl;
        else
            cout << "Empty\n";
    }
}

int main() {
    PlacementHashTable_asr portal_asr;
    int choice_asr, id_asr;
    string name_asr, company_asr, status_asr;

    while (true) {
        cout << "\n--- Smart College Placement Portal ---\n";
        cout << "1. Insert Placement Record\n";
        cout << "2. Search Placement Record\n";
        cout << "3. Display All Records\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_asr;

        switch (choice_asr) {
        case 1:
            cout << "Enter Student ID, Name, Company, Status: ";
            cin >> id_asr >> name_asr >> company_asr >> status_asr;
            insertRecord_asr(portal_asr, id_asr, name_asr, company_asr, status_asr);
            break;

        case 2:
            cout << "Enter Student ID to search: ";
            cin >> id_asr;
            searchRecord_asr(portal_asr, id_asr);
            break;

        case 3:
            displayTable_asr(portal_asr);
            break;

        case 4:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
```

### Output

```
--- Smart College Placement Portal ---
1. Insert Placement Record
2. Search Placement Record
3. Display All Records
4. Exit
Enter your choice: 1
Enter Student ID, Name, Company, Status: 101
Prithviraj
Microsoft
Placed
Record inserted at index 1!

--- Smart College Placement Portal ---
1. Insert Placement Record
2. Search Placement Record
3. Display All Records
4. Exit
Enter your choice: 1
Enter Student ID, Name, Company, Status: 156
Shreeniket
Google
Placed
Record inserted at index 6!

--- Smart College Placement Portal ---
1. Insert Placement Record
2. Search Placement Record
3. Display All Records
4. Exit
Enter your choice: 3

Placement Hash Table:
[0] Empty
[1] 101 | Prithviraj | Microsoft | Placed
[2] Empty
[3] Empty
[4] Empty
[5] Empty
[6] 156 | Shreeniket | Google | Placed
[7] Empty
[8] Empty
[9] Empty

--- Smart College Placement Portal ---
1. Insert Placement Record
2. Search Placement Record
3. Display All Records
4. Exit
Enter your choice:
```
![alt text](5image.png)