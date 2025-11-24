#include <iostream>
using namespace std;

// Node structure for linked list
struct Node_asr {
    int data_asr;
    Node_asr* next_asr;
};

// Hash table size
const int TABLE_SIZE_asr = 10;

// Hash table array of pointers
Node_asr* hashTable_asr[TABLE_SIZE_asr];

// Hash function
int hashFunction_asr(int key_asr) {
    return key_asr % TABLE_SIZE_asr;
}

// Insert key into hash table
void insertKey_asr(int key_asr) {
    int index_asr = hashFunction_asr(key_asr);

    Node_asr* newNode_asr = new Node_asr();
    newNode_asr->data_asr = key_asr;
    newNode_asr->next_asr = nullptr;

    if (hashTable_asr[index_asr] == nullptr) {
        hashTable_asr[index_asr] = newNode_asr;
    } else {
        Node_asr* temp_asr = hashTable_asr[index_asr];
        while (temp_asr->next_asr != nullptr) {
            temp_asr = temp_asr->next_asr;
        }
        temp_asr->next_asr = newNode_asr;
    }
}

// Search key in hash table
bool searchKey_asr(int key_asr) {
    int index_asr = hashFunction_asr(key_asr);
    Node_asr* temp_asr = hashTable_asr[index_asr];

    while (temp_asr != nullptr) {
        if (temp_asr->data_asr == key_asr)
            return true;
        temp_asr = temp_asr->next_asr;
    }
    return false;
}

// Display hash table
void displayTable_asr() {
    for (int i = 0; i < TABLE_SIZE_asr; i++) {
        cout << "Index " << i << ": ";
        Node_asr* temp_asr = hashTable_asr[i];
        while (temp_asr != nullptr) {
            cout << temp_asr->data_asr << " -> ";
            temp_asr = temp_asr->next_asr;
        }
        cout << "NULL\n";
    }
}

// Main function
int main() {
    // Initialize hash table
    for (int i = 0; i < TABLE_SIZE_asr; i++) {
        hashTable_asr[i] = nullptr;
    }

    insertKey_asr(15);
    insertKey_asr(25);
    insertKey_asr(35);
    insertKey_asr(5);
    insertKey_asr(7);

    cout << "Hash Table:\n";
    displayTable_asr();

    cout << "\nSearching for 25: " 
         << (searchKey_asr(25) ? "Found" : "Not Found") << endl;

    cout << "Searching for 40: " 
         << (searchKey_asr(40) ? "Found" : "Not Found") << endl;

    return 0;
}