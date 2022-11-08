#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n) {
    // simple recursive function for calculating the fibonacci sequence
    if (n == 1 || n == 0) {
        return 1;

    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    // A temporary value for the input
    int temp_value{};

    // A vector because then we don't have to work
    // with dynamic memory.
    // Praise C++ (over C).
    vector<int> fibonacci_numbers{};

    // Getting the input and handling it (good old)
    while(true) {
        // Check whether the first input fails
        cin >> temp_value;
        if (cin.fail() || temp_value == -69) {
            break;
        }
        // If it doesn't fail, then append it to our vector
        fibonacci_numbers.push_back(temp_value);

    }

    // When we don't receive anymore input, then we print what we got
    for (int i = 0; i < fibonacci_numbers.size(); i++) {
        // Printing the fibonacci of the given numbers
        cout << fibonacci(fibonacci_numbers[i]) << " ";
        
    }

    return 0;
}

// (0 ? c == c' : 1);