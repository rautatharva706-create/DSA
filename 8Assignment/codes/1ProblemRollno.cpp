#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Structure for student node
struct Student_asr {
    string name_asr;
    int marks_asr;
    Student_asr *left_asr, *right_asr;
};

// Create a new student node
Student_asr* createStudent_asr(string name_asr, int marks_asr) {
    Student_asr* node_asr = new Student_asr();
    node_asr->name_asr = name_asr;
    node_asr->marks_asr = marks_asr;
    node_asr->left_asr = node_asr->right_asr = nullptr;
    return node_asr;
}

// Insert student into BST based on marks
Student_asr* insertStudent_asr(Student_asr* root_asr, string name_asr, int marks_asr) {
    if (root_asr == nullptr)
        return createStudent_asr(name_asr, marks_asr);

    if (marks_asr < root_asr->marks_asr)
        root_asr->left_asr = insertStudent_asr(root_asr->left_asr, name_asr, marks_asr);
    else
        root_asr->right_asr = insertStudent_asr(root_asr->right_asr, name_asr, marks_asr);

    return root_asr;
}

// Assign roll numbers using reverse inorder traversal (highest marks first)
void assignRollNumbers_asr(Student_asr* root_asr, int &roll_asr) {
    if (root_asr == nullptr)
        return;

    assignRollNumbers_asr(root_asr->right_asr, roll_asr);

    cout << "Roll No. " << roll_asr << " -> "
         << root_asr->name_asr << " (Marks: "
         << root_asr->marks_asr << ")\n";

    roll_asr++;

    assignRollNumbers_asr(root_asr->left_asr, roll_asr);
}

int main() {
    srand(time(0));
    int n_asr;

    cout << "Enter total number of students: ";
    cin >> n_asr;

    if (n_asr <= 0) {
        cout << "Invalid number of students.\n";
        return 0;
    }

    string sampleNames_asr[] = {
        "Rahul", "Priya", "Aniket", "Neha", "Suresh", "Aarav", "Riya",
        "Tanish", "Sneha", "Aditya", "Kiran", "Manoj", "Pooja", "Vikas",
        "Shreya", "Omkar", "Nisha", "Akash", "Meena", "Rohan"
    };

    int totalNames_asr = 20;
    Student_asr* root_asr = nullptr;

    // Generate random students and marks
    for (int i = 0; i < n_asr; i++) {
        string name_asr = sampleNames_asr[i % totalNames_asr] + "_" + to_string(i + 1);
        int marks_asr = rand() % 51 + 50; // Random marks between 50–100
        root_asr = insertStudent_asr(root_asr, name_asr, marks_asr);
    }

    cout << "\n--- Roll Number Assignment (Topper = Roll No. 1) ---\n";
    
    int roll_asr = 1;
    assignRollNumbers_asr(root_asr, roll_asr);

    return 0;
}
