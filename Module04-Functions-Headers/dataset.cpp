#include <iostream>
#include <string>

using namespace std;

int main() {

    // 5 records from the Football Players Stats 2026-2027 dataset
    string players[5] = {
        "Brenden Aaronson",
        "Haitam Abaida",
        "James Abankwah",
        "Keyliane Abdallah",
        "Hamza Abdelkarim"
    };

    string teams[5] = {
        "Leeds United",
        "Malaga",
        "Udinese",
        "Marseille",
        "Barcelona"
    };

    string positions[5] = {
        "MF",
        "FW",
        "DF",
        "FW",
        "FW"
    };

    int goals[5] = {
        0,
        0,
        1,
        1,
        0
    };

    // Pointer to the first player's goals
    int *goalPtr = &goals[0];

    // Display the records
    cout << "Football Players Stats 2026-2027" << endl;
    cout << "---------------------------------" << endl;

    for (int i = 0; i < 5; i++) {
        cout << "Player: " << players[i] << endl;
        cout << "Team: " << teams[i] << endl;
        cout << "Position: " << positions[i] << endl;
        cout << "Goals: " << goals[i] << endl;
        cout << endl;
    }

    // Access one value through a pointer
    cout << "First player's goals through pointer: "
         << *goalPtr << endl;

    return 0;
}
