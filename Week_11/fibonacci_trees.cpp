#include <iostream>
#include <vector>
using namespace std;

// Global variables because then I don't have to make
// a tree structure.
// It is lazy I know... yes.
bool max_depth_reached = false;
int max_depth = 0;
int leaf_nodes = 0;
int calls = 0;
// A vector because then we don't have to work
// with dynamic memory.
// Praise C++ (over C).
vector<int> fibonacci_numbers{};

int fibonacci_tree(int n) {
    // simple recursive function for calculating the fibonacci sequence.
    //
    // Everytime we go into this function, then we have done an
    // extra call.
    calls++;

    if (!max_depth_reached) {
        // If we haven't reached max depth yet, well
        // then it is one deeper. 
        max_depth++;

    }
    
    if (n == 1 || n == 0) {
        // Because of the structure of this program, then first time
        // we reach either n == 1 or n == 0, we have reached
        // the maximum depth of our "call tree".
        max_depth_reached = true;

        // Everytime we reach either n == 1 or n == 0, we have
        // reached a leaf node in our "call tree".
        leaf_nodes++;

        return 1;

    } else if (n < 0) {
        // I think it was a mistake, this catch wasn't there on
        // my first implementation.
        return 0;

    }
    
    // This is such a hack solution.
    // But I don't care at this point, I got mad because my
    // solution for week 10 didn't work XD
    int temp_1{};
    int temp_2{};
    
    temp_1 = fibonacci_tree(n - 1);
    fibonacci_numbers.push_back(temp_1);
    temp_2 = fibonacci_tree(n - 2);
    fibonacci_numbers.push_back(temp_2);

    return temp_1 + temp_2;
}


int main() {
    // A temporary value for the input
    int temp_value{};
    // The size of the "call tree"
    int n = 0;

    cin >> temp_value;

    fibonacci_numbers.push_back(fibonacci_tree(temp_value));

    // Defining the length of our input (minus one, because zero-indexing).
    n = fibonacci_numbers.size() - 1;

    cout << "Call tree in pre-order: ";
    for (int i = n; i >= 0; i--) {
        // Printing the output in reverse
        cout << fibonacci_numbers[i] << " ";
        
    }
    cout << "\nCall tree size: " << calls;
    cout << "\nCall tree depth: " << max_depth;
    cout << "\nCall tree leafs: " << leaf_nodes;

    return 0;
}