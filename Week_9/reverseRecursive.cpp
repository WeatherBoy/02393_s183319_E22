#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int> to_be_reversed) {
    if (to_be_reversed.empty()) {
        // If there is nothing in the vector, then
        // the recursive function has reached its base-layer
        return;

    } else {
        // Printing final element
        cout << to_be_reversed.back() << " ";

        // Popping last element (removing it)
        to_be_reversed.pop_back();

        // Calling the function again (making it recursive)
        reverse(to_be_reversed);

    }


}

int main() {
    // A temporary value for the input
    int temp_value{};
    // A value for the final length of our input
    int n = 0;

    // A vector because then we don't have to work
    // with dynamic memory.
    // Praise C++ (over C).
    vector<int> to_be_reversed{};

    // Getting the input and handling it
    while(true) {
        // Check whether the first input fails
        cin >> temp_value;
        if (cin.fail()) {
            break;
        }
        // If it doesn't fail, then append it to our vector
        to_be_reversed.push_back(temp_value);

    }

    reverse(to_be_reversed);

    return 0;
}