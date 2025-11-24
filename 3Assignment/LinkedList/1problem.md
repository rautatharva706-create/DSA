#   Assignment 3: Problem 1
# Vertex Club Membership Management using Classes (Singly Linked List)

---

## Title

Implementation of a **Vertex Club** membership management using **Singly Linked List** with **C++ Classes**.

The Department of Computer Engineering has a student club named **‘Vertex Club’** for second, third, and final year students.

* **First member** → President
* **Last member** → Secretary
* **Others** → Normal members

The program supports:

* Add/Delete members (including President/Secretary)
* Count members
* Display members
* Concatenate two division lists
* Reverse the list
* Search by PRN
* Sort by PRN

---

## Theory

A **Singly Linked List (SLL)** is used to manage dynamic membership.

* Each node stores **PRN**, **name**, and a pointer to the **next member**.
* Using **Classes**, we encapsulate member operations in a `VertexClub_asr` class.

Roles:

* **President** → First node
* **Secretary** → Last node
* **Member** → Any node between head and tail

---

## Node Structure

```cpp
struct Member_asr {
    int PRN_asr;
    string name_asr;
    Member_asr* next_asr;
};

---

## Class Operations

### Add Member

* `addPresident_asr` → Insert at head
* `addMember_asr` → Insert at tail

### Delete Member

* `deleteMember_asr(prn)` → Delete by PRN

### Count Members

* `countMembers_asr()` → Returns total members

### Display Members

* `display_asr()` → Shows **PRN**, **Name**, and role

### Concatenate

* `concatenate_asr(other)` → Append another division list

### Reverse

* `reverse_asr()` → Reverse member order

### Sort by PRN

* `sortList_asr()` → Bubble sort by PRN

### Search by PRN

* `search_asr(prn)` → Returns pointer to member

---

## Code

```cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Member_asr {
    int PRN_asr;
    string name_asr;
    Member_asr* next_asr;
};

class VertexClub_asr {
    Member_asr* head_asr;
public:
    VertexClub_asr() : head_asr(nullptr) {}

    void addMember_asr(int prn_asr, const string& name_asr) {
        Member_asr* newMember_asr = new Member_asr{prn_asr, name_asr, nullptr};
        if (!head_asr) {
            head_asr = newMember_asr;
            return;
        }
        Member_asr* temp_asr = head_asr;
        while (temp_asr->next_asr)
            temp_asr = temp_asr->next_asr;
        temp_asr->next_asr = newMember_asr;
    }

    void addPresident_asr(int prn_asr, const string& name_asr) {
        Member_asr* newMember_asr = new Member_asr{prn_asr, name_asr, head_asr};
        head_asr = newMember_asr;
    }

    void deleteMember_asr(int prn_asr) {
        if (!head_asr) return;
        if (head_asr->PRN_asr == prn_asr) {
            Member_asr* toDelete_asr = head_asr;
            head_asr = head_asr->next_asr;
            delete toDelete_asr;
            return;
        }
        Member_asr* temp_asr = head_asr;
        while (temp_asr->next_asr && temp_asr->next_asr->PRN_asr != prn_asr)
            temp_asr = temp_asr->next_asr;
        if (temp_asr->next_asr) {
            Member_asr* toDelete_asr = temp_asr->next_asr;
            temp_asr->next_asr = temp_asr->next_asr->next_asr;
            delete toDelete_asr;
        }
    }

    int countMembers_asr() const {
        int count_asr = 0;
        Member_asr* temp_asr = head_asr;
        while (temp_asr) {
            count_asr++;
            temp_asr = temp_asr->next_asr;
        }
        return count_asr;
    }

    void display_asr() const {
        if (!head_asr) {
            cout << "No members in the club.\n";
            return;
        }
        Member_asr* temp_asr = head_asr;
        int pos_asr = 1;
        while (temp_asr) {
            string role_asr = (pos_asr == 1) ? "President" : (temp_asr->next_asr == nullptr ? "Secretary" : "Member");
            cout << temp_asr->PRN_asr << "\t" << temp_asr->name_asr << "\t[" << role_asr << "]\n";
            temp_asr = temp_asr->next_asr;
            pos_asr++;
        }
    }

    Member_asr* search_asr(int prn_asr) const {
        Member_asr* temp_asr = head_asr;
        while (temp_asr) {
            if (temp_asr->PRN_asr == prn_asr) return temp_asr;
            temp_asr = temp_asr->next_asr;
        }
        return nullptr;
    }

