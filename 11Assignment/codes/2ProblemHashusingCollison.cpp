#include <iostream>
using namespace std;

// Node structure for separate chaining
struct Node_asr {
    int data_asr;
    Node_asr* next_asr;
};

// Hash table size
const int TABLE_SIZE_asr = 10;

// Hash table array
Node_asr* hashTable_asr[TABLE_SIZE_asr];

// Hash function
int hashFunction_asr(int key_asr) {
    return key_asr % TABLE_SIZE_asr;
}

// Insert key
void insertKey_asr(int key_asr) {
    int index_asr = hashFunction_asr(key_asr);

    Node_asr* newNode_asr = new Node_asr();
    newNode_asr->data_asr = key_asr;
    newNode_asr->next_asr = hashTable_asr[index_asr];

    hashTable_asr[index_asr] = newNode_asr;

    cout << "Inserted " << key_asr << " at index " << index_asr << endl;
}

// Search key
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

// Delete key
void deleteKey_asr(int key_asr) {
    int index_asr = hashFunction_asr(key_asr);
    Node_asr* temp_asr = hashTable_asr[index_asr];
    Node_asr* prev_asr = nullptr;

    while (temp_asr != nullptr) {
        if (temp_asr->data_asr == key_asr) {
            if (prev_asr == nullptr)
                hashTable_asr[index_asr] = temp_asr->next_asr;
            else
                prev_asr->next_asr = temp_asr->next_asr;

            delete temp_asr;
            cout << "Deleted " << key_asr << " from index " << index_asr << endl;
            return;
        }
        prev_asr = temp_asr;
        temp_asr = temp_asr->next_asr;
    }

    cout << "Key " << key_asr << " not found!" << endl;
}

// Display hash table
void displayTable_asr() {
    for (int i_asr = 0; i_asr < TABLE_SIZE_asr; i_asr++) {
        cout << i_asr << ": ";
        Node_asr* temp_asr = hashTable_asr[i_asr];
        while (temp_asr != nullptr) {
            cout << temp_asr->data_asr << " -> ";
            temp_asr = temp_asr->next_asr;
        }
        cout << "NULL" << endl;
    }
}

int main() {
    for (int i = 0; i < TABLE_SIZE_asr; i++)
        hashTable_asr[i] = nullptr;

    insertKey_asr(15);
    insertKey_asr(25);
    insertKey_asr(35);
    insertKey_asr(5);

    displayTable_asr();

    cout << "Searching 25: " << (searchKey_asr(25) ? "Found" : "Not Found") << endl;

    deleteKey_asr(25);
    displayTable_asr();

    return 0;
}