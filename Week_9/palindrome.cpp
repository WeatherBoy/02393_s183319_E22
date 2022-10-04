#include <iostream>
#include <vector>
using namespace std;

int main() {
    // A temporary value for the input
    int temp_value{};
    // A value for the final length of our input
    int n = 0;
    // A value for half the length of our input
    int n_half = 0;
    // Boolean value to deem whether the input was
    // in fact a palindrome
    bool palindrome = true;

    // A vector because then we don't have to work
    // with dynamic memory.
    // Praise C++ (over C).
    vector<int> palindrome_list{};


    // Getting the input and handling it
    while(true) {
        // Check whether the first input fails
        cin >> temp_value;
        if (cin.fail()) {
            break;
        }
        // If it doesn't fail, then append it to our vector
        palindrome_list.push_back(temp_value);

    }

    // We need to subtract one from our size, because zero indexing.
    n = palindrome_list.size() - 1;
    // We only have to check half of our list (rounded down + 1,
    // in case it is of uneven length), because otherwise we would
    // be doing double the amount of work.
    n_half = (palindrome_list.size()/ 2) + 1;

    // When we don't receive anymore input, then we print what we got
    for (unsigned int i = 0; i < n; i++) {
        if (palindrome_list[i] != palindrome_list[n - i]) {
            // breaking out of our for-loop, beacuse we only need 
            // one to be wrong, for it to not be a palindrome
            palindrome = false;
            break;

        }
        
    }

    // Nice use of ternary
    cout << (palindrome ? "yes" : "no") << endl;

    return 0;
}