#include <iostream>
using namespace std;

int main() {
    int number_of_inputs;
    int int_input;
    int tmp_input;
    bool sorted_so_far = true;

    cin >> number_of_inputs;
    if (number_of_inputs < 0) {
        // if there are less than zero numbers,
        // then we don't know what to do
        cout << "UNSORTED" << endl;

    } else if (number_of_inputs == 0) {
        // if there is zero input, then it must be sorted
        cout << "SORTED" << endl;

    } else {
        // then we read the first input
        cin >> int_input;

        for (int i = 0; i < number_of_inputs - 1; i++) {
            // notice in this for-loop that that if "number_of_inputs"
            // are 1, then this for loop will never begin, because
            // we subtract one since we already checked one of
            // the inputs
            cin >> tmp_input;

            if (tmp_input < int_input) {
                sorted_so_far = false;
                cout << "UNSORTED" << endl;
                break;

            }
            // overwrite int_input so is the right relation we are
            // testing next
            int_input = tmp_input;
        }
        if (sorted_so_far) {
            // If we have been sorted until the very last input
            // then the entire thing must be sorted
            cout << "SORTED" << endl;

        }
    }
    
    return 0;
}