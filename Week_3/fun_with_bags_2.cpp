#include <iostream>
using namespace std;

int main() {
    // Initialize variables
    string command;
    int bag_index;
    
    // Initialize array to false
    int bag[1001] = { 0 };

    cin >> command;
    while (command != "quit") {
        if (command == "add") {
            cin >> bag_index;
            bag[bag_index]++;

        } else if (command == "del") {
            cin >> bag_index;
            bag[bag_index]--;

        } else if (command == "qry") {
            cin >> bag_index;

            if (0 < bag[bag_index]) {
                cout << "T";

            } else {
                cout << "F";

            }
        } 
        cin >> command;

    }
    
    return 0;
}