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
