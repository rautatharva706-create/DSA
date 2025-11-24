#include <iostream>
using namespace std;

// Structure for Hash Table
struct HashTable_asr {
    int size_asr;
    int *table_asr;
};

// Create a hash table
HashTable_asr* createTable_asr(int size_asr) {
    HashTable_asr* ht_asr = new HashTable_asr();
    ht_asr->size_asr = size_asr;
    ht_asr->table_asr = new int[size_asr];

    for (int i = 0; i < size_asr; i++) {
        ht_asr->table_asr[i] = -1; // -1 means empty
    }

    return ht_asr;
}

// Hash function
int hashFunction_asr(int key_asr, int size_asr) {
    return key_asr % size_asr;
}

// Insert using Linear Probing
void insertKey_asr(HashTable_asr* ht_asr, int key_asr) {
    int index_asr = hashFunction_asr(key_asr, ht_asr->size_asr);

    for (int i = 0; i < ht_asr->size_asr; i++) {
        int newIndex_asr = (index_asr + i) % ht_asr->size_asr;

        if (ht_asr->table_asr[newIndex_asr] == -1 || ht_asr->table_asr[newIndex_asr] == -2) {
            ht_asr->table_asr[newIndex_asr] = key_asr;
            cout << "Inserted " << key_asr << " at index " << newIndex_asr << endl;
            return;
        }
    }

    cout << "Hash Table Full! Cannot insert " << key_asr << endl;
}

// Search key
int searchKey_asr(HashTable_asr* ht_asr, int key_asr) {
    int index_asr = hashFunction_asr(key_asr, ht_asr->size_asr);

    for (int i = 0; i < ht_asr->size_asr; i++) {
        int newIndex_asr = (index_asr + i) % ht_asr->size_asr;

        if (ht_asr->table_asr[newIndex_asr] == key_asr)
            return newIndex_asr;

        if (ht_asr->table_asr[newIndex_asr] == -1)
            return -1;
    }

    return -1;
}

// Delete key
void deleteKey_asr(HashTable_asr* ht_asr, int key_asr) {
    int index_asr = searchKey_asr(ht_asr, key_asr);

    if (index_asr == -1) {
        cout << "Key " << key_asr << " not found!" << endl;
    } else {
        ht_asr->table_asr[index_asr] = -2; // -2 marks deleted
        cout << "Deleted " << key_asr << " from index " << index_asr << endl;
    }
}

// Display table
void displayTable_asr(HashTable_asr* ht_asr) {
    cout << "\nHash Table:\n";
    for (int i = 0; i < ht_asr->size_asr; i++) {
        cout << "Index " << i << ": " << ht_asr->table_asr[i] << endl;
    }
}

// Main function
int main() {
    HashTable_asr* ht_asr = createTable_asr(10);

    insertKey_asr(ht_asr, 23);
    insertKey_asr(ht_asr, 43);
    insertKey_asr(ht_asr, 13);
    insertKey_asr(ht_asr, 27);

    displayTable_asr(ht_asr);

    int search_asr = 43;
    int pos_asr = searchKey_asr(ht_asr, search_asr);
    if (pos_asr != -1)
        cout << "\nKey " << search_asr << " found at index " << pos_asr << endl;
    else
        cout << "\nKey " << search_asr << " not found!" << endl;

    deleteKey_asr(ht_asr, 13);
    displayTable_asr(ht_asr);

    return 0;
}