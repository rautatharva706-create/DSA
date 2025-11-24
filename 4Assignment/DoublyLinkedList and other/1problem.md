# Assignment No: 4 Problem:1

## Title: Implementation of Set using Generalized Linked List (GLL)

### Theory

A **Generalized Linked List (GLL)** is a data structure designed to represent hierarchical or nested information such as sets within sets. Unlike a regular linked list that stores only simple (atomic) data, a GLL node can store:

- An **atomic element**, or  
- A **pointer to another sublist**

This makes GLLs useful for representing recursive or multi-level structures like:
- Mathematical sets containing other sets
- Directory or folder hierarchies
- Expressions with nested components

In this assignment, a GLL is used to represent a **set** where each element may be:
1. A simple data value (atom), or  
2. Another set (nested element)

---

### Node Structure

Each node of the GLL contains:
* **data_asr** → stores a character if it is an atomic element (NULL for a sublist)
* **next_asr** → pointer to the next element within the same set level
* **down_asr** → pointer to a sublist if current element represents a set

---

### Display Operation

The display function:
- Uses recursion to traverse nested levels
- Prints atomic values directly
- Prints nested sets inside **curly braces `{}`**
- Ensures correct formatting to represent hierarchical set structure

---

### Significance

This structure demonstrates:
- Recursive data representation  
- Efficient handling of nested sets  
- Concept of multi-level pointer-based traversal  

### Algorithm

**Step 1:** Start the program and define the GLL node structure containing `data_asr`, `next_asr`, and `down_asr` pointers.
**Step 2:** Create a recursive function `createNode_asr()` to build the GLL structure.
**Step 3:** In the function, for each element:

* If it is an atomic element, store it in the node’s `data_asr` field.
* If it is a sublist (denoted by `{`), create a recursive call to form the sublist and assign it to `down_asr`.
  **Step 4:** Repeat until all elements are added.
  **Step 5:** Define a recursive display function `displaySet_asr()` that traverses the GLL and prints elements in proper set notation.
  **Step 6:** In `main()`, construct a sample GLL representing `S = {p, q, {r, s, t, {}, {u, v}, w, x, {y, z}, a1, b1}}` and call the display function.
  **Step 7:** Stop the program.

### C++ Code

```cpp
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Node_asr {
    char data_asr[10];
    Node_asr *next_asr;
    Node_asr *down_asr;
};

Node_asr* createNode_asr(const char* data_asr) {
    Node_asr* newNode_asr = new Node_asr;
    strcpy(newNode_asr->data_asr, data_asr);
    newNode_asr->next_asr = NULL;
    newNode_asr->down_asr = NULL;
    return newNode_asr;
}

Node_asr* insert_asr(Node_asr* head_asr, const char* data_asr) {
    Node_asr* newNode_asr = createNode_asr(data_asr);
    if (!head_asr) return newNode_asr;
    Node_asr* temp_asr = head_asr;
    while (temp_asr->next_asr)
        temp_asr = temp_asr->next_asr;
    temp_asr->next_asr = newNode_asr;
    return head_asr;
}

void displaySet_asr(Node_asr* head_asr) {
    cout << "{";
    Node_asr* temp_asr = head_asr;
    while (temp_asr) {
        if (temp_asr->down_asr) {
            displaySet_asr(temp_asr->down_asr);
        } else {
            cout << temp_asr->data_asr;
        }
        if (temp_asr->next_asr) cout << ", ";
        temp_asr = temp_asr->next_asr;
    }
    cout << "}";
}

int main() {


    Node_asr *S_asr = NULL, *sub1_asr = NULL, *sub2_asr = NULL, *sub3_asr = NULL;

    // Inner sets
    sub2_asr = insert_asr(sub2_asr, "u");
    sub2_asr = insert_asr(sub2_asr, "v");

    sub3_asr = insert_asr(sub3_asr, "y");
    sub3_asr = insert_asr(sub3_asr, "z");

    // Main sublist
    sub1_asr = insert_asr(sub1_asr, "r");
    sub1_asr = insert_asr(sub1_asr, "s");
    sub1_asr = insert_asr(sub1_asr, "t");
    sub1_asr = insert_asr(sub1_asr, "{}");

    Node_asr* node_uv_asr = createNode_asr("");
    node_uv_asr->down_asr = sub2_asr;
    sub1_asr = insert_asr(sub1_asr, "");
    Node_asr* temp_asr = sub1_asr;
    while (temp_asr->next_asr) temp_asr = temp_asr->next_asr;
    temp_asr->down_asr = sub2_asr;

    sub1_asr = insert_asr(sub1_asr, "w");
    sub1_asr = insert_asr(sub1_asr, "x");

    Node_asr* node_yz_asr = createNode_asr("");
    node_yz_asr->down_asr = sub3_asr;
    temp_asr = sub1_asr;
    while (temp_asr->next_asr) temp_asr = temp_asr->next_asr;
    temp_asr->next_asr = node_yz_asr;

    sub1_asr = insert_asr(sub1_asr, "a1");
    sub1_asr = insert_asr(sub1_asr, "b1");

    // Main set
    S_asr = insert_asr(S_asr, "p");
    S_asr = insert_asr(S_asr, "q");

    Node_asr* node_main_asr = createNode_asr("");
    node_main_asr->down_asr = sub1_asr;
    S_asr = insert_asr(S_asr, "");
    Node_asr* tmp_asr = S_asr;
    while (tmp_asr->next_asr) tmp_asr = tmp_asr->next_asr;
    tmp_asr->down_asr = sub1_asr;

    cout << "Set Representation using Generalized Linked List:\n";
    displaySet_asr(S_asr);
    cout << endl;

    return 0;
}
```

### Output

```
Set Representation using Generalized Linked List:
{p, q, {r, s, t, {}, {u, v}, w, x, {y, z}, a1, b1}}
```
