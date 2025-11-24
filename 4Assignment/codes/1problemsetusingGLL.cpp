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