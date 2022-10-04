#include <iostream>
#include <vector>
using namespace std;

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

    // Defining the length of our input (minus one, because zero-indexing).
    n = to_be_reversed.size() - 1;
    // When we don't receive anymore input, then we print what we got
    for (int i = n; i >= 0; i--) {
        // IMPORTANT!!
        // Your iterator variable shouldn't be an unsigned int, because when
        // it gets to zero and you try to subtract one, then it will not go
        // to negative one, instead it will go to largest possible integer...
        // which is stiller greater than zero.
        //
        // Printing the output in reverse
        cout << to_be_reversed[i] << " ";
        
    }

    return 0;
}