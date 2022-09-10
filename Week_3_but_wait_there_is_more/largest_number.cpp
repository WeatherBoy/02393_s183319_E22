#include <iostream>
#include <vector>
using namespace std;

int main() {
    int number_of_inputs;
    int tmp_input;
    // We will later set the first occurence to false
    bool first_occurence = true;
    // We can initialize the largest number to zero,
    // because it has been specified that all numbers
    // are positive.
    int largest_number = 0;

    cin >> number_of_inputs;

    if (0 < number_of_inputs) {
        // We use the vector type because Hanse said
        // we couldn't use a list.
        // aParEntLY thEy nEed tO kNoW tHe sIZe aT cOMpiLe tIMe
        vector<int> list_of_numbers(number_of_inputs);

        for (int i = 0; i < number_of_inputs; i++) {
            // get all the inputs
            cin >> tmp_input;

            if (0 <= tmp_input) {
                // the input SHOULD be a POSITIVE INTEGER!
                list_of_numbers[i] = tmp_input;
                if (largest_number < tmp_input) {
                    largest_number = tmp_input;

                }
            } else {
                // if the input isn't a POSITIVE INTEGER
                // it goes "straight to jail!"
                list_of_numbers[i] = -1;

            }
        }

        for (int i = 0; i < number_of_inputs; i++) {
            // print all the stored inputs
            if (list_of_numbers[i] == largest_number && first_occurence) {
                cout << "*" << list_of_numbers[i] << "* ";
                // it will no longer be the first occurence of the largest
                // number amongst the provided numbers
                first_occurence = false;

            } else if (list_of_numbers[i] != -1) {
                // if the the number isn't negative one, then
                // we weren't given a negative number on the
                // first go around.
                cout << list_of_numbers[i] << " ";
                
            }
        }
    }
    
    return 0;
}