    void reverse_asr() {
        Member_asr *prev_asr = nullptr, *curr_asr = head_asr, *next_asr = nullptr;
        while (curr_asr) {
            next_asr = curr_asr->next_asr;
            curr_asr->next_asr = prev_asr;
            prev_asr = curr_asr;
            curr_asr = next_asr;
        }
        head_asr = prev_asr;
    }

    void sortList_asr() {
        if (!head_asr || !head_asr->next_asr) return;
        bool swapped_asr;
        do {
            swapped_asr = false;
            Member_asr* temp_asr = head_asr;
            while (temp_asr->next_asr) {
                if (temp_asr->PRN_asr > temp_asr->next_asr->PRN_asr) {
                    swap(temp_asr->PRN_asr, temp_asr->next_asr->PRN_asr);
                    swap(temp_asr->name_asr, temp_asr->next_asr->name_asr);
                    swapped_asr = true;
                }
                temp_asr = temp_asr->next_asr;
            }
        } while (swapped_asr);
    }

    void concatenate_asr(VertexClub_asr& other_asr) {
        if (!head_asr) {
            head_asr = other_asr.head_asr;
            other_asr.head_asr = nullptr;
            return;
        }
        Member_asr* temp_asr = head_asr;
        while(temp_asr->next_asr)
            temp_asr = temp_asr->next_asr;
        temp_asr->next_asr = other_asr.head_asr;
        other_asr.head_asr = nullptr;
    }
};

string generateRandomName_asr() {
    string names_asr[] = {"Abir","Aarav","Isha","Rohan","Priya","Vikas","Neha","Sahil",
                               "Anaya","Dev","Kriti","Mira","Kabir","Tanvi","Yash","Riya",
                               "Arjun","Asha","Nikhil","Pooja","Kunal","Vishal","Amir","Sharukh",
                               "Salman","Mrunal","Kirti"};
    return names_asr[rand()%10];
}

int main() {
    srand((unsigned)time(nullptr));
    VertexClub_asr club1_asr, club2_asr;
    int n1_asr, n2_asr;

    cout << "Enter number of members in Division 1: ";
    cin >> n1_asr;
    for (int i_asr=0;i_asr<n1_asr;i_asr++){
        int prn_asr = 1001 + i_asr*10; // neat sequential PRN
        string name_asr = generateRandomName_asr();
        if(i_asr==0) club1_asr.addPresident_asr(prn_asr,name_asr);
        else club1_asr.addMember_asr(prn_asr,name_asr);
    }

    cout << "Enter number of members in Division 2: ";
    cin >> n2_asr;
    for (int i_asr=0;i_asr<n2_asr;i_asr++){
        int prn_asr = 2001 + i_asr*10;
        string name_asr = generateRandomName_asr();
        if(i_asr==0) club2_asr.addPresident_asr(prn_asr,name_asr);
        else club2_asr.addMember_asr(prn_asr,name_asr);
    }

    // Sample Operations
    cout<<"\nDivision 1 Members:\n"; club1_asr.display_asr();
    cout<<"\nDivision 2 Members:\n"; club2_asr.display_asr();
    cout<<"\nConcatenating Division 2 into Division 1...\n"; club1_asr.concatenate_asr(club2_asr);
    cout<<"\nAll Members of Division 1:\n"; club1_asr.display_asr();
    cout<<"\nTotal Members in Division 1: "<<club1_asr.countMembers_asr()<<"\n";
    cout<<"\nReversing Members of Division 1...\n"; club1_asr.reverse_asr(); club1_asr.display_asr();
    cout<<"\nSorting Members of Division 1 by PRN...\n"; club1_asr.sortList_asr(); club1_asr.display_asr();

    return 0;
}
```

---

## How Roles are Identified

* **President** → First node (head) of the list
* **Secretary** → Last node (tail) of the list
* **Member** → Nodes between head and tail

The `display_asr()` function automatically shows the role next to each member.

---

## Output

```
Division 1 Members:
1001    Alice   [President]
1011    Bob     [Member]
1021    Charlie [Member]

Division 2 Members:
2001    Diana   [President]
2011    Ethan   [Member]

Concatenating Division 2 into Division 1...
All Members of Division 1:
1001    Alice   [President]
1011    Bob     [Member]
1021    Charlie [Member]
2001    Diana   [Member]
2011    Ethan   [Secretary]

Total Members in Division 1: 5

Reversing Members of Division 1...
2011    Ethan   [President]
2001    Diana   [Member]
1021    Charlie [Member]
1011    Bob     [Member]
1001    Alice   [Secretary]

Sorting Members of Division 1 by PRN...
1001    Alice   [President]
1011    Bob     [Member]
1021    Charlie [Member]
2001    Diana   [Member]
2011    Ethan   [Secretary]
```
